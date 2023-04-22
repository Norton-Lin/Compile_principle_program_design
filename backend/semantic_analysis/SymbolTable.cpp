#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class SymbolTable;
class SymbolTableItem;


enum type_set {
    unset = 0,
    const_int = 1, const_real = 2, const_bool = 3, const_char = 4,
    var_int = 5, var_real = 6, var_bool = 7, var_char = 8,
    array_type = 9, function = 10, procedure = 11
};

class SymbolTableItem
{
private:
    string identifier;
    int id;
    type_set type;
    void* value;//TODO
    int define_line;
    vector<int> reference_line;
};

class SymbolTable
{
    unordered_map<int, vector<SymbolTableItem>> table;
    unordered_map<string, int> map_table;
};


class ConstIntType
{
    int value;

public:
    int get_value() 
    {
        return this->value;
    }
};
class constrealtype
{
    double value;

public:
    double get_value() 
    {
        return this->value;
    }
};
class constbooltype
{
    bool value;

public:
    bool get_value() 
    {
        return this->value;
    }
};
class constchartype
{
    char value;

public:
    char get_value() 
    {
        return this->value;
    }
};

class IntType
{
    bool has_value = false;
    int value;
public:
    int get_value() 
    {
        return this->value;
    }

    void set_value(int value)
    {
        this->value = value;
    }
};

class ArrayType
{
    int dimension;
    vector<int> begin;
    vector<int> end;
    vector<int> value;

    //Todo 数据的读写方法
};

class FunctionType
{
    int argc;
    type_set ret_type;
    vector<type_set> arg_type_list;
    vector<string> arg_name_list;
    vector<SymbolTableItem> arg_value_list;
};

class ProcedureType
{
    int argc;
    vector<type_set> arg_type_list;
    vector<string> arg_name_list;
    vector<SymbolTableItem> arg_value_list;
};


class test
{
    int test_val = 0;

};

int main()
{
    cout << "Hello World!\n";
}

