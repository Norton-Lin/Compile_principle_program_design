#ifndef _TYPESYSTEM_H__
#define _TYPESYSTEM_H__
#include <llvm/IR/Type.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <string>
#include <map>
#include <vector>
#include"symbol_table.hpp"
extern SymbolTable* symbol_table;
using namespace std;
using namespace llvm;
/**
 * 类型系统
 * 用于维护自定义类型的定义
 * 以及类型的比较
*/
class Type_IR{
public:
    llvm::LLVMContext llvmContext;
    map<string, string> arrayTypeList;           //数组元素类型列表
    map<string, vector<pair<int, int>> > arrayRangeLists; //数组上下界列表
    map<string, vector<int>> arraySizeLists;     //数组大小列表
    map<string, llvm::ArrayType*> arrayTypes;       //数组变量对应的LLVM Type
    //TypeSystem(LLVMContext& context): llvmContext(context) {}
    Type_IR(LLVMContext& context): llvmContext() {}
    Type* type_int = Type::getInt32Ty(llvmContext);
    Type* type_real = Type::getFloatTy(llvmContext);
    Type* type_char = Type::getInt8Ty(llvmContext);
    Type* type_boolean = Type::getInt1Ty(llvmContext);
    Type* type_void = Type::getVoidTy(llvmContext);
    Type* type_int64 = Type::getInt64Ty(llvmContext);
    //获取llvm类型
    Type* getLLVMType(const string& type);
    Type* getLLVMType(const int& type);
    Type* getArrayLLVMType(SymbolTableItem* item);
    Type* createArrayType(SymbolTableItem* item);
    //增加llvm类型
    void Type_IR::addArrayType(const string &name, llvm::ArrayType *type, SymbolTableItem* item);
    //获取数组元素类型名
    string getArrayMemberType(const string& arrName);
    //判断两个类型是否相同
    bool isSameType(const string& type1, const string& type2);
    //判断是否是基本类型
    bool isBasicType(const string& type);
    bool isBasicType(const int& type);
    
};
#endif