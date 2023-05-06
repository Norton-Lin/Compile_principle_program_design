#include <utility>

#include "main.h"

Pre::Pre(string filename) {
    Pre::filename = std::move(filename);
}

bool Pre::Read_Line() {
    input.open(filename);
    string line;
    if (input) {
        while (getline(input, line)) {
            lines.push_back(line);
        }
        input.close();
        return true;
    }
    return false;
}

void Pre::Dispose() {
    int state = 0;
    string line;
    for (auto & i : lines) {
        line = i;
        for (int j = 0; j < line.size(); ++j) {
            char nc = line[j];
            switch (state) {
                default:;
                case 0: {
                    nc = jump_space(j, line);
                    if (j > line.size())
                        break;

                    if (nc >= 'A' && nc <= 'Z')
                        line.replace(j, 1, 1, (char)(nc + 32));

                    if (nc == '\'')
                        state = 1;

                    if (nc == '{')
                        state = 2;

                    if (nc == '/')
                        state = 3;

                    if (nc == '(')
                        state = 4;
                    break;
                }

                case 1: {
                    if (nc != '\'')
                        continue;
                    else
                        state = 0;
                    break;
                }

                case 2: {
                    if (nc != '}')
                        continue;
                    else
                        state = 0;
                    break;
                }

                case 3: {
                    if (nc != '/') {
                        j--;
                        state = 0;
                    } else
                        continue;
                    break;
                }

                case 4: {
                    if (nc != '*') {
                        j--;
                        state = 0;
                    } else
                        state = 5;
                    break;
                }

                case 5: {
                    if (nc != '*')
                        continue;
                    else
                        state = 6;
                    break;
                }
                case 6: {
                    if (nc != ')') {
                        j--;
                        state = 5;
                    } else
                        continue;
                }
            }
        }
        i = line;
    }
    Write_Line();
}

bool Pre::Write_Line() {
    string prefix = Break(filename);
    output.open(prefix + "_out.txt", ios::out);
    if (output) {
        for (const string& line :lines) {
            output << line << endl;
        }
        output.close();
        return true;
    }
    return false;
}

string Pre::Break(const string& String) {
    string Buffer;
    for (char i : String) {
        if (i != '.')
            Buffer.push_back(i);
        else
            break;
    }
    return Buffer;
}

char Pre::jump_space(int& j, string line)//跳过空格，返回空格后的第一个字符，超界直接结束
{
    char now = line[j];
    while(now == ' ' || now == '\t')
    {
        j++;
        if (j >= line.size())
        {
            return ' ';
        }
        now = line[j];
    }
    return now;
}