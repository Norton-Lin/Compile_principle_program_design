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

BitNode* root;
vector<Error*> errorInfo;
int if_error=0;

void BitNode::insertChild(BitNode* child) {
    children.push_back(child);
	child->father=this;
	cout<<"\t\t"<<this->type<<"\t"<<child->type<<"\t"<<child->data<<"\t"<<endl;
}

BitNode* getBitNode(int yylineno,int yycolumn,string data, string type_val){
	if(type_val.compare("error")==0){
		if_error=1;
		// yyerror(data);
	}
	BitNode* ans=new BitNode(yylineno,yycolumn,data, type_val);
	return ans;
} 

%}

%token<TYPE> _PROGRAM _CONST _VAR _PROCEDURE _FUNCTION _BEGIN _END _ARRAY _OF _IF _THEN _FOR _TO _DO _READ _WRITE _WHILE _NOT _ELSE _RANGE _UMINUS _ID _RELOP _DIGITS _NUM _VARTYPE _ADDOP _MULOP _ASSIGNOP _SEPARATOR _CHAR _BOOLEAN
%type<BITNODE> programstruct program_head program_body idlist const_declarations const_declaration const_value var_declarations var_declaration basic_type type period subprogram_declarations subprogram subprogram_head formal_parameter 
%type<BITNODE> parameter_list parameter var_parameter value_parameter subprogram_body compound_statement statement_list statement variable_list variable id_varpart procedure_call else_part term factor simple_expression expression_list expression
%%

programstruct: program_head program_body '.' {
	BitNode *Node3 = getBitNode(yylineno,yycolumn,".", "SEPARATOR");

	root = getBitNode(yylineno,yycolumn,"","programstruct");
	root->insertChild($1);
        root->insertChild($2);
        root->insertChild(Node3);

	cout << "programstruct -> program_head program_body . [OK]" << endl;
	cout << "Parse OK!" << endl;
        $$ = root;
}
| error program_body '.' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | program_head error '.' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | program_head program_body error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '.'");
	$$ = newNode; 
};

program_head:  _PROGRAM _ID ';'{
	BitNode *newNode, *Node1, *Node2, *Node3;
       	Node1 = getBitNode(yylineno,yycolumn,$1->token, "PROGRAM");
       	Node2 = getBitNode(yylineno,yycolumn,$2->token, "ID");
       	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");
       	newNode = getBitNode(yylineno,yycolumn,"", "program_head");

       	newNode->insertChild(Node1);
       	newNode->insertChild(Node2);
       	newNode->insertChild(Node3);

       	cout<<"program_head -> program id ; [OK]"<<endl;
       	$$ = newNode;
}| error _ID ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROGRAM error ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROGRAM _ID error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 
	| _PROGRAM _ID '(' idlist ')' ';'{
        BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node6;
        newNode = getBitNode(yylineno,yycolumn,"", "program_head");
        Node1 = getBitNode(yylineno,yycolumn,$1->token, "PROGRAM");
        Node2 = getBitNode(yylineno,yycolumn,$2->token, "ID");
        Node3 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
        Node5 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");
        Node6 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild($4);
        newNode->insertChild(Node5);
        newNode->insertChild(Node6);

        cout<<"program_head -> program id ( idlist ) ; [OK]"<<endl;
	$$ = newNode;
}
| error _ID '(' idlist ')' ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROGRAM error '(' idlist ')' ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROGRAM _ID error idlist ')' ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 | _PROGRAM _ID '(' error ')' ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROGRAM _ID '(' idlist error ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode; 
} 


 | _PROGRAM _ID '(' idlist ')' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} ;

program_body: const_declarations var_declarations subprogram_declarations compound_statement {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "program_body");

	newNode->insertChild($1);
	newNode->insertChild($2);
	newNode->insertChild($3);
	newNode->insertChild($4);

	cout<<"program_body -> const_declarations var_declarationssubprogram_declarations compound_statement [OK]"<<endl;
	$$ = newNode;
}
 | error var_declarations subprogram_declarations compound_statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | const_declarations error subprogram_declarations compound_statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | const_declarations var_declarations error compound_statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | const_declarations var_declarations subprogram_declarations error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

idlist: idlist ',' _ID {
	BitNode *newNode, *Node2, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "idlist");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "ID");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"idlist -> idlist , id [OK]"<<endl;
	$$ = newNode;
}
| error ',' _ID { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | idlist error _ID { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	$$ = newNode; 
} 


 | idlist ',' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| _ID {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "idlist");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ID");
	newNode->insertChild(Node1);

	cout<<"idlist -> id [OK]"<<endl;
	$$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing id");
	$$ = newNode; 
} ;

const_declarations: _CONST const_declaration ';' {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "const_declarations");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "CONST");
	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"const_declarations -> const const_declaration ; [OK]"<<endl;
	$$ = newNode;
}
| error const_declaration ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _CONST error ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _CONST const_declaration error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 
	| {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "const_declarations");

	cout<<"const_declarations -> empty [OK]"<<endl;
	$$ = newNode;
};

const_declaration: const_declaration ';' _ID _RELOP const_value {
	if($4->token.compare("=") != 0){
			cout<<$4->token<<"     not   ="<<endl;
        	yyerror("");
	}

	BitNode *newNode, *Node2, *Node3, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "const_declaration");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "ID");
	Node4 = getBitNode(yylineno,yycolumn,$4->token, "RELOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild($5);

	cout<<"const_declaration -> const_declaration ; id = const_value [OK]"<<endl;
	$$ = newNode;
}
| error ';' _ID _RELOP const_value { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | const_declaration error _ID _RELOP const_value { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 


 | const_declaration ';' error _RELOP const_value { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | const_declaration ';' _ID error const_value { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | const_declaration ';' _ID _RELOP error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 	| _ID _RELOP const_value {
 	if($2->token.compare("=")!=0){
			cout<<$2->token<<"     not   ="<<endl;
        	yyerror("");
	}

	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "const_declaration");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ID");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "RELOP");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"const_declaration -> id = const_value [OK]"<<endl;
	$$ = newNode;
}
 | error _RELOP const_value { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ID error const_value { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ID _RELOP error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

const_value: _ADDOP _NUM {
	if($1->token.compare("+") != 0){
		// 修改终结符判断逻辑，因为对终结符 ADDOP的内容为 + or
		cout<<$1->token<<"     not   +"<<endl; 
		yyerror("");
	}

	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, $1->token, "ADDOP");
	Node2 = getBitNode(yylineno,yycolumn, $2->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> + num [OK]"<<endl;
	$$ = newNode;
}

	| _UMINUS _NUM { // 增加 UMINUS 的关联生成式
	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, $1->token, "UMINUS");
	Node2 = getBitNode(yylineno,yycolumn, $2->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> - num [OK]"<<endl;
	$$ = newNode;
}

	| error _NUM {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
}

	| _ADDOP error {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
}

	| _NUM {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "NUM");

	newNode->insertChild(Node1);

	cout<<"const_value -> num [OK]"<<endl;
	$$ = newNode;
}

 	|  _CHAR  { // 处理单个字符
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "CHAR");

	newNode->insertChild(Node1);

	cout<<"const_value -> char [OK]"<<endl;
	$$ = newNode;
}

	| error {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
}

	| _DIGITS { // 增加处理 digits 的生成式
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, $1->token, "DIGITS");

	newNode->insertChild(Node1);

	cout<<"const_value -> digits [OK]"<<endl;
        $$ = newNode;
}

	| _ADDOP _DIGITS { // 增加处理 digits 关联的生成式
	if($1->token.compare("+") != 0) {
		// ADDOP包括两种运算：+ or
		cout<<$1->token<<"     not    +"<<endl;
		yyerror("");
	}

	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, $1->token, "ADDOP");
	Node2 = getBitNode(yylineno,yycolumn, $2->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> + digits [OK]"<<endl;
	$$ = newNode;
}
	| _UMINUS _DIGITS { // 增加处理 digits 关联的生成式
	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, $1->token, "UMINUS");
	Node2 = getBitNode(yylineno,yycolumn, $2->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> - digits [OK]"<<endl;
	$$ = newNode;
}
	| _BOOLEAN{ // 增加处理 boolean 的生成式
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, $1->token, "BOOLEAN");

	newNode->insertChild(Node1);

	cout<<"const_value -> boolean [OK]"<<endl;
        $$ = newNode;
};

var_declarations: _VAR var_declaration ';' {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "var_declarations");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "VAR");
	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"var_declarations -> var var_declaration ; [OK]"<<endl;
	$$ = newNode;
}
| error var_declaration ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _VAR error ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _VAR var_declaration error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 
	| {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "var_declarations");

	cout<<"var_declarations -> empty [OK]"<<endl;
	$$ = newNode;
};

var_declaration: var_declaration ';' idlist ':' type {
	BitNode *newNode, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "var_declaration");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);
	newNode->insertChild($5);

	cout<<"var_declaration -> var_declaration ; idlist : type [OK]"<<endl;
	$$ = newNode;
}

 | error ';' idlist ':' type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | var_declaration error idlist ':' type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 


 | var_declaration ';' error ':' type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | var_declaration ';' idlist error type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	$$ = newNode; 
} 


 | var_declaration ';' idlist ':' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 	| idlist ':' type {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "var_declaration");
	Node2 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"var_declaration -> idlist : type [OK]"<<endl;
	$$ = newNode;
}
| error ':' type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | idlist error type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	$$ = newNode; 
} 


 | idlist ':' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

type: basic_type {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "type");

	newNode->insertChild($1);

	cout<<"type -> basic_type [OK]"<<endl;
	$$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 	| _ARRAY '[' period ']' _OF basic_type {
	BitNode *newNode, *Node1, *Node2, *Node4, *Node5;
	newNode = getBitNode(yylineno,yycolumn,"", "type");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ARRAY");
	Node2 = getBitNode(yylineno,yycolumn,"[", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,"]", "SEPARATOR");
	Node5 = getBitNode(yylineno,yycolumn,$5->token, "OF");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);
	newNode->insertChild($6);

	cout<<"type -> array [ period ] of basic_type [OK]"<<endl;
	$$ = newNode;
}

 | error '[' period ']' _OF basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ARRAY error period ']' _OF basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '['");
	$$ = newNode; 
} 


 | _ARRAY '[' error ']' _OF basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ARRAY '[' period error _OF basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ']'");
	$$ = newNode; 
} 


 | _ARRAY '[' period ']' error basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ARRAY '[' period ']' _OF error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

basic_type: _VARTYPE {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "basic_type");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "VARTYPE");

	newNode->insertChild(Node1);

	cout<<"type -> basic_type [OK]"<<endl;
	$$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

period: period ',' _DIGITS _RANGE _DIGITS{
	BitNode *newNode, *Node2, *Node3, *Node4, *Node5;
	newNode = getBitNode(yylineno,yycolumn,"", "period");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "DIGITS");
	Node4 = getBitNode(yylineno,yycolumn,$4->token, "RANGE");
	Node5 = getBitNode(yylineno,yycolumn,$5->token, "DIGITS");

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
	newNode = getBitNode(yylineno,yycolumn,"", "period");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "DIGITS");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "RANGE");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"period -> digits .. digits [OK]"<<endl;
	$$ = newNode;
} | error ',' _DIGITS _RANGE _DIGITS { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 

 | period error _DIGITS _RANGE _DIGITS { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	$$ = newNode; 
} 


 | period ',' error _RANGE _DIGITS { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | period ',' _DIGITS error _DIGITS { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | period ',' _DIGITS _RANGE error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} | error _RANGE _DIGITS { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _DIGITS error _DIGITS { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '..'");
	$$ = newNode; 
} 


 | _DIGITS _RANGE error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
};

subprogram_declarations: subprogram_declarations subprogram ';' {
	BitNode *newNode, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_declarations");
	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"subprogram_declarations -> subprogram_declarations subprogram ; [OK]"<<endl;
	$$ = newNode;
}
 	| {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "subprogram_declarations");

	cout<<"subprogram_declarations -> empty [OK]"<<endl;
	$$ = newNode;
}| error subprogram ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | subprogram_declarations error ';' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | subprogram_declarations subprogram error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
};

subprogram: subprogram_head ';' subprogram_body {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"subprogram -> subprogram_head _SEPARATOR subprogram_body [OK]"<<endl;
	$$ = newNode;
};

subprogram_head: _PROCEDURE _ID formal_parameter {
	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_head");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "PROCEDURE");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"subprogram_head -> procedure id formal_parameter [OK]"<<endl;
	$$ = newNode;
} | error _ID formal_parameter { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROCEDURE error formal_parameter { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _PROCEDURE _ID error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
}
 	| _FUNCTION _ID formal_parameter ':' basic_type {
	BitNode *newNode,*Node1, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_head");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "FUNCTION");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "ID");
	Node4 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);
	newNode->insertChild($5);

	cout<<"subprogram_head -> function id formal_parameter : basic_type [OK]"<<endl;
	$$ = newNode;
}| error _ID formal_parameter ':' basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _FUNCTION error formal_parameter ':' basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _FUNCTION _ID error ':' basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _FUNCTION _ID formal_parameter error basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	$$ = newNode; 
} 


 | _FUNCTION _ID formal_parameter ':' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
;

formal_parameter: '(' parameter_list ')' {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "formal_parameter");
	Node1 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<" formal_parameter -> ( parameter_list ) [OK]"<<endl;
	$$ = newNode;
} | error parameter_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 | '(' error ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | '(' parameter_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode; 
} 
	|{
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "formal_parameter");

	cout<<"formal_parameter -> empty [OK]"<<endl;
	$$ = newNode;
};

parameter_list: parameter_list ';' parameter {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "parameter_list");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"parameter_list -> parameter_list _SEPARATOR parameter [OK]"<<endl;
	$$ = newNode;
} | error ';' parameter { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | parameter_list error parameter { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 


 | parameter_list ';' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| parameter {
	BitNode * newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "parameter_list");

	newNode->insertChild($1);

	cout<<"parameter_list -> parameter [OK]"<<endl;
	$$ = newNode;
} | error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
};

parameter: var_parameter {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "parameter");

	newNode->insertChild($1);

	cout<<"parameter -> var_parameter [OK]"<<endl;
	$$ = newNode;
}
	| value_parameter {
	BitNode *newNode;
        newNode = getBitNode(yylineno,yycolumn,"", "parameter");

        newNode->insertChild($1);

        cout<<"parameter -> value_parameter [OK]"<<endl;
        $$ = newNode;
} | error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

var_parameter: _VAR value_parameter{
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "var_parameter");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "VAR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"var_parameter -> var value_parameter [OK]"<<endl;
	$$ = newNode;
} | error value_parameter { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing var");
	$$ = newNode; 
} 


 | _VAR error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
};

value_parameter: idlist ':' basic_type {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "value_parameter");
	Node2 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"value_parameter -> idlist : simple_type [OK]"<<endl;
	$$ = newNode;
}|  error ':' basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  idlist error basic_type { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	$$ = newNode; 
} 


 |  idlist ':' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
};

subprogram_body: const_declarations var_declarations compound_statement {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_body");

	newNode->insertChild($1);
	newNode->insertChild($2);
	newNode->insertChild($3);

	cout<<"subprogram_body -> const_declarations var_declarations compound_statement [OK]"<<endl;
	$$ = newNode;
}|  error var_declarations compound_statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  const_declarations error compound_statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  const_declarations var_declarations error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
};

compound_statement: _BEGIN statement_list _END {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "compound_statement");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "BEGIN");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "END");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"compound_statement -> begin statement_list end [OK]"<<endl;
	$$ = newNode;
} 
 |  error statement_list _END { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing begin");
	$$ = newNode; 
} 


 |  _BEGIN error _END { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _BEGIN statement_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing end");
	$$ = newNode; 
};

statement_list: statement_list ';' statement {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "statement_list");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"statement_list -> statement_list ; statement [OK]"<<endl;
	$$ = newNode;
}|  error ';' statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  statement_list error statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	$$ = newNode; 
} 


 |  statement_list ';' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| statement {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "statement_list");
	newNode->insertChild($1);

	cout<<"statement_list -> statement [OK]"<<endl;
	$$ = newNode;
} |  error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

statement: variable _ASSIGNOP expression {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "ASSIGNOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"statement -> variable _ASSIGNOP expression [OK]"<<endl;
	$$ = newNode;
}|  error _ASSIGNOP expression { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  variable error expression { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  variable _ASSIGNOP error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| procedure_call {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	newNode->insertChild($1);

	cout<<"statement -> procedure_call [OK]"<<endl;
	$$ = newNode;
}
	| compound_statement {
	BitNode *newNode;
        newNode = getBitNode(yylineno,yycolumn,"", "statement");
        newNode->insertChild($1);

        cout<<"statement -> compound_statement [OK]"<<endl;
        $$ = newNode;
}   | error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| _IF expression _THEN statement else_part {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "IF");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "THEN");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);
	newNode->insertChild($4);
	newNode->insertChild($5);

	cout<<"statement -> if expression then statement else_part [OK]"<<endl;
	$$ = newNode;
}|  error expression _THEN statement else_part { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing if");
	$$ = newNode; 
} 


 |  _IF error _THEN statement else_part { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _IF expression error statement else_part { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing then");
	$$ = newNode; 
} 


 |  _IF expression _THEN error else_part { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 	|  _IF expression _THEN statement error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| _FOR _ID _ASSIGNOP expression _TO expression _DO statement {
	BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node7;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "FOR");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "ID");
	Node3 = getBitNode(yylineno,yycolumn,$3->token, "ASSIGNOP");
	Node5 = getBitNode(yylineno,yycolumn,$5->token, "TO");
	Node7 = getBitNode(yylineno,yycolumn,$7->token, "DO");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild($4);
	newNode->insertChild(Node5);
	newNode->insertChild($6);
	newNode->insertChild(Node7);
	newNode->insertChild($8);

	cout<<"statement -> for id assignop expression to expression do statement [OK]"<<endl;
	$$ = newNode;
} |  error _ID _ASSIGNOP expression _TO expression _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing for");
	$$ = newNode; 
} 


 |  _FOR error _ASSIGNOP expression _TO expression _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _FOR _ID error expression _TO expression _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _FOR _ID _ASSIGNOP error _TO expression _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _FOR _ID _ASSIGNOP expression error expression _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing to");
	$$ = newNode; 
} 


 |  _FOR _ID _ASSIGNOP expression _TO error _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _FOR _ID _ASSIGNOP expression _TO expression error statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing do");
	$$ = newNode; 
} 


 |  _FOR _ID _ASSIGNOP expression _TO expression _DO error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| _READ '(' variable_list ')' {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "READ");
	Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);

	cout<<"statement -> read ( variable_list ) [OK]"<<endl;
	$$ = newNode;
}
 |  error '(' variable_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _READ error variable_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 |  _READ '(' error ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _READ '(' variable_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode; 
} 

 |  error '(' expression_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing write");
	$$ = newNode; 
} 


 |  _WRITE error expression_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 |  _WRITE '(' error ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _WRITE '(' expression_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode;
}
	| _WRITE '(' expression_list ')' {
        BitNode *newNode, *Node1, *Node2, *Node4;
        newNode = getBitNode(yylineno,yycolumn,"", "statement");
        Node1 = getBitNode(yylineno,yycolumn,$1->token, "WRITE");
        Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
        Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

        newNode->insertChild(Node1);
        newNode->insertChild(Node2);
        newNode->insertChild($3);
        newNode->insertChild(Node4);

        cout<<"statement -> write ( variable_list ) [OK]"<<endl;
        $$ = newNode;
}
	| {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "statement");

	cout<<"statement -> empty [OK]"<<endl;
	$$ = newNode;
}
 | _WHILE expression _DO statement{ // 增加while循环
	BitNode *newNode, *Node1, *Node3;
        newNode = getBitNode(yylineno,yycolumn,"", "statement");
        Node1 = getBitNode(yylineno,yycolumn,$1->token, "WHILE");
        Node3 = getBitNode(yylineno,yycolumn,$3->token, "DO");

        newNode->insertChild(Node1);
        newNode->insertChild($2);
        newNode->insertChild(Node3);
        newNode->insertChild($4);

        cout<<"statement -> _WHILE expression _DO statement [OK]"<<endl;
        $$ = newNode;
} |  error expression _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing while");
	$$ = newNode; 
} 


 |  _WHILE error _DO statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 |  _WHILE expression error statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing do");
	$$ = newNode; 
} 


 |  _WHILE expression _DO error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

variable_list: variable_list ',' variable{
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "variable_list");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"variable_list -> variable_list _SEPARATOR variable [OK]"<<endl;
	$$ = newNode;
}
| error ',' variable { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | variable_list error variable { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	$$ = newNode; 
} 


 | variable_list ',' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 	| variable {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "variable_list");

	newNode->insertChild($1);

	cout<<"statement -> variable [OK]"<<endl;
	$$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

variable: _ID id_varpart {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "variable");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"variable -> id id_varpart [OK]"<<endl;
	$$ = newNode;
}

 | error id_varpart { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ID error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

id_varpart: '[' expression_list ']' {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "id_varpart");
	Node1 = getBitNode(yylineno,yycolumn,"[", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,"]", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"id_varpart -> [ expression_list ] [OK]"<<endl;
	$$ = newNode;
}
| error expression_list ']' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '['");
	$$ = newNode; 
} 


 | '[' error ']' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | '[' expression_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ']'");
	$$ = newNode; 
} 
	| {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "id_varpart");

	cout<<"id_varpart -> empty [OK]"<<endl;
	$$ = newNode;
};

procedure_call: _ID {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "procedure_call");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ID");

	newNode->insertChild(Node1);

	cout<<"procedure_call -> id [OK]"<<endl;
	$$ = newNode;
}

 | error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | error '(' expression_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ID error expression_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 | _ID '(' error ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ID '(' expression_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode; 
} 
	| _ID '(' expression_list ')' {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "procedure_call");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ID");
	Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);

	cout<<"procedure_call -> id ( expression_list ) [OK]"<<endl;
	$$ = newNode;
};

else_part: _ELSE statement {
	BitNode *newNode, *Node1;
	newNode=getBitNode(yylineno,yycolumn,"", "else_part");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ELSE");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"else_part -> else statement [OK]"<<endl;
	$$ = newNode;
}


 | error statement { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing else");
	$$ = newNode; 
} 


 | _ELSE error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "else_part");

	cout<<"else_part -> empty [OK]"<<endl;
	$$ = newNode;
};

expression_list: expression_list ',' expression {

	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "expression_list");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"expression_list -> expression_list , expression [OK]"<<endl;
	$$ = newNode;
}

 | error ',' expression { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | expression_list error expression { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	$$ = newNode; 
} 


 | expression_list ',' error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| expression {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "expression_list");

	newNode->insertChild($1);

	cout<<"expression_list -> expression [OK]"<<endl;
	$$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

expression: simple_expression _RELOP simple_expression {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "expression");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "RELOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"expression -> simple_expression relop simple_expression [OK]"<<endl;
	$$ = newNode;
}
 	| simple_expression {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "expression");

	newNode->insertChild($1);

	cout<<"expression -> simple_expression [OK]"<<endl;
	$$ = newNode;
}

 | error _RELOP simple_expression { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | simple_expression error simple_expression { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | simple_expression _RELOP error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

simple_expression: simple_expression _ADDOP term {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "simple_expression");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "ADDOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"simple_expression -> simple_expression addop term [OK]"<<endl;
	$$ = newNode;
}| simple_expression _UMINUS term{ // 增加 uminus 关联生成式
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn, "", "simple_expression");
	Node2 = getBitNode(yylineno,yycolumn, $2->token, "UMINUS");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"simple_expression -> simple_expression uminus term [OK]"<<endl;
	$$ = newNode;
}
	| term {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "simple_expression");

	newNode->insertChild($1);

	cout<<"simple_expression -> term [OK]"<<endl;
	$$ = newNode;
}

 | error _ADDOP term { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | simple_expression error term { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | simple_expression _ADDOP error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} ;

term: term _MULOP factor {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "term");
	Node2 = getBitNode(yylineno,yycolumn,$2->token, "MULOP");

	newNode->insertChild($1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);

	cout<<"term -> term mulop factor [OK]"<<endl;
	$$ = newNode;
}
 | error _MULOP factor { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | term error factor { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | term _MULOP error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
	| factor {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "term");

	newNode->insertChild($1);

	cout<<"term -> factor [OK]"<<endl;
	$$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
;

factor: _NUM {
        BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");
        Node1 = getBitNode(yylineno,yycolumn,$1->token, "NUM");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        $$ = newNode;
}
| _DIGITS { // 增加整型
        BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn, "", "factor");
        Node1 = getBitNode(yylineno,yycolumn, $1->token, "DIGITS");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        $$ = newNode;
}| _BOOLEAN { // 增加布尔型
 	BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn, "", "factor");
        Node1 = getBitNode(yylineno,yycolumn, $1->token, "BOOLEAN");

        newNode->insertChild(Node1);

        cout<<" factor -> boolean [OK]"<<endl;
        $$ = newNode;
}
        | variable {
        BitNode *newNode;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");

        newNode->insertChild($1);

        cout<<" factor -> variable [OK]"<<endl;
        $$ = newNode;
}
| error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 | error '(' expression_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 | _ID error expression_list ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 | _ID '(' error ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _ID '(' expression_list error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode; 
} 
	| _ID '(' expression_list ')' {

	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode =  getBitNode(yylineno,yycolumn,"", "factor");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "ID");
	Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild($3);
	newNode->insertChild(Node4);

	cout<<"factor -> id ( expression_list ) [OK]"<<endl;
	$$ = newNode;
}

 	| '(' expression ')' {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "factor");
	Node1 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild($2);
	newNode->insertChild(Node3);

	cout<<"factor -> ( expression ) [OK]"<<endl;
	$$ = newNode;
}
 	| _NOT factor {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "factor");
	Node1 = getBitNode(yylineno,yycolumn,$1->token, "NOT");

	newNode->insertChild(Node1);
	newNode->insertChild($2);

	cout<<"factor -> not factor [OK]"<<endl;
	$$ = newNode;
}

  | error expression ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	$$ = newNode; 
} 


 | '(' error ')' { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | '(' expression error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	$$ = newNode; 
} 


 | error factor { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 


 | _NOT error { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	$$ = newNode; 
} 
 	| _ADDOP factor {
	BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");
        Node1 = getBitNode(yylineno,yycolumn,$1->token, "ADDOP");

        newNode->insertChild(Node1);
        newNode->insertChild($2);

        cout<<"factor -> add factor [OK]"<<endl;
        $$ = newNode;
} | _UMINUS factor {
	BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");
        Node1 = getBitNode(yylineno,yycolumn,$1->token, "UMINUS");

        newNode->insertChild(Node1);
        newNode->insertChild($2);

        cout<<"factor -> uminus factor [OK]"<<endl;
        $$ = newNode;
};

%%

void yyerror(const char *s)
{
	extern char *yytext;
	extern YYSTYPE yylval;
	string error_type(s);
	Error* cur=new Error(error_type,yylineno,yycolumn);
	errorInfo.push_back(cur);
    	if_error=1;
	cout<<error_type<<"\tat line: "<<yylineno<<"\tcol: "<<yycolumn<<endl;
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
    printf("%d \n",if_error);
    return 0;
}