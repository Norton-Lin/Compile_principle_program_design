%{
#include "main.h"
#include "y.tab.hpp"

vector<string> lexErrorInfo;
void addLexErrorInfo(string info, int lineno, int column);

int yycolumn = 1;
string charRes;

extern "C"
{
	int yywrap();
	int yylex();
}
%}

%option yylineno

%x CH
%x SINGLE1
%x SINGLE2
%x MULTIPLE

line \n
letter [a-z]
digit [0-9]
blank [ \r\t]
identifier {letter}({letter}|{digit})*
relop (>=|>|<|<=|<>|=)
digits {digit}+
num {digit}+\.{digit}+
vartype (integer|real|boolean|char)
addop (\+|or)
mulop (\*|\/|and|mod|div)
assignop (:=)
separator (\(|\)|\[|\]|:|,|\.|;)

%%

{line} {
	yycolumn = 1;
}

{blank} {
	yycolumn++;
}

{relop} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _RELOP;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"relop:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _RELOP;
#endif
}

{digits} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _DIGITS;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"integer:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _DIGITS;
#endif
}

{num} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _NUM;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"real:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _NUM;
#endif
}

{vartype} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _VARTYPE;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"vartype:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _VARTYPE;
#endif
}

{addop} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _ADDOP;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"addop:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ADDOP;
#endif
}
"-" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _UMINUS;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"UMINUS:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _UMINUS;
#endif
}

{mulop} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _MULOP;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"mulop:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _MULOP;
#endif
}

{assignop} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _ASSIGNOP;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"assignop:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ASSIGNOP;
#endif
}

{separator} {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _SEPARATOR;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"separator:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return yytext[0];
#endif
}

"program" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _PROGRAM;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _PROGRAM;
#endif
}

"const" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _CONST;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _CONST;
#endif
}
"while" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _WHILE;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _WHILE;
#endif
}


"var" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _VAR;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _VAR;
#endif
}

"procedure" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _PROCEDURE;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _PROCEDURE;
#endif
}

"function" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _FUNCTION;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _FUNCTION;
#endif
}

"begin" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _BEGIN;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _BEGIN;
#endif
}

"end" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _END;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _END;
#endif
}

"array" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _ARRAY;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ARRAY;
#endif
}

"of" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _OF;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _OF;
#endif
}

"if" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _IF;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _IF;
#endif
}

"then" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _THEN;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _THEN;
#endif
}

"for" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _FOR;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _FOR;
#endif
}

"to" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _TO;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _TO;
#endif
}

"do" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _DO;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _DO;
#endif
}

"read" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _READ;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _READ;
#endif
}

"write" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _WRITE;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _WRITE;
#endif
}

"not" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _NOT;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _NOT;
#endif
}

"else" {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _ELSE;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ELSE;
#endif
}

("true"|"false") {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _BOOLEAN;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"boolean:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _BOOLEAN;
#endif
}

{identifier} {
	if(yyleng > 50)//截断处理，防止出现过长的标识符
	{
		yytext[50] = 0;
	}
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _ID;
	yylval.TYPE->lineNumber = yylineno;
	//TODO 此处需要补充一个插入符号表的函数
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"id:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ID;
#endif
}

"\.\." {
	yylval.TYPE = new Type;
	yylval.TYPE->token = yytext;
	yylval.TYPE->id = _RANGE;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _RANGE;
#endif
}

"'" {//识别字符
	BEGIN(CH);
	charRes = "";
	yycolumn++;
}

"//" {//识别单行注释
	BEGIN SINGLE1;
}

"{" {//识别单行注释
	BEGIN SINGLE2;
	yycolumn++;
}

"(*" {//识别多行注释
	BEGIN MULTIPLE;
	yycolumn += 2;
}

. {//处理非法字符
	addLexErrorInfo("Invalid character", yylineno, yycolumn);
	yycolumn++;
}

<CH><<EOF>> {//遇到文件尾部
	int len = charRes.length();
	if(len <= 1)
		addLexErrorInfo("Unexpected end of file", yylineno, yycolumn);
	else
		addLexErrorInfo("Right quote missing", yylineno, yycolumn+len);
	return 0;
}

<CH>\n {
	int len = charRes.length();
	addLexErrorInfo("Right quote missing", yylineno, yycolumn+1);
	yyless(0);
	yylineno--;
	yylval.TYPE = new Type;
	if(len == 0)
		yylval.TYPE->token = "\0";
	else
		yylval.TYPE->token = charRes;
	yylval.TYPE->id = _CHAR;
	yylval.TYPE->lineNumber = yylineno;
	yycolumn = 1;
	BEGIN(INITIAL);
#ifdef LEXDEBUG
	fprintf(yyout,"char:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
	return _CHAR;
#endif
}

<CH>"'" {
	int len = charRes.length();
	if(len == 0)
	{
		addLexErrorInfo("Char context missing", yylineno, yycolumn);
		yylval.TYPE = new Type;
		yylval.TYPE->token = "\0";
		yylval.TYPE->id = _CHAR;
		yylval.TYPE->lineNumber = yylineno;
		yycolumn++;
		BEGIN(INITIAL);
#ifdef LEXDEBUG
		fprintf(yyout,"char:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
		return _CHAR;
#endif
	}
	else if(len > 1)
	{
		addLexErrorInfo("Too many characters", yylineno, yycolumn);
		yylval.TYPE = new Type;
		yylval.TYPE->token = charRes[0];
		yylval.TYPE->id = _CHAR;
		yylval.TYPE->lineNumber = yylineno;
		yycolumn += len+1;
		BEGIN(INITIAL);
#ifdef LEXDEBUG
		fprintf(yyout,"char:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
		return _CHAR;
#endif
	}
	else
	{
		yylval.TYPE = new Type;
		yylval.TYPE->token = charRes[0];
		yylval.TYPE->id = _CHAR;
		yylval.TYPE->lineNumber = yylineno;
		yycolumn += 2;
		BEGIN(INITIAL);
#ifdef LEXDEBUG
		fprintf(yyout,"char:%s\n",yylval.TYPE->token.c_str());
#endif
#ifndef LEXDEBUG
		return _CHAR;
#endif
	}
}

<CH>. { 
	charRes += yytext[0];
}

<SINGLE1><<EOF>> {
	return 0;
}

<SINGLE1>\n {
	BEGIN(INITIAL);
}

<SINGLE1>. {

}

<SINGLE2><<EOF>> {
	addLexErrorInfo("Unexpected end of file", yylineno, yycolumn);
	return 0;
}

<SINGLE2>\n {
	addLexErrorInfo("Right quote missing", yylineno, yycolumn+1);
	BEGIN(INITIAL);
}

<SINGLE2>"}" {
	BEGIN(INITIAL);
	yycolumn++;
}

<SINGLE2>. {
	yycolumn++;
}

<MULTIPLE><<EOF>> {
	addLexErrorInfo("Unexpected end of file", yylineno, yycolumn);
	return 0;
}

<MULTIPLE>"*)" {
	BEGIN(INITIAL);
	yycolumn += 2;
}

<MULTIPLE>\n {
	yycolumn = 1;
}

<MULTIPLE>. {
	yycolumn++;
}

%%
int yywrap(){
	return 1;
}

void addLexErrorInfo(string info, int lineno, int column){

	string errorInfo = "[" + info + "] 第" + to_string(lineno) + "行,第" + to_string(column) + "列\n"; 
	lexErrorInfo.push_back(errorInfo);

}