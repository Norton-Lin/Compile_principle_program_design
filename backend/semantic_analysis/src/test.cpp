
#include<iostream>
#include "semantic_analysis.hpp"


using namespace std;

//全局符号表
SymbolTable symbol_table;
SematicAnalysis analysis;

CodeGenContext context;

extern BitNode* root;
extern int if_error;

extern void printErrorList();

extern vector<string> lexErrorInfo;

void test05()
{
    ASTNode* pgstruct;
    pgstruct = analysis.ADT2AST(root);
	cout<<"programstruct_AST"<<endl;
    pgstruct->semantic_action();
    printErrorList();
    cout<< "finish" <<endl;
    //free(pgstruct);
}



int main(int argc,char *argv[])
{
    extern FILE* yyin;
    
    Pre pre(argv[1]);
    while (!pre.Read_Line()) {
        cout << "File path error.\n";
        cin >> argv[1];
    }
    pre.Dispose();
    
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
    
        //词法错误输出
    if(lexErrorInfo.size()!=0)
    {
        for (int i = 0; i < lexErrorInfo.size(); ++i) {
            cout << lexErrorInfo[i];
        }
    }

    //错误处理
    if(if_error!=0)
    {
        cout << "grammatical error" << endl;
        return -1;
    }
	string output_filename = "output.s";     //默认目标代码生成文件
    string compilerName = "gcc";             //默认C编译器
	string exeName = (string)argv[1]+".exe";         //默认的编译C程序后获得的可执行文件名
	string global = "global.c";
	context.init_funcStack();
    test05();
    if(!has_semantic_error)
    {
    	objectGenerate(output_filename);
	string cmd= compilerName + " " + output_filename + " global.c IO.c -o " +exeName;
	system(cmd.c_str());
	cout << "finish" << endl;
	cout << " "<<endl;
	//llvm::outs() << "Object code wrote to " << output_filename.c_str() << "\n";
    }
	return 0;
}
