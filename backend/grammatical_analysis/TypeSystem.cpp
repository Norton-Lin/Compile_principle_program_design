#include "TypeSystem.h"
#include "CodeGenerate.h"
extern CodeGenContext context;
bool isBasicType(const string &type)
{
    return (type == "integer" | type == "real" | type == "char" | type == "boolean");
}
bool isBasicType(const int& type)
{
    return type >= 5 && type <= 8;
}
Type *Type_IR::getLLVMType(const string &type)
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
Type *Type_IR::getLLVMType(const int &type)
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
Type *Type_IR::getArrayLLVMType(SymbolTableItem *item)
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
Type *Type_IR::createArrayType(SymbolTableItem *item)
{
    string name = "array";
    int range = 1;
    for (int i = 0; i < item->value.array_val->size.size(); i++)
    {
        name += "_" + to_string(item->value.array_val->begin[i]) + "_" + to_string(item->value.array_val->end[i]);
        range *= item->value.array_val->size[i];
    }
    Type *type = context.type_ir.getLLVMType(item->type); // 获取基本类型
    ArrayType *arrayType = ArrayType::get(type, range);   // 数组type
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
    SymbolTableItem *item = symbol_table->get(name);
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

    return name;
}
