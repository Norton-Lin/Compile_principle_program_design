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
//    string data; // Ҳ���Ǵʷ�������ȡ���ַ�������Ҷ�ӽڵ㣨���ս������ֵΪ���ַ���
//    string type; // ����
//    BitNode* father;
//    vector<BitNode*> children; //�ӽڵ�
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