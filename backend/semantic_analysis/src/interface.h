#pragma once
#include <vector>
#include <string>
#include "main.h"
#include "y.tab.hpp"


class llvm
{
public:
     typedef struct
     {
        int a;
     }Value;

     typedef struct
     {
         int b;
     }function;
};

using namespace std;
//class BitNode
//{
//public:
//    string data; // 也就是词法分析截取的字符串，非叶子节点（非终结符）的值为空字符串
//    string type; // 类型
//    BitNode* father;
//    vector<BitNode*> children; //子节点
//
//    void set(string data, string type);
//    void insertChild(BitNode* child);
//};

class ASTNode;
class CodeGenContext
{
    ;
};

class BasicBlock
{

};