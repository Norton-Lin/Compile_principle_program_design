%{
#include "main.h"

vector<string> lexErrorInfo;
%}

line \n
letter [a-z]
digit [0-9]
blank [ \r\t]
identifier {letter}({letter}|digit)*
relop (>=|>|<|<=|<>|=)
digits {digit}+
num {digit}+\.{digit}+
vartype (integer|real|boolean|char)
addop (\+|-|or)
mulop (\*|\/|div|mod|div)
assignop (:=)
separator (\(|\)|\[|\]|:|;|,|\.)

%%

%%
int yywarp(){
	return 1;
}