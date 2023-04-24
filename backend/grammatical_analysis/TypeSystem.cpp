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
        return this->type_boolen;
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