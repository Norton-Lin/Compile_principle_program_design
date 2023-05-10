"""
* @file server.py
* @author LinZhi 2020211472
* @brief
    Pascal-S简易编译器服务器模块
    基于Sanic实现框架
    调用基于llvm lex yacc的编译程序
* @version 0.1
* @data 2023-5-5
* @copyright (python) 2023
"""
import os
import subprocess
from sanic import Sanic, json, response

app = Sanic("Pascal-S_compiler")
#   编译器名称
compiler = "compiler"
#   pas临时文件名称
filename = "pas_temp.pas"
fileoutput = filename+".exe"


@app.post("/Compile")
async def Compile(request):
    """
    :param request: 参数 包含pas文件
    :return 返回，编译器输出，如果编译成功，获取文件
    """
    try:
        data = request.files.get("data")
        file_content = data.body
        #   data = request.json.get("data")
        output = ""
        rc = 1
        with open(filename, "wb") as f:
            f.write(file_content)
        #   先将文件信息写入临时文件
        if os.path.exists(compiler):
            rc, output = subprocess.getstatusoutput("./"+compiler+" "+filename)
            lines = output.splitlines()
            output = '\n'.join(lines[:-1])
            #   一些诡异的段错误需要处理
            if rc == 0 or rc == 139:
                print("编译成功")
            else:
                print("编译失败")
            #   print(output)
        if rc != 0 and rc != 139:
            rc = 400
        else:
            rc = 200
        #   return json({"output": output}, status=rc)
        return response.text(output, status=rc)
    except KeyError:
        return json({}, status=400)


#   客户端获取可执行文件
@app.route("/file")
async def get_file(request):
    return await response.file(fileoutput, status=200)


@app.get("/")
async def get(request):
    print("Compile coded by LinZhi")
    return json({"Compile coded by LinZhi": ""}, status=200)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8888)
