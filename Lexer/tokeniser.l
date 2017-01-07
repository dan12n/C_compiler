%{
	#include "parser.tab.hpp"
	#include <iostream>
	#include <string>
	#include <algorithm>
	#include <sstream>
%}

/* Token Classes complete break down (these will be grouped later) */

/* Constants */
DECIMAL							[0-9]+\.[0-9]+
INTEGER							[0-9]+
NUM_CONST						{DECIMAL}|{INTEGER}
CHARACTER						[a-zA-Z]
/*Useful for variables below*/
CHAR_STRING						{CHARACTER}[a-zA-Z0-9]*
/*Differentiate between an actual string and variable */
LITERAL_STRING					\"[a-zA-Z0-9]+\"
								(#[a-zA-Z][a-zA-Z0-9]*)( )?(<|")([a-zA-Z][a-zA-Z0-9]*\.?[a-zA-Z])(>|")
						

%%
{NUM_CONST}										{   ;return ...;}
{STRING}										{   ;return ...;}
{CHARACTER}										{   ;return ...;}
"using ".*										{   ;return ...;}
"//".*											{   ;return ...;}
"/*".*											{   ;return ...;}
"*/".*											{   ;return ...;}



/* Keywords */
"continue"										{   ;return ...;}
"default"										{   ;return ...;}
"short"											{   ;return ...;}
"goto"											{   ;return ...;}
"if"											{   ;return ...;}
"extern"										{   ;return ...;}
"float"											{   ;return ...;}
"unsigned"										{   ;return ...;}
"void"											{   ;return ...;}
"long"											{   ;return ...;}
"volatile"										{   ;return ...;}
"while"											{   ;return ...;}
"const"											{   ;return ...;}
"char"											{   ;return ...;}
"for"											{   ;return ...;}
"auto"											{   ;return ...;}
"do"											{   ;return ...;}
"sizeof"										{   ;return ...;}
"union"											{   ;return ...;}
"double"										{   ;return ...;}
"int"											{   ;return ...;}
"typedef"										{   ;return ...;}
"else"											{   ;return ...;}
"return"										{   ;return ...;}
"static"										{   ;return ...;}
"enum"											{   ;return ...;}
"case"											{   ;return ...;}
"register"										{   ;return ...;}
"restrict"										{   ;return ...;}
"break"											{   ;return ...;}
"signed"										{   ;return ...;}
"switch"										{   ;return ...;}
"struct"										{   ;return ...;}
				
[ \t\n]                 						;				
\/\*											{   ;return ...;}
\*\/											{   ;return ...;}
\/\/											{   ;return ...;}
				
				
/* Math operators */				
\+												{   ;return ...;}
\-												{   ;return ...;}
\*												{   ;return ...;}
\/												{   ;return ...;}
\%												{   ;return ...;}
\+\+											{   ;return ...;}
\-\-											{   ;return ...;}
/* Bitwise operations */				
\&												{   ;return ...;}
\|												{   ;return ...;}
\^												{   ;return ...;}
\~												{   ;return ...;}
\!												{   ;return ...;}
\&\&											{   ;return ...;}
\|\|											{   ;return ...;}
\<\<											{   ;return ...;}
\>\>											{   ;return ...;}
\?												{   ;return ...;}
/* Comparator */				
\<												{   ;return ...;}
\>												{   ;return ...;}
\=\=											{   ;return ...;}
\!\=											{   ;return ...;}
\>\=											{   ;return ...;}
\<\=											{   ;return ...;}
/* Brackets */				
\(												{   ;return ...;}
\)												{   ;return ...;}
\[												{   ;return ...;}
\]												{   ;return ...;}
\{												{   ;return ...;}
\}												{   ;return ...;}
/* Compound operators */				
\+\=											{   ;return ...;}
\-\=											{   ;return ...;}
\*\=											{   ;return ...;}
\/\=											{   ;return ...;}
\%\=											{   ;return ...;}
\&\=											{   ;return ...;}
\^\=											{   ;return ...;}
\|\=											{   ;return ...;}
\<\<\=											{   ;return ...;}
\>\>\=											{   ;return ...;}
/* Miscellaneous */				
\.\.\.											{   ;return ...;}
\;												{   ;return ...;}
\-\>											{   ;return ...;}
\:												{   ;return ...;}
\,												{   ;return ...;}
\.												{   ;return ...;}

(#{CHAR_STRING}*)( )?(<|")({CHAR_STRING}*\.?{CHARACTER})(>|") 	{   ;return ...;}
.												{   ; return ...;}
%%

int yywrap(void)
{
return 1;
}