#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <llvm/IR/Value.h>
#include "interface.h"

class SymbolTable;
class SymbolTableItem;

class MyArrayType;
class MyFunctionType;

using namespace std;

/*所有方法返回的对象都是引用，可直接修改
  不使用set方法，直接对成员变量修改
*/

//

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

class MyBasicType
{
public:
    llvm::Value* llvmvalue;
    basic_type_type value;
};

class MyArrayType
{
public:
    int dimension;
    symbol_type type;
    int max_index;
    vector<int> begin;
    vector<int> end;
    vector<int> size;
    vector<basic_type_type> value;
    llvm::Value* llvmvalue;
    //MyArrayType() {};


    MyArrayType(vector<int> begin, vector<int> end, symbol_type type)
    {
        this->dimension = begin.size();
        this->type = type;

        this->begin = begin;
        this->end = end;
        for (int i = 0; i < begin.size(); ++i) {
            int s = end[i] - begin[i]+1;
            if(s > 0)
                (this->size).insert(size.begin() + i,s);
            else
                (this->size).insert(size.begin() + i,1);
        }

        this->max_index = get_index(end);
        this->value.resize(this->max_index+1);
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
        value.insert(value.begin() + index,val);
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


class MyFunctionType
{
public:
    MyFunctionType() {};
    MyFunctionType(SymbolTable* main_table);

    //不要使用这个指针访问符号表，直接使用extern的symbol_table的get方法可以自动处理作用域
    SymbolTable* main_table;
    SymbolTable* child_table;

    vector<string> arg_name_list;//参数列表名，从左到右按顺序
    vector<string> arg_type_list;//标识参数的类型，从左到右排序
    vector<bool> arg_isvar_list;//标识参数是否是引用类型
    //vector<string> var_name_list;//子表引用名对应的父表名称//这一行应该没用
    llvm::Function* llvmfunction;

    bool isfunction;
    string ret_type;//只在是函数时才有意义
    llvm::Value* ret_llvmval;
};



union symbol_value {
    MyBasicType* basic_val;
    MyArrayType* array_val;
    MyFunctionType* function_val;
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
        this->value.function_val = NULL;
        this->value.array_val = NULL;
        this->value.basic_val = NULL;
//        switch (type)
//        {
//        case const_int:
//        case var_int:this->value.int_val = 0;
//            break;
//        case const_real:
//        case var_real:this->value.real_val = 0.0;
//            break;
//        case const_bool:
//        case var_bool:this->value.bool_val = false;
//            break;
//        case const_char:
//        case var_char:this->value.char_val = '\0';
//            break;
//        case unknown:
//            break;
//
//        case array_type:this->value.array_val = new MyArrayType();
//            break;
//        case function:this->value.function_val = new MyFunctionType();
//            break;
//        default:;//todo:调试信息.数组，函数类型在定义时必须赋值
//        }
    }

};

//todo:对符号表局部作用域功能进行测试
class SymbolTable
{
public:
    string main_function;
    //subprogram_body时，执行生成综合属性前修改至当前函数名，结束时置为main_function
    string cur_function;
private:
private:
    unordered_map<string, SymbolTableItem*> table;


public:
    SymbolTable() {
        ;
    }

    //增删查改方法

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
            table_ptr = func_item->value.function_val->child_table;
        }

        auto it = table_ptr->table.find(item->identifier);
        if(it == table_ptr->table.end())
        {
            table_ptr->table[item->identifier] = item;
            return true;
        }
        else
            return false;

    }

    //似乎不会被调用
    bool remove(string id)
    {
        SymbolTable* table_ptr;
        if(this->cur_function == this->main_function)
        {
            table_ptr = this;
        } else
        {
            SymbolTableItem* func_item = this->table[cur_function];
            table_ptr = func_item->value.function_val->child_table;
        }

        return table_ptr->table.erase(id);
    }
    //返回表项指针，实现查询和修改功能

    SymbolTableItem* get(string id)
    {
        //重定位符号表
        if(this->cur_function == this->main_function)//在主表查询
        {
            //检验是否存在表项
            auto it = this->table.find(id);
            if(it == this->table.end())//不存在
                return NULL;
            else
                return this->table[id];
        } else//在子表查询
        {
            //重定位符号表
            SymbolTableItem* func_item = this->table[cur_function];
            MyFunctionType* func = func_item->value.function_val;
            SymbolTable* table_ptr = func->child_table;

            auto it = table_ptr->table.find(id);
            //子表没有对应的标识符
            if(it == table_ptr->table.end())
            {
                table_ptr = this;//在父表查询
            }

            //检查是否存在
            auto it1 = table_ptr->table.find(id);
            if(it1 == table_ptr->table.end())//不存在
                return NULL;
            else
                return table_ptr->table[id];

        }
    }

};

MyFunctionType:: MyFunctionType(SymbolTable* main_table){
    this->main_table = main_table;
    this->child_table = new SymbolTable();
}

