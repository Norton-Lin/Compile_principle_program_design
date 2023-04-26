#include"TypeSystem.h"
#include"CodeGenerate.h"
Type* Type_IR::getLLVMType(const string& type){
    if(type == "integer")
        return this->type_int;
    if(type == "real")
        return this->type_real;
    if(type == "char")
        return this->type_char;
    if(type == "boolean")
        return this->type_boolean;
    if(type == "void")
        return this->type_void;
    if(type == "int64")
        return this->type_int64;

    //数组类型(这里type是数组的类型名)
    if (this->arrayTypes.find(type) != this->arrayTypes.end()){
        return this->arrayTypes[type];
    }
    else{
        LogErrorV("[getLLVMType]  Unknown type: " + type);
        return nullptr;
    }
}
void Type_IR::addArrayType(const string& name, llvm::ArrayType* type, string memberType,
        vector<pair<int,int>> arrayRangeList){
    arrayTypes[name] = type;
    arrayTypeList[name] = memberType;
    vector<pair<int,int>> temp(arrayRangeList);
    arrayRangeLists[name] = temp;
}
string Type_IR::getArrayMemberType(const string& name){
    SymbolTableItem* item = symbol_table->get(name);
    if(item == nullptr)
    {
        LogErrorV("Unknown array name: " + name);
        return "";
    }
    if(isBasicType(item->type))
    {
        LogErrorV("Not array name: " + name);
        return "";
    }
    {
        return name;
    }


}
bool isBasicType(const string& type){
    return (type == "integer"|type == "real"|type == "char"|type == "boolean");
}