#include"CodeGenerate.h"
#include"ASTNodes.hpp"
void CodeGenContext::init_funcStack()
{
    cout<< "CodeGenerate::init_funcStack" << endl;
    vector<Type*> param;
    //写整数
    param.push_back(this->type_ir.type_int);
    FunctionType* func_type = FunctionType::get(this->type_ir.type_void,param,false);
    Function* func = Function::Create(func_type,Function::ExternalLinkage,"write_int",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //写实数
    param.push_back(this->type_ir.type_real);
    func_type = FunctionType::get(this->type_ir.type_void,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"write_real",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //写字符
    param.push_back(this->type_ir.type_char);
    func_type = FunctionType::get(this->type_ir.type_void,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"write_char",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //写布尔
    param.push_back(this->type_ir.type_boolen);
    func_type = FunctionType::get(this->type_ir.type_void,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"write_boolen",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //读整数
    param.push_back(this->type_ir.type_void);
    func_type = FunctionType::get(this->type_ir.type_int,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"read_int",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //读实数
    param.push_back(this->type_ir.type_void);
    func_type = FunctionType::get(this->type_ir.type_real,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"read_real",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //读字符
    param.push_back(this->type_ir.type_void);
    func_type = FunctionType::get(this->type_ir.type_char,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"read_char",this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    //读布尔
    param.push_back(this->type_ir.type_void);
    func_type = FunctionType::get(this->type_ir.type_boolen,param,false);
    func = Function::Create(func_type,Function::ExternalLinkage,"read_boolen",this->module.get());
    this->funcStack.push_back(func);
    param.clear();

}
//AST CodeGenerate

//元素 常量 变量 类型
//常量元素：
/**
 * 常量IR生成
 * @param context 上下文
 * @return Value*
*/
Value* const_value_AST::code_generation(CodeGenContext& context)
{
    cout<< "const_value_AST::code_generation" << endl;
    Value* ret = nullptr;
    if (this->s_type == "integer")
    {
        int value = this->s_integer<0 ? -this->s_integer : this->s_integer;
        ret = ConstantInt::get(context.type_ir.type_int,value,true);
    }
    else if (this->s_type == "real")
    {
        float value = this->s_real<1e-6 ? -this->s_real : this->s_real;
        ret = ConstantFP::get(context.type_ir.type_real, value);
    }
    else if (this->s_type == "char")
    {
        char value = this->s_char;
        ret = ConstantInt::get(context.type_ir.type_char,value);
    }
    else if (this->s_type == "boolean")
    {
        bool value = this->s_boolean;
        ret = ConstantInt::get(context.type_ir.type_boolen, value);
    }
    else
    {
        //报错
        //可能需要一个位置信息 todo
        ret = LogErrorV("unknown const type"+this->s_type);
    }
    return ret;
}
/**
 * 变量IR生成
 * @param context 上下文
 * @return Value*
*/
Value* variable_AST::code_generation(CodeGenContext& context)
{
    cout<< "variable_AST::code_generation" << endl;
    //从符号表中获取这个变量信息    todo
    //如果是数组，需要计算偏移量
    //如果是变量，直接返回
    auto record = nullptr;//暂定
    Value* ret = nullptr;//局部变量地址
    Type* type = nullptr;
    //Type* type = context.type_ir.getLLVMType(record->type);//局部变量类型
    //是数组
    if(this->is_array)
    {
        Type* array_type = type;
        //数组元素直接用数据定义，获取数据类型
        if(array_type == nullptr)
        {
            //获取数据类型 todo
        }
        //栈上创建局部变量
        if(array_type)
            ret = context.builder->CreateAlloca(array_type);
    }
    else
    {
        if(type == nullptr)
            return LogErrorV("unknown variable type");
        ret = context.builder->CreateAlloca(type);
    }
    if(ret == nullptr)
        return LogError("create alloca failed");
    return ret;
}

/**
 * 类型IR生成
 * @param context 上下文
 * @return Value*
*/
Value* type_AST::code_generation(CodeGenContext& context){
    cout<< "type_Ast::code_generation" << endl;
    //数组类型
    if(this->l_isarray)
    {
        cout<< "type_Ast::code_generation is_array" << endl;
        int size = 1;
        int dimension = this->s_index_list.size();//多维
        for(auto& item : this->s_index_list)
        {
            size *= (item.second-item.second+1);
        }
        Type* type = context.type_ir.getLLVMType(this->s_type);
        if(type == nullptr)
        {
            return LogErrorV("unknown type");
        }
        ArrayType* arraytype = ArrayType::get(type,size);
        //todo 记录新类型
    }
    return nullptr;
}

//函数
/**
 * program IR生成
*/
Value* program_body_AST::code_generation(CodeGenContext& context){
    cout<< "program_body::code_generation" << endl;
    //生成函数
    FunctionType* type = FunctionType::get(context.type_ir.type_void,false);
    Function* program = Function::Create(type,Function::ExternalLinkage,"main",context.module.get());
    //生成基本块
    BasicBlock* block = BasicBlock::Create(context.llvmContext,"entry",program);
    //主程序块生成
    context.builder = make_unique<IRBuilder<>>(block);
    return nullptr;
}
/**
 * subprogram IR生成
*/
Value* subprogram_body_AST::code_generation(CodeGenContext& context){
    cout<< "program_body::code_generation" << endl;
    //生成函数
    FunctionType* type = FunctionType::get(context.type_ir.type_void,false);
    Function* program = Function::Create(type,Function::ExternalLinkage,"sub",context.module.get());
    //生成基本块
    BasicBlock* block = BasicBlock::Create(context.llvmContext,"entry",program);
    //块插入
    context.builder->SetInsertPoint(block);
    return nullptr;
}
/**
 * 过程调用 IR生成
*/
Value* procedure_call_AST::code_generation(CodeGenContext& context){
    cout<< "procedure_call_AST::code_generation" << endl;
    //符号表里寻找procedeure id     todo
    auto record = nullptr;
    if(record == nullptr)
        return LogErrorV("procedure not found in sympol table");
    vector<Value*> args;//获取参数列表
    for(auto& item : this->s_list)
    {
        //对每个参数进行解析
        Value* value = item->code_generation(context);
        if(value == nullptr)
            return LogErrorV("procedure call failed - param analyse failed");
        //获取参数类型 todo
        //string type = ...;从符号表找
        string type = "";
        if(type == "real")
            value = context.builder->CreateFPToSI(value,context.type_ir.type_int);
        args.push_back(value);
    }
    //获取一个过程指针 todo
    //Function* pro_ptr = record->func;
    Function* pro_ptr = nullptr;
    return context.builder->CreateCall(pro_ptr,args,"Call Procedure");
}
/**
 * wirte 语句
 * @param args 参数 需要一个参数列表，表示读的数是个啥 todo,暂定int型
*/
Value* procedure_call_AST::write(CodeGenContext& context,int types[])
{
    cout<<"procedure_call_AST::wirte_procedure"<<endl;
    vector<Value*> args;
    int count = 0;
    for(auto& item:s_list)
    {
        args.clear();
        if(item->value == nullptr)
            args.push_back(item->code_generation(context));
        if(args.empty())
            return LogErrorV("write procedure failed");
        context.builder->CreateCall(context.funcStack[types[count]],args,"write");
        ++count;
    }
    return nullptr;
}
/**
 * read 语句
 * @param args 参数 需要一个参数列表，表示读的数是个啥 todo,暂定int型
*/
Value* procedure_call_AST::read(CodeGenContext& context,int types[])
{
    cout<<"procedure_call_AST::read_procedure"<<endl;
    vector<Value*> args;
    

    int count = 0;
    for(auto& item:s_list)
    {
        Value* ret = context.builder->CreateCall(context.funcStack[types[count]],args,"read");
        Value* addr = nullptr;
        if(item->value == nullptr)//todo 是数组
            ;//获取一个指针
        else
            addr = item->value;//可能需要查符号表
        context.builder->CreateStore(ret,addr);
        ++count;
    }
    return nullptr;
}


//语句

//引用


//辅助函数
/**
 * 获取数组元素指针
*/
Value* get_array_item(CodeGenContext& context,const string& type, Value* array, int index)
{
    cout<<"get_array_item"<<endl;
    Type* item_type = context.type_ir.getLLVMType(type); 
    if(item_type == nullptr)
        return LogErrorV("unknown type");
    auto base = ConstantInt::get(context.type_ir.type_int,0);
    auto offset = ConstantInt::get(context.type_ir.type_int,index);
    Value* ret = context.builder->CreateGEP(item_type,array,{base,offset});
    if(ret == nullptr)
        return LogErrorV("get array item failed");
    return ret;
}
