#ifndef __CODEGENERATE_H_
#define __CODEGENERATE_H_

#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/LLVMContext.h>
#include<llvm/IR/Module.h>
#include<llvm/IR/Type.h>
#include<llvm/IR/Value.h>
#include<llvm/IR/LegacyPassManager.h>
#include<llvm/IR/IRPrintingPasses.h>
#include<llvm/IR/BasicBlock.h>
#include<llvm/IR/Constants.h>
#include<llvm/IR/DerivedTypes.h>
#include<llvm/IR/Function.h>
#include<llvm/IR/Verifier.h>
#include<llvm/Support/DynamicLibrary.h>
#include<llvm/Support/Casting.h>
#include<llvm/Support/TargetSelect.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Support/FileSystem.h>
#include<llvm/Support/ToolOutputFile.h>
#include<llvm/Support/TargetRegistry.h>
#include<llvm/Support/TargetSelect.h>
#include<llvm/ADT/APFloat.h>
#include<llvm/ADT/STLExtras.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<memory>
#include<iostream>
#include"TypeSystem.h"
//验证类型
#define ISTYPE(value, id) (value->getType()->getTypeID() == id)
using namespace std;
using namespace llvm;
/**
 * 在整个编译器程序中使用一个单例的CodeGenContext对象
 * 维护全局的编译信息。在这个对象中主要维护的成员包括
 * 处理CodeGenBlock时所用到的栈blockStack，
 * 全局变量表globalVars以及类型系统单例typeSystem，
 * 以及之后生成中间代码时需要用到的LLVM提供的相关对象。
*/
class CodeGenContext { 
public:
    LLVMContext llvmContext;
    unique_ptr<IRBuilder<>> builder;
    unique_ptr<Module> module;//中间代码生成对象
    Type_IR type_ir;//自定义类型系统
    vector<Function*> funcStack;//函数栈
    CodeGenContext(): type_ir(llvmContext) {
        module = make_unique<Module>("main", this->llvmContext);
    }
    //初始化库函数
    void init_funcStack();
};
Value* LogErrorV(string str);
Value* LogError(const char *str);
//获取数组元素指针
Value* get_array_item(CodeGenContext& context,const string& type, Value* array, int index);
//Value* getArrayIndex(string type,vector<T> idvaprt);
#endif
