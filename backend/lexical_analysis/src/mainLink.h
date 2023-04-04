#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//#define LEXDEBUG //����ģ�鵥������

class Type {

public:
    string token;//�ս����������
    int id;//�ս�������ʹ���
    int lineNumber;//�ս�����к�
    Type() {}
    Type(string content, int type, int line) : token(content), id(type), lineNumber(line) {}
    
};

#define YYSTYPE Type*


// enum yytokentype{
//         _PROGRAM = 256,
//         _CONST = 257,
//         _VAR = 258,
//         _PROCEDURE = 259,
//         _FUNCTION = 260,
//         _BEGIN = 261,
//         _END = 262,
//         _ARRAY = 263,
//         _OF = 264,
//         _IF = 265,
//         _THEN = 266,
//         _FOR = 267,
//         _TO = 268,
//         _DO = 269,
//         _READ = 270,
//         _WRITE = 271,
//         _NOT = 272,
//         _ELSE = 273,
//         _RANGE = 274,//��ʾ  ..
//         _UMINUS = 275,//��ʾ��Ŀ-���������������������ȼ����ߣ����Ǵʷ��������޷��������Ǻţ����б�Ҫ�������﷨�����н����޸�
//         _ID = 276,
//         _RELOP = 277,
//         _DIGITS = 278,//Integer
//         _NUM = 279,//real
//         _VARTYPE = 280,
//         _ADDOP = 281,
//         _MULOP = 282,
//         _ASSIGNOP = 283,
//         _SEPARATOR = 284,
//         _CHAR = 285,
//         _BOOLEAN = 286
// };