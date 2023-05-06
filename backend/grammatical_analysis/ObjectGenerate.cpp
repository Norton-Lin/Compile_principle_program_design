/**
 * @file ObjectGenerate.cpp
 * @brief 生成目标代码
 * @version 0.1
 * @date 2023-04-20
 * @author Linzhi 2020211472
 */
#include "ObjectGenerate.h"
void objectGenerate(CodeGenContext &context, string &filename)
{
    // 初始化llvm，设置目标机
    InitializeAllTargetInfos(); // 初始化所有目标信息
    InitializeAllTargets();     // 初始化所有目标
    InitializeAllTargetMCs();   // 初始化所有目标机码
    InitializeAllAsmParsers();  // 初始化所有汇编解析器
    InitializeAllAsmPrinters(); // 初始化所有汇编打印器

    // 获取目标三元组并设置
    string targetTriple = sys::getDefaultTargetTriple();
    context.module->setTargetTriple(targetTriple);

    // 获取目标机数据类型并设置
    string TargetError;
    const Target *target = TargetRegistry::lookupTarget(targetTriple, TargetError);
    if (!target)
    {
        errs() << TargetError;
        return;
    }
    // targetMachine对象表示目标架构，它包含了用于生成目标代码的所有必要信息。
    string CPU = "generic";
    string features = "";
    TargetOptions options;
    std::unique_ptr<llvm::TargetMachine> targetMachine(target->createTargetMachine(targetTriple, CPU, features, options, Reloc::Model::PIC_));
    // 设置模块的数据布局。数据布局描述了目标架构中数据类型的大小、对齐方式和字节顺序等信息
    context.module->setDataLayout(targetMachine->createDataLayout());

    // 设置目标文件类型
    CodeGenFileType type;
    if (filename[filename.size() - 1] == 's')
    { // 生成汇编文件
        type = CGFT_AssemblyFile;
    }
    else if (filename[filename.size() - 1] == 'o')
    { // 生成目标文件
        type = CGFT_ObjectFile;
    }
    else
    {
        errs() << "Unsupported target file format: " + filename;
        return;
    }

    // 将目标代码输出到文件
    error_code errorCode;
    // 原始文件描述符输出流。lvm::raw_ostream 类，并提供了将数据写入文件描述符的功能。
    raw_fd_ostream dest(filename.c_str(), errorCode, sys::fs::OF_None);
    legacy::PassManager passManager;

    // 设置优化流水线
    if (targetMachine->addPassesToEmitFile(passManager, dest, nullptr, llvm::CGFT_ObjectFile))
    {
        errs() << "theTargetMachine can't emit a file of this type";
        return;
    }
    passManager.run(*context.module);
    //将缓冲区数据写入文件
    dest.flush();
    outs() << "Object code generated successfully!"
           << "\n";
    outs() << "File name: " << filename.c_str() << "\n";
}
