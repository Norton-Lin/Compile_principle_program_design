# 指令

编译词法分析源文件`lex-link.l`，生成文件`lex.yy.cpp`

```cmd
win_flex -wincompat -o lex.yy.cpp lex-link.l
```

编译语法分析源文件`yacc.y`，生成文件`y.tab.cpp`和`y.tab.hpp`

```cmd
win_bison -d -o y.tab.cpp yacc.y
```

联合编译，生成可执行文件`test.exe`

```cmd
g++ -o test.exe y.tab.cpp lex.yy.cpp
```

测试

```cmd
test FilePath
```

# 环境

源文件与`win_flex` `win_bison`处于同一目录下，且该目录下有`data`目录。