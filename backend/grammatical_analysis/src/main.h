#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <fstream>

using namespace std;

class Type
{

public:
    string token;   // 终结符具体内容
    int id;         // 终结符的类型代号
    int lineNumber; // 终结符的行号
    Type() {}

    Type(string content, int type, int line) : token(content), id(type), lineNumber(line) {}
};
class Error
{

public:
    string error_type; // 错误信息
    int col;           // 错误所在列号
    int lineno;        // 错误所在行号

    Error(){};
    Error(string error_type_value, int col_value, int lineno_value) : error_type(error_type_value), col(col_value), lineno(lineno_value) {}
};

class BitNode
{

public:
    int col, line;              // 行列号
    string data;                // 左部非终结符的内容
    string type;                // 左部非终结符的类型
    BitNode *father;            // 左部非终结符的父节点
    vector<BitNode *> children; // 右部文法符号

    BitNode() {}

    BitNode(int line_value, int col_value, string data_val, string type_val) : line(line_value), col(col_value), data(data_val), type(type_val) {}

    void insertChild(BitNode *child); // 插入文法产生式的右部文法符号
};

class Pre {
public:
    explicit Pre(string filename);
    bool Read_Line();
    bool Write_Line();
    void Dispose();
private:
    ifstream input;
    ofstream output;
    vector<string> lines;
    string filename;
    static string Break(const string& String);
    static char jump_space(int &, string line);
};

union Nodes
{
    Type *TYPE;
    BitNode *BITNODE;
};
#define YYSTYPE Nodes
#endif