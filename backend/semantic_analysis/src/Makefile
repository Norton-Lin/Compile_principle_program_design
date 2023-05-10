all: compiler

OBJS =  y.tab.o \
		lex.yy.o  \
		Disposal.o \
		test.o

LLVMCONFIG = llvm-config-11
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) -rf y.tab.cpp y.tab.hpp lex.yy.cpp compiler $(OBJS)

y.tab.cpp: yacc.y
	bison -d -o $@ $<

y.tab.hpp: y.tab.cpp

lex.yy.cpp: lex-link.l y.tab.hpp
	flex -wincompat -o $@ $<
	
Disposal.cpp: main.h

test.cpp:ASTNodes.hpp

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS)
