#define _CRT_SECURE_NO_WARNINGS
//#include "semantic.h"
#include "interface.h"
#include "symbol_table.hpp"
#include <vector>

class SematicAnalysis;
class const_declaration_AST;

extern SymbolTable symbol_table;
extern SematicAnalysis analysis;
using namespace std;

enum ast_type
{
	// 终结符
	PROGRAM, CONST, VAR, PROCEDURE, FUNCTION, BEGIN, END, ARRAY, OF, IF,
	THEN, FOR, TO, DO, READ, WRITE, NOT, ELSE, RANGE, UMINUS,
	ID, RELOP, DIGITS, NUM, VARTYPE, ADDOP, MULOP, ASSIGNOP, SEPARATOR, CHAR,
	BOOLEAN,

	// 非终结符
	programstruct = 100, program_head, program_body, idlist, const_declarations,
	const_declaration, const_value, var_declarations, var_declaration, basic_type,
	type, period, subprogram_declarations, subprogram, subprogram_head,
	formal_parameter, parameter_list, parameter, var_parameter, value_parameter,
	subprogram_body, compound_statement, statement_list, statement, variable_list,
	variable, id_varpart, procedure_call, else_part, term,
	factor, simple_expression, expression_list, expression
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
	ASTNode* father;
	vector<ASTNode*> children;

public:
	ASTNode() {};

	virtual void sematic_action() {};
	virtual void sematic_checking() {};
	virtual Value* code_generation(CodeGenContext& context) {};
};

//终结符
class PROGRAM_AST :public ASTNode
{
public:
	PROGRAM_AST(BitNode* bn)
	{
		type = PROGRAM;
	}
};

class CONST_AST :public ASTNode
{
public:
    string s_value;
	CONST_AST(BitNode* bn)
	{
        this->s_value=bn->data;
		type = CONST;
	}
};

class VAR_AST :public ASTNode
{
public:
    string s_value;
	VAR_AST(BitNode* bn)
	{
		type = VAR;
        this->s_value = bn->data;
	}
};

class PROCEDURE_AST :public ASTNode
{
public:
    string s_value;
	PROCEDURE_AST(BitNode* bn)
	{
		type = PROCEDURE;
        this->s_value = bn->data;
	}
};

class FUNCTION_AST :public ASTNode
{
public:
    string s_value;
	FUNCTION_AST(BitNode* bn)
	{
		type = FUNCTION;
        this->s_value = bn->data;
	}
};

class BEGIN_AST :public ASTNode
{
public:
    string value;
	BEGIN_AST(BitNode* bn)
	{
		type = BEGIN;
        this->value = bn->data;
	}
};

class END_AST :public ASTNode
{
public:
    string value;
	END_AST(BitNode* bn)
	{
		type = END;
        this->value = bn->data;
	}
};

class ARRAY_AST :public ASTNode
{
public:
    string s_value;
	ARRAY_AST(BitNode* bn)
	{
		type = ARRAY;
        this->s_value = bn->data;
	}
};

class OF_AST :public ASTNode
{
public:
    string s_value;
	OF_AST(BitNode* bn)
	{
		type = OF;
        this->s_value = bn->data;
	}
};

class IF_AST :public ASTNode
{
public:
	IF_AST(BitNode* bn)
	{
		type = IF;
	}
};

class THEN_AST :public ASTNode
{
public:
	THEN_AST(BitNode* bn)
	{
		type = THEN;
	}
};

class FOR_AST :public ASTNode
{
public:
	FOR_AST(BitNode* bn)
	{
		type = FOR;
	}
};

class TO_AST :public ASTNode
{
public:

	TO_AST(BitNode* bn)
	{
		type = TO;
	}
};

class DO_AST :public ASTNode
{
public:
	DO_AST(BitNode* bn)
	{
		type = DO;
	}

};

class READ_AST :public ASTNode
{
public:
	READ_AST(BitNode* bn)
	{
		type = READ;
	}
};

class WRITE_AST :public ASTNode
{
public:
	WRITE_AST(BitNode* bn)
	{
		type = WRITE;
	}
};

class NOT_AST :public ASTNode
{
public:
	NOT_AST(BitNode* bn)
	{
		type = NOT;
	}
};

class ELSE_AST :public ASTNode
{
public:
	ELSE_AST(BitNode* bn)
	{
		type = ELSE;
	}
};

class RANGE_AST :public ASTNode
{
public:
    string s_value;
	RANGE_AST(BitNode* bn)
	{
		type = RANGE;//..
        this->s_value = bn->data;
	}
};

class UMINUS_AST :public ASTNode
{
public:
	UMINUS_AST(BitNode* bn)
	{
		type = UMINUS;//-
	}
};

class RELOP_AST :public ASTNode
{
public:
	RELOP_AST(BitNode* bn)
	{
		type = RELOP;//关系运算符
	}
};

class DIGITS_AST :public ASTNode
{
public:
    int s_int;
	DIGITS_AST(BitNode* bn)
	{
		type = DIGITS;
        this->s_int = stoi(bn->data);
	}
};

//s_type 只有real，PPT上的定义有歧义
class NUM_AST :public ASTNode
{
public:
    string s_type;
    double s_real;
	NUM_AST(BitNode* bn)
	{
        type = NUM;
        this->s_type="real";
        this->s_real = stod(bn->data);

//        bool isfloat = false;
//        for (int i = 0; i < bn->data.size(); ++i) {
//            if(bn->data[i]=='.') {
//                isfloat = true;
//                break;
//            }
//        }
//
//        if (isfloat){
//            this->s_real = stod(bn->data);
//            this->s_type="real";
//        }
//        else{
//            this->s_int = stoi(bn->data);
//            this->s_type = "int";
//        }
	}
};

class VARTYPE_AST :public ASTNode
{
public:
    string s_value;
	VARTYPE_AST(BitNode* bn)
	{
		type = VARTYPE;//int real boolean char
        this->s_value = bn->data;
	}
};

class ADDOP_AST :public ASTNode
{
public:
	ADDOP_AST(BitNode* bn)
	{
		type = ADDOP;
	}
};

class MULOP_AST :public ASTNode
{
public:
	MULOP_AST(BitNode* bn)
	{
		type = MULOP;
	}
};

class ASSIGNOP_AST :public ASTNode
{
public:
    string s_value;
	ASSIGNOP_AST(BitNode* bn)
	{
		type = ASSIGNOP;
        this->s_value = bn->data;
	}
};

/// <summary>
/// 完善分隔符类型
/// </summary>
class SEPARATOR_AST :public ASTNode
{
public:
	string value;
	SEPARATOR_AST(BitNode* bn)
	{
		type = SEPARATOR;
		this->value = bn->data;
	}

};

class CHAR_AST :public ASTNode
{
public:
    string s_type;//只能是value
    char s_char;
	CHAR_AST(BitNode* bn)
	{
        type = CHAR;

        if(bn->data=="char")
            s_type="value";
        else{
            s_type="type";
            this->s_char = bn->data[0];
        }

	}

};

class BOOLEAN_AST :public ASTNode
{
public:
	BOOLEAN_AST(BitNode* bn)
	{
		type = BOOLEAN;
	}
};

class ID_AST :public ASTNode
{
public:
	string identifier;

	ID_AST(BitNode* bn)
	{
		type = ID;
		this->identifier = bn->data;
	}
};


//非终结符

class idlist_AST :public ASTNode
{
public:
	vector<string> list;
	idlist_AST(BitNode* bn)
	{
		type = idlist;
	}

	void sematic_action()
	{
		if (this->children.size() == 3)
		{
			idlist_AST* child1 = (idlist_AST*)this->children[0];
			ID_AST* child3 = (ID_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

			this->list = child1->list;
			this->list.push_back(child3->identifier);
		}
		else if (this->children.size() == 1)
		{
			ID_AST* child1 = (ID_AST*)this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

			this->list.push_back(child1->identifier);
		}
		else
			sematic_error();

        sematic_checking();
        code_generation();
	}
};

//Todo:综合属性定义
class program_body_AST :public ASTNode
{
public:
	program_body_AST(BitNode* bn) {
        type = program_body;
    }
    virtual Value* code_generation(CodeGenContext& context);
    void sematic_action() override
    {
        if(this->children.size()==4)
        {
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }
        }
        else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class program_head_AST :public ASTNode
{
public:
	string program_name;
	vector<string> parameters;

	program_head_AST(BitNode* bn)
	{
		type = program_head;
	}

	void sematic_action()
	{
		if (this->children.size() == 6)
		{
            //有综合属性的节点
			ID_AST* ch1 = (ID_AST*)this->children[1];
			idlist_AST* ch3 = (idlist_AST*)this->children[3];

            //父节点继承属性准备

            //获得子节点综合属性
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            //设置父节点综合属性
			this->program_name = ch1->identifier;
			this->parameters = ch3->list;
		}
		else if (this->children.size() == 3)
		{
			ID_AST* ch1 = (ID_AST*)this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

			this->program_name = ch1->identifier;
		}
		else
		{
			cout << "error" << endl;
		}

        this->sematic_checking();
        this->code_generation();


	}

    void sematic_checking() override
    {
        //		symbol_table.insert(this->program_name);
//		for (size_t i = 0; i < this->parameters.size(); i++)
//		{
//			symbol_table.insert(this->parameters[i]);
//		}
    }

};

/// <summary>
/// 这个最大的节点可能什么都不做
/// </summary>
class programstruct_AST :public ASTNode
{
public:
	programstruct_AST(BitNode* bn)
	{
		type = programstruct;
	}

	void sematic_action()
	{
		if (this->children.size() == 3)
		{
			program_head_AST* ch0 = (program_head_AST*)this->children[0];
			program_body_AST* ch1 = (program_body_AST*)this->children[1];
            SEPARATOR_AST* ch2 = (SEPARATOR_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            sematic_checking();
            code_generation();
		}
	}
};

class const_declaration_AST :public ASTNode
{
public:
    vector<pair<string,const_value_AST*>> s_pair_list;
    const_declaration_AST(BitNode* bn)
    {
        type = const_declaration;
    }

    void sematic_action() override
    {
        if(this->children.size()==5)
        {
            const_declaration_AST* ch0 = (const_declaration_AST*) this->children[0];
            ID_AST* ch2 = (ID_AST*)this->children[2];
            const_value_AST* ch4 = (const_value_AST*)this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }
            this->s_pair_list = ch0->s_pair_list;
            this->s_pair_list.push_back(pair<string,const_value_AST*>(ch2->identifier,ch4));
        } else if(this->children.size()==3)
        {
            ID_AST* ch0 = (ID_AST*)this->children[0];
            const_value_AST* ch2 = (const_value_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_pair_list.push_back(pair<string,const_value_AST*>(ch0->identifier,ch2));

        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class const_declarations_AST :public ASTNode
{
public:
    vector<pair<string,const_value_AST*>> s_pair_list;

    const_declarations_AST(BitNode* bn)
    {
        type = const_declarations;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            const_declaration_AST* ch1 = (const_declaration_AST*)this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_pair_list = ch1->s_pair_list;
        } else if (this->children.size()==0)
            ;//do nothing
        else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class const_value_AST :public ASTNode
{
public:
    string s_type;
    int s_integer;
    char s_char;
    bool s_boolean;
    double s_real;
    virtual Value* code_generation(CodeGenContext& context);
    const_value_AST(BitNode* bn)
    {
        type = const_value;
    }

    void sematic_action() override
    {
        if(this->children[0]->type==ADDOP)//生成式1
        {
            NUM_AST* ch1 = (NUM_AST*)this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_type = ch1->s_type;
            this->s_real = ch1->s_real;

        } else if(this->children[0]->type==UMINUS)//生成式2
        {
            NUM_AST* ch1 = (NUM_AST*)this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_type = ch1->s_type;
            this->s_real = -(ch1->s_real);

        } else if(this->children[0]->type==NUM)
        {
            NUM_AST* ch0 = (NUM_AST*)this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_type = ch0->s_type;
            this->s_real = ch0->s_real;
        }
        else if(this->children[0]->type==CHAR)//生成式4
        {
            CHAR_AST* ch0 = (CHAR_AST*)this->children[0];
            this->s_type = ch0->s_type;
            this->s_char = ch0->s_char;
        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }

};

class basic_type_AST :public ASTNode
{
public:
    string s_type;
    basic_type_AST(BitNode* bn)
    {
        type = basic_type;
    }

    void sematic_action() override
    {
        VARTYPE_AST* ch0 = (VARTYPE_AST*) this->children[0];

        //无论使用哪一个归约式，操作都一样
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->sematic_action();
        }

        this->s_type = ch0->s_value;

        sematic_checking();
        code_generation();
    }

};

class period_AST :public ASTNode
{
public:
    vector<pair<int,int>> s_index_list;
    period_AST(BitNode* bn)
    {
        type = period;
    }

    void sematic_action() override
    {
        if(this->children.size()==5)
        {
            period_AST* ch0 = (period_AST*)this->children[0];
            DIGITS_AST* ch2 = (DIGITS_AST*)this->children[2];
            DIGITS_AST* ch4 = (DIGITS_AST*)this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_index_list = ch0->s_index_list;
            this->s_index_list.push_back(pair<int,int>(ch2->s_int,ch4->s_int));
        } else if (this->children.size()==3)
        {
            DIGITS_AST* ch0 = (DIGITS_AST*)this->children[0];
            DIGITS_AST* ch2 = (DIGITS_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_index_list.push_back(pair<int,int>(ch0->s_int,ch2->s_int));
        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class type_AST :public ASTNode
{
public:
    string s_type;//基本类型
    bool l_isarray;
    vector<pair<int,int>> s_index_list;
    virtual Value* code_generation(CodeGenContext& context);
    type_AST(BitNode* bn)
    {
        type = type;
    }

    void sematic_action() override
    {
        if(this->children.size()==1)
        {
            basic_type_AST* ch0 = (basic_type_AST*) this->children[0];

            this->l_isarray = false;

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_type = ch0->s_type;

        } else if(this->children.size()==6)
        {
            period_AST* ch2 = (period_AST*) this->children[2];
            basic_type_AST* ch5 = (basic_type_AST*) this->children[5];

            this->l_isarray = true;

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_index_list = ch2->s_index_list;
            this->s_type = ch5->s_type;

        }else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class var_declaration_AST :public ASTNode
{
public:
    vector<pair<idlist_AST*,type_AST*>> s_id_type_list;
    var_declaration_AST(BitNode* bn)
    {
        type = var_declaration;
    }

    void sematic_action() override
    {
        if(this->children.size()==5)
        {
            var_declaration_AST* ch0 = (var_declaration_AST*) this->children[0];
            idlist_AST* ch2 = (idlist_AST*) this->children[2];
            type_AST* ch4 = (type_AST*) this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_id_type_list = ch0->s_id_type_list;
            this->s_id_type_list.push_back(pair<idlist_AST*,type_AST*>(ch2,ch4));

        } else if(this->children.size()==3)
        {
            idlist_AST* ch0 = (idlist_AST*) this->children[0];
            type_AST* ch2 = (type_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_id_type_list.push_back(pair<idlist_AST*,type_AST*>(ch0,ch2));

        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }


};

class var_declarations_AST :public ASTNode
{
public:
    vector<pair<idlist_AST*,type_AST*>> s_id_type_list;
    var_declarations_AST(BitNode* bn)
    {
        type = var_declarations;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            var_declaration_AST* ch1 = (var_declaration_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_id_type_list = ch1->s_id_type_list;

        } else if (this->children.size()==0)
            ;//do nothing
        else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class value_parameter_AST :public ASTNode
{
public:
    vector<string> s_id_list;
    string s_type;
    value_parameter_AST(BitNode* bn)
    {
        type = value_parameter;
    }

    void sematic_action() override
    {
        //只有一个归约方法
        idlist_AST* ch0 = (idlist_AST*) this->children[0];
        basic_type_AST* ch2 = (basic_type_AST*) this->children[2];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->sematic_action();
        }

        this->s_id_list = ch0->list;
        this->s_type = ch2->s_type;

        sematic_checking();
        code_generation();
    }

};

class var_parameter_AST :public ASTNode
{
public:
    vector<string> s_id_list;
    string s_type;
    var_parameter_AST(BitNode* bn)
    {
        type = var_parameter;
    }

    void sematic_action() override
    {
        //只有一种归约
        value_parameter_AST* ch1 = (value_parameter_AST*) this->children[1];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->sematic_action();
        }

        this->s_id_list = ch1->s_id_list;
        this->s_type = ch1->s_type;
    }

};

class parameter_AST :public ASTNode
{
public:
    bool s_isvar;
    string s_type;
    vector<string> s_id_list;
    parameter_AST(BitNode* bn)
    {
        type = parameter;
    }

    void sematic_action() override
    {
        if(this->children[0]->type==var_parameter)
        {
            var_parameter_AST* ch0 = (var_parameter_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_isvar = true;
            this->s_id_list = ch0->s_id_list;
            this->s_type = ch0->s_type;

        } else if(this->children[0]->type==value_parameter)
        {
            value_parameter_AST* ch0 = (value_parameter_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_isvar = false;
            this->s_id_list = ch0->s_id_list;
            this->s_type = ch0->s_type;

        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class parameter_list_AST :public ASTNode
{

public:
    vector<parameter_AST*> s_list;
    parameter_list_AST(BitNode* bn)
    {
        type = parameter_list;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            parameter_list_AST* ch0 = (parameter_list_AST*) this->children[0];
            parameter_AST* ch1 = (parameter_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_list = ch0->s_list;
            this->s_list.push_back(ch1);
        } else if(this->children.size()==1)
        {
            parameter_AST* ch0 = (parameter_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_list.push_back(ch0);
        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }

};

class formal_parameter_AST :public ASTNode
{
public:
    vector<parameter_AST*> s_list;
    formal_parameter_AST(BitNode* bn)
    {
        type = formal_parameter;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            parameter_list_AST* ch1 = (parameter_list_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_list = ch1->s_list;
        }else if(this->children.size()==0)
        {
            ;//do nothing
        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class subprogram_head_AST :public ASTNode
{
public:
    bool s_isfunction;
    string s_ret_type;
    vector<parameter_AST*> s_list;

    subprogram_head_AST(BitNode* bn)
    {
        type = subprogram_head;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            formal_parameter_AST* ch2 = (formal_parameter_AST*) this->children[2];
            basic_type_AST* ch4 = (basic_type_AST*) this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_isfunction = true;
            this->s_ret_type = ch4->s_type;
            this->s_list = ch2->s_list;

        } else if(this->children.size()==5)
        {
            formal_parameter_AST* ch2 = (formal_parameter_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_isfunction = false;
            this->s_list = ch2->s_list;
        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }

};

class subprogram_body_AST :public ASTNode
{
public:
    virtual Value* code_generation(CodeGenContext& context);
    subprogram_body_AST(BitNode* bn)
    {
        type = subprogram_body;
    }

};

class subprogram_AST :public ASTNode
{
    subprogram_head_AST* s_sub_head;
    subprogram_body_AST* s_sub_body;
public:
    subprogram_AST(BitNode* bn)
    {
        type = subprogram;
    }

    void sematic_action() override
    {
        //仅一种生成式
        subprogram_head_AST* ch0 = (subprogram_head_AST*) this->children[0];
        subprogram_body_AST* ch2 = (subprogram_body_AST*) this->children[2];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->sematic_action();
        }

        this->s_sub_head = ch0;
        this->s_sub_body = ch2;

        sematic_checking();
        code_generation();
    }

};

class subprogram_declarations_AST :public ASTNode
{

public:
    vector<subprogram_AST*> s_subprogram_list;
    subprogram_declarations_AST(BitNode* bn)
    {
        type = subprogram_declarations;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            subprogram_declarations_AST* ch0 = (subprogram_declarations_AST*) this->children[0];
            subprogram_AST* ch1 = (subprogram_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }

            this->s_subprogram_list = ch0->s_subprogram_list;
            this->s_subprogram_list.push_back(ch1);
        } else if (this->children.size()==0)
            ;//do nothing
        else
            sematic_error();

        sematic_checking();
        code_generation();
    }

};

class compound_statement_AST :public ASTNode
{
public:
    compound_statement_AST(BitNode* bn)
    {
        type = compound_statement;
    }

    void sematic_action() override
    {
        if(this->children.size()==3)
        {
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->sematic_action();
            }
        }
        else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class statement_list_AST :public ASTNode
{
public:
    statement_list_AST(BitNode* bn)
    {
        type = statement_list;
    }

};

class statement_AST :public ASTNode
{
public:
    statement_AST(BitNode* bn)
    {
        type = statement;
    }

    void sematic_action() override
    {
        if(this->children.size()==0)
        {
            ;//do nothing
        }
    }

};

class variable_list_AST :public ASTNode
{
public:
    variable_list_AST(BitNode* bn)
    {
        type = variable_list;
    }

};

class variable_AST :public ASTNode
{
public:
    virtual Value* code_generation(CodeGenContext& context);
    bool is_array;
    variable_AST(BitNode* bn)
    {
        type = variable;
    }

};

class id_varpart_AST :public ASTNode
{
public:
    id_varpart_AST(BitNode* bn)
    {
        type = id_varpart;
    }
};

class procedure_call_AST :public ASTNode
{
public:
    virtual Value* code_generation(CodeGenContext& context);
    vector<expression_AST*> s_list;//参数列表
    Value* write(CodeGenContext& context,int args[]);
    Value* read(CodeGenContext& context,int args[]);
    procedure_call_AST(BitNode* bn)
    {
        type = procedure_call;
    }

};

class else_part_AST :public ASTNode
{
public:
    else_part_AST(BitNode* bn)
    {
        type = else_part;
    }

};

class term_AST :public ASTNode
{
public:
    term_AST(BitNode* bn)
    {
        type = term;
    }

};

class factor_AST :public ASTNode
{
public:
    bool l_is_left_value;
    bool s_is_array;//如果是左值才有意义
    bool s_is_var;//如果是左值才有意义

    string s_type;//real,int,bool,char
    double s_real;
    int s_int;
    char s_char;
    bool s_bool;

    factor_AST(BitNode* bn)
    {
        type = factor;
    }

    void sematic_action() override
    {
        if(this->children[0]->type==NUM)
        {
            NUM_AST* ch0 = (NUM_AST*) this->children[0];
            this->l_is_left_value = false;

            ch0->sematic_action();

            this->s_type = ch0->s_type;
            this->s_real = ch0->s_real;
        }else if(this->children[0]->type==variable)
        {
            //todo:variable未编写
        }else if(this->children[0]->type==ID)
        {
            //todo:函数调用未编写
        }else if(this->children[0]->type==SEPARATOR)
        {
            //todo
        }else if(this->children[0]->type==NOT)
        {
            //todo
        }else if(this->children[0]->type==UMINUS)
        {
            //todo
        } else
            sematic_error();

        sematic_checking();
        code_generation();
    }
};

class simple_expression_AST :public ASTNode
{
public:
    simple_expression_AST(BitNode* bn)
    {
        type = simple_expression;
    }

};

class expression_list_AST :public ASTNode
{
public:
    expression_list_AST(BitNode* bn)
    {
        type = expression_list;
    }

};

class expression_AST :public ASTNode
{
public:
    Value* value = nullptr;
    expression_AST(BitNode* bn)
    {
        type = expression;
    }

};

class SematicAnalysis
{
public:
	SematicAnalysis() {};


	ASTNode* create_ASTNode(BitNode* bn)
	{
		ASTNode* nodeptr = NULL;

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


//
//
//
//		if (bn->type == "programstruct")
//			nodeptr = new programstruct_AST(bn);
//		else if (bn->type == "program_head")
//			nodeptr = new program_head_AST(bn);
//		else if (bn->type == "program_body")
//			nodeptr = new program_body_AST(bn);
//		else if (bn->type == "PROGRAM")
//			nodeptr = new PROGRAM_AST(bn);
//		else if (bn->type == "ID")
//			nodeptr = new ID_AST(bn);
//		else if (bn->type == "SEPARATOR")
//			nodeptr = new SEPARATOR_AST(bn);
//		else if (bn->type == "idlist")
//			nodeptr = new idlist_AST(bn);
//
//        else if (bn->type == "")
//            nodeptr = new (bn);

		return nodeptr;

	}

	/*
	* 采用算法5.4先序遍历
	*/
	ASTNode* analyze(ASTNode* root)
	{

	}

	ASTNode* ADT2AST(BitNode* bn)
	{
		//父节点动作
		ASTNode* cur_node = create_ASTNode(bn);
		int n = bn->children.size();
		//子节点遍历
		for (size_t i = 0; i < n; i++)
		{
			ASTNode* child = ADT2AST(bn->children[i]);
			cur_node->children.push_back(child);
			child->father = cur_node;
		}
		return cur_node;
	}
private:


};

