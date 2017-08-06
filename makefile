CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter -Wno-unused-variable -Wunused-function
CPPFLAGS += -I include
SRCS=$(wildcard src/compiler/ast/*.cpp)
OBJS=$(subst .cc,.o,$(SRCS))


bin/c_lexer.yy.cpp : src/lexer/c_lexer.flex
		flex -o bin/c_lexer.yy.cpp  src/lexer/c_lexer.flex

bin/c_lexer : bin/c_lexer.yy.cpp
		g++ $(CPPFLAGS) -o bin/c_lexer  bin/c_lexer.yy.cpp

src/parser/c_parser.tab.cpp src/c_parser.tab.hpp : src/parser/c_parser.y
	bison -v -d src/parser/c_parser.y -o src/parser/c_parser.tab.cpp

src/parser/c_lexer.yy.cpp : src/parser/c_lexer.flex src/parser/c_parser.tab.hpp
	flex -o src/parser/c_lexer.yy.cpp  src/parser/c_lexer.flex

src/compiler/c_parser.tab.cpp src/c_parser.tab.hpp : src/compiler/c_parser.y
	bison -v -d src/compiler/c_parser.y -o src/compiler/c_parser.tab.cpp

src/compiler/c_lexer.yy.cpp : src/compiler/c_lexer.flex src/compiler/c_parser.tab.hpp
	flex -o src/compiler/c_lexer.yy.cpp  src/compiler/c_lexer.flex

bin/c_parser : src/parser/c_parser.o src/parser/c_parser.tab.o src/parser/c_lexer.yy.o src/parser/c_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_parser $^

bin/c_compiler : src/compiler/c_compiler.o src/compiler/c_parser.tab.o src/compiler/c_lexer.yy.o src/compiler/c_parser.tab.o $(OBJS)
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^

clean :
		-rm bin/*
		-rm src/parser/*.tab.cpp
		-rm src/parser/*.yy.cpp
		-rm src/parser/*.o
		-rm src/compiler/*.tab.cpp
		-rm src/compiler/*.yy.cpp
		-rm src/compiler/*.o
		-rm -r test/Compiler/out/assembly
		-rm -r test/Compiler/out/bin
		-rm -r test/Compiler/out/pretty_print
		-rm -r test/Compiler/out/result