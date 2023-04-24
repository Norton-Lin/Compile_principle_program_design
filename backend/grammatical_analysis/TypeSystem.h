#ifndef _TYPESYSTEM_H__
#define _TYPESYSTEM_H__
#include <llvm/IR/Type.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <string>
#include <map>
#include <vector>
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
    map<string, llvm::Type*> types;
    map<string, string> arrayTypeList;           //数组元素类型列表
    map<string, vector<pair<int, int>> > arrayRangeList; //数组上下界列表
    map<string, llvm::ArrayType*> arrayTypes;       //数组变量对应的LLVM Type
    llvm::Type* getLLVMType(const string& name);
    //TypeSystem(LLVMContext& context): llvmContext(context) {}
    Type_IR(LLVMContext& context): llvmContext() {}
    Type* type_int = Type::getInt32Ty(llvmContext);
    Type* type_real = Type::getFloatTy(llvmContext);
    Type* type_char = Type::getInt8Ty(llvmContext);
    Type* type_boolen = Type::getInt1Ty(llvmContext);
    Type* type_void = Type::getVoidTy(llvmContext);
    Type* type_int64 = Type::getInt64Ty(llvmContext);
    //获取llvm类型
    Type* getLLVMType(const string& type);
    //增加llvm类型
    void addType(const string& name, Type* type);
    //判断两个类型是否相同
    bool isSameType(const string& type1, const string& type2);
    //判断是否是基本类型
    bool isBasicType(const string& type);
    //增加新记录
    void addRecord(const string& name, const vector<pair<string, string>>& members);
    //获取记录的成员
    vector<pair<string, string>> getRecordMembers(const string& name);
    //获取记录的成员类型
    string getRecordMemberType(const string& name, const string& member);
};
#endif