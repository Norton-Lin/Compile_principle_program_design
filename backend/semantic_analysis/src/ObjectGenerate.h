#ifndef __OBJDECT_H__
#define __OBJDECT_H__
#include<llvm/Support/FileSystem.h>
#include<llvm/Support/Host.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Support/TargetRegistry.h>
#include<llvm/Support/TargetSelect.h>
#include<llvm/Support/FormattedStream.h>
#include<llvm/Target/TargetMachine.h>
#include<llvm/Target/TargetOptions.h>
#include<llvm/ADT/Optional.h>
#include"CodeGenerate.h"
using namespace std;
/**
 * @brief 生成目标代码
 * @param context 代码生成上下文
 * @param filename 目标代码文件名
*/
extern CodeGenContext context;
void objectGenerate(string& filename);
#endif