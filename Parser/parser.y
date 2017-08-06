%{
#include <iostream>
#include <cstdlib>
#include <string>

int yylex();
int yyerror(const char* s);

%}


%union{
	vectors...
	classes...
	objects...
}

%token ...
%type ...

%%

primaryexpression 		:	Identifier


%%

int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  return yyparse();
}