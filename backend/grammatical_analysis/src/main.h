#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class Type {

public:
    string token;//终结符具体内容
    int id;//终结符的类型代号
    int lineNumber;//终结符的行号
    Type() {}

    Type(string content, int type, int line) : token(content), id(type), lineNumber(line) {}

};

class BitNode {
public:
    string data;
    string type;
    vector<BitNode *> children;

    BitNode(){}

    BitNode(string data_val, string type_val) : data(data_val), type(type_val) {}

    void insertChild(BitNode *child);
};

union Nodes {
    Type *TYPE;
    BitNode *BITNODE;
};
#define YYSTYPE Nodes
#endif