%{
#include "main.h"
#include "y.tab.hpp"

extern "C"{
	// int yyparse(void);
	void yyerror(const char *s);
	void yyerror_2(const char *s, int line_val, int col_val);
	extern int yylex(void);
}
extern int yylineno,yycolumn;

void BitNode::insertChild(BitNode* child) {
    children.push_back(child);
	child->father=this;
	cout<<"\t\t"<<this->type<<"\t"<<child->type<<"\t"<<child->data<<"\t"<<endl;
}

BitNode* root;

%}

%token<TYPE> _PROGRAM _CONST _VAR _PROCEDURE _FUNCTION _BEGIN _END _ARRAY _OF _IF _THEN _FOR _TO _DO _READ _WRITE _NOT _ELSE _RANGE _UMINUS _ID _RELOP _DIGITS _NUM _VARTYPE _ADDOP _MULOP _ASSIGNOP _SEPARATOR _CHAR _BOOLEAN
%type<BITNODE> programstruct program_head program_body idlist const_declarations const_declaration const_value var_declarations var_declaration basic_type type period subprogram_declarations subprogram subprogram_head formal_parameter 
%type<BITNODE> parameter_list parameter var_parameter value_parameter subprogram_body compound_statement statement_list statement variable_list variable id_varpart procedure_call else_part term factor simple_expression expression_list expression
%%

programstruct: program_head program_body '.' {
	BitNode *Node3 = new BitNode(yycolumn,yylineno,".", "SEPARATOR");

	root = new BitNode(yycolumn,yylineno,"","programstruct");
	root->insertChild($1);
        root->insertChild($2);
        root->insertChild(Node3);

	cout << "programstruct -> program_head program_body . [OK]" << endl;
	cout << "Parse OK!" << endl;
        $$ = root;
};

program_head:  _PROGRAM _ID ';'{
	BitNode *newNode, *Node1, *Node2, *Node3;
       	Node1 = new BitNode(yycolumn,yylineno,$1->token, "PROGRAM");
       	Node2 = new BitNode(yycolumn,yylineno,$2->token, "ID");
       	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");
       	newNode = new BitNode(yycolumn,yylineno,"", "program_head");

       	newNode->insertChild(Node1);
       	newNode->insertChild(Node2);
       	newNode->insertChild(Node3);

       	cout<<"program_head -> program id ; [OK]"<<endl;
       	$$ = newNode;
}
	| _PROGRAM _ID '(' idlist ')' ';'{
        BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node6;
        newNode = new BitNode(yycolumn,yylineno,"", "program_head");
        Node1 = new BitNode(yycolumn,yylineno,$1->token, "PROGRAM");
        Node2 = new BitNode(yycolumn,yylineno,$2->token, "ID");
        Node3 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
        Node5 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");
        Node6 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild($4);
        newNode->insertChild(Node5);
        newNode->insertChild(Node6);

        cout<<"program_head -> program id ( idlist ) ; [OK]"<<endl;
	$$ = newNode;
};

program_body: const_declarations var_declarations subprogram_declarations compound_statement {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "program_body");

	newNode->insertChild($1);
	newNode->insertChild($2);
	newNode->insertChild($3);
	newNode->insertChild($4);

	cout<<"program_body -> const_declarations var_declarationssubprogram_declarations compound_statement [OK]"<<endl;
	$$ = newNode;
};

idlist: idlist ',' _ID {
	BitNode *newNode, *Node2, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "idlist");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "ID");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"idlist -> idlist , id [OK]"<<endl;
	$$ = newNode;
}
	| _ID {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "idlist");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ID");

	cout<<"idlist -> id [OK]"<<endl;
	$$ = newNode;
};

const_declarations: _CONST const_declaration ';' {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "const_declarations");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "CONST");
	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"const_declarations -> const const_declaration ; [OK]"<<endl;
	$$ = newNode;
}
	| {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "const_declarations");

	cout<<"const_declarations -> empty [OK]"<<endl;
	$$ = newNode;
};

const_declaration: const_declaration ';' _ID _RELOP const_value {
	if($3->token.compare("=") != 0)
        	yyerror("");

	BitNode *newNode, *Node2, *Node3, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "const_declaration");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "ID");
	Node4 = new BitNode(yycolumn,yylineno,$4->token, "RELOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild($5);

	cout<<"const_declaration -> const_declaration ; id = const_value [OK]"<<endl;
	$$ = newNode;
}
 	| _ID _RELOP const_value {
 	if($2->token.compare("=")!=0)
        	yyerror("");

	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "const_declaration");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ID");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "RELOP");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"const_declaration -> id = const_value [OK]"<<endl;
	$$ = newNode;
};

const_value: _ADDOP _NUM {
	if($1->token.compare("+") != 0 && $1->token.compare("-") != 0)
		yyerror("");

	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ADDOP");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> +/- num [OK]"<<endl;
	$$ = newNode;
}
	| _NUM {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "NUM");

	newNode->insertChild(Node1);

	cout<<"const_value -> num [OK]"<<endl;
	$$ = newNode;
}
 	|  _CHAR  {
	// TODO: 与词法分析部分沟通，确定文法产生式的符号如何处理
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "CHAR");

	newNode->insertChild(Node1);

	cout<<"const_value -> char [OK]"<<endl;
	$$ = newNode;
};

var_declarations: _VAR var_declaration ';' {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "var_declarations");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "VAR");
	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"var_declarations -> var var_declaration ; [OK]"<<endl;
	$$ = newNode;
}
	| {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "var_declarations");

	cout<<"var_declarations -> empty [OK]"<<endl;
	$$ = newNode;
};

var_declaration: var_declaration ';' idlist ':' type {
	BitNode *newNode, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "var_declaration");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);
	newNode->insertChild($5);

	cout<<"var_declaration -> var_declaration ; idlist : type [OK]"<<endl;
	$$ = newNode;
}
 	| idlist ':' type {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "var_declaration");
	Node2 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"var_declaration -> idlist : type [OK]"<<endl;
	$$ = newNode;
};

type: basic_type {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "type");

	newNode->insertChild($1);

	cout<<"type -> basic_type [OK]"<<endl;
	$$ = newNode;
}
 	| _ARRAY '[' period ']' _OF basic_type {
	BitNode *newNode, *Node1, *Node2, *Node4, *Node5;
	newNode = new BitNode(yycolumn,yylineno,"", "type");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ARRAY");
	Node2 = new BitNode(yycolumn,yylineno,"[", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,"]", "SEPARATOR");
	Node5 = new BitNode(yycolumn,yylineno,$5->token, "OF");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);
	newNode->insertChild($6);

	cout<<"type -> array [ period ] of basic_type [OK]"<<endl;
	$$ = newNode;
};

basic_type: _VARTYPE {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "basic_type");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "VARTYPE");

	newNode->insertChild(Node1);

	cout<<"type -> basic_type [OK]"<<endl;
	$$ = newNode;
};

period: period ',' _DIGITS _RANGE _DIGITS{
	BitNode *newNode, *Node2, *Node3, *Node4, *Node5;
	newNode = new BitNode(yycolumn,yylineno,"", "period");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "DIGITS");
	Node4 = new BitNode(yycolumn,yylineno,$4->token, "RANGE");
	Node5 = new BitNode(yycolumn,yylineno,$5->token, "DIGITS");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);

	cout<<"period -> period , digits .. digits [OK]"<<endl;
	$$ = newNode;
}
	| _DIGITS _RANGE _DIGITS {
	BitNode *newNode, *Node1, *Node2, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "period");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "DIGITS");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "RANGE");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"period -> digits .. digits [OK]"<<endl;
	$$ = newNode;
};

subprogram_declarations: subprogram_declarations subprogram ';' {
	BitNode *newNode, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_declarations");
	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"subprogram_declarations -> subprogram_declarations subprogram ; [OK]"<<endl;
	$$ = newNode;
}
 	| {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "subprogram_declarations");

	cout<<"subprogram_declarations -> empty [OK]"<<endl;
	$$ = newNode;
};

subprogram: subprogram_head ';' subprogram_body {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"subprogram -> subprogram_head _SEPARATOR subprogram_body [OK]"<<endl;
	$$ = newNode;
};

subprogram_head: _PROCEDURE _ID formal_parameter {
	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_head");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "PROCEDURE");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"subprogram_head -> procedure id formal_parameter [OK]"<<endl;
	$$ = newNode;
}
 	| _FUNCTION _ID formal_parameter ':' basic_type {
	BitNode *newNode,*Node1, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_head");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "FUNCTION");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "ID");
	Node4 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);
	newNode->insertChild($5);

	cout<<"subprogram_head -> function id formal_parameter : basic_type [OK]"<<endl;
	$$ = newNode;
};

formal_parameter: '(' parameter_list ')' {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "formal_parameter");
	Node1 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<" formal_parameter -> ( parameter_list ) [OK]"<<endl;
	$$ = newNode;
}
	|{
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "formal_parameter");

	cout<<"formal_parameter -> empty [OK]"<<endl;
	$$ = newNode;
};

parameter_list: parameter_list ';' parameter {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "parameter_list");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"parameter_list -> parameter_list _SEPARATOR parameter [OK]"<<endl;
	$$ = newNode;
}
	| parameter {
	BitNode * newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "parameter_list");

	newNode->insertChild($1);

	cout<<"parameter_list -> parameter [OK]"<<endl;
	$$ = newNode;
};

parameter: var_parameter {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "parameter");

	newNode->insertChild($1);

	cout<<"parameter -> var_parameter [OK]"<<endl;
	$$ = newNode;
}
	| value_parameter {
	BitNode *newNode;
        newNode = new BitNode(yycolumn,yylineno,"", "parameter");

        newNode->insertChild($1);

        cout<<"parameter -> value_parameter [OK]"<<endl;
        $$ = newNode;
};

var_parameter: _VAR value_parameter{
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "var_parameter");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "VAR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"var_parameter -> var value_parameter [OK]"<<endl;
	$$ = newNode;
};

value_parameter: idlist ':' basic_type {
	// if($2->token.compare(":") != 0)
	//	yyerror("");

	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "value_parameter");
	Node2 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"value_parameter -> idlist : simple_type [OK]"<<endl;
	$$ = newNode;
};

subprogram_body: const_declarations var_declarations compound_statement {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_body");

	newNode->insertChild($1);
	newNode->insertChild($2);
	newNode->insertChild($3);

	cout<<"subprogram_body -> const_declarations var_declarations compound_statement [OK]"<<endl;
	$$ = newNode;
};

compound_statement: _BEGIN statement_list _END {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "compound_statement");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "BEGIN");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "END");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"compound_statement -> begin statement_list end [OK]"<<endl;
	$$ = newNode;
};

statement_list: statement_list ';' statement {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "statement_list");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"statement_list -> statement_list ; statement [OK]"<<endl;
	$$ = newNode;
}
	| statement {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "statement_list");
	newNode->insertChild($1);

	cout<<"statement_list -> statement [OK]"<<endl;
	$$ = newNode;
};

statement: variable _ASSIGNOP expression {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "ASSIGNOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"statement -> variable _ASSIGNOP expression [OK]"<<endl;
	$$ = newNode;
}
	| procedure_call {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	newNode->insertChild($1);

	cout<<"statement -> procedure_call [OK]"<<endl;
	$$ = newNode;
}
	| compound_statement {
	BitNode *newNode;
        newNode = new BitNode(yycolumn,yylineno,"", "statement");
        newNode->insertChild($1);

        cout<<"statement -> compound_statement [OK]"<<endl;
        $$ = newNode;
}
	| _IF expression _THEN statement else_part {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "IF");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "THEN");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);
	newNode->insertChild($4);
	newNode->insertChild($5);

	cout<<"statement -> if expression then statement else_part [OK]"<<endl;
	$$ = newNode;
}
	| _FOR _ID _ASSIGNOP expression _TO expression _DO statement {
	BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node7;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "FOR");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "ID");
	Node3 = new BitNode(yycolumn,yylineno,$3->token, "ASSIGNOP");
	Node5 = new BitNode(yycolumn,yylineno,$5->token, "TO");
	Node7 = new BitNode(yycolumn,yylineno,$7->token, "DO");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild($4);
	newNode->insertChild(Node5);
	newNode->insertChild($6);
	newNode->insertChild(Node7);

	cout<<"statement -> for id assignop expression to expression do statement [OK]"<<endl;
	$$ = newNode;
}
	| _READ '(' variable_list ')' {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "READ");
	Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);

	cout<<"statement -> read ( variable_list ) [OK]"<<endl;
	$$ = newNode;
}
	| _WRITE '(' expression_list ')' {
        BitNode *newNode, *Node1, *Node2, *Node4;
        newNode = new BitNode(yycolumn,yylineno,"", "statement");
        Node1 = new BitNode(yycolumn,yylineno,$1->token, "WRITE");
        Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
        Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

        newNode->insertChild(Node1);
        newNode->insertChild(Node2);
        newNode->insertChild($3);
        newNode->insertChild(Node4);

        cout<<"statement -> write ( variable_list ) [OK]"<<endl;
        $$ = newNode;
}
	| {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "statement");

	cout<<"statement -> empty [OK]"<<endl;
	$$ = newNode;
};

variable_list: variable_list ',' variable{
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "variable_list");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"variable_list -> variable_list _SEPARATOR variable [OK]"<<endl;
	$$ = newNode;
}
 	| variable {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "variable_list");

	newNode->insertChild($1);

	cout<<"statement -> variable [OK]"<<endl;
	$$ = newNode;
};

variable: _ID id_varpart {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "variable");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"variable -> id id_varpart [OK]"<<endl;
	$$ = newNode;
};

id_varpart: '[' expression_list ']' {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "id_varpart");
	Node1 = new BitNode(yycolumn,yylineno,"[", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,"]", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"id_varpart -> [ expression_list ] [OK]"<<endl;
	$$ = newNode;
}
	| {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "id_varpart");

	cout<<"id_varpart -> empty [OK]"<<endl;
	$$ = newNode;
};

procedure_call: _ID {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "procedure_call");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ID");

	newNode->insertChild(Node1);

	cout<<"procedure_call -> id [OK]"<<endl;
	$$ = newNode;
}
	| _ID '(' expression_list ')' {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "procedure_call");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ID");
	Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);

	cout<<"procedure_call -> id ( expression_list ) [OK]"<<endl;
	$$ = newNode;
};

else_part: _ELSE statement {
	BitNode *newNode, *Node1;
	newNode=new BitNode(yycolumn,yylineno,"", "else_part");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ELSE");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"else_part -> else statement [OK]"<<endl;
	$$ = newNode;
}
	| {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "else_part");

	cout<<"else_part -> empty [OK]"<<endl;
	$$ = newNode;
};

expression_list: expression_list ',' expression {

	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "expression_list");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"expression_list -> expression_list , expression [OK]"<<endl;
	$$ = newNode;
}
	| expression {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "expression_list");

	newNode->insertChild($1);

	cout<<"expression_list -> expression [OK]"<<endl;
	$$ = newNode;
};

expression: simple_expression _RELOP simple_expression {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "expression");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "RELOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"expression -> simple_expression relop simple_expression [OK]"<<endl;
	$$ = newNode;
}
 	| simple_expression {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "expression");

	newNode->insertChild($1);

	cout<<"expression -> simple_expression [OK]"<<endl;
	$$ = newNode;
};

simple_expression: simple_expression _ADDOP term {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "simple_expression");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "ADDOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"simple_expression -> simple_expression addop term [OK]"<<endl;
	$$ = newNode;
}
	| term {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "simple_expression");

	newNode->insertChild($1);

	cout<<"simple_expression -> term [OK]"<<endl;
	$$ = newNode;
};

term: term _MULOP factor {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "term");
	Node2 = new BitNode(yycolumn,yylineno,$2->token, "MULOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"term -> term mulop factor [OK]"<<endl;
	$$ = newNode;
}
	| factor {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "term");

	newNode->insertChild($1);

	cout<<"term -> factor [OK]"<<endl;
	$$ = newNode;
};

factor: _NUM {
        BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");
        Node1 = new BitNode(yycolumn,yylineno,$1->token, "NUM");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        $$ = newNode;
}
| _DIGITS {
        BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");
        Node1 = new BitNode(yycolumn,yylineno,$1->token, "DIGITS");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        $$ = newNode;
}
        | variable {
        BitNode *newNode;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");

        newNode->insertChild($1);

        cout<<" factor -> variable [OK]"<<endl;
        $$ = newNode;
}
	| _ID '(' expression_list ')' {

	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode =  new BitNode(yycolumn,yylineno,"", "factor");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "ID");
	Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);

	cout<<"factor -> id ( expression_list ) [OK]"<<endl;
	$$ = newNode;
}

 	| '(' expression ')' {
	// if($1->token.compare("(") != 0 || $3->token.compare(")") != 0)
	//	yyerror("");

	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "factor");
	Node1 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"factor -> ( expression ) [OK]"<<endl;
	$$ = newNode;
}
 	| _NOT factor {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "factor");
	Node1 = new BitNode(yycolumn,yylineno,$1->token, "NOT");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"factor -> not factor [OK]"<<endl;
	$$ = newNode;
}
 	| _UMINUS factor {
	BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");
        Node1 = new BitNode(yycolumn,yylineno,$1->token, "UMINUS");

        newNode->insertChild(Node1);
        newNode->insertChild($2);

        cout<<"factor -> uminus factor [OK]"<<endl;
        $$ = newNode;
};

%%
// TODO: 确定列号传参
// TODO: 设置一个Error类，同一管理错误输出
void yyerror_2(const char *s, int line_val, int col_val)
{
	cout << "Line:" << line_val << "\tCol:" << col_val << "\t"<< s << endl;
}

void yyerror(const char *s)
{
	extern char *yytext;
	extern YYSTYPE yylval;
	cout << "Line:" << yylineno << "\t" << s <<"\tcolumn:"<<yycolumn<<"\t"<<yytext<<endl;
}

int main(int argc,char *argv[])
{   
    extern FILE* yyin;
    FILE* fin = NULL;
    fin = fopen(argv[1], "r");
    if(fin == NULL)
    { 
       	cout << "Fail to open file. Please try again..." << endl;
        return -1;
    }
    yyin=fin;
    yyparse();
    fclose(fin);
    return 0;
}



