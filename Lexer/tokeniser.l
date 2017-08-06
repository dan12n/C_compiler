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
IDENTIFIER						[a-zA-Z_][a-zA-Z0-9_]*						

%%
{NUM_CONST}										{   ;return Number_l;}
{}
{STRING}										{   ;return String_l;}
{CHARACTER}										{   ;return Character_l;}
"//".*											{   ;return OneLineComment;}
"/*".*											{   ;return StartMultiComment;}
"*/".*											{   ;return EndMultiComment;}



/* Keywords */
"continue"										{   ;return Continue_KEY;}
"default"										{   ;return Default_KEY;}
"short"											{   ;return Short_KEY;}
"goto"											{   ;return Goto_KEY;}
"if"											{   ;return If_KEY;}
"extern"										{   ;return Extern_KEY;}
"float"											{   ;return Float_KEY;}
"unsigned"										{   ;return Unsigned_KEY;}
"void"											{   ;return Void_KEY;}
"long"											{   ;return Long_KEY;}
"volatile"										{   ;return Volatile_KEY;}
"while"											{   ;return While_KEY;}
"const"											{   ;return Const_KEY;}
"char"											{   ;return Char_KEY;}
"for"											{   ;return For_KEY;}
"auto"											{   ;return Auto_KEY;}
"do"											{   ;return Do_KEY;}
"sizeof"										{   ;return Sizeof_KEY;}
"union"											{   ;return Union_KEY;}
"double"										{   ;return Double_KEY;}
"int"											{   ;return Int_KEY;}
"typedef"										{   ;return Typedef_KEY;}
"else"											{   ;return Else_KEY;}
"return"										{   ;return Return_KEY;}
"static"										{   ;return Static_KEY;}
"enum"											{   ;return Enum_KEY;}
"case"											{   ;return Case_KEY;}
"register"										{   ;return Register_KEY;}
"restrict"										{   ;return Restrict_KEY;}
"break"											{   ;return Break_KEY;}
"signed"										{   ;return Signed_KEY;}
"switch"										{   ;return Switch_KEY;}
"struct"										{   ;return Struct_KEY;}
				
[ \t\n]                 						;				
				
				
/* Math operators */				
\+												{   ;return Plus_MATH;}
\-												{   ;return Subtract_MATH;}
\*												{   ;return Multiply_MATH;}
\/												{   ;return Divide_MATH;}
\%												{   ;return Percentage_MATH;}
\+\+											{   ;return Increment_MATH;}
\-\-											{   ;return Subtract_MATH;}
/* Bitwise operations */				
\&												{   ;return And_BIT;}
\|												{   ;return Or_BIT;}
\^												{   ;return Xor_BIT;}
\~												{   ;return Tilde_BIT;}
\!												{   ;return Not_BIT;}
\&\&											{   ;return AndAnd_BIT;}
\|\|											{   ;return OrOr_BIT;}
\<\<											{   ;return LShift_BIT;}
\>\>											{   ;return RShift_BIT;}
\?												{   ;return Question_BIT;}
/* Comparator */				
\<												{   ;return Less_COMP;}
\>												{   ;return Greater_COMP;}
\=\=											{   ;return Equal_COMP;}
\!\=											{   ;return NEqual_COMP;}
\>\=											{   ;return GEqual_COMP;}
\<\=											{   ;return LEqual_COMP;}
/* Brackets */				
\(												{   ;return Open_BRACKET;}
\)												{   ;return Close_BRACKET;}
\[												{   ;return OSquare_BRACKET;}
\]												{   ;return CSquare_BRACKET;}
\{												{   ;return OCurly_BRACKET;}
\}												{   ;return CCurly_BRACKET;}
/* Compound operators */				
\+\=											{   ;return Add_CURRENT;}
\-\=											{   ;return Sub_CURRENT;}
\*\=											{   ;return Mul_CURRENT;}
\/\=											{   ;return Div_CURRENT;}
\%\=											{   ;return Mod_CURRENT;}
\&\=											{   ;return And_CURRENT;}
\^\=											{   ;return Xor_CURRENT;}
\|\=											{   ;return Or_CURRENT;}
\<\<\=											{   ;return LShift_CURRENT;}
\>\>\=											{   ;return RShift_CURRENT;}
/* Miscellaneous */				
\=												{	;return Equal}
\.\.\.											{   ;return Ellipses;}
\;												{   ;return Semicolon;}
\-\>											{   ;return PTR_Ref;}
\:												{   ;return Colon;}
\,												{   ;return Comma;}
\.												{   ;return Dot_Ref;}

(#{CHAR_STRING}*)(\ )?(\<|\")({CHAR_STRING}*\.?{CHARACTER})(\>|\") 	{   ;return Pre_Processor;}
{IDENTIFIER}									{ return Identifier;}
.												{ return Invalid_arg;}
%%

int yywrap(void)
{
return 1;
}