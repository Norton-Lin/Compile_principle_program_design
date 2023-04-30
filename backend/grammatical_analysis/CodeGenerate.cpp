#include "CodeGenerate.h"
#include "ASTNodes.hpp"
extern SymbolTable symbolTable;
extern CodeGenContext context;
/**
 * 初始化库函数
 */
void CodeGenContext::init_funcStack()
{
    cout << "CodeGenerate::init_funcStack" << endl;
    vector<Type *> param;
    // 写整数
    param.push_back(this->type_ir.type_int);
    llvm::FunctionType *func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    Function *func = Function::Create(func_type, Function::ExternalLinkage, "write_int", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 写实数
    param.push_back(this->type_ir.type_real);
    func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "write_real", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 写字符
    param.push_back(this->type_ir.type_char);
    func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "write_char", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 写布尔
    param.push_back(this->type_ir.type_boolean);
    func_type = llvm::FunctionType::get(this->type_ir.type_void, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "write_boolean", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读整数
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_int, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "read_int", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读实数
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_real, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "read_real", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读字符
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_char, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "read_char", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    // 读布尔
    param.push_back(this->type_ir.type_void);
    func_type = llvm::FunctionType::get(this->type_ir.type_boolean, param, false);
    func = Function::Create(func_type, Function::ExternalLinkage, "read_boolean", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
    sys::DynamicLibrary::AddSymbol("write_int", this->funcStack[0]);
    sys::DynamicLibrary::AddSymbol("write_real", this->funcStack[1]);
    sys::DynamicLibrary::AddSymbol("write_char", this->funcStack[2]);
    sys::DynamicLibrary::AddSymbol("write_boolean", this->funcStack[3]);
    sys::DynamicLibrary::AddSymbol("read_int", this->funcStack[4]);
    sys::DynamicLibrary::AddSymbol("read_real", this->funcStack[5]);
    sys::DynamicLibrary::AddSymbol("read_char", this->funcStack[6]);
    sys::DynamicLibrary::AddSymbol("read_boolean", this->funcStack[7]);
}
// AST CodeGenerate
/**
 * 主程序IR生成 该模块已完成
 */
Value *programstruct_AST::code_generation()
{
    cout << "programstruct_AST::code_generation" << endl;
    // 生成main program
    llvm::FunctionType *type = llvm::FunctionType::get(context.type_ir.type_void, false);
    Function *program = Function::Create(type, Function::ExternalLinkage, "main", context.module.get());
    // 基本块生成
    BasicBlock *block = BasicBlock::Create(context.llvmContext, "entry", program, 0);
    // 主程序块生成
    context.builder = make_unique<IRBuilder<>>(block);
    return nullptr;
}
// 常量元素：
/**
 * 常量定义IR生成 该模块已完成
 * @return Value* 常量的llvm Value
 */
Value *const_value_AST::code_generation()
{
    cout << "const_value_AST::code_generation" << endl;
    Value *ret = nullptr;
    if (this->s_type == "integer")
    {
        int value = this->s_int < 0 ? -this->s_int : this->s_int;
        ret = ConstantInt::get(context.type_ir.type_int, value, true);
    }
    else if (this->s_type == "real")
    {
        double value = this->s_real < 1e-6 ? -this->s_real : this->s_real;
        ret = ConstantFP::get(context.type_ir.type_real, value);
    }
    else if (this->s_type == "char")
    {
        char value = this->s_char;
        ret = ConstantInt::get(context.type_ir.type_char, value, true);
    }
    else if (this->s_type == "boolean")
    {
        bool value = this->s_bool;
        ret = ConstantInt::get(context.type_ir.type_boolean, value, true);
    }
    else
    {
        ret = LogErrorV("unknown const type" + this->s_type);
    }
    return ret;
}
// 元素 常量 变量 类型

/**
 * 变量声明IR生成 该模块已完成 
 * bug可能出现在 数组定义
 * @return Value* 局部变量地址
 */
Value *variable_AST::code_generation()
{
    cout << "variable_AST::code_generation" << endl;
    this->item = symbolTable.get(this->s_identifier);
    if (this->item == nullptr)
        return LogErrorV("unknown variable name" + this->s_identifier);
    Value *ret = nullptr;                                   // 局部变量地址
    Type *type = nullptr; // 局部变量类型
    if (this->s_isarray)
    {
        // 获取数组对应的llvm type
        type = context.type_ir.getArrayLLVMType(this->item);
        // 数组元素直接用数据定义，获取数据类型
        if (type == nullptr)//数组类型未定义
            type = context.type_ir.createArrayType(this->item);//新建数组类型
        // 栈上创建局部变量
        if (type)
            ret = context.builder->CreateAlloca(type, nullptr);
    }
    else
    {
        type = context.type_ir.getLLVMType(this->s_type);//获取基本变量类型
        if (type == nullptr)
            return LogErrorV("unknown variable type");
        ret = context.builder->CreateAlloca(type, nullptr);
    }
    if (ret == nullptr)
        return LogError("create alloca failed");
    return ret;
}

/**
 * 类型IR生成
 * 没用
 * @return Value*
 */
Value *type_AST::code_generation()
{
    //似乎没用，var那里生成了
    cout << "type_Ast::code_generation" << endl;
    // 数组类型
    Type* ret = nullptr;
    if (this->l_isarray)
    {
        cout << "type_Ast::code_generation is_array" << endl;
    }
    return nullptr;
}

// 函数
/**
 * 函数 过程定义IR生成 该模块已完成
 * bug可能出现在 传值传引用 符号表存储
 * @return Value* 函数地址指针
 */
Function* subprogram_head_AST::code_generation()
{
    cout<<"subprogram_head_AST::code_generation"<<endl;
    vector<Type*> argTypes;
    vector<pair<string,bool>> argNames;//形参名字和是否是引用传递
    //从一堆s_list中获取每个形参的类型,我同时可以知道他们是否是引用传递
    for(int i = 0 ;i<this->s_list.size();i++)
    {
        //获取每个形参的llvm类型
        for(int j = 0;i<s_list[i]->s_id_list.size();++j)
        {
            argTypes.push_back(context.type_ir.getLLVMType(this->s_list[i]->s_type));
            argNames.push_back(make_pair(this->s_list[i]->s_id_list[j],this->s_list[i]->s_isvar));
        }
    }
    //获取函数返回值类型
    //若是过程就是void
    string ret_string = (s_ret_type == "") ? "void":this->s_ret_type;
    Type* retType = context.type_ir.getLLVMType(ret_string);
    //生成函数类型
    FunctionType* type = FunctionType::get(retType,argTypes,false);
    //生成函数
    Function* func = Function::Create(type,Function::ExternalLinkage,this->program_name,context.module.get());
    //生成基本块
    BasicBlock* block = BasicBlock::Create(context.llvmContext,"entry",func,0);
    context.builder->SetInsertPoint(block);
    //形参
    auto argName = argNames.begin();
    auto argType =argTypes.begin();
    SymbolTableItem* item = nullptr;
    for(auto& arg:func->args())
    {
        arg.setName(argName->first);
        Value* loc = nullptr;
        if(argName->second)//是引用传递
        {
            //获取引用值地址
            loc =&arg;//传入值是地址
            Value* tmp = context.builder->CreateLoad(loc);//载入数据
            context.builder->CreateStore(tmp,loc,false);//参数存到地址中
        }  
        else
        {
            //获取局部变量地址
            loc = context.builder->CreateAlloca(*argType,nullptr,argName->first);
            context.builder->CreateStore(&arg,loc,false);//参数存到地址中
        }
        //符号表记录形参
        item = symbol_table->get(argName->first);//获取符号表项
        item->value.basic_val->llvmvalue = loc;//记录形参地址
        argName++;
        argType++;
    }
    return func;
}
/**
 * 函数返回值生成， 该模块未完全完成
 */
//此处建议，用符号表记录返回值
Value* subprogram_body_AST::ret_generation(Value* ret)
{
    //语义分析需要加一个标记，标记是否是函数
    if(isfunction)
    {
        context.builder->CreateRetVoid();
    }
    else{
        context.builder->CreateRet(ret);//符号表记录返回值
    }
}
/**
 * program IR生成
 *该模块已完成,与program_structure_AST::code_generation()重复
 */
Value *program_body_AST::code_generation()
{
    cout << "program_body::code_generation" << endl;
    // 生成函数
    llvm::FunctionType *type = llvm::FunctionType::get(context.type_ir.type_void, false);
    Function *program = Function::Create(type, Function::ExternalLinkage, "main", context.module.get());
    // 生成基本块
    BasicBlock *block = BasicBlock::Create(context.llvmContext, "entry", program);
    // 主程序块生成
    context.builder = make_unique<IRBuilder<>>(block);
    return nullptr;
}
/**
 * subprogram IR生成
 * 该模块已完成,废弃
 */
Value *subprogram_body_AST::code_generation()
{
    cout << "program_body::code_generation" << endl;
    // 生成函数
    llvm::FunctionType *type = llvm::FunctionType::get(context.type_ir.type_void, false);
    Function *program = Function::Create(type, Function::ExternalLinkage, "sub", context.module.get());
    // 生成基本块
    BasicBlock *block = BasicBlock::Create(context.llvmContext, "entry", program);
    // 块插入
    context.builder->SetInsertPoint(block);
    return nullptr;
}
/**
 * 过程调用 IR生成  该模块已完成
 * @return Value* 过程call
 */
Value *procedure_call_AST::code_generation()
{
    cout << "procedure_call_AST::code_generation" << endl;
    // 符号表里寻找procedeure id
    //当然，这里可能拿过了
    this->s_item = symbolTable.get(this->s_identifier);
    if (this->s_item == nullptr)
        return LogErrorV("procedure not found in sympol table");
    vector<Value *> args; // 获取参数列表
    int count = 0;
    for (auto &item : s_value_list)
    {
        if (s_type_list[count]== "real")
            item = context.builder->CreateSIToFP(item, context.type_ir.type_int);
        args.push_back(item);
        ++count;
    }
    // 获取一个过程指针 todo
    // Function* pro_ptr = record->func;
    Function *pro_ptr = nullptr;
    return context.builder->CreateCall(pro_ptr, args, "Call Procedure");
    /**
     * 也可以这么写,上面那个做了错误处理，但是，语义分析那里就爆了，所以没必要23333
     *  auto ptr = s_item->value.function_val;//获取函数符号表指针
     * Function* call = ptr->llvmfunction;//获取函数指针
     * return context.builder->CreateCall(call, s_value_list, "Call Procedure")
    */
}
/**
 * 函数调用 IR生成  该模块已完成
 * @return Value* 函数call
*/
Value *factor_AST::function_call_generation()
{
    cout<<"factor_AST::function_call_generation"<<endl;
    auto ptr = s_func_item->value.function_val;//获取函数符号表指针
    Function* call = ptr->llvmfunction;//获取函数指针
    return context.builder->CreateCall(call, s_parameter_list, "Call Function");
}
// 表达式
/**
 * factor IR生成
 * 因子
 * 该部分包括 常数值、变量值、函数调用、表达式、取非、取负
 */
Value *factor_AST::code_generation()
{
    cout << "factor_AST::code_generation" << endl;
    Value *value = nullptr;
    // 四种常数
    switch (s_state)
    {
    case 1: // 常数
    {
        if (s_type == "integer")
            value = ConstantInt::get(context.type_ir.type_int, s_int, true);
        else if (s_type == "real")
            value = ConstantInt::get(context.type_ir.type_real, s_real, true);
        else if (s_type == "char")
            value = ConstantInt::get(context.type_ir.type_char, s_char, true);
        else if (s_type == "boolean")
            value = ConstantInt::get(context.type_ir.type_boolean, s_bool, true);
    }
    break;
    case 2:
    {
        value = this->s_value; // 变量，拿解析值
    }
    break;
    case 3: // 函数、表达式
    {
        value = this->s_value; // 变量，拿解析值
    }
    break;
    case 4: //单目运算符
    {
        if (this->s_op == "!") // 取非
            value = context.builder->CreateNot(this->s_operand0, "not");
        else if (this->s_op == "1") // 取负
        {
            // 浮点形
            if (this->s_operand0_type == "real")
            {
                Value *temp = ConstantFP::get(context.type_ir.type_real, (double)(0.0));
                value = context.builder->CreateFNeg(this->s_operand0, "uminus");
            }
            else
            {
                Value *temp = ConstantInt::get(context.type_ir.type_real, 0, true);
                value = context.builder->CreateNeg(this->s_operand0, "uminus");
            }
        }
    }
    break;
    }
    // 可以语法做
    // this->s_value = value;
    return value;
}
/**
 * term IR生成
 * 该部分包括 mulop ： *、/、div、mod 和 and
 */
Value *term_AST::code_generation()
{
    cout << "term_AST::code_generation" << endl;
    // 二位运算符
    Value* value = nullptr;
    //类型转换,待浮点全部转浮点 /运算好像不用
    bool judge = true;
    if(operand0_type=="real"||operand1_type=="real"){
        operand0 = context.builder->CreateSIToFP(operand0,context.type_ir.type_real);
        operand1 = context.builder->CreateSIToFP(operand1,context.type_ir.type_real);
        judge = false;
    }
    if(s_op=="*"){
        if(judge)
            value = context.builder->CreateMul(operand0,operand1,"multmp");
        else
            value = context.builder->CreateFMul(operand0,operand1,"multmp");
    }
    //两种除法有待商榷
    else if(s_op=="/"){
        if(judge)
            value = context.builder->CreateSDiv(operand0,operand1,"divtmp");
        else
            value = context.builder->CreateFDiv(operand0,operand1,"div");
    }
    else if(s_op=="div"){
        if(judge)
            value = context.builder->CreateSDiv(operand0,operand1,"divtmp");
        else
            value = context.builder->CreateFDiv(operand0,operand1,"divtmp");
    }
    //取模没有浮点
    else if(s_op=="mod"){
        value = context.builder->CreateSRem(operand0,operand1,"modtmp");
    }
    else if(s_op=="and"){
        value = context.builder->CreateAnd(operand0,operand1,"andtmp");
    }
    return value;
}
/**
 * simple_expression IR生成
 * 该部分包括 addop ：+、-、or
*/
Value *simple_expression_AST::code_generation()
{
    cout << "simple_expression_AST::code_generation" << endl;
    Value* value = nullptr;
    //类型转换,待浮点全部转浮点 /运算好像不用
    bool judge = true;
    if(operand0_type=="real"||operand1_type=="real"){
        operand0 = context.builder->CreateSIToFP(operand0,context.type_ir.type_real);
        operand1 = context.builder->CreateSIToFP(operand1,context.type_ir.type_real);
        judge = false;
    }
    if(s_op=="+"){
        if(judge)
            value = context.builder->CreateAdd(operand0,operand1,"addtmp");
        else
            value = context.builder->CreateFAdd(operand0,operand1,"addtmp");
    }
    //两种除法有待商榷
    else if(s_op=="-"){
        if(judge)
            value = context.builder->CreateSub(operand0,operand1,"subtmp");
        else
            value = context.builder->CreateFSub(operand0,operand1,"subtmp");
    }
    else if(s_op=="or"){
        value = context.builder->CreateOr(operand0,operand1,"ortmp");
    }
    return value;
}
/**
 * expression IR生成
 * 该部分包括 relop ：=、<>、<、<=、>、>=
*/
Value *expression_AST::code_generation()
{
    cout << "expression_AST::code_generation" << endl;
    Value* value = nullptr;
    //类型转换,带浮点全部转浮点 
    bool judge = true;
    if(operand0_type=="real"||operand1_type=="real"){
        operand0 = context.builder->CreateSIToFP(operand0,context.type_ir.type_real);
        operand1 = context.builder->CreateSIToFP(operand1,context.type_ir.type_real);
        judge = false;
    }
    if(s_op=="<"){
        if(judge)
            value = context.builder->CreateICmpSLT(operand0,operand1,"lttmp");
        else
            value = context.builder->CreateFCmpULT(operand0,operand1,"lttmp");
    }
    else if(s_op=="<="){
        if(judge)
            value = context.builder->CreateICmpSLE(operand0,operand1,"letmp");
        else
            value = context.builder->CreateFCmpULE(operand0,operand1,"letmp");
    }else if(s_op==">"){
        if(judge)
            value = context.builder->CreateICmpSGT(operand0,operand1,"gttmp");
        else
            value = context.builder->CreateFCmpUGT(operand0,operand1,"gttmp");
    }else if(s_op==">="){
        if(judge)
            value = context.builder->CreateICmpSGE(operand0,operand1,"getmp");
        else
            value = context.builder->CreateFCmpUGE(operand0,operand1,"getmp");
    }else if(s_op=="="){
        if(judge)
            value = context.builder->CreateICmpEQ(operand0,operand1,"eqtmp");
        else
            value = context.builder->CreateFCmpUEQ(operand0,operand1,"eqtmp");
    }else if(s_op=="<>"){
        if(judge)
            value = context.builder->CreateICmpNE(operand0,operand1,"netmp");
        else
            value = context.builder->CreateFCmpUNE(operand0,operand1,"netmp");
    }
    return value;
}

// 语句
Value *statement_AST::code_generation()
{
    cout << "statement_AST::code_generation" << endl;
    // todo
    return nullptr;
}
/**
 * if 语句
 * 第一阶段
*/
Value* statement_AST::if_code_generation_1()
{
    cout << "statement_AST::if_code_generation" << endl;
    if(s_expression_value == nullptr)
        return LogErrorV("if expression is null");
    s_expression_value = expressionToBoolean(s_expression_value);
    function = context.builder->GetInsertBlock()->getParent();//得到if语句所属函数
    block1 = llvm::BasicBlock::Create(context.llvmContext, "then", function);
    block2 = llvm::BasicBlock::Create(context.llvmContext, "else"); // else部分
    block3 = llvm::BasicBlock::Create(context.llvmContext, "ifcont");
    if(s_has_else)
    {
        //有else
        context.builder->CreateCondBr(s_expression_value, block1, block2);
    } 
    else{
        //无else
        context.builder->CreateCondBr(s_expression_value, block1, block3);
    }
    context.builder->SetInsertPoint(block1);
    IP = context.builder->saveIP();//保存插入点
    return nullptr;
}
/**
 * if 语句
 * 第二阶段
*/
Value* statement_AST::if_code_generation_2()
{
    context.builder->restoreIP(IP);
    //restoreIP(IP);//恢复插入点
    block1 = context.builder->GetInsertBlock();
    // 在thenBB插入的最后一条指令是ret，则不再跳转回final_block
    if(block1->getTerminator()== nullptr)
        context.builder->CreateBr(block3);
    if(s_has_else)
    {
        function->getBasicBlockList().push_back(block2);
        context.builder->SetInsertPoint(block2);
        IP = context.builder->saveIP();//保存插入点
        //生成else
    }
    return nullptr;
}
/**
 * if语句
 * 第三阶段
*/
Value *statement_AST::if_code_generation_3()
{
    context.builder->restoreIP(IP);
    if(s_has_else)
    {
        if(block2->getTerminator()== nullptr)
            context.builder->CreateBr(block3);
    }
    function->getBasicBlockList().push_back(block3);
    context.builder->SetInsertPoint(block3);
    return nullptr;
}
/**
 * for语句
 * 第一阶段
*/
Value *statement_AST::for_code_generation_1()
{
    cout<<"statement_AST::for_code_generation"<<endl;
    function = context.builder->GetInsertBlock()->getParent();//得到for语句所属函数
    block1 = llvm::BasicBlock::Create(context.llvmContext, "forloop", function);
    block2 = llvm::BasicBlock::Create(context.llvmContext, "forcont", function);
    s_expression_value = expressionToBoolean(s_expression_value);//条件值
    context.builder->CreateCondBr(s_expression_value, block1, block2);
    context.builder->SetInsertPoint(block1);
    IP = context.builder->saveIP();//保存插入点
    //循环体生成
    return nullptr;
}
/**
 * for语句
 * 第二阶段
*/
Value *statement_AST::for_code_generation_2()
{
    context.builder->SetInsertPoint(block1);//设置插入点，这个地方有待考量
    s_expression_value = expressionToBoolean(s_expression_value);//条件值
    context.builder->CreateCondBr(s_expression_value, block1, block2);
    function->getBasicBlockList().push_back(block2);
    context.builder->SetInsertPoint(block2);
    return nullptr;
}
/**
 * while语句
 * 第一阶段
*/
Value* statement_AST::while_code_generation_1()
{
    cout<<"statement_AST::while_code_generation"<<endl;
    function = context.builder->GetInsertBlock()->getParent();//得到while语句所属函数
    block1 = llvm::BasicBlock::Create(context.llvmContext, "whileloop", function);
    block2 = llvm::BasicBlock::Create(context.llvmContext, "whilecont", function);
    s_expression_value = expressionToBoolean(s_expression_value);//条件值
    context.builder->CreateCondBr(s_expression_value, block1, block2);
    context.builder->SetInsertPoint(block1);
    IP = context.builder->saveIP();//保存插入点
    return nullptr;
}
/**
 * while语句
 * 第二阶段
*/
Value* statement_AST::while_code_generation_2()
{
    context.builder->SetInsertPoint(block1);//设置插入点，这个地方有待考量
    s_expression_value = expressionToBoolean(s_expression_value);//条件值
    context.builder->CreateCondBr(s_expression_value, block1, block2);
    function->getBasicBlockList().push_back(block2);
    context.builder->SetInsertPoint(block2);
    return nullptr;
}
/**
 * assign语句
*/
Value* statement_AST::assign_code_generation()
{
    cout<<"statement_AST::assign_code_generation"<<endl;
    //获取左值 item
    SymbolTableItem* item = this->s_variable->item;
    if(item == nullptr)
        return LogErrorV("assign_code_generation: item is null");
    //获取左值,左值可以是变量，也可以是数组元素，
    Value* value = nullptr;//左值变量地址
    if(this->s_expression_type == "return")//函数返回值
    {
        //记录函数返回值
        item->value.function_val->ret_llvmval = s_expression_value;
        return nullptr;
    }
    if(item->type == 6&&s_expression_type=="integer"){
        s_expression_value = context.builder->CreateSIToFP(s_expression_value, context.type_ir.type_real);
    }
    if(item->type == 5&&s_expression_type=="real"){
        s_expression_value = context.builder->CreateFPToSI(s_expression_value, context.type_ir.type_int);
    }
    if(s_variable->s_isarray)//可能有问题 
    {
        //获取指针 获取数组元素地址
        //Value* ptr = nullptr;
        value = get_item(this->s_variable);
        context.builder->CreateStore(s_expression_value, value);
    }
    else{
        value = item->value.basic_val->llvmvalue;
        context.builder->CreateStore(s_expression_value, value);
    }
    return value;

}
/**
 * wirte 语句
 */
Value *statement_AST::write()
{
    cout << "statement_AST::wirte_procedure" << endl;
    vector<Value *> args;
    int count = 0;
    int index = 0;
    for (auto &item : s_value_list)
    {
        args.clear();
        args.push_back(item);
        if (args.empty())
            return LogErrorV("write procedure failed");   
        if(s_type_list[count]=="integer")
            index = 0;
        else if(s_type_list[count]=="real")
            index = 1;
        else if(s_type_list[count]=="char")
            index = 2;
        else if(s_type_list[count]=="boolean")
            index = 3;
        //调用库函数
        context.builder->CreateCall(context.funcStack[index], args, "write");
        ++count;
    }
    return nullptr;
}
/**
 * read 语句
 */
Value *statement_AST::read()
{
    cout << "procedure_call_AST::read_procedure" << endl;
    vector<Value *> args;
    int index;
    int count = 0;
    for (auto &item : s_variable_list)
    {
        if(s_type_list[count]=="integer")
            index = 4;
        else if(s_type_list[count]=="real")
            index = 5;
        else if(s_type_list[count]=="char")
            index = 6;
        else if(s_type_list[count]=="boolean")
            index = 7;
        Value *ret = context.builder->CreateCall(context.funcStack[index], args, "read");
        //todo 变量操作
        Value *addr = nullptr;
        addr = item->item->value.basic_val->llvmvalue; // 获取变量地址
        context.builder->CreateStore(ret, addr);
        ++count;
    }
    return nullptr;
}

// 引用
Value* variable_AST::code_generation()
{
    cout<<"variable_AST::code_generation"<<endl;
    //获取左值 item
    SymbolTableItem* item = this->item;
    Value* addr = nullptr;//左值变量地址
    if(item->type<9)//普通变量
    {
        addr = item->value.basic_val->llvmvalue;
        this->llvmleftValue = addr;
        return context.builder->CreateLoad(addr,false,"");
    }
    else if(item->type==10)//数组
    {
        //获取数组
        addr = get_item(this);
        this->llvmleftValue = addr;
        return context.builder->CreateLoad(addr,false,"");
    }
}
// 辅助函数
/**
 * 获取左值
*/
Value* get_item(variable_AST* var)
{
    cout<<"get_item"<<endl;
    Value* ptr = nullptr;
    SymbolTableItem* item = var->item;
    ptr = var->item->value.array_val->llvmvalue;//数组首地址
    string cur = "";//当前维度type
    for(int i = 0;i<var->s_type_list.size();++i)//遍历维度
    {
        cur = var->s_type_list[i];
        ptr = get_array_item(cur,ptr,item->value.array_val->begin[i],var->s_value_list[i]);
    }
    return ptr;
}
/**
 * 获取数组元素指针
 */
Value *get_array_item(const string &type, Value *array,int loc, Value* index)
{
    cout << "get_array_item" << endl;
    Type *item_type = context.type_ir.getLLVMType(type);
    if (item_type == nullptr)
        return LogErrorV("unknown type");
    auto base = ConstantInt::get(context.type_ir.type_int, loc);
    Value *ret = context.builder->CreateGEP(item_type, array, {base, index});
    if (ret == nullptr)
        return LogErrorV("get array item failed");
    return ret;
}

Value *expressionToBoolean(Value* value){
    if(value->getType()->getTypeID() == Type::IntegerTyID)
    {
        value = context.builder->CreateIntCast(value,context.type_ir.type_boolean,true);
        value = context.builder->CreateICmpNE(value,llvm::ConstantInt::get(context.type_ir.type_boolean,0,true));
    }
    else if(value->getType()->getTypeID() == Type::FloatTyID)
    {
        value = context.builder->CreateFCmpONE(value, llvm::ConstantFP::get(context.llvmContext, llvm::APFloat(0.0)));
    }
    return value;
}