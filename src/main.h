#include <iostream>
#inlcude <string>
#include <vector>

using namespace std;

class Type {

public:
    string token;//终结符具体内容
    int id;//终结符的类型代号
    int lineNumber;//终结符的行号
    Type() {}
    Type(string content, int type, int line) : token(content), id(type), lineNumber(line) {}

};
#define YYSTYPE Type*

#define YYTOKENTYPE enum yytokentype{
    _PROGRAM = 256,
    _CONST = 257,
    _VAR = 258,
    _PROCEDURE = 259,
    _FUNCTION = 260,
    _BEGIN = 261,
    _END = 262,
    _ARRAY = 263,
    _OF = 264,
    _IF = 265,
    _THEN = 266,
    _FOR = 267,
    _TO = 268,
    _DO = 269,
    _READ = 270,
    _WRITE = 271
    _NOT = 272,
    _ELSE = 273,
    _RANGE = 274,//表示  ..
    _UMINUS = 275,
    _ID = 276,
    _RELOP = 277,
    _DIGITS = 278,
    _NUM = 279,
    _VARTYPE = 280,
    _ADDOP = 281,
    _MULOP = 282,
    _ASSIGNOP = 283,
    _SEPARATOR = 284,
    _CHAR = 285
};