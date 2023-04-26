#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class SymbolTable;
class SymbolTableItem;

class ArrayType;
class FunctionType;

using namespace std;

/*所有方法返回的对象都是引用，可直接修改
  不使用set方法，直接对成员变量修改
*/

enum symbol_type {
    unknown = 0,
    const_int = 1, const_real = 2, const_bool = 3, const_char = 4,
    var_int = 5, var_real = 6, var_bool = 7, var_char = 8,
    array_type = 9, function = 10, procedure = 11
};

union basic_type_type
{
    int int_val;
    double real_val;
    bool bool_val;
    char char_val;
};

//todo:对数组类型进行测试
class ArrayType
{
public:
    int dimension;
    symbol_type type;
    int max_index;
    vector<int> begin;
    vector<int> end;
    vector<int> size;
    vector<basic_type_type> value;

    //ArrayType() {};
    ArrayType(vector<int> begin, vector<int> end,symbol_type type)
    {
        this->dimension = begin.size();
        this->type = type;
        for (int i = 0; i <dimension ; i++)
        {
            this->begin[i] = begin[i];
            this->end[i] = end[i];
            this->size[i] = end[i] - begin[i] + 1;
        }
        this->max_index = get_index(end);
    }

    bool set(vector<int> indexlist, basic_type_type val)
    {
        if (indexlist.size() != this->dimension)
            return false;
        int index = get_index(indexlist);
        if (index>max_index)
        {
            return false;
        }
        value[index] = val;
        return true;
    }

    bool get(vector<int> indexlist, basic_type_type& val)
    {
        if (indexlist.size() != this->dimension)
            return false;
        int index = get_index(indexlist);
        if (index > max_index)
        {
            return false;
        }
        val = value[index];
        return true;
    }


    int get_index(vector<int> vec)
    {
        int offset = 0;
        int product = 1;
        for (size_t i = 0; i < vec.size(); i++)
        {
            vec[i] = vec[i] - begin[i];
        }

        for (int i = dimension - 1; i >= 0; i--)
        {
            offset += vec[i] * product;
            product *= size[i];
        }

        return offset;
    }
};


class FunctionType
{
public:
    FunctionType() {};

    FunctionType(SymbolTable* main_table){
        this->main_table = main_table;
    }

    SymbolTable* main_table;
    SymbolTable* child_table;

    vector<string> var_arg_name_list;//get和set方法检查确定是否从上级符号表
    vector<string> var_name_list;//子表引用名对应的父表名称

    bool isfunction;
    symbol_type ret_type;//只在是函数时才有意义
};



union symbol_value {
    int int_val;
    double real_val;
    bool bool_val;
    char char_val;
    ArrayType* array_val;
    FunctionType* function_type;
};

class SymbolTableItem
{
public:
    string identifier;
    symbol_type type;
    symbol_value value;
    int define_line;
    vector<int> reference_line;

    bool isvalid = false;

public:
    SymbolTableItem() {};
    SymbolTableItem(string identifier, symbol_type type = unknown)
    {
        this->identifier = identifier;
        this->type = type;
        this->set_def_value();
        this->isvalid = false;
    }

    SymbolTableItem(string identifier, symbol_type type,symbol_value val)
    {
        this->identifier = identifier;
        this->type = type;
        this->value = val;
    }


    void set_define_line(int define_line)
    {
        this->define_line = define_line;
    }

    void add_reference_line(int reference_line)
    {
        this->reference_line.push_back(reference_line);
    }


private:
    void set_def_value()
    {
        switch (type)
        {
        case const_int:
        case var_int:this->value.int_val = 0; 
            break;
        case const_real:
        case var_real:this->value.real_val = 0.0;
            break;
        case const_bool:
        case var_bool:this->value.bool_val = false;
            break;
        case const_char:
        case var_char:this->value.char_val = '\0';
            break;
        case unknown:
            break;

//        case array_type:this->value.array_val = new ArrayType();
//            break;
//        case function:this->value.function_type = new FunctionType();
//            break;
        default:;//todo:调试信息.数组，函数类型在定义时必须赋值
        }
    }

};

//todo:对符号表进行测试
class SymbolTable
{
public:
    string main_function;
    //subprogram_body时，执行生成综合属性前修改至当前函数名，结束时置为main_function
    string cur_function;
private:
    unordered_map<string, SymbolTableItem*> table;


public:
    SymbolTable() {
        ;
    }

    //增删查改方法
    //todo:子表和父表的顺序查询

    //默认的插入方法，插入默认的不包含类型和值的符号表对象
    bool insert(string id)
    {
        SymbolTableItem* item = new SymbolTableItem(id);
        return insert(item);
    }

    //插入符号表项对象,在子表中不会运行该函数
    bool insert(SymbolTableItem* item)
    {
        if (item == NULL)
            return false;

        SymbolTable* table_ptr;
        if(this->cur_function == this->main_function)
        {
            table_ptr = this;
        } else
        {
            SymbolTableItem* func_item = this->table[cur_function];
            table_ptr = func_item->value.function_type->child_table;
        }
        table_ptr->table[item->identifier] = item;
        return true;
    }

    bool remove(string id)
    {
        SymbolTable* table_ptr;
        if(this->cur_function == this->main_function)
        {
            table_ptr = this;
        } else
        {
            SymbolTableItem* func_item = this->table[cur_function];
            table_ptr = func_item->value.function_type->child_table;
        }

        return table_ptr->table.erase(id);
    }
    //返回表项指针，实现查询和修改功能

    SymbolTableItem* get(string id)
    {
        if(this->cur_function == this->main_function)
        {
            return this->table[id];
        } else
        {
            SymbolTableItem* func_item = this->table[cur_function];
            FunctionType* func = func_item->value.function_type;
            SymbolTable* table_ptr = func->child_table;
            //如果是子表对父表中的引用
            for (int i = 0; i <func->var_arg_name_list.size(); ++i) {
                if (id == func->var_arg_name_list[i])
                {
                    return this->table[func->var_name_list[i]];
                }
            }
            //只是子表的局部变量
            return table_ptr->table[id];
        }
    }


};


