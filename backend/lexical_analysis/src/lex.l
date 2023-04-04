%{
#include "main.h"
#define LEXDEBUG 1
vector<string> lexErrorInfo;
void addLexErrorInfo(string info, int lineno, int column);

int yycolumn = 1;
string charRes;

extern "C"
{
	int yywrap();
	int yylex();
}
//extern YYSTYPE yylval;
Type* yylval;
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
identifier {letter}({letter}|digit)*
relop (>=|>|<|<=|<>|=)
digits {digit}+
num {digit}+\.{digit}+
vartype (integer|real|boolean|char)
addop (\+|-|or)
mulop (\*|\/|and|mod|div)
assignop (:=)
separator (\(|\)|\[|\]|:|;|,|\.)

%%

{line} {
	yycolumn = 1;
}

{blank} {
	yycolumn++;
}

{relop} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _RELOP;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"relop:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _RELOP;
#endif
}

{digits} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _DIGITS;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"integer:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _DIGITS;
#endif
}

{num} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _NUM;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"real:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _NUM;
#endif
}

{vartype} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _VARTYPE;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"vartype:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _VARTYPE;
#endif
}

{addop} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _ADDOP;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"addop:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ADDOP;
#endif
}

{mulop} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _MULOP;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"mulop:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _MULOP;
#endif
}

{assignop} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _ASSIGNOP;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"assignop:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ASSIGNOP;
#endif
}

{separator} {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _SEPARATOR;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"separator:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _SEPARATOR;
#endif
}

"program" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _PROGRAM;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _PROGRAM;
#endif
}

"const" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _CONST;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _CONST;
#endif
}

"var" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _VAR;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _VAR;
#endif
}

"procedure" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _PROCEDURE;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _PROCEDURE;
#endif
}

"function" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _FUNCTION;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _FUNCTION;
#endif
}

"begin" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _BEGIN;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _BEGIN;
#endif
}

"end" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _END;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _END;
#endif
}

"array" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _ARRAY;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ARRAY;
#endif
}

"of" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _OF;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _OF;
#endif
}

"if" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _IF;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _IF;
#endif
}

"then" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _THEN;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _THEN;
#endif
}

"for" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _FOR;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _FOR;
#endif
}

"to" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _TO;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _TO;
#endif
}

"do" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _DO;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _DO;
#endif
}

"read" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _READ;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _READ;
#endif
}

"write" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _WRITE;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _WRITE;
#endif
}

"not" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _NOT;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _NOT;
#endif
}

"else" {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _ELSE;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ELSE;
#endif
}

"\.\." {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _RANGE;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"keyword:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _RANGE;
#endif
}

("true"|"false") {
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _BOOLEAN;
	yylval->lineNumber = yylineno;
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"boolean:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _BOOLEAN;
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
	yylval = new Type;
	if(len == 0)
		yylval->token = "\0";
	else
		yylval->token = charRes;
	yylval->id = _CHAR;
	yylval->lineNumber = yylineno;
	yycolumn = 1;
	BEGIN(INITIAL);
#ifdef LEXDEBUG
	fprintf(yyout,"char:%s\n",yylval->token.c_str());
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
		yylval = new Type;
		yylval->token = "\0";
		yylval->id = _CHAR;
		yylval->lineNumber = yylineno;
		yycolumn++;
		BEGIN(INITIAL);
#ifdef LEXDEBUG
		fprintf(yyout,"char:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
		return _CHAR;
#endif
	}
	else if(len > 1)
	{
		addLexErrorInfo("Too many characters", yylineno, yycolumn);
		yylval = new Type;
		yylval->token = charRes[0];
		yylval->id = _CHAR;
		yylval->lineNumber = yylineno;
		yycolumn += len+1;
		BEGIN(INITIAL);
#ifdef LEXDEBUG
		fprintf(yyout,"char:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
		return _CHAR;
#endif
	}
	else
	{
		yylval = new Type;
		yylval->token = charRes[0];
		yylval->id = _CHAR;
		yylval->lineNumber = yylineno;
		yycolumn += 2;
		BEGIN(INITIAL);
#ifdef LEXDEBUG
		fprintf(yyout,"char:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
		return _CHAR;
#endif
	}
}

{identifier} {
	if(yyleng > 50)//截断处理，防止出现过长的标识符
	{
		yytext[50] = 0;
	}
	yylval = new Type;
	yylval->token = yytext;
	yylval->id = _ID;
	yylval->lineNumber = yylineno;
	//TODO 此处需要补充一个插入符号表的函数
	yycolumn += yyleng;
#ifdef LEXDEBUG
	fprintf(yyout,"id:%s\n",yylval->token.c_str());
#endif
#ifndef LEXDEBUG
	return _ID;
#endif
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

int main(){
	yyin = fopen("D://homework//test.txt","r");
	yyout = fopen("D://homework//out.txt","w");
	yylex();
	for (auto c : lexErrorInfo)
	    cout << c << endl;
	return 0;
}