
#include<iostream>
#include "semantic_analysis.hpp"


using namespace std;

//全局变量
SymbolTable symbol_table;
SematicAnalysis analysis;

CodeGenContext context;

extern BitNode* root;
extern int if_error;

extern void printErrorList();

BitNode* test_case01()
{
	BitNode* programstruct_node = new BitNode;
	programstruct_node->type = "programstruct";
	
	BitNode* program_head_node = new BitNode;
	BitNode* program_body_node = new BitNode;

	program_head_node->father = programstruct_node;
	program_head_node->type = "program_head";
	programstruct_node->children.push_back(program_head_node);

	program_body_node->father = programstruct_node;
	program_body_node->type = "program_body";
	programstruct_node->children.push_back(program_body_node);

	BitNode* PROGRAM_node = new BitNode;
	BitNode* ID_node1 = new BitNode;
	BitNode* SEPARATOR1 = new BitNode;

	PROGRAM_node->father = program_head_node;
	PROGRAM_node->data = "program";
	PROGRAM_node->type = "PROGRAM";
	program_head_node->children.push_back(PROGRAM_node);
	
	ID_node1->father = program_head_node;
	ID_node1->data = "aaa";
	ID_node1->type = "ID";
	program_head_node->children.push_back(ID_node1);

	SEPARATOR1->father = program_head_node;
	SEPARATOR1->data = ";";
	SEPARATOR1->type = "SEPARATOR";
	program_head_node->children.push_back(SEPARATOR1);

	return programstruct_node;
}

BitNode* test_case02()
{
	BitNode* programstruct_node = new BitNode;
	programstruct_node->type = "programstruct";

	BitNode* program_head_node = new BitNode;
	BitNode* program_body_node = new BitNode;

	program_head_node->father = programstruct_node;
	program_head_node->type = "program_head";
	programstruct_node->children.push_back(program_head_node);

	program_body_node->father = programstruct_node;
	program_body_node->type = "program_body";
	programstruct_node->children.push_back(program_body_node);

	BitNode* PROGRAM_node = new BitNode;
	BitNode* ID_node1 = new BitNode;
	BitNode* SEPARATOR1 = new BitNode;
	BitNode* idlist1 = new BitNode;
	BitNode* SEPARATOR2 = new BitNode;
	BitNode* SEPARATOR3 = new BitNode;

	PROGRAM_node->father = program_head_node;
	PROGRAM_node->data = "program";
	PROGRAM_node->type = "PROGRAM";
	program_head_node->children.push_back(PROGRAM_node);

	ID_node1->father = program_head_node;
	ID_node1->data = "program_aaa";
	ID_node1->type = "ID";
	program_head_node->children.push_back(ID_node1);

	SEPARATOR1->father = program_head_node;
	SEPARATOR1->data = "(";
	SEPARATOR1->type = "SEPARATOR";
	program_head_node->children.push_back(SEPARATOR1);

	idlist1->father = program_head_node;
	idlist1->type = "idlist";
	program_head_node->children.push_back(idlist1);

	SEPARATOR2->father = program_head_node;
	SEPARATOR2->data = ")";
	SEPARATOR2->type = "SEPARATOR";
	program_head_node->children.push_back(SEPARATOR2);

	SEPARATOR3->father = program_head_node;
	SEPARATOR3->data = ";";
	SEPARATOR3->type = "SEPARATOR";
	program_head_node->children.push_back(SEPARATOR3);

	BitNode* idlist2 = new BitNode;
	BitNode* SEPARATOR4 = new BitNode;
	BitNode* ID_node2 = new BitNode;

	idlist2->father = idlist1;
	idlist2->type = "idlist";
	idlist1->children.push_back(idlist2);

	SEPARATOR4->father = idlist1;
	SEPARATOR4->data = ",";
	SEPARATOR4->type = "SEPARATOR";
	idlist1->children.push_back(SEPARATOR4);

	ID_node2->father = idlist1;
	ID_node2->data = "bbb";
	ID_node2->type = "ID";
	idlist1->children.push_back(ID_node2);

	BitNode* ID_node3 = new BitNode;

	ID_node3->father = idlist2;
	ID_node3->data = "aaa";
	ID_node3->type = "ID";
	idlist2->children.push_back(ID_node3);

	return programstruct_node;
}

void test01()
{
	BitNode* root = test_case01();
	ASTNode* pgstruct = analysis.ADT2AST(root);
	cout << "finish" << endl;
}



void test02()
{
	BitNode* root = test_case02();
	ASTNode* pgstruct = analysis.ADT2AST(root);
    pgstruct->semantic_action();
	cout << symbol_table.get(0)->identifier << endl;
}


void test03()
{
    ASTNode* pgstruct;
    pgstruct = analysis.ADT2AST(root);
    pgstruct->semantic_action();
    cout<< "finish" <<endl;
}

//只涉及主表时对符号表进行测试
void test04()
{
    symbol_table.main_function = "main";
    symbol_table.cur_function = "main";

    symbol_table.insert("onlyname");

//    symbol_value int_value;
//    int_value.int_val = 100;
//    SymbolTableItem* item1 = new SymbolTableItem("basicname",var_int,int_value);
//    symbol_table.insert(item1);

    //array[1..10,11..20]
    vector<int> begin = {1,11};
    vector<int> end = {10,20};

    symbol_value arr_value;
    basic_type_type val;
    val.int_val = 999;
    arr_value.array_val = new MyArrayType(begin, end, var_int);
    arr_value.array_val->set({3,15},val);

    SymbolTableItem* item2 = new SymbolTableItem("arrayname",array_type,arr_value);
    symbol_table.insert(item2);



    //get test
    SymbolTableItem* item1_result = symbol_table.get("onlyname");
    SymbolTableItem* item2_result = symbol_table.get("basicname");
    SymbolTableItem* item3_result = symbol_table.get("arrayname");
    basic_type_type arr_res;
    item3_result->value.array_val->get({3,15},arr_res);
}

void test05()
{
    ASTNode* pgstruct;
    pgstruct = analysis.ADT2AST(root);
    pgstruct->semantic_action();
    printErrorList();
    cout<< "finish" <<endl;
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

    //语义分析部分
    if(if_error!=0)
    {
        cout << "grammatical error" << endl;
        return -1;
    }
    test05();
    //test04();

    return 0;
}