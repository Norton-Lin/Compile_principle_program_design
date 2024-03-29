#include "interface.h"
#include "symbol_table.hpp"
#include "CodeGenerate.h"
#include <vector>
#include <iostream>
#include <fstream>

class SematicAnalysis;
class const_declaration_AST;
class expression_AST;
class expression_list_AST;
class variable_AST;

extern SymbolTable symbol_table;
extern SematicAnalysis analysis;
extern CodeGenContext context;
using namespace std;

class SemanticError
{
public:
    SemanticError(){};

    SemanticError(int line, int col, string error_type = "", string info = "")
    {
        this->line = line;
        this->col = col;
        this->error_type = error_type;
        this->error_info = info;
    }

public:
    int line;
    int col;
    string error_type;
    string error_info;
};

vector<SemanticError *> semantic_error_list;
bool has_semantic_error = false; // 5.2
void printErrorList()
{
    // todo:sort
    for (int i = 0; i < semantic_error_list.size(); ++i)
    {
        int line = semantic_error_list[i]->line;
        int col = semantic_error_list[i]->col;
        string error_type = semantic_error_list[i]->error_type;
        string error_info = semantic_error_list[i]->error_info;
        cout << "Semantic Error! line:" << line << " "
             << "col:" << col << " " << error_type << ":" << error_info << ";" << endl;
    }
}

class SematicAnalysis
{
public:
    SematicAnalysis(){};
    static ASTNode *create_ASTNode(BitNode *bn);
    static ASTNode *ADT2AST(BitNode *bn);

private:
};

enum ast_type
{
    // 终结符
    PROGRAM,
    CONST,
    VAR,
    PROCEDURE,
    FUNCTION,
    BEGIN,
    END,
    ARRAY,
    OF,
    IF,
    THEN,
    FOR,
    TO,
    DO,
    READ,
    WRITE,
    NOT,
    ELSE,
    RANGE,
    UMINUS,
    ID,
    RELOP,
    DIGITS,
    NUM,
    VARTYPE,
    ADDOP,
    MULOP,
    ASSIGNOP,
    SEPARATOR,
    CHAR,
    BOOLEAN,
    WHILE,

    // 非终结符
    programstruct = 100,
    program_head,
    program_body,
    idlist,
    const_declarations,
    const_declaration,
    const_value,
    var_declarations,
    var_declaration,
    basic_type,
    type,
    period,
    subprogram_declarations,
    subprogram,
    subprogram_head,
    formal_parameter,
    parameter_list,
    parameter,
    var_parameter,
    value_parameter,
    subprogram_body,
    compound_statement,
    statement_list,
    statement,
    variable_list,
    variable,
    id_varpart,
    procedure_call,
    else_part,
    term,
    factor,
    simple_expression,
    expression_list,
    expression
};

class const_value_AST;

void sematic_error()
{
    ;
}

class ASTNode
{
public:
    ast_type type;
    ASTNode *father;
    vector<ASTNode *> children;
    int line;
    int col;

    // 调试用信息
    string pascal_info;
    void pascal_info_cat()
    {
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->pascal_info += this->children[i]->pascal_info + " ";
        }
    }

public:
    ASTNode(){};

    void get_line_col(BitNode *bn)
    {
        this->line = bn->line;
        this->col = bn->col;
    }
    void get_line_col(ASTNode *ch)
    {
        this->line = ch->line;
        this->col = ch->col;
    }
    virtual void semantic_action(){};
    virtual void semantic_checking(){};
    virtual llvm::Value *code_generation() { return NULL; };
};

// 终结符
class WHILE_AST : public ASTNode
{
public:
    WHILE_AST(BitNode *bn)
    {
        type = WHILE;
        pascal_info = bn->data;
        get_line_col(bn);
    }
};

class PROGRAM_AST : public ASTNode
{
public:
    PROGRAM_AST(BitNode *bn)
    {
        type = PROGRAM;
        pascal_info = bn->data;
        get_line_col(bn);
    }
};

class CONST_AST : public ASTNode
{
public:
    string s_value;
    CONST_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        this->s_value = bn->data;
        type = CONST;
        get_line_col(bn);
    }
};

class VAR_AST : public ASTNode
{
public:
    string s_value;
    VAR_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = VAR;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class PROCEDURE_AST : public ASTNode
{
public:
    string s_value;
    PROCEDURE_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = PROCEDURE;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class FUNCTION_AST : public ASTNode
{
public:
    string s_value;
    FUNCTION_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = FUNCTION;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class BEGIN_AST : public ASTNode
{
public:
    string value;
    BEGIN_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = BEGIN;
        this->value = bn->data;
        get_line_col(bn);
    }
};

class END_AST : public ASTNode
{
public:
    string value;
    END_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = END;
        this->value = bn->data;
        get_line_col(bn);
    }
};

class ARRAY_AST : public ASTNode
{
public:
    string s_value;
    ARRAY_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = ARRAY;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class OF_AST : public ASTNode
{
public:
    string s_value;
    OF_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = OF;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class IF_AST : public ASTNode
{
public:
    IF_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        get_line_col(bn);
        type = IF;
    }
};

class THEN_AST : public ASTNode
{
public:
    THEN_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = THEN;
        get_line_col(bn);
    }
};

class FOR_AST : public ASTNode
{
public:
    FOR_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = FOR;
        get_line_col(bn);
    }
};

class TO_AST : public ASTNode
{
public:
    TO_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = TO;
        get_line_col(bn);
    }
};

class DO_AST : public ASTNode
{
public:
    DO_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = DO;
        get_line_col(bn);
    }
};

class READ_AST : public ASTNode
{
public:
    READ_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = READ;
        get_line_col(bn);
    }
};

class WRITE_AST : public ASTNode
{
public:
    WRITE_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = WRITE;
        get_line_col(bn);
    }
};

class NOT_AST : public ASTNode
{
public:
    NOT_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = NOT;
        get_line_col(bn);
    }
};

class ELSE_AST : public ASTNode
{
public:
    ELSE_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = ELSE;
        get_line_col(bn);
    }
};

class RANGE_AST : public ASTNode
{
public:
    string s_value;
    RANGE_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = RANGE; //..
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class UMINUS_AST : public ASTNode
{
public:
    string s_value;
    UMINUS_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = UMINUS;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class RELOP_AST : public ASTNode
{
public:
    string s_value;
    RELOP_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = RELOP;             // 关系运算符
        this->s_value = bn->data; // todo:检查是否相符s
        get_line_col(bn);
    }
};

class DIGITS_AST : public ASTNode
{
public:
    string s_type;
    int s_int;
    DIGITS_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = DIGITS;
        this->s_type = "integer";
        this->s_int = stoi(bn->data);
        get_line_col(bn);
    }
};

// s_type 只有real，PPT上的定义有歧义
class NUM_AST : public ASTNode
{
public:
    string s_type;
    double s_real;
    NUM_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = NUM;
        this->s_type = "real";
        this->s_real = stod(bn->data);
        get_line_col(bn);
    }
};

class VARTYPE_AST : public ASTNode
{
public:
    string s_value;
    VARTYPE_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = VARTYPE; // todo:integer real boolean char
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class ADDOP_AST : public ASTNode
{
public:
    string s_value;
    ADDOP_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = ADDOP;
        this->s_value = bn->data; // todo:检查类型是否一致(OK)
        get_line_col(bn);
    }
};

class MULOP_AST : public ASTNode
{
public:
    string s_value;
    MULOP_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = MULOP;
        this->s_value = bn->data; // todo：检查语法分析给出的字符串是否与语义分析定义相同，不相同则在此修改
        get_line_col(bn);
    }
};

class ASSIGNOP_AST : public ASTNode
{
public:
    string s_value;
    ASSIGNOP_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = ASSIGNOP;
        this->s_value = bn->data;
        get_line_col(bn);
    }
};

class SEPARATOR_AST : public ASTNode
{
public:
    string value;
    SEPARATOR_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = SEPARATOR;
        this->value = bn->data;
        get_line_col(bn);
    }
};

class CHAR_AST : public ASTNode
{
public:
    string s_type; // 只能是value
    char s_char;
    CHAR_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = CHAR;
        s_type = "char";
        this->s_char = bn->data[0];
        get_line_col(bn);
    }
};

class BOOLEAN_AST : public ASTNode
{
public:
    bool s_bool;
    string s_type;
    BOOLEAN_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = BOOLEAN;
        this->s_type = "boolean";
        if (bn->data == "true")
            this->s_bool = true;
        else
            this->s_bool = false;
        get_line_col(bn);
    }
};

class ID_AST : public ASTNode
{
public:
    string identifier;

    ID_AST(BitNode *bn)
    {
        pascal_info = bn->data;
        type = ID;
        this->identifier = bn->data;
        get_line_col(bn);
    }
};

// 非终结符

class idlist_AST : public ASTNode
{
public:
    vector<string> list;
    vector<ID_AST *> s_id_ast_list;
    idlist_AST(BitNode *bn)
    {
        type = idlist;
    }

    void semantic_action()
    {
        if (this->children.size() == 3)
        {
            idlist_AST *child1 = (idlist_AST *)this->children[0];
            ID_AST *child3 = (ID_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->list = child1->list;
            this->s_id_ast_list = child1->s_id_ast_list;
            this->list.push_back(child3->identifier);
            this->s_id_ast_list.push_back(child3);
        }
        else if (this->children.size() == 1)
        {
            ID_AST *child1 = (ID_AST *)this->children[0];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->list.push_back(child1->identifier);
            this->s_id_ast_list.push_back(child1);
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class program_head_AST : public ASTNode
{
public:
    string program_name;
    vector<string> parameters;

    program_head_AST(BitNode *bn)
    {
        type = program_head;
    }

    void semantic_action()
    {
        if (this->children.size() == 6)
        {
            // 有综合属性的节点
            ID_AST *ch1 = (ID_AST *)this->children[1];
            idlist_AST *ch3 = (idlist_AST *)this->children[3];

            // 父节点继承属性准备

            // 获得子节点综合属性
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            // 设置父节点综合属性
            this->program_name = ch1->identifier;
            this->parameters = ch3->list;
        }
        else if (this->children.size() == 3)
        {
            ID_AST *ch1 = (ID_AST *)this->children[1];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->program_name = ch1->identifier;
        }
        else
        {
            sematic_error();
        }

        // 设置符号表父表名称
        symbol_table.main_function = this->program_name;
        symbol_table.cur_function = this->program_name;
        // 语义检查和符号表插入操作
        // 插入参数
        for (int i = 0; i < parameters.size(); ++i)
        {
            // 检查参数是否重名
            if (false == symbol_table.insert(parameters[i]))
            {
                // 进入循环即不为空
                ID_AST *id = ((idlist_AST *)this->children[3])->s_id_ast_list[i];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "Duplicate definition",
                                                       "identifier '" + id->identifier + "' redefined");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                // return;允许继续插入
            }
        }
        // 插入函数名
        symbol_value value;
        value.function_val = new MyFunctionType();
        value.function_val->arg_name_list = parameters;
        SymbolTableItem *item = new SymbolTableItem(this->program_name, procedure, value);
        // 检查主函数是否重名
        if (false == symbol_table.insert(item))
        {
            // 进入循环即不为空
            ID_AST *id = (ID_AST *)this->children[1];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "Duplicate definition",
                                                   "identifier '" + id->identifier + "' redefined");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            // return;
        }

        pascal_info_cat();
        if (!has_semantic_error)
            this->code_generation();
    }
};

/// <summary>
/// 这个最大的节点可能什么都不做
/// </summary>

class const_declaration_AST : public ASTNode
{
public:
    vector<pair<string, const_value_AST *>> s_pair_list;
    vector<ID_AST *> s_id_AST_list;
    const_declaration_AST(BitNode *bn)
    {
        type = const_declaration;
    }

    void semantic_action() override
    {
        if (this->children.size() == 5)
        {
            const_declaration_AST *ch0 = (const_declaration_AST *)this->children[0];
            ID_AST *ch2 = (ID_AST *)this->children[2];
            const_value_AST *ch4 = (const_value_AST *)this->children[4];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_pair_list = ch0->s_pair_list;
            this->s_id_AST_list = ch0->s_id_AST_list;
            this->s_pair_list.push_back(pair<string, const_value_AST *>(ch2->identifier, ch4));
            this->s_id_AST_list.push_back(ch2);
        }
        else if (this->children.size() == 3)
        {
            ID_AST *ch0 = (ID_AST *)this->children[0];
            const_value_AST *ch2 = (const_value_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_pair_list.push_back(pair<string, const_value_AST *>(ch0->identifier, ch2));
            this->s_id_AST_list.push_back(ch0);
        }
        else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class const_value_AST : public ASTNode
{
public:
    string s_type;
    bool l_isglobal;
    int s_int;
    char s_char;
    double s_real;
    bool s_bool;
    llvm::Value *s_value = nullptr;
    llvm::Value *code_generation() override;
    const_value_AST(BitNode *bn)
    {
        type = const_value;
    }

    void semantic_action() override
    {
        if (this->children[0]->type == ADDOP) // 生成式1
        {

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            if (this->children[1]->type == NUM)
            {
                NUM_AST *ch1 = (NUM_AST *)this->children[1];
                this->s_type = ch1->s_type;
                this->s_real = ch1->s_real;
            }
            else if (this->children[1]->type == DIGITS)
            {
                DIGITS_AST *ch1 = (DIGITS_AST *)this->children[1];
                this->s_type = ch1->s_type;
                this->s_int = ch1->s_int;
            }
            else
                sematic_error();
        }
        else if (this->children[0]->type == UMINUS) // 生成式2
        {
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            if (this->children[1]->type == NUM)
            {
                NUM_AST *ch1 = (NUM_AST *)this->children[1];
                this->s_type = ch1->s_type;
                this->s_real = -(ch1->s_real);
            }
            else if (this->children[1]->type == DIGITS)
            {
                DIGITS_AST *ch1 = (DIGITS_AST *)this->children[1];
                this->s_type = ch1->s_type;
                this->s_int = -(ch1->s_int);
            }
            else
                sematic_error();
        }
        else if (this->children[0]->type == NUM)
        {
            NUM_AST *ch0 = (NUM_AST *)this->children[0];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_type = ch0->s_type;
            this->s_real = ch0->s_real;
        }
        else if (this->children[0]->type == CHAR) // 生成式4
        {
            CHAR_AST *ch0 = (CHAR_AST *)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_char = ch0->s_char;
        }
        else if (this->children[0]->type == DIGITS)
        {
            DIGITS_AST *ch0 = (DIGITS_AST *)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_int = ch0->s_int;
        }
        else if (this->children[0]->type == BOOLEAN)
        {
            BOOLEAN_AST *ch0 = (BOOLEAN_AST *)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_bool = ch0->s_bool;
        }
        sematic_error();
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            s_value = code_generation();
    }

    void semantic_checking() override
    {
        // 检查常量定义是否使用错误的符号标识正负
        if (this->children[0]->type == ADDOP)
        {
            ADDOP_AST *ch0 = (ADDOP_AST *)this->children[0];
            if (ch0->s_value != "+")
            {
                semantic_error_list.push_back(new SemanticError(ch0->line, ch0->col,
                                                                "operator type error",
                                                                "only '+' or '-' can be used in const declaration"));
                has_semantic_error = true;
                return;
            }
        }
    }
};

class const_declarations_AST : public ASTNode
{
public:
    bool l_isglobal;
    vector<pair<string, const_value_AST *>> s_pair_list;
    vector<ID_AST *> s_id_AST_list;
    llvm::Value *code_generation() override;
    const_declarations_AST(BitNode *bn)
    {
        type = const_declarations;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            const_declaration_AST *ch1 = (const_declaration_AST *)this->children[1];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_pair_list = ch1->s_pair_list;
            this->s_id_AST_list = ch1->s_id_AST_list;

            // 语义检查和符号表插入操作
            // 插入参数
            for (int i = 0; i < s_pair_list.size(); ++i)
            {
                SymbolTableItem *item = new SymbolTableItem(s_pair_list[i].first);
                MyBasicType *value = new MyBasicType();
                item->value.basic_val = value;
                item->value.basic_val->llvmvalue = s_pair_list[i].second->s_value;

                if (s_pair_list[i].second->s_type == "integer")
                {
                    item->type = const_int;
                    value->value.int_val = s_pair_list[i].second->s_int;
                }
                else if (s_pair_list[i].second->s_type == "real")
                {
                    item->type = const_real;
                    value->value.real_val = s_pair_list[i].second->s_real;
                }
                else if (s_pair_list[i].second->s_type == "boolean")
                {
                    item->type = const_bool;
                    value->value.bool_val = s_pair_list[i].second->s_bool;
                }
                else // char
                {
                    item->type = const_char;
                    value->value.char_val = s_pair_list[i].second->s_char;
                }

                // 检查常量名是否重名
                if (false == symbol_table.insert(item))
                {
                    // 进入循环即不为空
                    ID_AST *id = s_id_AST_list[i];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "Duplicate definition",
                                                           "identifier '" + id->identifier + "' redefined");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    // return;允许继续定义
                }
            }
        }
        else if (this->children.size() == 0)
            ; // do nothing
        else
            sematic_error();

        pascal_info_cat();
        // semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class basic_type_AST : public ASTNode
{
public:
    string s_type;
    basic_type_AST(BitNode *bn)
    {
        type = basic_type;
    }

    void semantic_action() override
    {
        VARTYPE_AST *ch0 = (VARTYPE_AST *)this->children[0];

        // 无论使用哪一个归约式，操作都一样
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }

        this->s_type = ch0->s_value;
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class period_AST : public ASTNode
{
public:
    vector<pair<int, int>> s_index_list;
    period_AST(BitNode *bn)
    {
        type = period;
    }

    void semantic_action() override
    {
        if (this->children.size() == 5)
        {
            period_AST *ch0 = (period_AST *)this->children[0];
            DIGITS_AST *ch2 = (DIGITS_AST *)this->children[2];
            DIGITS_AST *ch4 = (DIGITS_AST *)this->children[4];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_index_list = ch0->s_index_list;
            this->s_index_list.push_back(pair<int, int>(ch2->s_int, ch4->s_int));
        }
        else if (this->children.size() == 3)
        {
            DIGITS_AST *ch0 = (DIGITS_AST *)this->children[0];
            DIGITS_AST *ch2 = (DIGITS_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_index_list.push_back(pair<int, int>(ch0->s_int, ch2->s_int));
        }
        else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class type_AST : public ASTNode
{
public:
    string s_type; // 基本类型
    bool l_isarray;
    vector<pair<int, int>> s_index_list;
    llvm::Value *code_generation() override;
    type_AST(BitNode *bn)
    {
        type = type;
    }

    void semantic_action() override
    {
        if (this->children.size() == 1)
        {
            basic_type_AST *ch0 = (basic_type_AST *)this->children[0];

            this->l_isarray = false;

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_type = ch0->s_type;
        }
        else if (this->children.size() == 6)
        {
            period_AST *ch2 = (period_AST *)this->children[2];
            basic_type_AST *ch5 = (basic_type_AST *)this->children[5];

            this->l_isarray = true;

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_index_list = ch2->s_index_list;
            this->s_type = ch5->s_type;
        }
        else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class var_declaration_AST : public ASTNode
{
public:
    vector<pair<idlist_AST *, type_AST *>> s_id_type_list;
    var_declaration_AST(BitNode *bn)
    {
        type = var_declaration;
    }

    void semantic_action() override
    {
        if (this->children.size() == 5)
        {
            var_declaration_AST *ch0 = (var_declaration_AST *)this->children[0];
            idlist_AST *ch2 = (idlist_AST *)this->children[2];
            type_AST *ch4 = (type_AST *)this->children[4];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_id_type_list = ch0->s_id_type_list;
            this->s_id_type_list.push_back(pair<idlist_AST *, type_AST *>(ch2, ch4));
        }
        else if (this->children.size() == 3)
        {
            idlist_AST *ch0 = (idlist_AST *)this->children[0];
            type_AST *ch2 = (type_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_id_type_list.push_back(pair<idlist_AST *, type_AST *>(ch0, ch2));
        }
        else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class var_declarations_AST : public ASTNode
{
public:
    bool l_isglobal; // 表示是主函数定义的全局变量还是子函数定义的局部变量
    vector<pair<idlist_AST *, type_AST *>> s_id_type_list;
    llvm::Value *code_generation() override;
    var_declarations_AST(BitNode *bn)
    {
        type = var_declarations;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            var_declaration_AST *ch1 = (var_declaration_AST *)this->children[1];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_id_type_list = ch1->s_id_type_list;

            // 语义检查和符号表插入操作
            // 插入参数
            for (int i = 0; i < s_id_type_list.size(); ++i)
            {
                for (int j = 0; j < s_id_type_list[i].first->s_id_ast_list.size(); ++j)
                {
                    ID_AST *idAst = s_id_type_list[i].first->s_id_ast_list[j];
                    SymbolTableItem *item = new SymbolTableItem(idAst->identifier);
                    symbol_type idtype;

                    if (s_id_type_list[i].second->s_type == "integer")
                        idtype = var_int;
                    else if (s_id_type_list[i].second->s_type == "real")
                        idtype = var_real;
                    else if (s_id_type_list[i].second->s_type == "boolean")
                        idtype = var_bool;
                    else // char
                        idtype = var_char;
                    if (s_id_type_list[i].second->l_isarray)
                    {
                        int dimension = s_id_type_list[i].second->s_index_list.size();
                        vector<int> begin;
                        vector<int> end;
                        for (int k = 0; k < dimension; ++k)
                        {
                            int a = s_id_type_list[i].second->s_index_list[k].first;
                            int b = s_id_type_list[i].second->s_index_list[k].second;
                            begin.push_back(a);
                            end.push_back(b);
                            // 检查变量数组定义下标是否合法
                            if (a > b)
                            {
                                begin[k] = 0;
                                end[k] = 0;
                                ID_AST *id = s_id_type_list[i].first->s_id_ast_list[j];
                                SemanticError *err = new SemanticError(id->line, id->col,
                                                                       "Array range error",
                                                                       "identifier '" + id->identifier + "' array[a..b],a>b");
                                semantic_error_list.push_back(err);
                                has_semantic_error = true;
                                // return;
                            }
                        }
                        MyArrayType *value = new MyArrayType(begin, end, idtype);
                        item->value.array_val = value;
                        item->type = array_type;
                    }
                    else
                    {
                        MyBasicType *value = new MyBasicType();
                        item->value.basic_val = value;
                        item->type = idtype;
                    }

                    // 检查变量名是否重复
                    if (false == symbol_table.insert(item))
                    {
                        // 进入循环即不为空
                        ID_AST *id = s_id_type_list[i].first->s_id_ast_list[j];
                        SemanticError *err = new SemanticError(id->line, id->col,
                                                               "Duplicate definition",
                                                               "identifier '" + id->identifier + "' redefined");
                        semantic_error_list.push_back(err);
                        has_semantic_error = true;
                        // return;
                    }
                }
            }
            if (!has_semantic_error)
                this->code_generation();
        }
        else if (this->children.size() == 0)
            ; // do nothing
        else
            sematic_error();
        pascal_info_cat();
        // semantic_checking();
    }
};

class program_body_AST : public ASTNode
{
public:
    const_declarations_AST *s_const_declarations;
    var_declarations_AST *s_var_declarations;
    llvm::Value *code_generation() override;
    llvm::IRBuilderBase::InsertPoint IP;
    program_body_AST(BitNode *bn)
    {
        type = program_body;
    }

    void semantic_action() override
    {
        if (this->children.size() == 4)
        {
            const_declarations_AST *ch0 = (const_declarations_AST *)this->children[0];
            var_declarations_AST *ch1 = (var_declarations_AST *)this->children[1];
            this->s_const_declarations = ch0;
            this->s_var_declarations = ch1;

            ch1->l_isglobal = true;

            this->children[0]->semantic_action();
            this->children[1]->semantic_action();
            if (!has_semantic_error)
            {
                this->global_declaration(); // 声明全局变量
            }
            this->children[2]->semantic_action();
            context.builder->restoreIP(IP);
            this->children[3]->semantic_action();
        }
        else
            sematic_error();

        get_line_col(this->children[3]);
        pascal_info_cat();
        semantic_checking();
        // code_generation();
    }

    void global_declaration()
    {
        ofstream file;
        file.open("global.c");
        if (!file.is_open())
        {
            cout << "Unable to open file global.c" << endl;
            return;
        }

        // const
        file << "#include <stdio.h>" << endl
             << "#include <stdbool.h>" << endl;
        for (int i = 0; i < s_const_declarations->s_pair_list.size(); ++i)
        {
            string sentence = "";
            string identifier = s_const_declarations->s_pair_list[i].first;
            const_value_AST *const_value = s_const_declarations->s_pair_list[i].second;
            if (const_value->s_type == "integer")
            {
                sentence = "const int " + identifier + "=" + std::to_string(const_value->s_int) + ";";
            }
            else if (const_value->s_type == "real")
            {
                sentence += "const double " + identifier + "=" + std::to_string(const_value->s_real) + ";";
            }
            else if (const_value->s_type == "char")
            {
                sentence += "const char " + identifier + "=" + std::to_string(const_value->s_char) + ";";
            }
            else
            {
                sentence += "const bool " + identifier + "=" + std::to_string(const_value->s_bool) + ";";
            }
            file << sentence << endl;
        }
        // var
        for (int i = 0; i < s_var_declarations->s_id_type_list.size(); ++i)
        {
            vector<string> id_list = s_var_declarations->s_id_type_list[i].first->list;
            string type = s_var_declarations->s_id_type_list[i].second->s_type;
            bool isarray = s_var_declarations->s_id_type_list[i].second->l_isarray;

            for (int j = 0; j < id_list.size(); ++j)
            {
                SymbolTableItem *array_item;
                string sentence = "";
                string index = "";

                if (isarray)
                {
                    array_item = symbol_table.get(id_list[j]);
                    // 检查符号表是否存在元素
                    if (array_item == NULL)
                    {
                        ID_AST *id = (ID_AST *)s_var_declarations->s_id_type_list[i].first->s_id_ast_list[j];
                        SemanticError *err = new SemanticError(id->line, id->col,
                                                               "unknown identifier",
                                                               "identifier '" + id->identifier + "' identifier is not declared or there is an error near its declarations declaration");
                        semantic_error_list.push_back(err);
                        has_semantic_error = true;
                        return;
                    }

                    for (int k = 0; k < array_item->value.array_val->size.size(); ++k)
                    {
                        index += "[" + std::to_string(array_item->value.array_val->size[k] + 1) + "]";
                    }
                }
                if (type == "integer")
                {
                    sentence += "int " + id_list[j] + index + ";";
                }
                else if (type == "real")
                {
                    sentence += "double " + id_list[j] + index + ";";
                }
                else if (type == "char")
                {
                    sentence += "char " + id_list[j] + index + ";";
                }
                else if (type == "boolean")
                {
                    sentence += "bool " + id_list[j] + index + ";";
                }
                file << sentence << endl;
            }
        }
    }
};

class programstruct_AST : public ASTNode
{
public:
    llvm::IRBuilderBase::InsertPoint IP;
    programstruct_AST(BitNode *bn)
    {
        type = programstruct;
    }
    // virtual llvm::Value *code_generation() override;

    void semantic_action()
    {
        if (this->children.size() == 3)
        {
            program_head_AST *ch0 = (program_head_AST *)this->children[0];
            program_body_AST *ch1 = (program_body_AST *)this->children[1];
            SEPARATOR_AST *ch2 = (SEPARATOR_AST *)this->children[2];
            if (!has_semantic_error)
                code_generation();
            for (int i = 0; i < this->children.size(); ++i)
            {
                if (i == 1)
                    ch1->IP = IP;
                this->children[i]->semantic_action();
            }
            pascal_info_cat();
            semantic_checking();
        }
        context.builder->CreateRetVoid();
    }
    llvm::Value *code_generation() override;
};

class value_parameter_AST : public ASTNode
{
public:
    vector<string> s_id_list;
    vector<ID_AST *> s_id_ast_list;
    string s_type;
    value_parameter_AST(BitNode *bn)
    {
        type = value_parameter;
    }

    void semantic_action() override
    {
        // 只有一个归约方法
        idlist_AST *ch0 = (idlist_AST *)this->children[0];
        basic_type_AST *ch2 = (basic_type_AST *)this->children[2];

        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }

        this->s_id_list = ch0->list;
        this->s_type = ch2->s_type;
        this->s_id_ast_list = ch0->s_id_ast_list;
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class var_parameter_AST : public ASTNode
{
public:
    vector<string> s_id_list;
    vector<ID_AST *> s_id_ast_list;
    string s_type;
    var_parameter_AST(BitNode *bn)
    {
        type = var_parameter;
    }

    void semantic_action() override
    {
        // 只有一种归约
        value_parameter_AST *ch1 = (value_parameter_AST *)this->children[1];

        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }

        this->s_id_list = ch1->s_id_list;
        this->s_id_ast_list = ch1->s_id_ast_list;
        this->s_type = ch1->s_type;

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class parameter_AST : public ASTNode
{
public:
    bool s_isvar;
    string s_type;
    vector<string> s_id_list;
    vector<ID_AST *> s_id_ast_list;
    parameter_AST(BitNode *bn)
    {
        type = parameter;
    }

    void semantic_action() override
    {
        if (this->children[0]->type == var_parameter)
        {
            var_parameter_AST *ch0 = (var_parameter_AST *)this->children[0];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_isvar = true;
            this->s_id_list = ch0->s_id_list;
            this->s_id_ast_list = ch0->s_id_ast_list;
            this->s_type = ch0->s_type;
        }
        else if (this->children[0]->type == value_parameter)
        {
            value_parameter_AST *ch0 = (value_parameter_AST *)this->children[0];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_isvar = false;
            this->s_id_list = ch0->s_id_list;
            this->s_id_ast_list = ch0->s_id_ast_list;
            this->s_type = ch0->s_type;
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class parameter_list_AST : public ASTNode
{

public:
    vector<parameter_AST *> s_list;
    parameter_list_AST(BitNode *bn)
    {
        type = parameter_list;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            parameter_list_AST *ch0 = (parameter_list_AST *)this->children[0];
            parameter_AST *ch2 = (parameter_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_list = ch0->s_list;
            this->s_list.push_back(ch2);
        }
        else if (this->children.size() == 1)
        {
            parameter_AST *ch0 = (parameter_AST *)this->children[0];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_list.push_back(ch0);
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class formal_parameter_AST : public ASTNode
{
public:
    vector<parameter_AST *> s_list;
    // llvm::Value *code_generation() override;
    formal_parameter_AST(BitNode *bn)
    {
        type = formal_parameter;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            parameter_list_AST *ch1 = (parameter_list_AST *)this->children[1];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_list = ch1->s_list;
        }
        else if (this->children.size() == 0)
        {
            ; // do nothing
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class subprogram_head_AST : public ASTNode
{
public:
    bool s_isfunction;
    string s_ret_type; // 仅在是函数时有返回值类型
    string program_name;
    vector<parameter_AST *> s_list;
    llvm::Function *s_llvmfunction; // 5.1
    SymbolTableItem *s_item;        // 5.1

    llvm::Function *function_generation();

    subprogram_head_AST(BitNode *bn)
    {
        type = subprogram_head;
    }

    void semantic_action() override
    {
        if (this->children.size() == 5)
        {
            ID_AST *ch1 = (ID_AST *)this->children[1];
            formal_parameter_AST *ch2 = (formal_parameter_AST *)this->children[2];
            basic_type_AST *ch4 = (basic_type_AST *)this->children[4];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->program_name = ch1->identifier;
            this->s_isfunction = true;
            this->s_ret_type = ch4->s_type;
            this->s_list = ch2->s_list;
        }
        else if (this->children.size() == 3)
        {
            ID_AST *ch1 = (ID_AST *)this->children[1];
            formal_parameter_AST *ch2 = (formal_parameter_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->program_name = ch1->identifier;
            this->s_isfunction = false;
            this->s_list = ch2->s_list;
        }
        else
            sematic_error();

        // 插入函数名
        symbol_value value;
        MyFunctionType *functionType = new MyFunctionType(&symbol_table);
        value.function_val = functionType;
        SymbolTableItem *item = new SymbolTableItem(this->program_name, s_isfunction ? symbol_type::function : procedure, value);
        this->s_item = item;
        functionType->isfunction = this->s_isfunction;
        if (s_isfunction)
        {
            functionType->ret_type = this->s_ret_type;
        }
        // 检查函数、过程名是否重复
        if (false == symbol_table.insert(item))
        {
            // 进入循环即不为空
            ID_AST *id = (ID_AST *)this->children[1];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "Duplicate definition",
                                                   "identifier '" + id->identifier + "' redefined");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        // 符号表重定向
        // 设置符号表子表名称
        symbol_table.cur_function = this->program_name;
        // 语义检查和符号表插入操作
        // 插入参数
        int count = 0;
        for (int i = 0; i < this->s_list.size(); ++i)
        {
            for (int j = 0; j < s_list[i]->s_id_list.size(); ++j)
            {
                ID_AST *idAst = s_list[i]->s_id_ast_list[j];
                SymbolTableItem *item = new SymbolTableItem(idAst->identifier);
                symbol_type idtype;

                if (s_list[i]->s_type == "integer")
                    idtype = var_int;
                else if (s_list[i]->s_type == "real")
                    idtype = var_real;
                else if (s_list[i]->s_type == "boolean")
                    idtype = var_bool;
                else // char
                    idtype = var_char;

                // 参数类型不能是array
                MyBasicType *value = new MyBasicType();
                item->value.basic_val = value;
                item->type = idtype;

                // 记录函数定义信息
                functionType->arg_name_list.push_back(idAst->identifier);
                functionType->arg_type_list.push_back(this->s_list[i]->s_type);
                functionType->arg_isvar_list.push_back(this->s_list[i]->s_isvar);

                // 检查函数、过程参数名是否重复
                if (false == symbol_table.insert(item))
                {
                    ID_AST *id = idAst;
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "Duplicate definition",
                                                           "identifier '" + id->identifier + "' redefined");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    // return;
                }
            }
        }

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            functionType->llvmfunction = function_generation();
    }
};

class subprogram_body_AST : public ASTNode
{
public:
    bool isfunction;         // 标记todo
    SymbolTableItem *l_item; // 5.1

    llvm::Value *code_generation() override;
    llvm::Value *ret_generation(llvm::Value *ret);
    subprogram_body_AST(BitNode *bn)
    {
        type = subprogram_body;
    }

    void semantic_action() override
    {
        var_declarations_AST *ch1 = (var_declarations_AST *)this->children[1];
        ch1->l_isglobal = false;
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        get_line_col(this->children[2]);
        pascal_info_cat();
        semantic_checking();
        // l_item空指针时
        isfunction = l_item->type == symbol_type::function;
        if (!has_semantic_error)
            ret_generation(this->l_item->value.function_val->ret_llvmval); // 5.1
        // code_generation();//todo 改成ret_generation(Value* ret)插入符号表
    }
};

class subprogram_AST : public ASTNode
{
    subprogram_head_AST *s_sub_head;
    subprogram_body_AST *s_sub_body;

public:
    subprogram_AST(BitNode *bn)
    {
        type = subprogram;
    }

    void semantic_action() override
    {
        // 仅一种生成式
        subprogram_head_AST *ch0 = (subprogram_head_AST *)this->children[0];
        subprogram_body_AST *ch2 = (subprogram_body_AST *)this->children[2];

        for (int i = 0; i < this->children.size(); ++i)
        {
            if (i == 2)
                ch2->l_item = ch0->s_item;
            this->children[i]->semantic_action();
        }

        // 子函数退出，符号表重定位到主符号表
        symbol_table.cur_function = symbol_table.main_function;

        this->s_sub_head = ch0;
        this->s_sub_body = ch2;
        this->s_sub_body->l_item = this->s_sub_head->s_item;

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class subprogram_declarations_AST : public ASTNode
{

public:
    vector<subprogram_AST *> s_subprogram_list;
    subprogram_declarations_AST(BitNode *bn)
    {
        type = subprogram_declarations;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            subprogram_declarations_AST *ch0 = (subprogram_declarations_AST *)this->children[0];
            subprogram_AST *ch1 = (subprogram_AST *)this->children[1];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_subprogram_list = ch0->s_subprogram_list;
            this->s_subprogram_list.push_back(ch1);
        }
        else if (this->children.size() == 0)
            ; // do nothing
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

// 这个类较为复杂，共有可能有4种情况
// 无论哪种情况，代码生成应该返回一个llvm::Value*,因为此后这个类会被作为表达式使用
class factor_AST : public ASTNode
{
public:
    // 在任意情况下有意义的值
    int s_state;                    // 1-4表示某一种情况
    string s_type;                  // 表示4种基本类型，integer real boolean char
    llvm::Value *s_value = nullptr; // 右值，在表达式运算中使用
    bool isleftvalue = false;       // 是左值则赋值为true,由语义分析赋值

    // 1.是一个字面值常量，根据s_type区别类型
    double s_real; // 仅在字面量时有意义
    int s_int;     // 仅在字面量时有意义
    char s_char;   // 仅在字面量时有意义
    bool s_bool;   // 仅在字面量时有意义

    // 2.是一个变量或常量变量
    bool s_isconst = false;              // 是否是const变量
    string s_identifier;         // 变量或数组的符号表标识符
    SymbolTableItem *s_var_item; // 符号表表项
    bool s_isarray;              // 是否是数组
    vector<string> s_index_type_list;
    vector<llvm::Value *> s_index_list; // 是数组时才有意义，数组index列表
    llvm::Value *llvmleftValue = NULL;  // 在是变量或数组时保存左值指针，在传引用时使用
    // 标识符类型或数组元素类型是s_type

    // 3.函数调用语句
    string s_func_identifier;     // 函数名标识符
    SymbolTableItem *s_func_item; // 符号表表项
    vector<string> s_parameter_type_list;
    vector<llvm::Value *> s_parameter_list; // 是函数调用时才有意义，函数参数列表
    // 返回值类型是s_type

    // 4.单目运算
    string s_op; // 单目运算符类型，共三种分别是非，取反，加括号 !,-,()//实际上可能加括号与你没什么关系，我这边会处理优先级但还是记上
    string s_operand0_type;
    llvm::Value *s_operand0;
    llvm::Value *function_call_generation();
    llvm::Value *code_generation() override;
    factor_AST(BitNode *bn)
    {
        type = factor;
    }

    void semantic_action() override;
};

class term_AST : public ASTNode
{
public:
    int s_state; // 共有两种状态，状态1是属性的传递，不做运算，状态2做运算
    string s_type;
    llvm::Value *s_value;
    bool isleftvalue = false;   // 是左值则赋值为true
    llvm::Value *llvmleftValue; // 左值指针，在传引用时使用

    // 1.二元运算
    string s_op; // 乘，除，整除，取模，与操作（如果s_type是boolean做逻辑与，如果是integer做按位与）*,/,div,mod,and
    llvm::Value *operand0;
    string operand0_type;
    llvm::Value *operand1;
    string operand1_type;

    // 2.属性传递
    llvm::Value *code_generation() override;
    term_AST(BitNode *bn)
    {
        type = term;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            term_AST *ch0 = (term_AST *)this->children[0];
            MULOP_AST *ch1 = (MULOP_AST *)this->children[1];
            factor_AST *ch2 = (factor_AST *)this->children[2];
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->operand0 = ch0->s_value;
            this->operand0_type = ch0->s_type;
            this->operand1 = ch2->s_value;
            this->operand1_type = ch2->s_type;
            this->s_op = ch1->s_value;
            this->isleftvalue = false;
            this->llvmleftValue = NULL;
            this->s_type = ch0->s_type;

            // 语义检查
            // 操作数类型是否相同
            if (operand1_type != operand0_type)
            {
                MULOP_AST *id = (MULOP_AST *)this->children[1];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "operand type Error",
                                                       "The two operands of '" + id->s_value + "' must be of the same type");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // 乘除必须是整数和浮点
            if ((ch1->s_value == "*" || ch1->s_value == "/") && (this->s_type != "integer" && this->s_type != "real"))
            {
                MULOP_AST *id = (MULOP_AST *)this->children[1];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "operand type Error",
                                                       "The two operands of '" + id->s_value + "' must be integer or real type");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // 整除和模必须是整数
            if ((ch1->s_value == "div" || ch1->s_value == "mod") && (this->s_type != "integer"))
            {
                MULOP_AST *id = (MULOP_AST *)this->children[1];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "operand type Error",
                                                       "The two operands of '" + id->s_value + "' must be integer type");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // and必须是Boolean或整数
            if (ch1->s_value == "and" && this->s_type != "boolean" && this->s_type != "integer")
            {
                MULOP_AST *id = (MULOP_AST *)this->children[1];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "operand type Error",
                                                       "The two operands of '" + id->s_value + "'must be boolean or integer type");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }

            if (!has_semantic_error)
                this->s_value = code_generation();
        }
        else if (this->children.size() == 1)
        {
            factor_AST *ch0 = (factor_AST *)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_value = ch0->s_value;
            this->isleftvalue = ch0->isleftvalue;
            this->llvmleftValue = ch0->llvmleftValue;
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking(); // todo:设置s_type
    }
};

class simple_expression_AST : public ASTNode
{
public:
    int s_state; // 共有两种状态，状态1是属性的传递，不做运算，状态2做运算
    string s_type;
    llvm::Value *s_value;
    bool isleftvalue = false;   // 是左值则赋值为true
    llvm::Value *llvmleftValue; // 左值指针，在传引用时使用

    // 1.二元运算
    string s_op; // 加，减，或操作（如果s_type是boolean做逻辑或，如果是integer做按位或）+,-,or
    llvm::Value *operand0;
    string operand0_type;
    llvm::Value *operand1;
    string operand1_type;

    // 2.属性传递
    llvm::Value *code_generation() override;
    simple_expression_AST(BitNode *bn)
    {
        type = simple_expression;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            simple_expression_AST *ch0 = (simple_expression_AST *)this->children[0];
            term_AST *ch2 = (term_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            if (this->children[1]->type == ADDOP)
            {
                ADDOP_AST *ch1 = (ADDOP_AST *)this->children[1];
                this->s_op = ch1->s_value;
            }
            else // if(this->children[1]->type==UMINUS)
            {
                UMINUS_AST *ch1 = (UMINUS_AST *)this->children[1];
                this->s_op = ch1->s_value;
            }
            this->operand0 = ch0->s_value;
            this->operand0_type = ch0->s_type;
            this->operand1 = ch2->s_value;
            this->operand1_type = ch2->s_type;
            this->isleftvalue = false;
            this->llvmleftValue = NULL;
            this->s_type = ch0->s_type;

            // 语义检查
            // 操作数类型是否相同
            if (operand1_type != operand0_type)
            {
                if (this->children[1]->type == ADDOP)
                {
                    ADDOP_AST *id = (ADDOP_AST *)this->children[1];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "operand type Error",
                                                           "The two operands of '" + id->s_value + "' must be of the same type");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
                else
                {
                    UMINUS_AST *id = (UMINUS_AST *)this->children[1];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "operand type Error",
                                                           "The two operands of '" + id->s_value + "' must be of the same type");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
            }
            // 加必须是整数和浮点
            if (this->children[1]->type == ADDOP)
            {
                ADDOP_AST *ch1 = (ADDOP_AST *)this->children[1];
                if ((ch1->s_value == "+") && (this->s_type != "integer" && this->s_type != "real"))
                {
                    ADDOP_AST *id = (ADDOP_AST *)this->children[1];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "operand type Error",
                                                           "The two operands of '" + id->s_value + "' must be integer or real type");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
            }
            // 减必须是整数和浮点
            if (this->children[1]->type == UMINUS)
            {
                UMINUS_AST *ch1 = (UMINUS_AST *)this->children[1];
                if ((ch1->s_value == "-") && (this->s_type != "integer" && this->s_type != "real"))
                {
                    UMINUS_AST *id = (UMINUS_AST *)this->children[1];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "operand type Error",
                                                           "The two operands of '" + id->s_value + "' must be integer or real type");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
            }
            // or必须是bool或integer
            if (this->children[1]->type == ADDOP)
            {
                ADDOP_AST *ch1 = (ADDOP_AST *)this->children[1];
                if ((ch1->s_value == "or") && (this->s_type != "boolean") && (this->s_type != "integer"))
                {
                    ADDOP_AST *id = (ADDOP_AST *)this->children[1];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "operand type Error",
                                                           "The two operands of '" + id->s_value + "'must be boolean or integer type");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
            }

            if (!has_semantic_error)
                this->s_value = code_generation();
        }
        else if (this->children.size() == 1)
        {
            this->s_state = 2;
            term_AST *ch0 = (term_AST *)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_value = ch0->s_value;
            this->isleftvalue = ch0->isleftvalue;
            this->llvmleftValue = ch0->llvmleftValue;
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking(); // todo:设置s_type
    }
};

class expression_AST : public ASTNode
{
public:
    int s_state; // 共有两种状态，状态1是属性的传递，不做运算，状态2做运算
    string s_type;
    llvm::Value *s_value;
    bool isleftvalue = false;   // 是左值则赋值为true
    llvm::Value *llvmleftValue; // 左值指针，在传引用时使用
    BitNode *bn;

    // 1.二元运算
    string s_op; // 等于，不等于，小于，小于等于，大于，大于等于 =,<>,<,<=,>,>=
    llvm::Value *operand0;
    string operand0_type;
    llvm::Value *operand1;
    string operand1_type;
    llvm::Value *code_generation() override;
    // 2.属性传递
    expression_AST(BitNode *bn)
    {
        type = expression;
        this->bn = bn;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            simple_expression_AST *ch0 = (simple_expression_AST *)this->children[0];
            RELOP_AST *ch1 = (RELOP_AST *)this->children[1];
            simple_expression_AST *ch2 = (simple_expression_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->operand0 = ch0->s_value;
            this->operand0_type = ch0->s_type;
            this->operand1 = ch2->s_value;
            this->operand1_type = ch2->s_type;
            this->s_op = ch1->s_value;
            this->isleftvalue = false;
            this->llvmleftValue = NULL;
            this->s_type = "boolean";

            // 两个操作数类型是否相同
            if (operand1_type != operand0_type)
            {
                RELOP_AST *id = (RELOP_AST *)this->children[1];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "operand type Error",
                                                       "The two operands of '" + id->s_value + "' must be of the same type");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }

            if (!has_semantic_error)
                this->s_value = code_generation();
        }
        else if (this->children.size() == 1)
        {
            this->s_state = 2;
            simple_expression_AST *ch0 = (simple_expression_AST *)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_value = ch0->s_value;
            this->isleftvalue = ch0->isleftvalue;
            this->llvmleftValue = ch0->llvmleftValue;
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking(); // todo:设置s_type
    }
};

class expression_list_AST : public ASTNode
{
public:
    vector<string> s_type_list;
    vector<llvm::Value *> s_value_list;
    vector<expression_AST *> s_expression_list;
    expression_list_AST(BitNode *bn)
    {
        type = expression_list;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            expression_list_AST *ch0 = (expression_list_AST *)this->children[0];
            expression_AST *ch2 = (expression_AST *)this->children[2];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_type_list = ch0->s_type_list;
            this->s_type_list.push_back(ch2->s_type);
            this->s_value_list = ch0->s_value_list;
            this->s_value_list.push_back(ch2->s_value);
            this->s_expression_list = ch0->s_expression_list;
            this->s_expression_list.push_back(ch2);
        }
        else if (this->children.size() == 1)
        {
            expression_AST *ch0 = (expression_AST *)this->children[0];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_type_list.push_back(ch0->s_type);
            this->s_value_list.push_back(ch0->s_value);
            this->s_expression_list.push_back(ch0);
        }
        else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class id_varpart_AST : public ASTNode
{
public:
    bool s_isarray;
    vector<string> s_type_list;         // 数组index列表参数类型，只可能是int，语义对其类型检查
    vector<llvm::Value *> s_value_list; // 数组index列表参数的值
    id_varpart_AST(BitNode *bn)
    {
        type = id_varpart;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            expression_list_AST *ch1 = (expression_list_AST *)this->children[1];

            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }

            this->s_isarray = true;
            this->s_type_list = ch1->s_type_list;
            this->s_value_list = ch1->s_value_list;
        }
        else if (this->children.size() == 0)
        {
            this->s_isarray = false;
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class variable_AST : public ASTNode
{
public:
    string s_identifier;
    string s_type;  // 表示4种基本类型，integer real boolean char
    bool s_isconst; // 是否常量
    SymbolTableItem *item;
    bool s_isarray;                       // 是否是数组
    vector<string> s_type_list;           // 数组index列表参数类型，只可能是int，语义对其类型检查
    vector<llvm::Value *> s_value_list;   // 数组index列表参数的值
    llvm::Value *llvmleftValue = nullptr; // 在是变量或数组时保存左值指针，在传引用时使用
    llvm::Value *code_generation() override;
    llvm::Value *s_value = nullptr;
    variable_AST(BitNode *bn)
    {
        type = variable;
    }

    void semantic_action() override
    {
        // 只有一种生成式
        ID_AST *ch0 = (ID_AST *)this->children[0];
        id_varpart_AST *ch1 = (id_varpart_AST *)this->children[1];

        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_identifier = ch0->identifier;
        this->s_isarray = ch1->s_isarray;
        this->s_type_list = ch1->s_type_list;
        this->s_value_list = ch1->s_value_list;
        // 从符号表获得类型
        this->item = symbol_table.get(this->s_identifier);
        // 检查符号表是否存在元素
        if (this->item == NULL)
        {
            ID_AST *id = (ID_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "unknown identifier",
                                                   "identifier '" + id->identifier + "' identifier is not declared or there is an error near its declaration");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        symbol_type t = symbol_type::unknown;
        if (this->s_isarray == true)
        {
            // 检查标识符是否是array类型
            if (this->item->type != array_type)
            {
                ID_AST *id = (ID_AST *)this->children[0];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "type error",
                                                       "identifier '" + id->identifier + "' identifier is not array type");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // 检查index数量与数组维度是否匹配
            if (this->s_type_list.size() != item->value.array_val->size.size())
            {
                ID_AST *id = (ID_AST *)this->children[0];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "index error",
                                                       "identifier '" + id->identifier + "' the number of index mismatch");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // 检查index类型
            for (int i = 0; i < this->s_type_list.size(); ++i)
            {
                if (this->s_type_list[i] != "integer")
                {
                    ID_AST *id = (ID_AST *)this->children[0];
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "index type error",
                                                           "index " + std::to_string(i) + " is not integer type");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
            }

            t = item->value.array_val->type;
        }
        else
        {
            t = this->item->type;
        }
        switch (t)
        {
            case var_int:
                this->s_type = "integer";
                this->s_isconst = false;
                break;
            case var_bool:
                this->s_type = "boolean";
                this->s_isconst = false;
                break;
            case var_char:
                this->s_type = "char";
                this->s_isconst = false;
                break;
            case var_real:
                this->s_type = "real";
                this->s_isconst = false;
                break;
            case const_int:
                this->s_type = "integer";
                this->s_isconst = true;
                break;
            case const_bool:
                this->s_type = "boolean";
                this->s_isconst = true;
                break;
            case const_char:
                this->s_type = "char";
                this->s_isconst = true;
                break;
            case const_real:
                this->s_type = "real";
                this->s_isconst = true;
            default:
                sematic_error();
        }

        pascal_info_cat();
        get_line_col(ch0);
        semantic_checking();
        if (!has_semantic_error)
        {
            s_value = code_generation();
        }
    }
};

class variable_list_AST : public ASTNode
{
public:
    vector<variable_AST *> s_variable_list;

    variable_list_AST(BitNode *bn)
    {
        type = variable_list;
    }

    void semantic_action() override
    {

        if (this->children.size() == 3)
        {
            variable_list_AST *ch0 = (variable_list_AST *)this->children[0];
            variable_AST *ch2 = (variable_AST *)this->children[2];
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_variable_list = ch0->s_variable_list;
            this->s_variable_list.push_back(ch2);
        }
        else if (this->children.size() == 1)
        {
            variable_AST *ch0 = (variable_AST *)this->children[0];
            ch0->semantic_action();
            this->s_variable_list.push_back(ch0);
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class procedure_call_AST : public ASTNode
{
public:
    string s_identifier;     // 过程名
    SymbolTableItem *s_item; // 过程的符号表表项
    vector<string> s_type_list;
    vector<llvm::Value *> s_value_list;
    llvm::Value *code_generation() override;
    procedure_call_AST(BitNode *bn)
    {
        type = procedure_call;
    }

    void semantic_action() override
    {
        if (this->children.size() == 1)
        {
            ID_AST *ch0 = (ID_AST *)this->children[0];
            ch0->semantic_action();
            this->s_identifier = ch0->identifier;
            this->s_item = symbol_table.get(this->s_identifier);

            if (this->s_item == NULL)
            {
                ID_AST *id = (ID_AST *)this->children[0]->children[0];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "id Error",
                                                       "The identifier '" + id->identifier + "' doesnt exist");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // 语义检查，id必须是过程
            if (this->s_item->type != symbol_type::procedure)
            {
                ID_AST *id = (ID_AST *)this->children[0]->children[0];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "id type Error",
                                                       "The identifier '" + id->identifier + "'must be procedure for proceduer call statement");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }

            get_line_col(ch0);
        }
        else if (this->children.size() == 4)
        {
            ID_AST *ch0 = (ID_AST *)this->children[0];
            expression_list_AST *ch2 = (expression_list_AST *)this->children[2];
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_identifier = ch0->identifier;
            this->s_item = symbol_table.get(this->s_identifier);
            this->s_type_list = ch2->s_type_list;

            // 语义检查，未定义的id
            if (s_item == NULL)
            {
                ID_AST *id = ch0;
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "undefined identifier",
                                                       "identifier '" + id->identifier + "' is undefined");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            // 标识符是否是过程
            if (s_item->type != procedure)
            {
                ID_AST *id = ch0;
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "identifier type Error",
                                                       "in function '" + id->identifier + "',identifier is not a function");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            if (s_item != NULL) // 存在函数名才进行函数调用的语义检查
            {
                MyFunctionType *functionType = s_item->value.function_val;
                // 检查参数数量是否匹配
                if (functionType->arg_name_list.size() != ch2->s_value_list.size())
                {
                    ID_AST *id = ch0;
                    SemanticError *err = new SemanticError(id->line, id->col,
                                                           "number of parameter Error",
                                                           "in procedure '" + id->identifier + "',The number of parameters does not match the definition");
                    semantic_error_list.push_back(err);
                    has_semantic_error = true;
                    return;
                }
                else
                {
                    for (int i = 0; i < functionType->arg_name_list.size(); ++i)
                    {
                        // 参数类型是否正确
                        if (functionType->arg_type_list[i] != s_type_list[i])
                        {
                            ID_AST *id = ch0;
                            SemanticError *err = new SemanticError(id->line, id->col,
                                                                   "parameter type Error",
                                                                   "in procedure '" + id->identifier + "',parameter " + functionType->arg_name_list[i] + "type must be" + functionType->arg_type_list[i]);
                            semantic_error_list.push_back(err);
                            has_semantic_error = true;
                            return;
                        }
                        if (functionType->arg_isvar_list[i]) // 检查引用参数位能否是引用
                        {

                            if (!ch2->s_expression_list[i]->isleftvalue) // 但不是可引用类型
                            {
                                ID_AST *id = ch0;
                                SemanticError *err = new SemanticError(id->line, id->col,
                                                                       "parameter type Error",
                                                                       "in procedure '" + id->identifier + "',parameter " + functionType->arg_name_list[i] + "type must be referencable");
                                semantic_error_list.push_back(err);
                                has_semantic_error = true;
                                return;
                            }
                            this->s_value_list.push_back(ch2->s_expression_list[i]->llvmleftValue);
                        }
                        else
                        {
                            this->s_value_list.push_back(ch2->s_value_list[i]);
                        }
                    }
                }
            }

            get_line_col(ch0);
        }
        else
            sematic_error();

        pascal_info_cat();
        // semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class statement_AST : public ASTNode
{
public:
    // 语句有多种类型
    llvm::Value *s_cur_llvmvalue;
    int s_state;
    llvm::Function *function;            // 当前所在的函数
    llvm::IRBuilderBase::InsertPoint IP; // 记录当前的插入点
    llvm::BasicBlock *block1 = nullptr;
    llvm::BasicBlock *block2 = nullptr;
    llvm::BasicBlock *block3 = nullptr;
    llvm::BasicBlock *block4 = nullptr;

    // 1.赋值语句
    variable_AST *s_variable;
    string s_expression_type;
    llvm::Value *s_expression_value;
    bool is_while_assign = false; // 判断是否是while循环中的赋值语句

    // 2.过程调用
    string s_identifier;     // 过程名
    SymbolTableItem *s_item; // 过程的符号表表项
    vector<string> s_type_list;
    vector<llvm::Value *> s_value_list;

    // 3.复合语句
    vector<statement_AST *> s_statement_list;

    // 4.if-else
    // expression共用赋值语句的
    statement_AST *s_if_statement;
    bool s_has_else; // 判断有无else部分
    statement_AST *s_else_statement;

    // 5.for
    statement_AST *s_for_statement;

    string s_for_identifier;
    string s_for_type; // 表示4种基本类型，integer real boolean char
    SymbolTableItem *s_for_item;

    string s_for_expression_type1;
    llvm::Value *s_for_expression_value1;
    string s_for_expression_type2;
    llvm::Value *s_for_expression_value2;

    // 6.read
    vector<variable_AST *> s_variable_list;

    // 7.write
    // expression_list共用procedure_call的

    // 8.空语句
    // 空语句时，行号和列号不确定

    // 9.while 生成式WHILE expression DO statement
    llvm::Value *while_temp_value;

    llvm::Value *code_generation() override;
    llvm::Value *if_code_generation_1();
    llvm::Value *if_code_generation_2();
    llvm::Value *if_code_generation_3();
    llvm::Value *for_code_generation_1();
    llvm::Value *for_code_generation_2();
    llvm::Value *while_code_generation_1();
    llvm::Value *while_code_generation_2();
    llvm::Value *assign_code_generation();
    llvm::Value *write();
    llvm::Value *read();
    statement_AST(BitNode *bn)
    {
        type = statement;
    }
    statement_AST(){}; // 空语句

    void semantic_action() override;
};

class statement_list_AST : public ASTNode
{
public:
    vector<statement_AST *> s_statement_list;
    vector<llvm::Value *> s_llvmvalue_list;
    statement_list_AST(BitNode *bn)
    {
        type = statement_list;
    }

    void code_init();

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            statement_list_AST *ch0 = (statement_list_AST *)this->children[0];
            statement_AST *ch2 = (statement_AST *)this->children[2];
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_statement_list = ch0->s_statement_list;
            this->s_statement_list.push_back(ch2);
            this->s_llvmvalue_list = ch0->s_llvmvalue_list;
            this->s_llvmvalue_list.push_back(ch2->s_cur_llvmvalue);
        }
        else if (this->children.size() == 1)
        {
            statement_AST *ch0 = (statement_AST *)this->children[0];
            ch0->semantic_action();
            this->s_statement_list.push_back(ch0);
            this->s_llvmvalue_list.push_back(ch0->s_cur_llvmvalue);
        }
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

class else_part_AST : public ASTNode
{
public:
    bool s_has_else;
    statement_AST *s_statement;
    llvm::Value *s_cur_llvmvalue;
    else_part_AST(BitNode *bn)
    {
        type = else_part;
    }

    void semantic_action() override
    {
        if (this->children.size() == 2)
        {
            statement_AST *ch1 = (statement_AST *)this->children[1];
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_has_else = true;
            this->s_statement = ch1;
            get_line_col(this->children[0]);
        }
        else if (this->children.size() == 0)
        {
            this->s_has_else = false;
        }

        pascal_info_cat();
        semantic_checking();
        // code_generation();
        // this->s_cur_llvmvalue = s_statement->s_cur_llvmvalue;
    }
};

class compound_statement_AST : public ASTNode
{
public:
    vector<statement_AST *> s_statement_list;
    vector<llvm::Value *> s_llvmvalue_list;
    compound_statement_AST(BitNode *bn)
    {
        type = compound_statement;
    }

    void semantic_action() override
    {
        if (this->children.size() == 3)
        {
            statement_list_AST *ch1 = (statement_list_AST *)this->children[1];
            for (int i = 0; i < this->children.size(); ++i)
            {
                this->children[i]->semantic_action();
            }
            this->s_statement_list = ch1->s_statement_list;
            this->s_llvmvalue_list = ch1->s_llvmvalue_list;
        }
        else
            sematic_error();
        pascal_info_cat();
        get_line_col(this->children[0]);
        semantic_checking();
        if (!has_semantic_error)
            code_generation();
    }
};

void statement_AST::semantic_action()
{
    if (this->children.size() == 0)
    {
        this->s_state = 8;
        return;
    }
    else if (this->children[0]->type == variable)
    {
        this->s_state = 1;
        variable_AST *ch0 = (variable_AST *)this->children[0];
        expression_AST *ch2 = (expression_AST *)this->children[2];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_variable = ch0;
        this->s_expression_type = ch2->s_type;
        this->s_expression_value = ch2->s_value;
        get_line_col(ch0);

        // 语义检查，id必须已经定义
        if (this->s_variable->item == NULL)
        {
            ID_AST *id = (ID_AST *)this->s_variable->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "id Error",
                                                   "The identifier '" + id->identifier + "' doesnt exist");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        // 语义检查，variable必须不是const
        if (this->s_variable->s_isconst == true)
        {
            ID_AST *id = (ID_AST *)this->s_variable->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "id type Error",
                                                   "The identifier '" + id->identifier + "' is const type");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        // 语义检查，variable的id不能是过程
        if (this->s_variable->item->type == symbol_type::procedure)
        {
            ID_AST *id = (ID_AST *)this->s_variable->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "id type Error",
                                                   "The identifier '" + id->identifier + "' cant be procedure type");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        // 对返回语句检查作用域
        if (this->s_variable->item->type == symbol_type::function && this->s_variable->s_identifier != symbol_table.cur_function)
        {
            ID_AST *id = (ID_AST *)this->s_variable->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "Scope error",
                                                   "Cannot assign values to the return values of other functions");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        // 检查左右类型是否相同
        if (this->s_variable->item->type == symbol_type::function)
        {
            if (this->s_variable->item->value.function_val->ret_type != this->s_expression_type)
            {
                ID_AST *id = (ID_AST *)this->s_variable->children[0];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "type Error",
                                                       "return type mismatch");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
        }
        else if (this->s_variable->s_type != this->s_expression_type)
        {
            ID_AST *id = (ID_AST *)this->s_variable->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "type Error",
                                                   "The types of variables and expressions do not match");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        if (!has_semantic_error)
            assign_code_generation();
    }
    else if (this->children[0]->type == procedure_call)
    {
        this->s_state = 2;
        procedure_call_AST *ch0 = (procedure_call_AST *)this->children[0];
        ch0->semantic_action();
        this->s_identifier = ch0->s_identifier;
        this->s_item = ch0->s_item;
        this->s_type_list = ch0->s_type_list;
        this->s_value_list = ch0->s_value_list;
        get_line_col(ch0);
    }
    else if (this->children[0]->type == compound_statement)
    {
        this->s_state = 3;
        compound_statement_AST *ch0 = (compound_statement_AST *)this->children[0];
        ch0->semantic_action();
        this->s_statement_list = ch0->s_statement_list;

        //
        for (int i = this->s_statement_list.size() - 1; i >= 0; i--)
        {
            if (this->s_statement_list[i]->children.size() == 0)
            {
                continue;
            }
            if (this->s_statement_list[i]->children[0]->type == IF ||
                this->s_statement_list[i]->children[0]->type == WHILE ||
                this->s_statement_list[i]->children[0]->type == FOR)
            {
                this->block4 = this->s_statement_list[i]->block3;
                break;
            }
        }

        get_line_col(ch0);
    }
    else if (this->children[0]->type == IF)
    {
        this->s_state = 4;
        expression_AST *ch1 = (expression_AST *)this->children[1];
        statement_AST *ch3 = (statement_AST *)this->children[3];
        else_part_AST *ch4 = (else_part_AST *)this->children[4];

        this->children[0]->semantic_action();
        this->children[1]->semantic_action();
        this->s_expression_type = ch1->s_type;
        this->s_expression_value = ch1->s_value;

        // 语义检查，expression type必须是boolean
        if (this->s_expression_type != "boolean")
        {
            IF_AST *id = (IF_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "expression type Error",
                                                   "The expression of IF statement must be boolean expression");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        this->children[2]->semantic_action();
        if (this->children[4]->children.size() == 0)
        {
            this->s_has_else = false;
        }
        else
        {
            this->s_has_else = true;
        }
        if (!has_semantic_error)
            this->if_code_generation_1();
        this->children[3]->semantic_action();
        this->s_if_statement = ch3;

        if (ch3->children.size() > 0 && ch3->children[0]->type == compound_statement)
        {
            this->block4 = ch3->block4;
        }
        else
        {
            this->block4 = ch3->block3;
        }
        if (!has_semantic_error)
            this->if_code_generation_2();
        this->children[4]->semantic_action();
        this->s_has_else = ch4->s_has_else;
        this->s_else_statement = ch4->s_statement;
        if (s_else_statement != nullptr)
        {
            if (s_else_statement->children[0]->type == compound_statement)
            {
                this->block4 = s_else_statement->block4;
            }
            else
            {
                this->block4 = s_else_statement->block3;
            }
        }
        if (!has_semantic_error)
            this->if_code_generation_3();
        get_line_col(this->children[0]);
    }
    else if (this->children[0]->type == FOR)
    {
        this->s_state = 5;
        ID_AST *ch1 = (ID_AST *)this->children[1];
        expression_AST *ch3 = (expression_AST *)this->children[3];
        expression_AST *ch5 = (expression_AST *)this->children[5];
        statement_AST *ch7 = (statement_AST *)this->children[7];

        this->children[0]->semantic_action();
        this->children[1]->semantic_action();

        this->s_for_identifier = ch1->identifier;
        this->s_for_item = symbol_table.get(s_for_identifier);
        // 语义检查，id必须已经定义
        if (this->s_for_item == NULL)
        {
            ID_AST *id = (ID_AST *)this->children[1];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "id Error",
                                                   "The identifier '" + id->identifier + "' doesnt exist");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        this->children[2]->semantic_action();
        this->children[3]->semantic_action();

        this->s_for_expression_type1 = ch3->s_type;
        this->s_for_expression_value1 = ch3->s_value;

        this->children[4]->semantic_action();
        this->children[5]->semantic_action();

        this->s_for_expression_type2 = ch5->s_type;
        this->s_for_expression_value2 = ch5->s_value;

        this->children[6]->semantic_action();

        if (this->s_for_item->type != symbol_type::var_int)
        {
            FOR_AST *id = (FOR_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "identifier type Error",
                                                   "The identifier must be integer type and can't be const");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        // 语义检查，expression type必须是integer
        if (this->s_for_expression_type1 != "integer" || this->s_for_expression_type2 != "integer")
        {
            FOR_AST *id = (FOR_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "expression type Error",
                                                   "The expression of For statement must be integer expression");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        if (!has_semantic_error)
            this->for_code_generation_1();
        this->children[7]->semantic_action();
        this->s_for_statement = ch7;

        if (ch7->children.size() > 0 && ch7->children[0]->type == compound_statement)
        {
            this->block4 = ch7->block4;
        }
        else
        {
            this->block4 = ch7->block3;
        }

        if (!has_semantic_error)
            this->for_code_generation_2();

        this->s_for_item = symbol_table.get(s_for_identifier);
        // 检查符号表是否存在元素
        if (s_for_item == NULL)
        {
            ID_AST *id = (ID_AST *)this->children[1];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "unknown identifier",
                                                   "identifier '" + id->identifier + "' identifier is not declared or there is an error near its declaration");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        this->s_for_type = "integer";

        get_line_col(this->children[0]);
    }
    else if (this->children[0]->type == READ)
    {
        this->s_state = 6;
        variable_list_AST *ch2 = (variable_list_AST *)this->children[2];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_variable_list = ch2->s_variable_list;
        for (int i = 0; i < s_variable_list.size(); ++i)
        {
            if (s_variable_list[i]->s_isconst)
            {
                ID_AST *id = (ID_AST *)s_variable_list[i]->children[0];
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "type error",
                                                       "identifier '" + id->identifier + "' identifier can't be const");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
        }
        get_line_col(this->children[0]);
        if (!has_semantic_error)
            read();
    }
    else if (this->children[0]->type == WRITE)
    {
        this->s_state = 7;
        expression_list_AST *ch2 = (expression_list_AST *)this->children[2];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_type_list = ch2->s_type_list;
        this->s_value_list = ch2->s_value_list;
        get_line_col(this->children[0]);
        if (!has_semantic_error)
            write();
    }
    else if (this->children.size() == 0)
    {
        this->s_state = 8;
    }
    else if (this->children[0]->type == WHILE)
    {
        this->s_state = 9;
        expression_AST *ch1 = (expression_AST *)this->children[1];
        statement_AST *ch3 = (statement_AST *)this->children[3];

        this->children[0]->semantic_action();
        this->children[1]->semantic_action();
        this->s_expression_type = ch1->s_type;
        this->s_expression_value = ch1->s_value;
        if (this->s_expression_type != "boolean")
        {
            WHILE_AST *id = (WHILE_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "expression type Error",
                                                   "The expression of WHILE statement must be boolean expression");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        this->children[2]->semantic_action();
        if (!has_semantic_error)
            this->while_code_generation_1();
        this->children[3]->semantic_action();
        // 创建隐式赋值语句
        ASTNode *node = SematicAnalysis::ADT2AST(ch1->bn);
        expression_AST *exp_ast = (expression_AST *)node;

        statement_AST *assign_statement = new statement_AST();
        assign_statement->children.push_back(new ASTNode()); // id
        assign_statement->children.push_back(new ASTNode()); //:=
        // assign_statement->children.push_back(ch1); // expression
        assign_statement->children.push_back(exp_ast); // expression

        assign_statement->children[2]->semantic_action();
        assign_statement->s_expression_value = exp_ast->s_value;
        assign_statement->is_while_assign = true;
        assign_statement->while_temp_value = this->while_temp_value;
        if (!has_semantic_error)
            assign_statement->assign_code_generation();

        if (ch3->children.size() > 0 && ch3->children[0]->type == compound_statement)
        {
            this->block4 = ch3->block4;
        }
        else
        {
            this->block4 = ch3->block3;
        }
        this->s_for_statement = ch3;
        if (!has_semantic_error)
            this->while_code_generation_2();

        get_line_col(this->children[0]);
    }
    else
        sematic_error();
    pascal_info_cat();
    semantic_checking();
    if (!has_semantic_error)
        code_generation();
}

void factor_AST::semantic_action()
{
    if (this->children[0]->type == NUM)
    {
        this->s_state = 1;
        NUM_AST *ch0 = (NUM_AST *)this->children[0];
        ch0->semantic_action();
        this->s_type = ch0->s_type;
        this->s_real = ch0->s_real;
    }
    else if (this->children[0]->type == DIGITS)
    {
        this->s_state = 1;
        DIGITS_AST *ch0 = (DIGITS_AST *)this->children[0];
        ch0->semantic_action();
        this->s_type = ch0->s_type;
        this->s_int = ch0->s_int;
    }
    else if (this->children[0]->type == BOOLEAN)
    {
        this->s_state = 1;
        BOOLEAN_AST *ch0 = (BOOLEAN_AST *)this->children[0];
        ch0->semantic_action();
        this->s_type = ch0->s_type;
        this->s_bool = ch0->s_bool;
    }
    else if (this->children[0]->type == variable)
    {
        this->s_state = 2;
        variable_AST *ch0 = (variable_AST *)this->children[0];
        ch0->semantic_action();
        this->s_type = ch0->s_type;
        this->s_isconst = ch0->s_isconst;
        this->s_isarray = ch0->s_isarray;
        this->s_identifier = ch0->s_identifier;
        this->s_var_item = ch0->item;
        this->s_index_type_list = ch0->s_type_list;
        this->s_index_list = ch0->s_value_list;
        this->s_value = ch0->s_value;
        this->isleftvalue = true;
        this->s_isconst = ch0->s_isconst;
        this->llvmleftValue = ch0->llvmleftValue;
        if (this->s_isconst == true)
            this->isleftvalue = false;
    }
    else if (this->children[0]->type == ID)
    {
        this->s_state = 3;
        ID_AST *ch0 = (ID_AST *)this->children[0];
        expression_list_AST *ch2 = (expression_list_AST *)this->children[2];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_func_identifier = ch0->identifier;
        // this->s_parameter_list = ch2->s_value_list;

        this->s_func_item = symbol_table.get(this->s_func_identifier);
        this->s_parameter_type_list = ch2->s_type_list;

        // 语义检查，未定义的id
        // 语义检查，未定义的id
        if (s_func_item == NULL)
        {
            ID_AST *id = ch0;
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "undefined identifier",
                                                   "identifier '" + id->identifier + "' is undefined");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
        // 语义检查，类型不是function
        if (s_func_item->type != symbol_type::function)
        {
            ID_AST *id = ch0;
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "identifier type Error",
                                                   "in function '" + id->identifier + "',identifier is not a function");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }

        if (s_func_item != NULL) // 存在函数名才进行函数调用的语义检查
        {
            MyFunctionType *functionType = s_func_item->value.function_val;
            if (!functionType->isfunction) // 如果不是函数
            {
                ID_AST *id = ch0;
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "identifier type Error",
                                                       "in function '" + id->identifier + "',identifier is not a function");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            this->s_type = functionType->ret_type;

            if (functionType->arg_name_list.size() != ch2->s_value_list.size()) // 检查参数数量是否匹配
            {
                ID_AST *id = ch0;
                SemanticError *err = new SemanticError(id->line, id->col,
                                                       "number of parameter Error",
                                                       "in function '" + id->identifier + "',The number of parameters does not match the definition");
                semantic_error_list.push_back(err);
                has_semantic_error = true;
                return;
            }
            else
            {
                for (int i = 0; i < functionType->arg_name_list.size(); ++i)
                {
                    if (functionType->arg_type_list[i] != s_parameter_type_list[i]) // 参数类型错误
                    {
                        ID_AST *id = ch0;
                        SemanticError *err = new SemanticError(id->line, id->col,
                                                               "parameter type Error",
                                                               "in function '" + id->identifier + "',parameter " + functionType->arg_name_list[i] + "type must be" + functionType->arg_type_list[i]);
                        semantic_error_list.push_back(err);
                        has_semantic_error = true;
                        return;
                    }
                    if (functionType->arg_isvar_list[i]) // 检查引用参数位能否是引用
                    {
                        if (!ch2->s_expression_list[i]->isleftvalue) // 但不是可引用类型
                        {
                            ID_AST *id = ch0;
                            SemanticError *err = new SemanticError(id->line, id->col,
                                                                   "parameter type Error",
                                                                   "in function '" + id->identifier + "',parameter " + functionType->arg_name_list[i] + "type must be referencable");
                            semantic_error_list.push_back(err);
                            has_semantic_error = true;
                            return;
                        }
                        this->s_parameter_list.push_back(ch2->s_expression_list[i]->llvmleftValue);
                    }
                    else
                    {
                        this->s_parameter_list.push_back(ch2->s_value_list[i]);
                    }
                }
            }
        }
        if (!has_semantic_error)
            this->s_value = function_call_generation();
    }
    else if (this->children[0]->type == SEPARATOR)
    {
        this->s_state = 4;
        expression_AST *ch1 = (expression_AST *)this->children[1];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_op = "()";
        this->s_operand0_type = ch1->s_type;
        this->s_operand0 = ch1->s_value;
        this->s_type = ch1->s_type;
        this->s_value = ch1->s_value;
    }
    else if (this->children[0]->type == NOT)
    {
        this->s_state = 4;
        factor_AST *ch1 = (factor_AST *)this->children[1];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_op = "!";
        this->s_operand0_type = ch1->s_type;
        this->s_operand0 = ch1->s_value;
        this->s_type = ch1->s_type;
        this->s_value = ch1->s_value;
        if (s_type != "boolean" && s_type != "integer")
        {
            NUM_AST *id = (NUM_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "operand type Error",
                                                   "'not' operator only can be used on boolean or integer type operand");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
    }
    else if (this->children[0]->type == UMINUS)
    {
        this->s_state = 4;
        factor_AST *ch1 = (factor_AST *)this->children[1];
        for (int i = 0; i < this->children.size(); ++i)
        {
            this->children[i]->semantic_action();
        }
        this->s_op = "-";
        this->s_operand0_type = ch1->s_type;
        this->s_operand0 = ch1->s_value;
        this->s_type = ch1->s_type;
        this->s_value = ch1->s_value;
        // 语义检查
        if (s_type != "integer" && s_type != "real")
        {
            NUM_AST *id = (NUM_AST *)this->children[0];
            SemanticError *err = new SemanticError(id->line, id->col,
                                                   "operand type Error",
                                                   "'-' operator only can be used on integer type or real type");
            semantic_error_list.push_back(err);
            has_semantic_error = true;
            return;
        }
    }
    else
        sematic_error();
    pascal_info_cat();
    // semantic_checking();
    if (!has_semantic_error)
        this->s_value = code_generation();
}

ASTNode *SematicAnalysis::create_ASTNode(BitNode *bn)
{
    ASTNode *nodeptr = NULL;

    if (bn->type == "PROGRAM")
        nodeptr = new PROGRAM_AST(bn);
    else if (bn->type == "CONST")
        nodeptr = new CONST_AST(bn);
    else if (bn->type == "VAR")
        nodeptr = new VAR_AST(bn);
    else if (bn->type == "PROCEDURE")
        nodeptr = new PROCEDURE_AST(bn);
    else if (bn->type == "FUNCTION")
        nodeptr = new FUNCTION_AST(bn);
    else if (bn->type == "BEGIN")
        nodeptr = new BEGIN_AST(bn);
    else if (bn->type == "END")
        nodeptr = new END_AST(bn);
    else if (bn->type == "ARRAY")
        nodeptr = new ARRAY_AST(bn);
    else if (bn->type == "OF")
        nodeptr = new OF_AST(bn);
    else if (bn->type == "IF")
        nodeptr = new IF_AST(bn);
    else if (bn->type == "THEN")
        nodeptr = new THEN_AST(bn);
    else if (bn->type == "FOR")
        nodeptr = new FOR_AST(bn);
    else if (bn->type == "TO")
        nodeptr = new TO_AST(bn);
    else if (bn->type == "DO")
        nodeptr = new DO_AST(bn);
    else if (bn->type == "READ")
        nodeptr = new READ_AST(bn);
    else if (bn->type == "WRITE")
        nodeptr = new WRITE_AST(bn);
    else if (bn->type == "NOT")
        nodeptr = new NOT_AST(bn);
    else if (bn->type == "ELSE")
        nodeptr = new ELSE_AST(bn);
    else if (bn->type == "RANGE")
        nodeptr = new RANGE_AST(bn);
    else if (bn->type == "UMINUS")
        nodeptr = new UMINUS_AST(bn);
    else if (bn->type == "ID")
        nodeptr = new ID_AST(bn);
    else if (bn->type == "RELOP")
        nodeptr = new RELOP_AST(bn);
    else if (bn->type == "DIGITS")
        nodeptr = new DIGITS_AST(bn);
    else if (bn->type == "NUM")
        nodeptr = new NUM_AST(bn);
    else if (bn->type == "VARTYPE")
        nodeptr = new VARTYPE_AST(bn);
    else if (bn->type == "ADDOP")
        nodeptr = new ADDOP_AST(bn);
    else if (bn->type == "MULOP")
        nodeptr = new MULOP_AST(bn);
    else if (bn->type == "ASSIGNOP")
        nodeptr = new ASSIGNOP_AST(bn);
    else if (bn->type == "SEPARATOR")
        nodeptr = new SEPARATOR_AST(bn);
    else if (bn->type == "CHAR")
        nodeptr = new CHAR_AST(bn);
    else if (bn->type == "BOOLEAN")
        nodeptr = new BOOLEAN_AST(bn);
    else if (bn->type == "WHILE")
        nodeptr = new WHILE_AST(bn);
    else if (bn->type == "programstruct")
        nodeptr = new programstruct_AST(bn);
    else if (bn->type == "program_head")
        nodeptr = new program_head_AST(bn);
    else if (bn->type == "program_body")
        nodeptr = new program_body_AST(bn);
    else if (bn->type == "idlist")
        nodeptr = new idlist_AST(bn);
    else if (bn->type == "const_declarations")
        nodeptr = new const_declarations_AST(bn);
    else if (bn->type == "const_declaration")
        nodeptr = new const_declaration_AST(bn);
    else if (bn->type == "const_value")
        nodeptr = new const_value_AST(bn);
    else if (bn->type == "var_declarations")
        nodeptr = new var_declarations_AST(bn);
    else if (bn->type == "var_declaration")
        nodeptr = new var_declaration_AST(bn);
    else if (bn->type == "basic_type")
        nodeptr = new basic_type_AST(bn);
    else if (bn->type == "type")
        nodeptr = new type_AST(bn);
    else if (bn->type == "period")
        nodeptr = new period_AST(bn);
    else if (bn->type == "subprogram_declarations")
        nodeptr = new subprogram_declarations_AST(bn);
    else if (bn->type == "subprogram")
        nodeptr = new subprogram_AST(bn);
    else if (bn->type == "subprogram_head")
        nodeptr = new subprogram_head_AST(bn);
    else if (bn->type == "formal_parameter")
        nodeptr = new formal_parameter_AST(bn);
    else if (bn->type == "parameter_list")
        nodeptr = new parameter_list_AST(bn);
    else if (bn->type == "parameter")
        nodeptr = new parameter_AST(bn);
    else if (bn->type == "var_parameter")
        nodeptr = new var_parameter_AST(bn);
    else if (bn->type == "value_parameter")
        nodeptr = new value_parameter_AST(bn);
    else if (bn->type == "subprogram_body")
        nodeptr = new subprogram_body_AST(bn);
    else if (bn->type == "compound_statement")
        nodeptr = new compound_statement_AST(bn);
    else if (bn->type == "statement_list")
        nodeptr = new statement_list_AST(bn);
    else if (bn->type == "statement")
        nodeptr = new statement_AST(bn);
    else if (bn->type == "variable_list")
        nodeptr = new variable_list_AST(bn);
    else if (bn->type == "variable")
        nodeptr = new variable_AST(bn);
    else if (bn->type == "id_varpart")
        nodeptr = new id_varpart_AST(bn);
    else if (bn->type == "procedure_call")
        nodeptr = new procedure_call_AST(bn);
    else if (bn->type == "else_part")
        nodeptr = new else_part_AST(bn);
    else if (bn->type == "term")
        nodeptr = new term_AST(bn);
    else if (bn->type == "factor")
        nodeptr = new factor_AST(bn);
    else if (bn->type == "simple_expression")
        nodeptr = new simple_expression_AST(bn);
    else if (bn->type == "expression_list")
        nodeptr = new expression_list_AST(bn);
    else if (bn->type == "expression")
        nodeptr = new expression_AST(bn);

    return nodeptr;
}

ASTNode *SematicAnalysis::ADT2AST(BitNode *bn)
{
    // 父节点动作
    ASTNode *cur_node = create_ASTNode(bn);
    int n = bn->children.size();
    // 子节点遍历
    for (size_t i = 0; i < n; i++)
    {
        ASTNode *child = ADT2AST(bn->children[i]);
        cur_node->children.push_back(child);
        child->father = cur_node;
    }
    return cur_node;
}
/**
class Type_IR{
public:
    llvm::LLVMContext llvmContext;
    map<string, string> arrayTypeList;           //数组元素类型列表
    map<string, vector<pair<int, int>> > arrayRangeLists; //数组上下界列表
    map<string, vector<int>> arraySizeLists;     //数组大小列表
    map<string, llvm::ArrayType*> arrayTypes;       //数组变量对应的LLVM Type
    //TypeSystem(LLVMContext& context): llvmContext(context) {}
    Type_IR(llvm::LLVMContext& context): llvmContext() {}
    llvm::Type* type_int = llvm::Type::getInt32Ty(llvmContext);
    llvm::Type* type_real = llvm::Type::getFloatTy(llvmContext);
    llvm::Type* type_char = llvm::Type::getInt8Ty(llvmContext);
    llvm::Type* type_boolean = llvm::Type::getInt1Ty(llvmContext);
    llvm::Type* type_void = llvm::Type::getVoidTy(llvmContext);
    llvm::Type* type_int64 = llvm::Type::getInt64Ty(llvmContext);
    //获取llvm类型
    llvm::Type* getLLVMType(const string& type);
    llvm::Type* getLLVMType(const int& type);
    llvm::Type* getArrayLLVMType(SymbolTableItem* item);
    llvm::Type* createArrayType(SymbolTableItem* item);
    //增加llvm类型
    void addArrayType(const string &name, llvm::ArrayType *type, SymbolTableItem* item);
    //获取数组元素类型名
    string getArrayMemberType(const string& arrName);
    //判断两个类型是否相同
    bool isSameType(const string& type1, const string& type2);
    //判断是否是基本类型
    bool isBasicType(const string& type);
    bool isBasicType(const int& type);

};*/
/**
 * 初始化库函数
 */
llvm::Value *get_item(variable_AST *var);
void CodeGenContext::init_funcStack()
{
    cout << "CodeGenerate::init_funcStack" << endl;
    vector<llvm::Type *> param;
    // 写整数
    param.push_back(this->type_ir.type_int);
    llvm::FunctionType *func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "write_int", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 写实数
    param.push_back(this->type_ir.type_real);
    func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "write_real", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 写字符
    param.push_back(this->type_ir.type_char);
    func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "write_char", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 写布尔
    param.push_back(this->type_ir.type_boolean);
    func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "write_boolean", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读整数
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_int, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "read_int", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读实数
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_real, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "read_real", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读字符
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_char, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "read_char", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读布尔
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_boolean, param, false);
    func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "read_boolean", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    llvm::sys::DynamicLibrary::AddSymbol("write_int", this->funcStack[0]);
    llvm::sys::DynamicLibrary::AddSymbol("write_real", this->funcStack[1]);
    llvm::sys::DynamicLibrary::AddSymbol("write_char", this->funcStack[2]);
    llvm::sys::DynamicLibrary::AddSymbol("write_boolean", this->funcStack[3]);
    llvm::sys::DynamicLibrary::AddSymbol("read_int", this->funcStack[4]);
    llvm::sys::DynamicLibrary::AddSymbol("read_real", this->funcStack[5]);
    llvm::sys::DynamicLibrary::AddSymbol("read_char", this->funcStack[6]);
    llvm::sys::DynamicLibrary::AddSymbol("read_boolean", this->funcStack[7]);
}
// AST CodeGenerate
/**
 * 主程序IR生成 该模块已完成
 */
llvm::Value *programstruct_AST::code_generation()
{
    cout << "programstruct_AST::code_generation" << endl;
    // 生成main program
    llvm::FunctionType *type = llvm::FunctionType::get(context.type_ir.type_void, false);
    llvm::Function *program = llvm::Function::Create(type, llvm::Function::ExternalLinkage, "main", context.module.get());
    // 基本块生成
    llvm::BasicBlock *block = llvm::BasicBlock::Create(context.llvmContext, "main_entry", program, 0);
    // 主程序块生成
    context.builder = make_unique<llvm::IRBuilder<>>(block);
    context.builder->SetInsertPoint(block);
    IP = context.builder->saveIP();
    return nullptr;
}
// 常量元素：
/**
 * 常量定义IR生成 该模块已完成
 * @return Value* 常量的llvm Value
 */
llvm::Value *const_value_AST::code_generation()
{
    cout << "const_value_AST::code_generation" << endl;
    llvm::Value *ret = nullptr;
    llvm::Value *addr = nullptr;
    if (this->s_type == "integer")
    {
        int value = this->s_int < 0 ? -this->s_int : this->s_int;
        ret = llvm::ConstantInt::get(context.type_ir.type_int, value, true);
    }
    else if (this->s_type == "real")
    {
        double value = this->s_real < 1e-6 ? -this->s_real : this->s_real;
        ret = llvm::ConstantFP::get(context.type_ir.type_real, value);
    }
    else if (this->s_type == "char")
    {
        char value = this->s_char;
        ret = llvm::ConstantInt::get(context.type_ir.type_char, value, true);
    }
    else if (this->s_type == "boolean")
    {
        bool value = this->s_bool;
        ret = llvm::ConstantInt::get(context.type_ir.type_boolean, value, true);
    }
    else
    {
        ret = LogErrorV("unknown const type" + this->s_type);
    }
    return ret;
}
llvm::Value *const_declarations_AST::code_generation()
{
    cout << "const_declarations_AST::code_generation" << endl;
    SymbolTableItem *symbol_table_item = nullptr;
    llvm::Type *type = nullptr;
    llvm::Value *ret = nullptr;
    for (auto &item : s_pair_list)
    {
        if (l_isglobal)
        {
            symbol_table_item = symbol_table.get(item.first);
            type = context.type_ir.getLLVMType(item.second->s_type); // 获取基本变量类型
            context.module->getOrInsertGlobal(item.first, type);
            llvm::GlobalVariable *v = context.module->getNamedGlobal(item.first);
            int num = 0;
            if (symbol_table_item->type == 1 || symbol_table_item->type == 5)
                num = 4;
            else if (symbol_table_item->type == 2 || symbol_table_item->type == 6)
                num = 8;
            else
                num = 1;
            v->setAlignment(llvm::MaybeAlign(num));
            ret = context.builder->CreateLoad(v);
            symbol_table_item->value.array_val->llvmvalue = v;
        }
        else
        {
            symbol_table_item = symbol_table.get(item.first);
            type = context.type_ir.getLLVMType(item.second->s_type); // 获取基本变量类型
            ret = context.builder->CreateAlloca(type, nullptr);
            context.builder->CreateStore(item.second->s_value, ret);
            symbol_table_item->value.basic_val->llvmvalue = ret;
        }
    }
}
// 元素 常量 变量 类型

/**
 * 变量声明IR生成 该模块已完成
 * bug可能出现在 数组定义
 * @return Value* 局部变量地址
 */
llvm::Value *var_declarations_AST::code_generation()
{
    cout << "var_declarations_AST::code_generation" << endl;
    for (auto &item : this->s_id_type_list)
    {
        llvm::Type *type = nullptr;
        llvm::Value *ret = nullptr;
        SymbolTableItem *symbol_table_item = nullptr;
        // l_isglobal = false;
        if (item.second->l_isarray)
        {
            for (auto &id : item.first->list)
            {
                if (l_isglobal)
                {
                    int len = 0;
                    symbol_table_item = symbol_table.get(id);
                    type = context.type_ir.getLLVMType(symbol_table_item->value.array_val->type); // 获取基本类型
                    llvm::ArrayType *arrayType = llvm::ArrayType::get(type, symbol_table_item->value.array_val->end[0] + 1);
                    for (int i = 1; i < symbol_table_item->value.array_val->size.size(); ++i)
                        arrayType = llvm::ArrayType::get(arrayType, symbol_table_item->value.array_val->end[i] + 1);
                    context.module->getOrInsertGlobal(id, arrayType);
                    llvm::GlobalVariable *v = context.module->getNamedGlobal(id);
                    int num = 0;
                    if (symbol_table_item->value.array_val->type == 1 || symbol_table_item->value.array_val->type == 5)
                        num = 4;
                    else if (symbol_table_item->value.array_val->type == 2 || symbol_table_item->value.array_val->type == 6)
                        num = 8;
                    else
                        num = 1;
                    v->setAlignment(llvm::MaybeAlign(num));
                    ret = context.builder->CreateLoad(v);
                    symbol_table_item->value.array_val->llvmvalue = v;
                }
                else
                {
                    int len = 0;
                    symbol_table_item = symbol_table.get(id);
                    type = context.type_ir.getArrayLLVMType(symbol_table_item);
                    type = context.type_ir.getLLVMType(symbol_table_item->value.array_val->type);
                    llvm::ArrayType *arrayType = llvm::ArrayType::get(type, symbol_table_item->value.array_val->end[0] + 1);
                    for (int i = 0; i < symbol_table_item->value.array_val->size.size(); ++i)
                        arrayType = llvm::ArrayType::get(arrayType, symbol_table_item->value.array_val->end[i] + 1);
                    ret = context.builder->CreateAlloca(arrayType);
                    symbol_table_item->value.array_val->llvmvalue = ret;
                }

            }
        }
        else
        {
            for (auto &id : item.first->list)
            {
                if (l_isglobal)
                {
                    symbol_table_item = symbol_table.get(id);
                    type = context.type_ir.getLLVMType(item.second->s_type); // 获取基本变量类型
                    context.module->getOrInsertGlobal(id, type);
                    llvm::GlobalVariable *v = context.module->getNamedGlobal(id);
                    int num = 0;
                    if (symbol_table_item->type == 1 || symbol_table_item->type == 5)
                        num = 4;
                    else if (symbol_table_item->type == 2 || symbol_table_item->type == 6)
                        num = 8;
                    else
                        num = 1;
                    v->setAlignment(llvm::MaybeAlign(num));
                    ret = context.builder->CreateLoad(v);
                    symbol_table_item->value.basic_val->llvmvalue = v;
                }
                else
                {
                    symbol_table_item = symbol_table.get(id);
                    type = context.type_ir.getLLVMType(item.second->s_type); // 获取基本变量类型
                    ret = context.builder->CreateAlloca(type, nullptr);
                    symbol_table_item->value.basic_val->llvmvalue = ret;
                }

            }
        }
    }
    return nullptr;
}

/**
 * 类型IR生成
 * 没用
 * @return Value*
 */
llvm::Value *type_AST::code_generation()
{
    // 似乎没用，var那里生成了
    cout << "type_Ast::code_generation" << endl;
    // 数组类型
    llvm::Type *ret = nullptr;
    if (this->l_isarray)
    {
        cout << "type_Ast::code_generation is_array" << endl;
    }
    return nullptr;
}

// 函数
/**
 * 函数 过程定义IR生成 该模块已完成
 * bug可能出现在 传值传引用 符号表存储
 * @return Value* 函数地址指针
 */
llvm::Function *subprogram_head_AST::function_generation()
{
    cout << "subprogram_head_AST::code_generation" << endl;
    vector<llvm::Type *> argTypes;
    vector<pair<string, bool>> argNames; // 形参名字和是否是引用传递
    // 从一堆s_list中获取每个形参的类型,我同时可以知道他们是否是引用传递
    for (int i = 0; i < this->s_list.size(); i++)
    {
        // 获取每个形参的llvm类型
        for (int j = 0; j < s_list[i]->s_id_list.size(); ++j)
        {
            llvm::Type *cur = context.type_ir.getLLVMType(this->s_list[i]->s_type);
            llvm::PointerType *pstructType = llvm::PointerType::get(cur, 0);
            if (this->s_list[i]->s_isvar)
                argTypes.push_back(pstructType);
            else
                argTypes.push_back(cur);
            argNames.push_back(make_pair(this->s_list[i]->s_id_list[j], this->s_list[i]->s_isvar));
        }
    }
    // 获取函数返回值类型
    // 若是过程就是void
    string ret_string = (s_ret_type == "") ? "void" : this->s_ret_type;
    llvm::Type *retType = context.type_ir.getLLVMType(ret_string);
    // 生成函数类型
    llvm::FunctionType *type = llvm::FunctionType::get(retType, argTypes, false);
    // 生成函数
    llvm::Function *func = llvm::Function::Create(type, llvm::Function::ExternalLinkage, this->program_name, context.module.get());
    // 生成基本块
    llvm::BasicBlock *block = llvm::BasicBlock::Create(context.llvmContext, "entry", func, 0);
    context.builder->SetInsertPoint(block);
    // 形参
    auto argName = argNames.begin();
    auto argType = argTypes.begin();
    SymbolTableItem *item = nullptr;
    for (auto &arg : func->args())
    {
        arg.setName(argName->first);
        llvm::Value *loc = nullptr;
        if (argName->second) // 是引用传递
        {
            loc = &arg; // 传入值是地址
        }
        else
        {
            // 获取局部变量地址
            loc = context.builder->CreateAlloca(*argType, nullptr, argName->first);
            context.builder->CreateStore(&arg, loc, false); // 参数存到地址中
        }
        // 符号表记录形参
        item = symbol_table.get(argName->first); // 获取符号表项
        item->value.basic_val->llvmvalue = loc;  // 记录形参地址
        argName++;
        argType++;
    }
    if (s_item->type == 10)
        s_item->value.function_val->ret_llvmval = context.builder->CreateAlloca(context.type_ir.getLLVMType(ret_string), nullptr, "ret"); // 返回值
    return func;
}
/**
 * 函数返回值生成， 该模块未完全完成
 */
// 此处建议，用符号表记录返回值
llvm::Value *subprogram_body_AST::ret_generation(llvm::Value *addr)
{
    // 语义分析需要加一个标记，标记是否是函数
    if (isfunction)
    {
        llvm::Value *ret = context.builder->CreateLoad(addr);
        context.builder->CreateRet(ret); // 符号表记录返回值
    }
    else
    {
        context.builder->CreateRetVoid();
    }
    return nullptr;
}
/**
 * program IR生成
 *该模块已完成,与program_structure_AST::code_generation()重复
 */
llvm::Value *program_body_AST::code_generation()
{
    cout << "program_body::code_generation" << endl;
    // 生成函数
    llvm::FunctionType *type = llvm::FunctionType::get(context.type_ir.type_void, false);
    llvm::Function *program = llvm::Function::Create(type, llvm::Function::ExternalLinkage, "main", context.module.get());
    // 生成基本块
    llvm::BasicBlock *block = llvm::BasicBlock::Create(context.llvmContext, "entry", program);
    // 主程序块生成
    context.builder = make_unique<llvm::IRBuilder<>>(block);
    return nullptr;
}
/**
 * subprogram IR生成
 * 该模块已完成,废弃
 */
llvm::Value *subprogram_body_AST::code_generation()
{
    cout << "program_body::code_generation" << endl;
    // 生成函数
    llvm::FunctionType *type = llvm::FunctionType::get(context.type_ir.type_void, false);
    llvm::Function *program = llvm::Function::Create(type, llvm::Function::ExternalLinkage, "sub", context.module.get());
    // 生成基本块
    llvm::BasicBlock *block = llvm::BasicBlock::Create(context.llvmContext, "entry", program);
    // 块插入
    context.builder->SetInsertPoint(block);
    return nullptr;
}
/**
 * 过程调用 IR生成  该模块已完成
 * @return Value* 过程call
 */
llvm::Value *procedure_call_AST::code_generation()
{
    cout << "procedure_call_AST::code_generation" << endl;
    // 符号表里寻找procedeure id
    // 当然，这里可能拿过了
    this->s_item = symbol_table.get(this->s_identifier);
    if (this->s_item == nullptr)
        return LogErrorV("procedure not found in sympol table");
    vector<llvm::Value *> args; // 获取参数列表
    int count = 0;
    for (auto &item : s_value_list)
    {
        if (s_type_list[count] == "real")
            item = context.builder->CreateSIToFP(item, context.type_ir.type_int);
        args.push_back(item);
        ++count;
    }
    // 获取一个过程指针 todo
    // Function* pro_ptr = record->func;
    llvm::Function *pro_ptr = s_item->value.function_val->llvmfunction;

    return context.builder->CreateCall(pro_ptr, args, "Call Procedure");
    /**
     * 也可以这么写,上面那个做了错误处理，但是，语义分析那里就爆了，所以没必要23333
     *  auto ptr = s_item->value.function_val;//获取函数符号表指针
     * Function* call = ptr->llvmfunction;//获取函数指针
     * return context.builder->CreateCall(call, s_value_list, "Call Procedure")
     */
}
/**
 * 函数调用 IR生成  该模块已完成
 * @return Value* 函数call
 */
llvm::Value *factor_AST::function_call_generation()
{
    cout << "factor_AST::function_call_generation" << endl;
    auto ptr = s_func_item->value.function_val; // 获取函数符号表指针
    llvm::Function *call = ptr->llvmfunction;   // 获取函数指针
    return context.builder->CreateCall(call, s_parameter_list, "Call Function");
}
// 表达式
/**
 * factor IR生成
 * 因子
 * 该部分包括 常数值、变量值、函数调用、表达式、取非、取负
 */
llvm::Value *factor_AST::code_generation()
{
    cout << "factor_AST::code_generation" << endl;
    llvm::Value *value = this->s_value;
    // 四种常数
    switch (s_state)
    {
        case 1: // 常数
        {
            if (s_type == "integer")
                value = llvm::ConstantInt::get(context.type_ir.type_int, s_int, true);
            else if (s_type == "real")
                value = llvm::ConstantFP::get(context.type_ir.type_real, (double)s_real);
            else if (s_type == "char")
                value = llvm::ConstantInt::get(context.type_ir.type_char, s_char, true);
            else if (s_type == "boolean")
                value = llvm::ConstantInt::get(context.type_ir.type_boolean, s_bool, true);
        }
            break;
        case 2:
        {
            value = this->s_value; // 变量，拿解析值
        }
            break;
        case 3: // 函数、表达式
        {
            value = this->s_value; // 变量，拿解析值
        }
            break;
        case 4: // 单目运算符
        {
            if (this->s_op == "!") // 取非
                value = context.builder->CreateNot(this->s_operand0, "not");
            else if (this->s_op == "-") // 取负
            {
                // 浮点形
                if (this->s_operand0_type == "real")
                {
                    llvm::Value *temp = llvm::ConstantFP::get(context.type_ir.type_real, (double)(0.0));
                    value = context.builder->CreateFNeg(this->s_operand0, "uminus");
                }
                else
                {
                    llvm::Value *temp = llvm::ConstantInt::get(context.type_ir.type_real, 0, true);
                    value = context.builder->CreateNeg(this->s_operand0, "uminus");
                }
            }
        }
            break;
    }
    // 可以语法做
    // this->s_value = value;
    return value;
}
/**
 * term IR生成
 * 该部分包括 mulop ： *、/、div、mod 和 and
 */
llvm::Value *term_AST::code_generation()
{
    cout << "term_AST::code_generation" << endl;
    // 二位运算符
    llvm::Value *value = nullptr;
    // 类型转换,待浮点全部转浮点 /运算好像不用
    bool judge = true;
    if (operand0_type == "real" || operand1_type == "real")
    {
        operand0 = context.builder->CreateSIToFP(operand0, context.type_ir.type_real);
        operand1 = context.builder->CreateSIToFP(operand1, context.type_ir.type_real);
        judge = false;
    }
    if (s_op == "*")
    {
        if (judge)
            value = context.builder->CreateMul(operand0, operand1, "multmp");
        else
            value = context.builder->CreateFMul(operand0, operand1, "multmp");
    }
        // 两种除法有待商榷
    else if (s_op == "/")
    {
        if (judge)
            value = context.builder->CreateSDiv(operand0, operand1, "divtmp");
        else
            value = context.builder->CreateFDiv(operand0, operand1, "div");
    }
    else if (s_op == "div")
    {
        if (judge)
            value = context.builder->CreateSDiv(operand0, operand1, "divtmp");
        else
            value = context.builder->CreateFDiv(operand0, operand1, "divtmp");
    }
        // 取模没有浮点
    else if (s_op == "mod")
    {
        value = context.builder->CreateSRem(operand0, operand1, "modtmp");
    }
    else if (s_op == "and")
    {
        value = context.builder->CreateAnd(operand0, operand1, "andtmp");
    }
    return value;
}
/**
 * simple_expression IR生成
 * 该部分包括 addop ：+、-、or
 */
llvm::Value *simple_expression_AST::code_generation()
{
    cout << "simple_expression_AST::code_generation" << endl;
    llvm::Value *value = nullptr;
    // 类型转换,待浮点全部转浮点 /运算好像不用
    bool judge = true;
    if (operand0_type == "real" || operand1_type == "real")
    {
        operand0 = context.builder->CreateSIToFP(operand0, context.type_ir.type_real);
        operand1 = context.builder->CreateSIToFP(operand1, context.type_ir.type_real);
        judge = false;
    }
    if (s_op == "+")
    {
        if (judge)
            value = context.builder->CreateAdd(operand0, operand1, "addtmp");
        else
            value = context.builder->CreateFAdd(operand0, operand1, "addtmp");
    }
        // 两种除法有待商榷
    else if (s_op == "-")
    {
        if (judge)
            value = context.builder->CreateSub(operand0, operand1, "subtmp");
        else
            value = context.builder->CreateFSub(operand0, operand1, "subtmp");
    }
    else if (s_op == "or")
    {
        value = context.builder->CreateOr(operand0, operand1, "ortmp");
    }
    return value;
}
/**
 * expression IR生成
 * 该部分包括 relop ：=、<>、<、<=、>、>=
 */
llvm::Value *expression_AST::code_generation()
{
    cout << "expression_AST::code_generation" << endl;
    llvm::Value *value = nullptr;
    // 类型转换,带浮点全部转浮点
    bool judge = true;
    if (operand0_type == "real" || operand1_type == "real")
    {
        operand0 = context.builder->CreateSIToFP(operand0, context.type_ir.type_real);
        operand1 = context.builder->CreateSIToFP(operand1, context.type_ir.type_real);
        judge = false;
    }
    if (s_op == "<")
    {
        if (judge)
            value = context.builder->CreateICmpSLT(operand0, operand1, "lttmp");
        else
            value = context.builder->CreateFCmpULT(operand0, operand1, "lttmp");
    }
    else if (s_op == "<=")
    {
        if (judge)
            value = context.builder->CreateICmpSLE(operand0, operand1, "letmp");
        else
            value = context.builder->CreateFCmpULE(operand0, operand1, "letmp");
    }
    else if (s_op == ">")
    {
        if (judge)
            value = context.builder->CreateICmpSGT(operand0, operand1, "gttmp");
        else
            value = context.builder->CreateFCmpUGT(operand0, operand1, "gttmp");
    }
    else if (s_op == ">=")
    {
        if (judge)
            value = context.builder->CreateICmpSGE(operand0, operand1, "getmp");
        else
            value = context.builder->CreateFCmpUGE(operand0, operand1, "getmp");
    }
    else if (s_op == "=")
    {
        if (judge)
            value = context.builder->CreateICmpEQ(operand0, operand1, "eqtmp");
        else
            value = context.builder->CreateFCmpUEQ(operand0, operand1, "eqtmp");
    }
    else if (s_op == "<>")
    {
        if (judge)
            value = context.builder->CreateICmpNE(operand0, operand1, "netmp");
        else
            value = context.builder->CreateFCmpUNE(operand0, operand1, "netmp");
    }
    return value;
}

// 语句
llvm::Value *statement_AST::code_generation()
{
    cout << "statement_AST::code_generation" << endl;
    // todo
    return nullptr;
}
/**
 * if 语句
 * 第一阶段
 */
llvm::Value *statement_AST::if_code_generation_1()
{
    cout << "statement_AST::if_code_generation" << endl;
    if (s_expression_value == nullptr)
        return LogErrorV("if expression is null");
    s_expression_value = expressionToBoolean(s_expression_value);
    function = context.builder->GetInsertBlock()->getParent(); // 得到if语句所属函数
    block1 = llvm::BasicBlock::Create(context.llvmContext, "then", function);
    block2 = llvm::BasicBlock::Create(context.llvmContext, "else"); // else部分
    block3 = llvm::BasicBlock::Create(context.llvmContext, "ifcont");
    if (s_has_else)
    {
        // 有else
        context.builder->CreateCondBr(s_expression_value, block1, block2);
    }
    else
    {
        // 无else
        context.builder->CreateCondBr(s_expression_value, block1, block3);
    }
    context.builder->SetInsertPoint(block1);
    IP = context.builder->saveIP(); // 保存插入点
    return nullptr;
}
/**
 * if 语句
 * 第二阶段
 */
llvm::Value *statement_AST::if_code_generation_2()
{
    cout << "statement_AST::if_code_generation_2" << endl;
    context.builder->restoreIP(IP);
    // restoreIP(IP);//恢复插入点
    block1 = context.builder->GetInsertBlock();
    // 在thenBB插入的最后一条指令是ret，则不再跳转回final_block
    if (block1->getTerminator() == nullptr)
        context.builder->CreateBr(block3);
    if (block4 != nullptr)
    {
        context.builder->SetInsertPoint(block4);
        context.builder->CreateBr(block3);
    }
    if (s_has_else)
    {
        function->getBasicBlockList().push_back(block2);
        context.builder->SetInsertPoint(block2);
        IP = context.builder->saveIP(); // 保存插入点
        // 生成else
    }
    return nullptr;
}
/**
 * if语句
 * 第三阶段
 */
llvm::Value *statement_AST::if_code_generation_3()
{
    cout << "statement_AST::if_code_generation_3" << endl;
    context.builder->restoreIP(IP);
    if (s_has_else)
    {
        if (block2->getTerminator() == nullptr)
            context.builder->CreateBr(block3);
        if (block4 != nullptr)
        {
            context.builder->SetInsertPoint(block4);
            context.builder->CreateBr(block3);
        }
    }
    function->getBasicBlockList().push_back(block3);
    context.builder->SetInsertPoint(block3);
    return nullptr;
}
/**
 * for语句
 * 第一阶段
 */
llvm::Value *statement_AST::for_code_generation_1()
{
    llvm::Value *condition = nullptr;
    cout << "statement_AST::for_code_generation_1" << endl;
    function = context.builder->GetInsertBlock()->getParent(); // 得到for语句所属函数
    block1 = llvm::BasicBlock::Create(context.llvmContext, "forloop", function);
    block3 = llvm::BasicBlock::Create(context.llvmContext, "forcont");
    condition = context.builder->CreateICmpSLE(s_for_expression_value1, s_for_expression_value2, "for.condition.compare.result");
    s_for_item = symbol_table.get(s_for_identifier);
    context.builder->CreateStore(s_for_expression_value1, s_for_item->value.basic_val->llvmvalue);
    // s_expression_value = expressionToBoolean(s_for_expression_valpue1,s_for_expression_value2);//条件值
    context.builder->CreateCondBr(condition, block1, block3);
    context.builder->SetInsertPoint(block1);
    IP = context.builder->saveIP(); // 保存插入点
    // 循环体生成
    return nullptr;
}
/**
 * for语句
 * 第二阶段
 */
llvm::Value *statement_AST::for_code_generation_2()
{
    cout << "statement_AST::for_code_generation_2" << endl;
    llvm::Value *condition = nullptr;
    llvm::Value *increase = nullptr;
    llvm::Value *value_old = nullptr;
    if (block4 != nullptr)
    {
        context.builder->SetInsertPoint(block4); // 设置插入点，这个地方有待考量
        s_for_item = symbol_table.get(s_for_identifier);
        value_old = context.builder->CreateLoad(s_for_item->value.basic_val->llvmvalue);
        increase = context.builder->CreateAdd(value_old, context.builder->getInt32(1), "increase");
        context.builder->CreateStore(increase, s_for_item->value.basic_val->llvmvalue);
        value_old = context.builder->CreateLoad(s_for_item->value.basic_val->llvmvalue);
        condition = context.builder->CreateICmpSLE(value_old, s_for_expression_value2, "for.condition.compare.result");
        context.builder->CreateCondBr(condition, block1, block3);
    }
    else
    {
        context.builder->SetInsertPoint(block1); // 设置插入点，这个地方有待考量
        s_for_item = symbol_table.get(s_for_identifier);
        value_old = context.builder->CreateLoad(s_for_item->value.basic_val->llvmvalue);
        increase = context.builder->CreateAdd(value_old, context.builder->getInt32(1), "increase");
        context.builder->CreateStore(increase, s_for_item->value.basic_val->llvmvalue);
        value_old = context.builder->CreateLoad(s_for_item->value.basic_val->llvmvalue);
        condition = context.builder->CreateICmpSLE(value_old, s_for_expression_value2, "for.condition.compare.result");
        context.builder->CreateCondBr(condition, block1, block3);
        // s_expression_value = expressionToBoolean(s_for_expression_value1,s_for_expression_value2);//
    }
    function->getBasicBlockList().push_back(block3);
    context.builder->SetInsertPoint(block3);
    return nullptr;
}
/**
 * while语句
 * 第一阶段
 */
llvm::Value *statement_AST::while_code_generation_1()
{
    cout << "statement_AST::while_code_generation_1" << endl;
    function = context.builder->GetInsertBlock()->getParent(); // 得到while语句所属函数

    block1 = llvm::BasicBlock::Create(context.llvmContext, "whileloop", function);

    block3 = llvm::BasicBlock::Create(context.llvmContext, "whilecont", function);

    while_temp_value = context.builder->CreateAlloca(context.type_ir.type_boolean);
    s_expression_value = expressionToBoolean(s_expression_value); // 条件值
    context.builder->CreateStore(s_expression_value, while_temp_value);
    context.builder->CreateCondBr(s_expression_value, block1, block3);
    context.builder->SetInsertPoint(block1);
    IP = context.builder->saveIP(); // 保存插入点
    return nullptr;
}
/**
 * while语句
 * 第二阶段
 */
llvm::Value *statement_AST::while_code_generation_2()
{
    cout << "statement_AST::while_code_generation_2" << endl;
    llvm::Value *condition = nullptr;
    llvm::Value *increase = nullptr;
    llvm::Value *value_old = nullptr;
    if (block4 != nullptr)
    {
        context.builder->SetInsertPoint(block4); // 设置插入点，这个地方有待考量
        condition = context.builder->CreateLoad(while_temp_value);
        context.builder->CreateCondBr(condition, block1, block3);
    }
    else
    {
        context.builder->SetInsertPoint(block1); // 设置插入点，这个地方有待考量
        condition = context.builder->CreateLoad(while_temp_value);
        context.builder->CreateCondBr(condition, block1, block3);
    }
    // function->getBasicBlockList().push_back(block3);
    context.builder->SetInsertPoint(block3);
    return nullptr;
}
/**
 * assign语句
 */
llvm::Value *statement_AST::assign_code_generation()
{
    cout << "statement_AST::assign_code_generation" << endl;
    // 获取左值 item
    SymbolTableItem *item = nullptr;

    // 获取左值,左值可以是变量，也可以是数组元素，
    llvm::Value *value = nullptr; // 左值变量地址    if (is_while_assign == true)
    if (is_while_assign)
    {
        context.builder->CreateStore(s_expression_value, while_temp_value);
        value = while_temp_value;
    }
    else
    {
        item = this->s_variable->item;
        if (this->s_expression_type == "return") // 函数返回值
        {
            // 记录函数返回值
            item->value.function_val->ret_llvmval = s_expression_value;
            return nullptr;
        }
        if (item->type == 6 && s_expression_type == "integer")
        {
            s_expression_value = context.builder->CreateSIToFP(s_expression_value, context.type_ir.type_real);
        }
        if (item->type == 5 && s_expression_type == "real")
        {
            s_expression_value = context.builder->CreateFPToSI(s_expression_value, context.type_ir.type_int);
        }
        if (s_variable->s_isarray) // 可能有问题
        {
            // 获取指针 获取数组元素地址
            // Value* ptr = nullptr;
            value = get_item(this->s_variable);
            context.builder->CreateStore(s_expression_value, value);
        }
        else
        {
            if (item->type < 10)
                value = item->value.basic_val->llvmvalue;
            else
                value = item->value.function_val->ret_llvmval;
            context.builder->CreateStore(s_expression_value, value);
        }
    }

    return value;
}
/**
 * wirte 语句
 */
llvm::Value *statement_AST::write()
{
    cout << "statement_AST::wirte_procedure" << endl;
    vector<llvm::Value *> args;
    int count = 0;
    int index = 0;
    for (auto &item : s_value_list)
    {
        args.clear();
        args.push_back(item);
        if (args.empty())
            return LogErrorV("write procedure failed");
        if (s_type_list[count] == "integer")
            index = 0;
        else if (s_type_list[count] == "real")
            index = 1;
        else if (s_type_list[count] == "char")
            index = 2;
        else if (s_type_list[count] == "boolean")
            index = 3;
        // 调用库函数
        context.builder->CreateCall(context.funcStack[index], args, "write");
        ++count;
    }
    return nullptr;
}
/**
 * read 语句
 */
llvm::Value *statement_AST::read()
{
    cout << "procedure_call_AST::read_procedure" << endl;
    vector<llvm::Value *> args;
    int index = 4;
    int count = 0;
    for (auto &item : s_variable_list)
    {
        if (item->s_type == "integer")
            index = 4;
        else if (item->s_type == "real")
            index = 5;
        else if (item->s_type == "char")
            index = 6;
        else if (item->s_type == "boolean")
            index = 7;
        llvm::Value *ret = context.builder->CreateCall(context.funcStack[index], args, "read");
        // todo 变量操作
        llvm::Value *addr = nullptr;
        if (item->item->type == 9)
            addr = get_item(item); // 获取数组元素地址
        else
            addr = item->item->value.basic_val->llvmvalue; // 获取变量地址
        context.builder->CreateStore(ret, addr);
        ++count;
    }
    cout<<"read_end"<<endl;
    return nullptr;
}

// 引用
llvm::Value *variable_AST::code_generation()
{
    cout << "variable_AST::code_generation" << endl;
    // 获取左值 item
    SymbolTableItem *item = this->item;
    llvm::Value *addr = nullptr; // 左值变量地址
    if (item->type < 9) // 普通变量
    {
        addr = item->value.basic_val->llvmvalue;
        this->llvmleftValue = addr;
        return context.builder->CreateLoad(addr, false, "");
    }
    else if (item->type == 9) // 数组
    {
        // 获取数组
        addr = get_item(this);
        this->llvmleftValue = addr;
        return context.builder->CreateLoad(addr, false, "");
    }
    return nullptr;
}
// 辅助函数
/**
 * 获取左值
 */
llvm::Value *get_item(variable_AST *var)
{
    cout << "get_item" << endl;
    llvm::Value *base = var->item->value.array_val->llvmvalue; // 数组首地址
    llvm::Value *ret = nullptr;
    SymbolTableItem *item = var->item;
    vector<int> sum;
    int temp = 1;
    for (int i = item->value.array_val->size.size(); i >= 0; --i)
        temp *= item->value.array_val->size[i];
    for (int i = 0; i < item->value.array_val->size.size(); ++i)
    {
        temp /= item->value.array_val->size[i];
        sum.push_back(temp);
    }
    string cur = ""; // 当前维度type
    int len = 0;
    /**
    for (int i = 0; i < var->s_type_list.size(); ++i) // 遍历维度
    {
        cur = var->s_type_list[i];
        ptr = get_array_item(cur, ptr, item->value.array_val->begin[i], var->s_value_list[i]);
    }*/
    for (int i = 0; i < item->value.array_val->size.size(); ++i)
        len += item->value.array_val->size[i];
    // llvm::Type *arrayType = llvm::ArrayType::get(context.type_ir.getLLVMType(item->value.array_val->type), len);
    llvm::Type *arrayType = llvm::ArrayType::get(context.type_ir.getLLVMType(var->s_type), len);
    llvm::Value *head = nullptr;
    llvm::Value *i32zero = llvm::ConstantInt::get(context.type_ir.type_int, 0);
    llvm::Value *indices[var->item->value.array_val->size.size() + 1];
    indices[0] = i32zero;
    for (int i = 0; i < var->item->value.array_val->size.size(); ++i)
    {
        // llvm::Value* offset = nullptr;
        // offset = context.builder->CreateGEP(context.type_ir.getLLVMType(var->s_type),llvm::ConstantInt::get(context.type_ir.type_int,item->value.array_val->begin[i]),var->s_value_list[i]);
        indices[i + 1] = var->s_value_list[i];
        // indices[i+1] = offset;
    }
    base = context.builder->CreateInBoundsGEP(base, llvm::ArrayRef<llvm::Value *>(indices, var->item->value.array_val->size.size() + 1));
    /*
     for (int i = 0; i < var->item->value.array_val->size.size(); ++i)
     {
         head = llvm::ConstantInt::get(context.type_ir.type_int, sum[i], true);
         //base = var->item->value.array_val->llvmvalue;
         base = context.builder->CreateGEP(arrayType, base,{head,var->s_value_list[i]});
     }*/
    // base = context.builder->CreateConstGEP2_32(arrayType,base,0,0);
    return base;
}
/**
 * 获取数组元素指针
 */
llvm::Value *get_array_item(const string &type, llvm::Value *array, int loc, llvm::Value *index)
{
    cout << "get_array_item" << endl;
    llvm::Type *item_type = context.type_ir.getLLVMType(type);
    if (item_type == nullptr)
        return LogErrorV("unknown type");
    auto base = llvm::ConstantInt::get(context.type_ir.type_int, loc);
    llvm::Value *ret = context.builder->CreateGEP(item_type, array, {base, index});
    if (ret == nullptr)
        return LogErrorV("get array item failed");
    return ret;
}

llvm::Value *expressionToBoolean(llvm::Value *value)
{
    if (value->getType()->getTypeID() == llvm::Type::IntegerTyID)
    {
        value = context.builder->CreateIntCast(value, context.type_ir.type_int, true);
        value = context.builder->CreateICmpNE(value, llvm::ConstantInt::get(context.type_ir.type_int, 0));
    }
    else if (value->getType()->getTypeID() == llvm::Type::FloatTyID)
    {
        value = context.builder->CreateFCmpONE(value, llvm::ConstantFP::get(context.llvmContext, llvm::APFloat(0.0)));
    }
    return value;
}

llvm::Value *LogErrorV(string str)
{
    cout << str << endl;
    return nullptr;
}

llvm::Value *LogError(const char *str)
{
    return nullptr;
}

void objectGenerate(string &filename)
{
    cout << "ObjCodeGen" << endl;

    // 初始化llvm，设置目标机
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    // 获取目标三元组并设置
    auto targetTriple = llvm::sys::getDefaultTargetTriple();
    context.module->setTargetTriple(targetTriple);

    // 获取目标机数据类型并设置
    string TargetError;
    auto target = llvm::TargetRegistry::lookupTarget(targetTriple, TargetError);
    if (!target)
    {
        llvm::errs() << TargetError;
        return;
    }
    auto CPU = "generic";
    auto features = "";

    llvm::TargetOptions options;
    auto relocationModel = llvm::Reloc::Model::PIC_;
    auto theTargetMachine = target->createTargetMachine(targetTriple, CPU, features, options, relocationModel);
    context.module->setDataLayout(theTargetMachine->createDataLayout());

    // int outputType = 0;
    llvm::CodeGenFileType type;
    if (filename[filename.size() - 1] == 's')
    { // 生成汇编文件
        type = llvm::CGFT_AssemblyFile;
    }
    else if (filename[filename.size() - 1] == 'o')
    { // 生成目标文件
        type = llvm::CGFT_ObjectFile;
    }
    else
    {
        llvm::errs() << "Unsupported target file format: " + filename;
        return;
    }

    // 将目标代码输出到文件
    error_code ErrCode;
    llvm::raw_fd_ostream dest(filename.c_str(), ErrCode, llvm::sys::fs::OF_None);

    llvm::legacy::PassManager pass;
    if (theTargetMachine->addPassesToEmitFile(pass, dest, &dest, type))
    {
        llvm::errs() << "theTargetMachine can't emit a file of this type";
        return;
    }
    context.module->print(llvm::outs(), nullptr);

    pass.run(*(context.module));
    dest.flush();

    // 打印LLVM IR
}

bool isBasicType(const string &type)
{
    return (type == "integer" | type == "real" | type == "char" | type == "boolean");
}

bool isBasicType(const int &type)
{
    return type >= 5 && type <= 8;
}

llvm::Type *Type_IR::getLLVMType(const string &type)
{
    if (type == "integer")
        return this->type_int;
    if (type == "real")
        return this->type_real;
    if (type == "char")
        return this->type_char;
    if (type == "boolean")
        return this->type_boolean;
    if (type == "void")
        return this->type_void;
    LogErrorV("[getLLVMType]  Unknown type: " + type);
    return nullptr;
}
llvm::Type *Type_IR::getLLVMType(const int &type)
{
    if (type == 5)
        return this->type_int;
    if (type == 6)
        return this->type_real;
    if (type == 7)
        return this->type_boolean;
    if (type == 8)
        return this->type_char;
    LogErrorV("[getLLVMType]  Unknown type: " + type);
    return nullptr;
}

llvm::Type *Type_IR::getArrayLLVMType(SymbolTableItem *item)
{
    string name = "array";
    for (int i = 0; i < item->value.array_val->size.size(); i++)
    {
        name += "_" + to_string(item->value.array_val->begin[i]) + "_" + to_string(item->value.array_val->end[i]);
    }
    if (arrayTypes.find(name) != arrayTypes.end())
        return arrayTypes[name];
    return nullptr;
}

llvm::Type *Type_IR::createArrayType(SymbolTableItem *item)
{
    string name = "array";
    int range = 1;
    for (int i = 0; i < item->value.array_val->size.size(); i++)
    {
        name += "_" + to_string(item->value.array_val->begin[i]) + "_" + to_string(item->value.array_val->end[i]);
        range *= item->value.array_val->size[i];
    }
    llvm::Type *type = context.type_ir.getLLVMType(item->value.array_val->type); // 获取基本类型
    llvm::ArrayType *arrayType = llvm::ArrayType::get(type, range);              // 数组type
    context.type_ir.addArrayType(name, arrayType, item);
    return arrayType;
}

void Type_IR::addArrayType(const string &name, llvm::ArrayType *type, SymbolTableItem *item)
{
    arrayTypes[name] = type;
    arrayTypeList[name] = item->type;
    vector<pair<int, int>> temp;
    for (int i = 0; i < item->value.array_val->size.size(); i++)
        temp.push_back(make_pair(item->value.array_val->begin[i], item->value.array_val->end[i]));
    arrayRangeLists[name] = temp;
}

string Type_IR::getArrayMemberType(const string &name)
{
    SymbolTableItem *item = symbol_table.get(name);
    /**
    if (item == nullptr)
    {
        LogErrorV("Unknown array name: " + name);
        return "";
    }

    if (isBasicType(item->type))
    {
        LogErrorV("Not array name: " + name);
        return "";
    }
    */
    return name;
}


