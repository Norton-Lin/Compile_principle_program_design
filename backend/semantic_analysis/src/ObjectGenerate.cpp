/**
 * @file ObjectGenerate.cpp
 * @brief 生成目标代码
 * @version 0.1
 * @date 2023-04-20
 * @author Linzhi 2020211472
 */
#include "ObjectGenerate.h"
void objectGenerate(string &filename)
{
    // 初始化llvm，设置目标机
    llvm::InitializeAllTargetInfos(); // 初始化所有目标信息
    llvm::InitializeAllTargets();     // 初始化所有目标
    llvm::InitializeAllTargetMCs();   // 初始化所有目标机码
    llvm::InitializeAllAsmParsers();  // 初始化所有汇编解析器
    llvm::InitializeAllAsmPrinters(); // 初始化所有汇编打印器

    // 获取目标三元组并设置
    string targetTriple = llvm::sys::getDefaultTargetTriple();
    context.module->setTargetTriple(targetTriple);

    // 获取目标机数据类型并设置
    string TargetError;
    const llvm::Target *target = llvm::TargetRegistry::lookupTarget(targetTriple, TargetError);
    if (!target)
    {
        llvm::errs() << TargetError;
        return;
    }
    // targetMachine对象表示目标架构，它包含了用于生成目标代码的所有必要信息。
    string CPU = "generic";
    string features = "";
    llvm::TargetOptions options;
    std::unique_ptr<llvm::TargetMachine> targetMachine(target->createTargetMachine(targetTriple, CPU, features, options, llvm::Reloc::Model::PIC_));
    // 设置模块的数据布局。数据布局描述了目标架构中数据类型的大小、对齐方式和字节顺序等信息
    context.module->setDataLayout(targetMachine->createDataLayout());

    // 设置目标文件类型
    llvm::CodeGenFileType type;
    if (filename[filename.size() - 1] == 's')
    { // 生成汇编文件
        type = llvm::CGFT_AssemblyFile;
    }
    else if (filename[filename.size() - 1] == 'o')
    { // 生成目标文件
        type = llvm::CGFT_ObjectFile;
    }
    else
    {
        llvm::errs() << "Unsupported target file format: " + filename;
        return;
    }

    // 将目标代码输出到文件
    error_code errorCode;
    // 原始文件描述符输出流。lvm::raw_ostream 类，并提供了将数据写入文件描述符的功能。
    llvm::raw_fd_ostream dest(filename.c_str(), errorCode, llvm::sys::fs::OF_None);
    llvm::legacy::PassManager passManager;

    // 设置优化流水线
    if (targetMachine->addPassesToEmitFile(passManager, dest, nullptr, llvm::CGFT_ObjectFile))
    {
        llvm::errs() << "theTargetMachine can't emit a file of this type";
        return;
    }
    passManager.run(*context.module);
    //将缓冲区数据写入文件
    dest.flush();
    llvm::outs() << "Object code generated successfully!"
           << "\n";
    llvm::outs() << "File name: " << filename.c_str() << "\n";
}
