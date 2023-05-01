#include "interface.h"
#include "symbol_table.hpp"
#include <vector>

class SematicAnalysis;
class const_declaration_AST;
class expression_AST;
class expression_list_AST;
class variable_AST;

extern SymbolTable symbol_table;
extern SematicAnalysis analysis;
using namespace std;



//4.26���£�
/*

 */

enum ast_type
{
	// �ս��
	PROGRAM, CONST, VAR, PROCEDURE, FUNCTION, BEGIN, END, ARRAY, OF, IF,
	THEN, FOR, TO, DO, READ, WRITE, NOT, ELSE, RANGE, UMINUS,
	ID, RELOP, DIGITS, NUM, VARTYPE, ADDOP, MULOP, ASSIGNOP, SEPARATOR, CHAR,
	BOOLEAN,WHILE,

	// ���ս��
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

class SemanticError
{
public:
    SemanticError(){};

    SemanticError(int line,int col,string error_type = "",string info = "")
    {
        this->line = line;
        this->col= col;
        this->error_type = error_type;
        this->error_info = info;
    }
public:
    int line;
    int col;
    string error_type;
    string error_info;

};

vector<SemanticError*> semantic_error_list;

void printErrorList()
{
    //todo:sort
    for (int i = 0; i < semantic_error_list.size(); ++i) {
        int line = semantic_error_list[i]->line;
        int col = semantic_error_list[i]->col;
        string error_type = semantic_error_list[i]->error_type;
        string error_info = semantic_error_list[i]->error_info;
        cout << "Semantic Error! line:"<<line<<" "<<"col:"<<col<<" "<<error_type << ":"<<error_info<<";"<< endl;
    }
}


class ASTNode
{
public:
	ast_type type;
	ASTNode* father;
	vector<ASTNode*> children;
    int line;
    int col;

    //��������Ϣ
    string pascal_info;
    void pascal_info_cat()
    {
        for (int i = 0; i < this->children.size(); ++i) {
            this->pascal_info += this->children[i]->pascal_info + " ";
        }
    }

public:
	ASTNode() {};

    void get_line_col(BitNode* bn)
    {
        this->line = bn->line;
        this->col = bn->col;
    }
    void get_line_col(ASTNode* ch)
    {
        this->line = ch->line;
        this->col = ch->col;
    }
	virtual void semantic_action() {};
	virtual void semantic_checking() {};
	virtual llvm::Value *code_generation() {return NULL;};
};

//�ս��
class WHILE_AST :public ASTNode
{
public:
    WHILE_AST(BitNode* bn)
    {
        type = WHILE;
        pascal_info = bn->data;
        get_line_col(bn);
    }
};

class PROGRAM_AST :public ASTNode
{
public:
	PROGRAM_AST(BitNode* bn)
	{
		type = PROGRAM;
        pascal_info = bn->data;
	}
};

class CONST_AST :public ASTNode
{
public:
    string s_value;
	CONST_AST(BitNode* bn)
	{
        pascal_info = bn->data;
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
        pascal_info = bn->data;
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
        pascal_info = bn->data;
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
        pascal_info = bn->data;
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
        pascal_info = bn->data;
		type = BEGIN;
        this->value = bn->data;
        get_line_col(bn);
	}

};

class END_AST :public ASTNode
{
public:
    string value;
	END_AST(BitNode* bn)
	{
        pascal_info = bn->data;
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
        pascal_info = bn->data;
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
        pascal_info = bn->data;
		type = OF;
        this->s_value = bn->data;
	}

};

class IF_AST :public ASTNode
{
public:
	IF_AST(BitNode* bn)
	{
        pascal_info = bn->data;
        get_line_col(bn);
		type = IF;
	}

};

class THEN_AST :public ASTNode
{
public:
	THEN_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = THEN;
	}

};

class FOR_AST :public ASTNode
{
public:
	FOR_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = FOR;
        get_line_col(bn);
	}

};

class TO_AST :public ASTNode
{
public:

	TO_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = TO;
	}

};

class DO_AST :public ASTNode
{
public:
    DO_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = DO;
	}

};

class READ_AST :public ASTNode
{
public:
	READ_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = READ;
        get_line_col(bn);
	}

};

class WRITE_AST :public ASTNode
{
public:
	WRITE_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = WRITE;
        get_line_col(bn);
	}

};

class NOT_AST :public ASTNode
{
public:
	NOT_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = NOT;
	}

};

class ELSE_AST :public ASTNode
{
public:
	ELSE_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = ELSE;
	}

};

class RANGE_AST :public ASTNode
{
public:
    string s_value;
	RANGE_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = RANGE;//..
        this->s_value = bn->data;
	}

};

class UMINUS_AST :public ASTNode
{
public:
    string s_value;
	UMINUS_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = UMINUS;//-
        this->s_value = bn->data;//todo:��������Ƿ�һ��
	}

};

class RELOP_AST :public ASTNode
{
public:
    string s_value;
	RELOP_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = RELOP;//��ϵ�����
        this->s_value = bn->data;//todo:����Ƿ����s
    }

};

class DIGITS_AST :public ASTNode
{
public:
    string s_type;
    int s_int;
	DIGITS_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = DIGITS;
        this->s_type = "integer";
        this->s_int = stoi(bn->data);
	}

};

//s_type ֻ��real��PPT�ϵĶ���������
class NUM_AST :public ASTNode
{
public:
    string s_type;
    double s_real;
	NUM_AST(BitNode* bn)
	{
        pascal_info = bn->data;
        type = NUM;
        this->s_type="real";
        this->s_real = stod(bn->data);
	}

};

class VARTYPE_AST :public ASTNode
{
public:
    string s_value;
	VARTYPE_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = VARTYPE;//todo:integer real boolean char
        this->s_value = bn->data;
	}

};

class ADDOP_AST :public ASTNode
{
public:
    string s_value;
	ADDOP_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = ADDOP;
        this->s_value = bn->data;//todo:��������Ƿ�һ��(OK)
        get_line_col(bn);
	}

};

class MULOP_AST :public ASTNode
{
public:
    string s_value;
	MULOP_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = MULOP;
        this->s_value = bn->data;//todo������﷨�����������ַ����Ƿ����������������ͬ������ͬ���ڴ��޸�
	}

};

class ASSIGNOP_AST :public ASTNode
{
public:
    string s_value;
	ASSIGNOP_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = ASSIGNOP;
        this->s_value = bn->data;
	}

};


class SEPARATOR_AST :public ASTNode
{
public:
	string value;
	SEPARATOR_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = SEPARATOR;
		this->value = bn->data;
	}

};

class CHAR_AST :public ASTNode
{
public:
    string s_type;//ֻ����value
    char s_char;
	CHAR_AST(BitNode* bn)
	{
        pascal_info = bn->data;
        type = CHAR;
        s_type="char";
        this->s_char = bn->data[0];
	}

};

class BOOLEAN_AST :public ASTNode
{
public:
    bool s_bool;
    string s_type;
	BOOLEAN_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = BOOLEAN;
        this->s_type = "boolean";
        if(bn->data=="true")
            this->s_bool = true;
        else
            this->s_bool = false;
	}

};

class ID_AST :public ASTNode
{
public:
	string identifier;

	ID_AST(BitNode* bn)
	{
        pascal_info = bn->data;
		type = ID;
		this->identifier = bn->data;
        get_line_col(bn);
	}

};


//���ս��

class idlist_AST :public ASTNode
{
public:
	vector<string> list;
    vector<ID_AST*> s_id_ast_list;
	idlist_AST(BitNode* bn)
	{
		type = idlist;
	}

	void semantic_action()
	{
		if (this->children.size() == 3)
		{
			idlist_AST* child1 = (idlist_AST*)this->children[0];
			ID_AST* child3 = (ID_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

			this->list = child1->list;
            this->s_id_ast_list = child1->s_id_ast_list;
			this->list.push_back(child3->identifier);
            this->s_id_ast_list.push_back(child3);
		}
		else if (this->children.size() == 1)
		{
			ID_AST* child1 = (ID_AST*)this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

			this->list.push_back(child1->identifier);
            this->s_id_ast_list.push_back(child1);
		}
		else
			sematic_error();

        pascal_info_cat();
        semantic_checking();
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


	void semantic_action()
	{
		if (this->children.size() == 6)
		{
            //���ۺ����ԵĽڵ�
			ID_AST* ch1 = (ID_AST*)this->children[1];
			idlist_AST* ch3 = (idlist_AST*)this->children[3];

            //���ڵ�̳�����׼��

            //����ӽڵ��ۺ�����
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            //���ø��ڵ��ۺ�����
			this->program_name = ch1->identifier;
			this->parameters = ch3->list;
		}
		else if (this->children.size() == 3)
		{
			ID_AST* ch1 = (ID_AST*)this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

			this->program_name = ch1->identifier;
		}
		else
		{
			cout << "error" << endl;
		}

        //���÷��ű�������
        symbol_table.main_function = this->program_name;
        symbol_table.cur_function = this->program_name;
        //������ͷ��ű�������
        //�������
        for (int i = 0; i < parameters.size(); ++i) {
            if(false == symbol_table.insert(parameters[i]))
            {
                //����ѭ������Ϊ��
                ID_AST* id = ((idlist_AST*)this->children[3])->s_id_ast_list[i];
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "Duplicate definition",
                                                       "identifier '"+id->identifier+"' used more than once");
                semantic_error_list.push_back(err);
            }

        }
        //���뺯����
        symbol_value value;
        value.function_val = new MyFunctionType();
        value.function_val->arg_name_list = parameters;
        SymbolTableItem* item = new SymbolTableItem(this->program_name,procedure,value);
        if(false == symbol_table.insert(item))
        {
            //����ѭ������Ϊ��
            ID_AST* id = (ID_AST*)this->children[1];
            SemanticError* err = new SemanticError(id->line,id->col,
                                                   "Duplicate definition",
                                                   "identifier '"+id->identifier+"' used more than once");
            semantic_error_list.push_back(err);
        }

        pascal_info_cat();
        this->code_generation();
	}


};

/// <summary>
/// ������Ľڵ����ʲô������
/// </summary>


class const_declaration_AST :public ASTNode
{
public:
    vector<pair<string,const_value_AST*>> s_pair_list;
    vector<ID_AST*> s_id_AST_list;
    const_declaration_AST(BitNode* bn)
    {
        type = const_declaration;
    }


    void semantic_action() override
    {
        if(this->children.size()==5)
        {
            const_declaration_AST* ch0 = (const_declaration_AST*) this->children[0];
            ID_AST* ch2 = (ID_AST*)this->children[2];
            const_value_AST* ch4 = (const_value_AST*)this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_pair_list = ch0->s_pair_list;
            this->s_id_AST_list = ch0->s_id_AST_list;
            this->s_pair_list.push_back(pair<string,const_value_AST*>(ch2->identifier,ch4));
            this->s_id_AST_list.push_back(ch2);
        } else if(this->children.size()==3)
        {
            ID_AST* ch0 = (ID_AST*)this->children[0];
            const_value_AST* ch2 = (const_value_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_pair_list.push_back(pair<string,const_value_AST*>(ch0->identifier,ch2));
            this->s_id_AST_list.push_back(ch0);
        } else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class const_value_AST :public ASTNode
{
public:
    string s_type;
    int s_int;
    char s_char;
    double s_real;
    bool s_bool;
    const_value_AST(BitNode* bn)
    {
        type = const_value;
    }


    void semantic_action() override
    {
        if(this->children[0]->type==ADDOP)//����ʽ1
        {

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            if (this->children[1]->type==NUM)
            {
                NUM_AST* ch1 = (NUM_AST*)this->children[1];
                this->s_type = ch1->s_type;
                this->s_real = ch1->s_real;
            }
            else if(this->children[1]->type==DIGITS)
            {
                DIGITS_AST* ch1 = (DIGITS_AST*) this->children[1];
                this->s_type = ch1->s_type;
                this->s_int = ch1->s_int;
            } else
                sematic_error();

        } else if(this->children[0]->type==UMINUS)//����ʽ2
        {
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            if (this->children[1]->type==NUM)
            {
                NUM_AST* ch1 = (NUM_AST*)this->children[1];
                this->s_type = ch1->s_type;
                this->s_real = -(ch1->s_real);
            }
            else if(this->children[1]->type==DIGITS)
            {
                DIGITS_AST* ch1 = (DIGITS_AST*) this->children[1];
                this->s_type = ch1->s_type;
                this->s_int = -(ch1->s_int);
            } else
                sematic_error();

        } else if(this->children[0]->type==NUM)
        {
            NUM_AST* ch0 = (NUM_AST*)this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_type = ch0->s_type;
            this->s_real = ch0->s_real;
        }
        else if(this->children[0]->type==CHAR)//����ʽ4
        {
            CHAR_AST* ch0 = (CHAR_AST*)this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_char = ch0->s_char;
        } else if(this->children[0]->type==DIGITS)
        {
            DIGITS_AST* ch0 = (DIGITS_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_int = ch0->s_int;
        }else if(this->children[0]->type==BOOLEAN)
        {
            BOOLEAN_AST* ch0 = (BOOLEAN_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_bool = ch0->s_bool;
        }
        sematic_error();
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }

    void semantic_checking() override
    {
        if (this->children[0]->type==ADDOP)
        {
            ADDOP_AST* ch0 = (ADDOP_AST*)this->children[0];
            if (ch0->s_value!="+")
            {
                semantic_error_list.push_back(new SemanticError(ch0->line, ch0->col,
                                                                "operator type error",
                                                                "only '+' or '-' can be used in const declaration"));
            }
        }
    }

};

class const_declarations_AST :public ASTNode
{
public:
    vector<pair<string,const_value_AST*>> s_pair_list;
    vector<ID_AST*> s_id_AST_list;

    const_declarations_AST(BitNode* bn)
    {
        type = const_declarations;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            const_declaration_AST* ch1 = (const_declaration_AST*)this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_pair_list = ch1->s_pair_list;
            this->s_id_AST_list = ch1->s_id_AST_list;

            //������ͷ��ű�������
            //�������
            for (int i = 0; i < s_pair_list.size(); ++i)
            {
                SymbolTableItem* item = new SymbolTableItem(s_pair_list[i].first);
                MyBasicType* value = new MyBasicType();
                item->value.basic_val = value;

                if (s_pair_list[i].second->s_type=="integer")
                {
                    item->type = const_int;
                    value->value.int_val = s_pair_list[i].second->s_int;
                } else if(s_pair_list[i].second->s_type=="real")
                {
                    item->type = const_real;
                    value->value.real_val = s_pair_list[i].second->s_real;
                } else if(s_pair_list[i].second->s_type=="boolean")
                {
                    item->type = const_bool;
                    value->value.bool_val = s_pair_list[i].second->s_bool;
                } else//char
                {
                    item->type = const_char;
                    value->value.char_val = s_pair_list[i].second->s_char;
                }

                if(false == symbol_table.insert(item))
                {
                    //����ѭ������Ϊ��
                    ID_AST* id = s_id_AST_list[i];
                    SemanticError* err = new SemanticError(id->line,id->col,
                                                           "Duplicate definition",
                                                           "identifier '"+id->identifier+"' used more than once");
                    semantic_error_list.push_back(err);
                }

            }

        } else if (this->children.size()==0)
            ;//do nothing
        else
            sematic_error();

        pascal_info_cat();
        //semantic_checking();
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


    void semantic_action() override
    {
        VARTYPE_AST* ch0 = (VARTYPE_AST*) this->children[0];

        //����ʹ����һ����Լʽ��������һ��
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }

        this->s_type = ch0->s_value;
        pascal_info_cat();
        semantic_checking();
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


    void semantic_action() override
    {
        if(this->children.size()==5)
        {
            period_AST* ch0 = (period_AST*)this->children[0];
            DIGITS_AST* ch2 = (DIGITS_AST*)this->children[2];
            DIGITS_AST* ch4 = (DIGITS_AST*)this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_index_list = ch0->s_index_list;
            this->s_index_list.push_back(pair<int,int>(ch2->s_int,ch4->s_int));
        } else if (this->children.size()==3)
        {
            DIGITS_AST* ch0 = (DIGITS_AST*)this->children[0];
            DIGITS_AST* ch2 = (DIGITS_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_index_list.push_back(pair<int,int>(ch0->s_int,ch2->s_int));
        } else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class type_AST :public ASTNode
{
public:
    string s_type;//��������
    bool l_isarray;
    vector<pair<int,int>> s_index_list;

    type_AST(BitNode* bn)
    {
        type = type;
    }


    void semantic_action() override
    {
        if(this->children.size()==1)
        {
            basic_type_AST* ch0 = (basic_type_AST*) this->children[0];

            this->l_isarray = false;

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_type = ch0->s_type;

        } else if(this->children.size()==6)
        {
            period_AST* ch2 = (period_AST*) this->children[2];
            basic_type_AST* ch5 = (basic_type_AST*) this->children[5];

            this->l_isarray = true;

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_index_list = ch2->s_index_list;
            this->s_type = ch5->s_type;

        }else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
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


    void semantic_action() override
    {
        if(this->children.size()==5)
        {
            var_declaration_AST* ch0 = (var_declaration_AST*) this->children[0];
            idlist_AST* ch2 = (idlist_AST*) this->children[2];
            type_AST* ch4 = (type_AST*) this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_id_type_list = ch0->s_id_type_list;
            this->s_id_type_list.push_back(pair<idlist_AST*,type_AST*>(ch2,ch4));

        } else if(this->children.size()==3)
        {
            idlist_AST* ch0 = (idlist_AST*) this->children[0];
            type_AST* ch2 = (type_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_id_type_list.push_back(pair<idlist_AST*,type_AST*>(ch0,ch2));

        } else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }


};

class var_declarations_AST :public ASTNode
{
public:
    bool l_isglobal;//��ʾ�������������ȫ�ֱ��������Ӻ�������ľֲ�����
    vector<pair<idlist_AST*,type_AST*>> s_id_type_list;
    var_declarations_AST(BitNode* bn)
    {
        type = var_declarations;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            var_declaration_AST* ch1 = (var_declaration_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_id_type_list = ch1->s_id_type_list;

            //������ͷ��ű�������
            //�������
            for (int i = 0; i < s_id_type_list.size(); ++i)
            {
                for (int j = 0; j < s_id_type_list[i].first->s_id_ast_list.size(); ++j)
                {
                    ID_AST* idAst = s_id_type_list[i].first->s_id_ast_list[j];
                    SymbolTableItem* item = new SymbolTableItem(idAst->identifier);
                    symbol_type idtype;

                    if (s_id_type_list[i].second->s_type =="integer")
                        idtype = var_int;
                    else if(s_id_type_list[i].second->s_type=="real")
                        idtype = var_real;
                    else if(s_id_type_list[i].second->s_type=="boolean")
                        idtype = var_bool;
                    else//char
                        idtype = var_char;

                    if (s_id_type_list[i].second->l_isarray)
                    {
                        int dimension = s_id_type_list[i].second->s_index_list.size();
                        vector<int> begin;
                        vector<int> end;
                        for (int k = 0; k < dimension; ++k) {
                            int a = s_id_type_list[i].second->s_index_list[k].first;
                            int b = s_id_type_list[i].second->s_index_list[k].second;
                            begin.push_back(a);
                            end.push_back(b);
                            if(a>b)
                            {
                                begin[k] = 0;
                                end[k] = 0;
                                ID_AST* id = s_id_type_list[i].first->s_id_ast_list[j];
                                SemanticError* err = new SemanticError(id->line,id->col,
                                                                       "Array range error",
                                                                       "identifier '"+id->identifier+"' array[a..b],a>b");
                                semantic_error_list.push_back(err);
                            }
                        }
                        MyArrayType* value = new MyArrayType(begin,end,idtype);
                        item->value.array_val = value;
                        item->type = array_type;
                    } else
                    {
                        MyBasicType* value = new MyBasicType();
                        item->value.basic_val = value;
                        item->type = idtype;
                    }


                    if(false == symbol_table.insert(item))
                    {
                        //����ѭ������Ϊ��
                        ID_AST* id = s_id_type_list[i].first->s_id_ast_list[j];
                        SemanticError* err = new SemanticError(id->line,id->col,
                                                               "Duplicate definition",
                                                               "identifier '"+id->identifier+"' used more than once");
                        semantic_error_list.push_back(err);
                    }
                }

            }
        } else if (this->children.size()==0)
            ;//do nothing
        else
            sematic_error();
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class program_body_AST :public ASTNode
{
public:
    program_body_AST(BitNode* bn) {
        type = program_body;
    }


    void semantic_action() override
    {
        if(this->children.size()==4)
        {
            var_declarations_AST* ch1 = (var_declarations_AST*)this->children[1];
            ch1->l_isglobal = true;

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
        }
        else
            sematic_error();

        get_line_col(this->children[3]);
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class programstruct_AST :public ASTNode
{
public:
    programstruct_AST(BitNode* bn)
    {
        type = programstruct;
    }
    //virtual llvm::Value *code_generation() override;//todo:��ֳɶಽ����

    void semantic_action()
    {
        if (this->children.size() == 3)
        {
            program_head_AST* ch0 = (program_head_AST*)this->children[0];
            program_body_AST* ch1 = (program_body_AST*)this->children[1];
            SEPARATOR_AST* ch2 = (SEPARATOR_AST*)this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            pascal_info_cat();
            semantic_checking();
            code_generation();
        }
    }
};












class value_parameter_AST :public ASTNode
{
public:
    vector<string> s_id_list;
    vector<ID_AST*> s_id_ast_list;
    string s_type;
    value_parameter_AST(BitNode* bn)
    {
        type = value_parameter;
    }


    void semantic_action() override
    {
        //ֻ��һ����Լ����
        idlist_AST* ch0 = (idlist_AST*) this->children[0];
        basic_type_AST* ch2 = (basic_type_AST*) this->children[2];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }

        this->s_id_list = ch0->list;
        this->s_type = ch2->s_type;
        this->s_id_ast_list = ch0->s_id_ast_list;
        pascal_info_cat();
        semantic_checking();
        code_generation();
    }

};

class var_parameter_AST :public ASTNode
{
public:
    vector<string> s_id_list;
    vector<ID_AST*> s_id_ast_list;
    string s_type;
    var_parameter_AST(BitNode* bn)
    {
        type = var_parameter;
    }


    void semantic_action() override
    {
        //ֻ��һ�ֹ�Լ
        value_parameter_AST* ch1 = (value_parameter_AST*) this->children[1];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }

        this->s_id_list = ch1->s_id_list;
        this->s_id_ast_list = ch1->s_id_ast_list;
        this->s_type = ch1->s_type;

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }


};

class parameter_AST :public ASTNode
{
public:
    bool s_isvar;
    string s_type;
    vector<string> s_id_list;
    vector<ID_AST*> s_id_ast_list;
    parameter_AST(BitNode* bn)
    {
        type = parameter;
    }


    void semantic_action() override
    {
        if(this->children[0]->type==var_parameter)
        {
            var_parameter_AST* ch0 = (var_parameter_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_isvar = true;
            this->s_id_list = ch0->s_id_list;
            this->s_id_ast_list = ch0->s_id_ast_list;
            this->s_type = ch0->s_type;

        } else if(this->children[0]->type==value_parameter)
        {
            value_parameter_AST* ch0 = (value_parameter_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_isvar = false;
            this->s_id_list = ch0->s_id_list;
            this->s_id_ast_list = ch0->s_id_ast_list;
            this->s_type = ch0->s_type;

        } else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
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


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            parameter_list_AST* ch0 = (parameter_list_AST*) this->children[0];
            parameter_AST* ch2 = (parameter_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_list = ch0->s_list;
            this->s_list.push_back(ch2);
        } else if(this->children.size()==1)
        {
            parameter_AST* ch0 = (parameter_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_list.push_back(ch0);
        } else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
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


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            parameter_list_AST* ch1 = (parameter_list_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_list = ch1->s_list;
        }else if(this->children.size()==0)
        {
            ;//do nothing
        } else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class subprogram_head_AST :public ASTNode
{
public:
    bool s_isfunction;
    string s_ret_type;//�����Ǻ���ʱ�з���ֵ����
    string program_name;
    vector<parameter_AST*> s_list;

    subprogram_head_AST(BitNode* bn)
    {
        type = subprogram_head;
    }


    void semantic_action() override
    {
        if(this->children.size()==5)
        {
            ID_AST* ch1 = (ID_AST*) this->children[1];
            formal_parameter_AST* ch2 = (formal_parameter_AST*) this->children[2];
            basic_type_AST* ch4 = (basic_type_AST*) this->children[4];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->program_name = ch1->identifier;
            this->s_isfunction = true;
            this->s_ret_type = ch4->s_type;
            this->s_list = ch2->s_list;

        } else if(this->children.size()==3)
        {
            ID_AST* ch1 = (ID_AST*) this->children[1];
            formal_parameter_AST* ch2 = (formal_parameter_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->program_name = ch1->identifier;
            this->s_isfunction = false;
            this->s_list = ch2->s_list;
        } else
            sematic_error();

        //���뺯����
        symbol_value value;
        MyFunctionType* functionType = new MyFunctionType(&symbol_table);
        value.function_val = functionType;
        SymbolTableItem* item = new SymbolTableItem(this->program_name,s_isfunction?function:procedure,value);
        functionType->isfunction = this->s_isfunction;
        if (s_isfunction)
        {
            functionType->ret_type = this->s_ret_type;
        }
        if(false == symbol_table.insert(item))
        {
            //����ѭ������Ϊ��
            ID_AST* id = (ID_AST*)this->children[1];
            SemanticError* err = new SemanticError(id->line,id->col,
                                                   "Duplicate definition",
                                                   "identifier '"+id->identifier+"' used more than once");
            semantic_error_list.push_back(err);
        }

        //���ű��ض���
        //���÷��ű��ӱ�����
        symbol_table.cur_function = this->program_name;
        //������ͷ��ű�������
        //�������
        int count = 0;
        for (int i = 0; i < this->s_list.size(); ++i)
        {
            for (int j = 0; j < s_list[i]->s_id_list.size(); ++j)
            {
                ID_AST* idAst = s_list[i]->s_id_ast_list[j];
                SymbolTableItem* item = new SymbolTableItem(idAst->identifier);
                symbol_type idtype;

                if (s_list[i]->s_type =="integer")
                    idtype = var_int;
                else if(s_list[i]->s_type =="real")
                    idtype = var_real;
                else if(s_list[i]->s_type == "boolean")
                    idtype = var_bool;
                else//char
                    idtype = var_char;

                //�������Ͳ�����array
                MyBasicType* value = new MyBasicType();
                item->value.basic_val = value;
                item->type = idtype;

                //��¼����������Ϣ
                functionType->arg_name_list.push_back(idAst->identifier);
                functionType->arg_type_list.push_back(this->s_list[i]->s_type);
                functionType->arg_isvar_list.push_back(this->s_list[i]->s_isvar);


                //������ű�����Ƿ�����
                if(false == symbol_table.insert(item))
                {
                    ID_AST* id = idAst;
                    SemanticError* err = new SemanticError(id->line,id->col,
                                                           "Duplicate definition",
                                                           "identifier '"+id->identifier+"' used more than once");
                    semantic_error_list.push_back(err);
                }
            }

        }

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }

};

class subprogram_body_AST :public ASTNode
{
public:
    subprogram_body_AST(BitNode* bn)
    {
        type = subprogram_body;
    }


    void semantic_action() override
    {
        var_declarations_AST* ch1 = (var_declarations_AST*)this->children[1];
        ch1->l_isglobal = false;
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        get_line_col(this->children[2]);

        pascal_info_cat();
        semantic_checking();
        code_generation();
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


    void semantic_action() override
    {
        //��һ������ʽ
        subprogram_head_AST* ch0 = (subprogram_head_AST*) this->children[0];
        subprogram_body_AST* ch2 = (subprogram_body_AST*) this->children[2];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }

        //�Ӻ����˳������ű��ض�λ�������ű�
        symbol_table.cur_function = symbol_table.main_function;

        this->s_sub_head = ch0;
        this->s_sub_body = ch2;

        pascal_info_cat();
        semantic_checking();
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


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            subprogram_declarations_AST* ch0 = (subprogram_declarations_AST*) this->children[0];
            subprogram_AST* ch1 = (subprogram_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_subprogram_list = ch0->s_subprogram_list;
            this->s_subprogram_list.push_back(ch1);
        } else if (this->children.size()==0)
            ;//do nothing
        else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }

};
























//������Ϊ���ӣ����п�����4�����
//���������������������Ӧ�÷���һ��llvm::Value*,��Ϊ�˺������ᱻ��Ϊ���ʽʹ��
class factor_AST :public ASTNode
{
public:
    //������������������ֵ
    int s_state;//1-4��ʾĳһ�����
    string s_type;//��ʾ4�ֻ������ͣ�integer real boolean char
    llvm::Value* s_value;//��ֵ���ڱ��ʽ������ʹ��
    bool isleftvalue = false;//����ֵ��ֵΪtrue,�����������ֵ


    //1.��һ������ֵ����������s_type��������
    double s_real;//����������ʱ������
    int s_int;//����������ʱ������
    char s_char;//����������ʱ������
    bool s_bool;//����������ʱ������

    //2.��һ��������������
    bool s_isconst;//�Ƿ���const����
    string s_identifier;//����������ķ��ű��ʶ��
    SymbolTableItem* s_var_item;//���ű����
    bool s_isarray;//�Ƿ�������
    vector<string> s_index_type_list;
    vector<llvm::Value*> s_index_list;//������ʱ�������壬����index�б�
    llvm::Value* llvmleftValue = NULL;//���Ǳ���������ʱ������ֵָ�룬�ڴ�����ʱʹ��
    //��ʶ�����ͻ�����Ԫ��������s_type

    //3.�����������
    string s_func_identifier;//��������ʶ��
    SymbolTableItem* s_func_item;//���ű����
    vector<string> s_parameter_type_list;
    vector<llvm::Value*> s_parameter_list;//�Ǻ�������ʱ�������壬���������б�
    //����ֵ������s_type

    //4.��Ŀ����
    string s_op;//��Ŀ��������ͣ������ֱַ��Ƿǣ�ȡ���������� !,-,()//ʵ���Ͽ��ܼ���������ûʲô��ϵ������߻ᴦ�����ȼ������Ǽ���
    string s_operand0_type;
    llvm::Value* s_operand0;


    factor_AST(BitNode* bn)
    {
        type = factor;
    }


    void semantic_action() override;
};


class term_AST :public ASTNode
{
public:
    int s_state;//��������״̬��״̬1�����ԵĴ��ݣ��������㣬״̬2������
    string s_type;
    llvm::Value* s_value;
    bool isleftvalue = false;//����ֵ��ֵΪtrue
    llvm::Value* llvmleftValue;//��ֵָ�룬�ڴ�����ʱʹ��

    //1.��Ԫ����
    string s_op;//�ˣ�����������ȡģ������������s_type��boolean���߼��룬�����integer����λ�룩*,/,div,mod,and
    llvm::Value* operand0;
    string operand0_type;
    llvm::Value* operand1;
    string operand1_type;

    //2.���Դ���

    term_AST(BitNode* bn)
    {
        type = term;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            term_AST* ch0 = (term_AST*) this->children[0];
            MULOP_AST* ch1 = (MULOP_AST*) this->children[1];
            factor_AST* ch2 = (factor_AST*) this->children[2];
            for (int i = 0; i < this->children.size(); ++i) {
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

            pascal_info_cat();
//            //������
//            //�����������Ƿ���ͬ
//            if(operand1_type!=operand0_type)
//            {
//                MULOP_AST* id = (MULOP_AST*) this->children[1];
//                SemanticError* err = new SemanticError(id->line,id->col,
//                                                       "operand type Error",
//                                                       "The two operands of '"+id->s_value+"' must be of the same type" );
//                semantic_error_list.push_back(err);
//            }
//            //�˳������������͸���
//            if((ch1->s_value=="*"||ch1->s_value=="/")&&)
//            {
//                MULOP_AST* id = (MULOP_AST*) this->children[1];
//                SemanticError* err = new SemanticError(id->line,id->col,
//                                                       "operand type Error",
//                                                       "The two operands of '"+id->s_value+"' must be of the same type" );
//                semantic_error_list.push_back(err);
//            }
//            //������ģ����������
//            if(operand1_type!=operand0_type)
//            {
//                MULOP_AST* id = (MULOP_AST*) this->children[1];
//                SemanticError* err = new SemanticError(id->line,id->col,
//                                                       "operand type Error",
//                                                       "The two operands of '"+id->s_value+"' must be of the same type" );
//                semantic_error_list.push_back(err);
//            }
//            //and������Boolean
//            if(operand1_type!=operand0_type)
//            {
//                MULOP_AST* id = (MULOP_AST*) this->children[1];
//                SemanticError* err = new SemanticError(id->line,id->col,
//                                                       "operand type Error",
//                                                       "The two operands of '"+id->s_value+"' must be of the same type" );
//                semantic_error_list.push_back(err);
//            }
        }
        else if(this->children.size()==1)
        {
            this->s_state = 2;
            factor_AST* ch0 = (factor_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_value = ch0->s_value;
            this->isleftvalue = ch0->isleftvalue;
            this->llvmleftValue = ch0->llvmleftValue;
            pascal_info_cat();
        }else
            sematic_error();


        //semantic_checking();
        this->s_value = code_generation();
    }
};

class simple_expression_AST :public ASTNode
{
public:
    int s_state;//��������״̬��״̬1�����ԵĴ��ݣ��������㣬״̬2������
    string s_type;
    llvm::Value* s_value;
    bool isleftvalue = false;//����ֵ��ֵΪtrue
    llvm::Value* llvmleftValue;//��ֵָ�룬�ڴ�����ʱʹ��

    //1.��Ԫ����
    string s_op;//�ӣ���������������s_type��boolean���߼��������integer����λ��+,-,or
    llvm::Value* operand0;
    string operand0_type;
    llvm::Value* operand1;
    string operand1_type;

    //2.���Դ���

    simple_expression_AST(BitNode* bn)
    {
        type = simple_expression;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            simple_expression_AST* ch0 = (simple_expression_AST*) this->children[0];
            term_AST* ch2 = (term_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            if (this->children[1]->type==ADDOP)
            {
                ADDOP_AST* ch1 = (ADDOP_AST*) this->children[1];
                this->s_op = ch1->s_value;
            }else// if(this->children[1]->type==UMINUS)
            {
                UMINUS_AST* ch1 = (UMINUS_AST*) this->children[1];
                this->s_op = ch1->s_value;
            }
            this->operand0 = ch0->s_value;
            this->operand0_type = ch0->s_type;
            this->operand1 = ch2->s_value;
            this->operand1_type = ch2->s_type;
            this->isleftvalue = false;
            this->llvmleftValue = NULL;

        }
        else if(this->children.size()==1)
        {
            this->s_state = 2;
            term_AST* ch0 = (term_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_value = ch0->s_value;
            this->isleftvalue = ch0->isleftvalue;
            this->llvmleftValue = ch0->llvmleftValue;
        }else
            sematic_error();

        pascal_info_cat();
        semantic_checking();//todo:����s_type
        this->s_value = code_generation();
    }

};

class expression_AST :public ASTNode
{
public:
    int s_state;//��������״̬��״̬1�����ԵĴ��ݣ��������㣬״̬2������
    string s_type;
    llvm::Value* s_value;
    bool isleftvalue = false;//����ֵ��ֵΪtrue
    llvm::Value* llvmleftValue;//��ֵָ�룬�ڴ�����ʱʹ��

    //1.��Ԫ����
    string s_op;//���ڣ������ڣ�С�ڣ�С�ڵ��ڣ����ڣ����ڵ��� =,<>,<,<=,>,>=
    llvm::Value* operand0;
    string operand0_type;
    llvm::Value* operand1;
    string operand1_type;

    //2.���Դ���
    expression_AST(BitNode* bn)
    {
        type = expression;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            simple_expression_AST* ch0 = (simple_expression_AST*) this->children[0];
            RELOP_AST* ch1 = (RELOP_AST*) this->children[1];
            simple_expression_AST* ch2 = (simple_expression_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->operand0 = ch0->s_value;
            this->operand0_type = ch0->s_type;
            this->operand1 = ch2->s_value;
            this->operand1_type = ch2->s_type;
            this->s_op = ch1->s_value;
            this->isleftvalue = false;
            this->llvmleftValue = NULL;
        }
        else if(this->children.size()==1)
        {
            this->s_state = 2;
            simple_expression_AST* ch0 = (simple_expression_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_value = ch0->s_value;
            this->isleftvalue = ch0->isleftvalue;
            this->llvmleftValue = ch0->llvmleftValue;
        }else
            sematic_error();

        pascal_info_cat();
        semantic_checking();//todo:����s_type
        this->s_value = code_generation();
    }

};

class expression_list_AST :public ASTNode
{
public:
    vector<string> s_type_list;
    vector<llvm::Value*> s_value_list;
    vector<expression_AST*> s_expression_list;
    expression_list_AST(BitNode* bn)
    {
        type = expression_list;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            expression_list_AST* ch0 = (expression_list_AST*) this->children[0];
            expression_AST* ch2 = (expression_AST*) this->children[2];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_type_list = ch0->s_type_list;
            this->s_type_list.push_back(ch2->s_type);
            this->s_value_list = ch0->s_value_list;
            this->s_value_list.push_back(ch2->s_value);
            this->s_expression_list = ch0->s_expression_list;
            this->s_expression_list.push_back(ch2);
        }else if(this->children.size()==1) {
            expression_AST* ch0 = (expression_AST*) this->children[0];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_type_list.push_back(ch0->s_type);
            this->s_value_list.push_back(ch0->s_value);
            this->s_expression_list.push_back(ch0);
        }else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class id_varpart_AST :public ASTNode
{
public:
    bool s_isarray;
    vector<string> s_type_list;//����index�б�������ͣ�ֻ������int������������ͼ��
    vector<llvm::Value*> s_value_list;//����index�б������ֵ
    id_varpart_AST(BitNode* bn)
    {
        type = id_varpart;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            expression_list_AST* ch1 = (expression_list_AST*) this->children[1];

            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }

            this->s_isarray = true;
            this->s_type_list = ch1->s_type_list;
            this->s_value_list = ch1->s_value_list;

        }else if(this->children.size()==0)
        {
            this->s_isarray = false;
        } else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }
};

class variable_AST :public ASTNode
{
public:
    string s_identifier;
    string s_type;//��ʾ4�ֻ������ͣ�integer real boolean char
    bool s_isconst;//�Ƿ���
    SymbolTableItem* item;
    bool s_isarray;//�Ƿ�������
    vector<string> s_type_list;//����index�б�������ͣ�ֻ������int������������ͼ��
    vector<llvm::Value*> s_value_list;//����index�б������ֵ

    llvm::Value* llvmleftValue = NULL;//���Ǳ���������ʱ������ֵָ�룬�ڴ�����ʱʹ��

    variable_AST(BitNode* bn)
    {
        type = variable;
    }


    void semantic_action() override
    {
        //ֻ��һ������ʽ
        ID_AST* ch0 = (ID_AST*) this->children[0];
        id_varpart_AST* ch1 = (id_varpart_AST*) this->children[1];

        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }

        this->s_identifier = ch0->identifier;
        this->s_isarray = ch1->s_isarray;
        this->s_type_list = ch1->s_type_list;
        this->s_value_list = ch1->s_value_list;

        //�ӷ��ű�������
        this->item = symbol_table.get(this->s_identifier);
        symbol_type t;
        if(this->s_isarray = true)
        {
            if (this->item->type!=array_type)
                sematic_error();//todo
            else
            {
                t = item->value.array_val->type;
            }
        }else
        {
            t = this->item->type;
        }

        switch (t) {
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
            default:sematic_error();
        }

        pascal_info_cat();
        get_line_col(ch0);
        semantic_checking();
        code_generation();
    }

};

class variable_list_AST :public ASTNode
{
public:
    vector<variable_AST*> s_variable_list;

    variable_list_AST(BitNode* bn)
    {
        type = variable_list;
    }


    void semantic_action() override
    {
        if (this->children.size()==3)
        {
            variable_list_AST* ch0 = (variable_list_AST*) this->children[0];
            variable_AST* ch2 = (variable_AST*) this->children[2];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_variable_list = ch0->s_variable_list;
            this->s_variable_list.push_back(ch2);
        }else if(this->children.size()==1)
        {
            variable_AST* ch0 = (variable_AST*) this->children[0];
            ch0->semantic_action();
            this->s_variable_list.push_back(ch0);
        } else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }

};

class procedure_call_AST :public ASTNode
{
public:
    string s_identifier;//������
    SymbolTableItem* s_item;//���̵ķ��ű����
    vector<string> s_type_list;
    vector<llvm::Value*> s_value_list;

    procedure_call_AST(BitNode* bn)
    {
        type = procedure_call;
    }


    void semantic_action() override
    {
        if(this->children.size()==1)
        {
            ID_AST* ch0 = (ID_AST*) this->children[0];
            ch0->semantic_action();
            this->s_identifier = ch0->identifier;
            this->s_item = symbol_table.get(this->s_identifier);

            get_line_col(ch0);
        }
        else if(this->children.size()==4)
        {
            ID_AST* ch0 = (ID_AST*) this->children[0];
            expression_list_AST* ch2 = (expression_list_AST*) this->children[2];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_identifier = ch0->identifier;
            this->s_item = symbol_table.get(this->s_identifier);
            this->s_type_list = ch2->s_type_list;

            //�����飬δ�����id
            if(s_item==NULL)
            {
                ID_AST* id = ch0;
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "undefined identifier",
                                                       "identifier '"+id->identifier+"' is undefined");
                semantic_error_list.push_back(err);
            }
            if(s_item->type!=procedure)
            {
                ID_AST* id = ch0;
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "identifier type Error",
                                                       "in function '"+id->identifier+"',identifier is not a function");
                semantic_error_list.push_back(err);
                return;
            }
            if(s_item!=NULL)//���ں������Ž��к������õ�������
            {
                MyFunctionType* functionType = s_item->value.function_val;
                if(functionType->arg_name_list.size()!=ch2->s_value_list.size())//�����������Ƿ�ƥ��
                {
                    ID_AST* id = ch0;
                    SemanticError* err = new SemanticError(id->line,id->col,
                                                           "number of parameter Error",
                                                           "in procedure '"+id->identifier+"',The number of parameters does not match the definition");
                    semantic_error_list.push_back(err);
                }
                else
                {
                    for (int i = 0; i < functionType->arg_name_list.size(); ++i)
                    {
                        if(functionType->arg_type_list[i]!=s_type_list[i])//�������ʹ���
                        {
                            ID_AST* id = ch0;
                            SemanticError* err = new SemanticError(id->line,id->col,
                                                                   "parameter type Error",
                                                                   "in procedure '"+id->identifier+"',parameter "+functionType->arg_name_list[i]+"type must be"+functionType->arg_type_list[i]);
                            semantic_error_list.push_back(err);
                        }
                        if(functionType->arg_isvar_list[i])//������ò���λ�ܷ�������
                        {
                            if(!ch2->s_expression_list[i]->isleftvalue)//�����ǿ���������
                            {
                                ID_AST* id = ch0;
                                SemanticError* err = new SemanticError(id->line,id->col,
                                                                       "parameter type Error",
                                                                       "in procedure '"+id->identifier+"',parameter "+functionType->arg_name_list[i]+"type must be referencable");
                                semantic_error_list.push_back(err);
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
        } else
            sematic_error();

        pascal_info_cat();
        //semantic_checking();
        code_generation();
    }
};



class statement_AST :public ASTNode
{
public:
    //����ж�������
    llvm::Value* s_cur_llvmvalue;
    int s_state;
    BasicBlock* block1;
    BasicBlock* block2;
    BasicBlock* block3;

    //1.��ֵ���
    variable_AST* s_variable;
    string s_expression_type;
    llvm::Value* s_expression_value;

    //2.���̵���
    string s_identifier;//������
    SymbolTableItem* s_item;//���̵ķ��ű����
    vector<string> s_type_list;
    vector<llvm::Value*> s_value_list;

    //3.�������
    vector<statement_AST*> s_statement_list;

    //4.if-else
    //expression���ø�ֵ����
    statement_AST* s_if_statement;
    bool s_has_else;//�ж�����else����
    statement_AST* s_else_statement;

    //5.for
    statement_AST* s_for_statement;

    string s_for_identifier;
    string s_for_type;//��ʾ4�ֻ������ͣ�integer real boolean char
    SymbolTableItem* s_for_item;

    string s_for_expression_type1;
    llvm::Value* s_for_expression_value1;
    string s_for_expression_type2;
    llvm::Value* s_for_expression_value2;

    //6.read
    vector<variable_AST*> s_variable_list;

    //7.write
    //expression_list����procedure_call��

    //8.�����
    //�����ʱ���кź��кŲ�ȷ��

    //9.while ����ʽWHILE expression DO statement


    statement_AST(BitNode* bn)
    {
        type = statement;
    }


    void semantic_action() override;

};

class statement_list_AST :public ASTNode
{
public:
    vector<statement_AST*> s_statement_list;
    vector<llvm::Value*> s_llvmvalue_list;
    statement_list_AST(BitNode* bn)
    {
        type = statement_list;
    }

    void code_init();

    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            statement_list_AST* ch0 = (statement_list_AST*) this->children[0];
            statement_AST* ch2 = (statement_AST*) this->children[2];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_statement_list = ch0->s_statement_list;
            this->s_statement_list.push_back(ch2);
            this->s_llvmvalue_list = ch0->s_llvmvalue_list;
            this->s_llvmvalue_list.push_back(ch2->s_cur_llvmvalue);
        }
        else if(this->children.size()==1)
        {
            statement_AST* ch0 = (statement_AST*) this->children[0];
            ch0->semantic_action();
            this->s_statement_list.push_back(ch0);
            this->s_llvmvalue_list.push_back(ch0->s_cur_llvmvalue);
        } else
            sematic_error();

        pascal_info_cat();
        semantic_checking();
        code_generation();
    }

};

class else_part_AST :public ASTNode
{
public:
    bool s_has_else;
    statement_AST* s_statement;
    llvm::Value* s_cur_llvmvalue;
    else_part_AST(BitNode* bn)
    {
        type = else_part;
    }


    void semantic_action() override
    {
        if(this->children.size()==2)
        {
            statement_AST* ch1 = (statement_AST*) this->children[1];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_has_else = true;
            this->s_statement = ch1;
            get_line_col(this->children[0]);
        }
        else if(this->children.size()==0)
        {
            this->s_has_else = false;
        }

        pascal_info_cat();
        semantic_checking();
        //code_generation();
        this->s_cur_llvmvalue = s_statement->s_cur_llvmvalue;
    }

};

class compound_statement_AST :public ASTNode
{
public:
    vector<statement_AST*> s_statement_list;
    vector<llvm::Value*> s_llvmvalue_list;
    compound_statement_AST(BitNode* bn)
    {
        type = compound_statement;
    }


    void semantic_action() override
    {
        if(this->children.size()==3)
        {
            statement_list_AST* ch1 = (statement_list_AST*) this->children[1];
            for (int i = 0; i < this->children.size(); ++i) {
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
        code_generation();
    }
};

void statement_AST::semantic_action()
{
    if(this->children.size()==0)
    {
        return;
    }
    else if(this->children[0]->type==variable)
    {
        this->s_state = 1;
        variable_AST* ch0 = (variable_AST*)this->children[0];
        expression_AST* ch2 = (expression_AST*) this->children[2];
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        this->s_variable = ch0;
        this->s_expression_type = ch2->s_type;
        this->s_expression_value = ch2->s_value;
        get_line_col(ch0);
    }
    else if(this->children[0]->type==procedure_call)
    {
        this->s_state = 2;
        procedure_call_AST* ch0 = (procedure_call_AST*) this->children[0];
        ch0->semantic_action();
        this->s_identifier = ch0->s_identifier;
        this->s_item = ch0->s_item;
        this->s_type_list = ch0->s_type_list;
        this->s_value_list = ch0->s_value_list;
        get_line_col(ch0);
    }
    else if(this->children[0]->type==compound_statement)
    {
        this->s_state = 3;
        compound_statement_AST* ch0 = (compound_statement_AST*) this->children[0];
        ch0->semantic_action();
        this->s_statement_list = ch0->s_statement_list;
        get_line_col(ch0);
    }
    else if(this->children[0]->type==IF)
    {
        this->s_state = 4;
        expression_AST* ch1 = (expression_AST*) this->children[1];
        statement_AST* ch3 = (statement_AST*) this->children[3];
        else_part_AST* ch4 = (else_part_AST*) this->children[4];
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        this->s_expression_type = ch1->s_type;
        this->s_expression_value = ch1->s_value;
        this->s_if_statement = ch3;
        this->s_has_else = ch4->s_has_else;
        this->s_else_statement = ch4->s_statement;
        get_line_col(this->children[0]);
    }
    else if(this->children[0]->type==FOR)
    {
        this->s_state = 5;
        ID_AST* ch1 = (ID_AST*) this->children[1];
        expression_AST* ch3 = (expression_AST*) this->children[3];
        expression_AST* ch5 = (expression_AST*) this->children[5];
        statement_AST* ch7 = (statement_AST*) this->children[7];
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        this->s_for_identifier = ch1->identifier;
        this->s_for_item = symbol_table.get(s_for_identifier);
        this->s_for_type = "integer";

        this->s_for_expression_type1 = ch3->s_type;
        this->s_for_expression_value1 = ch3->s_value;
        this->s_for_expression_type2 = ch5->s_type;
        this->s_for_expression_value2 = ch5->s_value;
        this->s_for_statement = ch7;
        get_line_col(this->children[0]);
    }
    else if(this->children[0]->type == READ)
    {
        this->s_state = 6;
        variable_list_AST* ch2 = (variable_list_AST*)this->children[2];
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        this->s_variable_list = ch2->s_variable_list;
        get_line_col(this->children[0]);
    }
    else if(this->children[0]->type == WRITE)
    {
        this->s_state = 7;
        expression_list_AST* ch2 = (expression_list_AST*) this->children[2];
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        this->s_type_list = ch2->s_type_list;
        this->s_value_list = ch2->s_value_list;
        get_line_col(this->children[0]);
    }
    else if(this->children.size()==0)
    {
        this->s_state = 8;
    }
    else if(this->children[0]->type==WHILE)
    {
        this->s_state = 9;
        expression_AST* ch1 = (expression_AST*) this->children[1];
        statement_AST* ch3 = (statement_AST*) this->children[3];
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->semantic_action();
        }
        this->s_expression_type = ch1->s_type;
        this->s_expression_value = ch1->s_value;
        this->s_for_statement = ch3;
        get_line_col(this->children[0]);
    }
    else
        sematic_error();

    if(this->children.size()!=0)
        pascal_info_cat();

    semantic_checking();
    code_generation();
}


void factor_AST::semantic_action() {

        if(this->children[0]->type==NUM)
        {
            this->s_state = 1;
            NUM_AST* ch0 = (NUM_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_real = ch0->s_real;
        }
        else if(this->children[0]->type==DIGITS)
        {
            this->s_state = 1;
            DIGITS_AST* ch0 = (DIGITS_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_int = ch0->s_int;
        }
        else if(this->children[0]->type==BOOLEAN)
        {
            this->s_state = 1;
            BOOLEAN_AST* ch0 = (BOOLEAN_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_bool = ch0->s_bool;
        }
        else if(this->children[0]->type==variable)
        {
            this->s_state = 2;
            variable_AST* ch0 = (variable_AST*) this->children[0];
            ch0->semantic_action();
            this->s_type = ch0->s_type;
            this->s_isconst = ch0->s_isconst;
            this->s_isarray = ch0->s_isarray;
            this->s_identifier = ch0->s_identifier;
            this->s_var_item = ch0->item;
            this->s_index_type_list = ch0->s_type_list;
            this->s_index_list = ch0->s_value_list;
            if (this->s_isconst== false)
            {
                this->isleftvalue = true;
                this->llvmleftValue = ch0->llvmleftValue;
            }

        }
        else if(this->children[0]->type==ID)
        {
            this->s_state = 3;
            ID_AST* ch0 = (ID_AST*)this->children[0];
            expression_list_AST* ch2 = (expression_list_AST*) this->children[2];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_func_identifier = ch0->identifier;
            this->s_parameter_list = ch2->s_value_list;


            this->s_func_item = symbol_table.get(this->s_func_identifier);
            this->s_parameter_type_list = ch2->s_type_list;

            //�����飬δ�����id
            if(s_func_item==NULL)
            {
                ID_AST* id = ch0;
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "undefined identifier",
                                                       "identifier '"+id->identifier+"' is undefined");
                semantic_error_list.push_back(err);
                return;
            }
            if(s_func_item->type!=function)
            {
                ID_AST* id = ch0;
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "identifier type Error",
                                                       "in function '"+id->identifier+"',identifier is not a function");
                semantic_error_list.push_back(err);
                return;
            }

            if(s_func_item!=NULL)//���ں������Ž��к������õ�������
            {
                MyFunctionType* functionType = s_func_item->value.function_val;
                if(!functionType->isfunction)//������Ǻ���
                {
                    ID_AST* id = ch0;
                    SemanticError* err = new SemanticError(id->line,id->col,
                                                           "identifier type Error",
                                                           "in function '"+id->identifier+"',identifier is not a function");
                    semantic_error_list.push_back(err);
                    return;
                }
                this->s_type = functionType->ret_type;

                if(functionType->arg_name_list.size()!=ch2->s_value_list.size())//�����������Ƿ�ƥ��
                {
                    ID_AST* id = ch0;
                    SemanticError* err = new SemanticError(id->line,id->col,
                                                           "number of parameter Error",
                                                           "in procedure '"+id->identifier+"',The number of parameters does not match the definition");
                    semantic_error_list.push_back(err);
                }
                else
                {
                    for (int i = 0; i < functionType->arg_name_list.size(); ++i)
                    {
                        if(functionType->arg_type_list[i]!=s_parameter_type_list[i])//�������ʹ���
                        {
                            ID_AST* id = ch0;
                            SemanticError* err = new SemanticError(id->line,id->col,
                                                                   "parameter type Error",
                                                                   "in function '"+id->identifier+"',parameter "+functionType->arg_name_list[i]+"type must be"+functionType->arg_type_list[i]);
                            semantic_error_list.push_back(err);
                        }
                        if(functionType->arg_isvar_list[i])//������ò���λ�ܷ�������
                        {
                            if(!ch2->s_expression_list[i]->isleftvalue)//�����ǿ���������
                            {
                                ID_AST* id = ch0;
                                SemanticError* err = new SemanticError(id->line,id->col,
                                                                       "parameter type Error",
                                                                       "in function '"+id->identifier+"',parameter "+functionType->arg_name_list[i]+"type must be referencable");
                                semantic_error_list.push_back(err);
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


        }
        else if(this->children[0]->type==SEPARATOR)
        {
            this->s_state = 4;
            expression_AST* ch1 = (expression_AST*) this->children[1];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_op = "()";
            this->s_operand0_type = ch1->s_type;
            this->s_operand0 = ch1->s_value;
            this->s_type = ch1->s_type;
        }
        else if(this->children[0]->type==NOT)
        {
            this->s_state = 4;
            factor_AST* ch1 = (factor_AST*) this->children[1];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_op = "!";
            this->s_operand0_type = ch1->s_type;
            this->s_operand0 = ch1->s_value;
            this->s_type = ch1->s_type;

            //������
            if(s_type!="boolean")
            {
                NUM_AST* id = (NUM_AST*) this->children[0];
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "operand type Error",
                                                       "'not' operator only can be used on boolean type operand");
                semantic_error_list.push_back(err);
            }
        }
        else if(this->children[0]->type==UMINUS)
        {
            this->s_state = 4;
            factor_AST* ch1 = (factor_AST*) this->children[1];
            for (int i = 0; i < this->children.size(); ++i) {
                this->children[i]->semantic_action();
            }
            this->s_op = "-";
            this->s_operand0_type = ch1->s_type;
            this->s_operand0 = ch1->s_value;
            this->s_type = ch1->s_type;

            //������
            if(s_type!="integer"&&s_type!="real")
            {
                NUM_AST* id = (NUM_AST*) this->children[0];
                SemanticError* err = new SemanticError(id->line,id->col,
                                                       "operand type Error",
                                                       "'-' operator only can be used on integer type or real type");
                semantic_error_list.push_back(err);
            }
        } else
            sematic_error();

        pascal_info_cat();
    semantic_checking();//todo:����s_type
        this->s_value = code_generation();
}

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

	ASTNode* ADT2AST(BitNode* bn)
	{
		//���ڵ㶯��
		ASTNode* cur_node = create_ASTNode(bn);
		int n = bn->children.size();
		//�ӽڵ����
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

