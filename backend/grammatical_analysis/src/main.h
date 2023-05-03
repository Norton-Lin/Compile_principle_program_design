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

class Type {

public:
    string token;//终结符具体内容
    int id;//终结符的类型代号
    int lineNumber;//终结符的行号
    Type() {}

    Type(string content, int type, int line) : token(content), id(type), lineNumber(line) {}

};
class Error{
    
public:
    string error_type;
    int col;
    int lineno;

    Error() {};
    Error(string error_type_value, int col_value, int lineno_value) : error_type(error_type_value), col(col_value), lineno(lineno_value) {}
};
class BitNode {
public:
    int col,line;
    string data;
    string type;
    BitNode* father;
    vector<BitNode *> children;

    BitNode(){}

    BitNode(int col_value,int line_value,string data_val, string type_val) : col(col_value),line(line_value),data(data_val), type(type_val) {}

    void insertChild(BitNode *child);
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

union Nodes {
    Type *TYPE;
    BitNode *BITNODE;
};
#define YYSTYPE Nodes
#endif