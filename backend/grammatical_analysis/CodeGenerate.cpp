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
    func = Function::Create(func_type, Function::ExternalLinkage, "write_boolen", this->module.get());
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
    func = Function::Create(func_type, Function::ExternalLinkage, "read_boolen", this->module.get());
    this->funcStack.push_back(func);
    param.clear();
}
// AST CodeGenerate
/**
 * 主程序IR生成
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
 * 常量定义IR生成
 * @param context 上下文
 * @return Value*
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
        // 报错
        // 可能需要一个位置信息 todo
        ret = LogErrorV("unknown const type" + this->s_type);
    }
    return ret;
}
// 元素 常量 变量 类型

/**
 * 变量声明IR生成
 * @param context 上下文
 * @return Value* 局部变量地址
 */
Value *variable_AST::code_generation(CodeGenContext &context)
{
    cout << "variable_AST::code_generation" << endl;
    this->item = symbolTable.get(this->s_identifier);
    if (this->item == nullptr)
        return LogErrorV("unknown variable name" + this->s_identifier);
    Value *ret = nullptr;                                   // 局部变量地址
    Type *type = context.type_ir.getLLVMType(this->s_type); // 局部变量类型
    // Type* type = context.type_ir.getLLVMType(record->type);//局部变量类型
    // 是数组
    if (this->s_isarray)
    {
        // 获取数组对应的llvm type
        Type *array_type = type;
        // 数组元素直接用数据定义，获取数据类型
        if (array_type == nullptr)
        {
            // 没找到数组表项
            if (this->item->type == 0)
            {
                return LogErrorV("unknown array type");
            }
            // 这里需要创建一个新llvm类型
            symbol_type type = this->item->type;
        }
        // 栈上创建局部变量
        if (array_type)
            ret = context.builder->CreateAlloca(type, nullptr);
    }
    else
    {
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
 * @param context 上下文
 * @return Value*
 */
Value *type_AST::code_generation(CodeGenContext &context)
{
    cout << "type_Ast::code_generation" << endl;
    // 数组类型
    if (this->l_isarray)
    {
        cout << "type_Ast::code_generation is_array" << endl;
        int size = 1;
        int dimension = this->s_index_list.size(); // 多维
        for (auto &item : this->s_index_list)
        {
            size *= (item.second - item.second + 1);
        }
        Type *type = context.type_ir.getLLVMType(this->s_type);
        if (type == nullptr)
        {
            return LogErrorV("unknown type");
        }
        llvm::ArrayType *arraytype = llvm::ArrayType::get(type, size);
        context.
        // todo 记录新类型
    }
    return nullptr;
}

// 函数
/**
 * program IR生成
 */
Value *program_body_AST::code_generation(CodeGenContext &context)
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
 */
Value *subprogram_body_AST::code_generation(CodeGenContext &context)
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
 * 过程调用 IR生成
 */
Value *procedure_call_AST::code_generation(CodeGenContext &context)
{
    cout << "procedure_call_AST::code_generation" << endl;
    // 符号表里寻找procedeure id     todo
    this->s_item = symbolTable.get(this->s_identifier);
    if (this->s_item == nullptr)
        return LogErrorV("procedure not found in sympol table");
    vector<Value *> args; // 获取参数列表
    for (auto &item : this->s)
    {
        // 对每个参数进行解析
        Value *value = item->code_generation(context);
        if (value == nullptr)
            return LogErrorV("procedure call failed - param analyse failed");
        // 获取参数类型 todo
        // string type = ...;从符号表找
        string type = "";
        if (type == "real")
            value = context.builder->CreateFPToSI(value, context.type_ir.type_int);
        args.push_back(value);
    }
    // 获取一个过程指针 todo
    // Function* pro_ptr = record->func;
    Function *pro_ptr = nullptr;
    return context.builder->CreateCall(pro_ptr, args, "Call Procedure");
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
    //获取左值
    Value* value = item->llvalue;//左值变量地址
    if(this->s_expression_type == "return")//函数返回值
    {
        //记录函数返回值
        item->returnValue = s_expression_value;
        return nullptr;
    }
    if(item->type == 6&&s_expression_type=="integer"){
        s_expression_value = context.builder->CreateSIToFP(s_expression_value, context.type_ir.type_real);
    }
    if(item->type == 5&&s_expression_type=="real"){
        s_expression_value = context.builder->CreateFPToSI(s_expression_value, context.type_ir.type_int);
    }
    if(s_variable->s_isarray)
    {
        //获取指针
        Value* ptr = nullptr;
        context.builder->CreateStore(s_expression_value, ptr);
    }
    else{
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
        if (item->value == nullptr) // todo 是数组
            ;                       // 获取一个指针
        else
            addr = item->value; // 可能需要查符号表
        context.builder->CreateStore(ret, addr);
        ++count;
    }
    return nullptr;
}

// 引用

// 辅助函数
/**
 * 获取数组元素指针
 */
Value *get_array_item(CodeGenContext &context, const string &type, Value *array, int index)
{
    cout << "get_array_item" << endl;
    Type *item_type = context.type_ir.getLLVMType(type);
    if (item_type == nullptr)
        return LogErrorV("unknown type");
    auto base = ConstantInt::get(context.type_ir.type_int, 0);
    auto offset = ConstantInt::get(context.type_ir.type_int, index);
    Value *ret = context.builder->CreateGEP(item_type, array, {base, offset});
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