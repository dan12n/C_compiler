%option noyywrap

%{
	#include <iostream>
	#include <string>
	#include <algorithm>
	#include <sstream>
	#include <regex>
	#include "c_parser.tab.hpp"

	extern "C" int fileno(FILE *stream);

	int StreamLine = 1; //The line number the token appears on, in terms of the input stream.
	std::string SourceFile;
	int SourceLine = 1; //The source line the token came from
	int SourceCol = 1; //The source column the token started at. If a token starts at the first character on a line, it would have "SourceCol":1
	bool multi_line_comment = false;

	std::string check_quote(std::string name) {
	    if ((name[0] == '\"') && (name[name.length()-1] == '\"')) {
	        name.erase(0,1);
	        name.erase(name.length()-1, name.length());
	    }
	    return name;
	}

	int get_num (std::string my_string) {
		std::smatch m;
		std::string temp;

		if (std::regex_search(my_string, m, std::regex("# [0-9]+"))) {
			temp = m.str(0);
			temp = temp.substr(2, temp.size());
			return stoi(temp);
		}
		else {
			return 1;
		}

	}

	int last_pos(std::string str, char my_char) {
		for (int i = str.size(); i >= 0; i --) {
			if (str[i] == my_char) {
				return i;
			}
		}

		return str.size();
	}

	int first_pos(std::string str, char my_char) {
		for (unsigned int i = 0; i < str.size(); i ++) {
			if (str[i] == my_char) {
				return i;
			}
		}

		return 0;
	}

	void JSON_conversion(std::string type) {
		if (multi_line_comment == false) {
			std::string temp = check_quote(yytext);

			std::cout << "\t{ \"Class\" : \"" 		<< type 
					  << "\", \t \"Text\" : \"" 	<< temp 
					  << "\", \t \"StreamLine\" : " << StreamLine
					  << ", \t \"SourceFile\" : \""	<< SourceFile
					  << "\", \t \"SourceLine\" : " << SourceLine
					  << ", \t \"SourceCol\" : " 	<< SourceCol
					  << " }," 						<< std::endl;
			SourceCol += yyleng;
		}
	}

	std::string get_file(std::string name) {
		size_t path = first_pos(name,'\"');
		int final = last_pos(name, '\"');
		return name.substr(path+1, final-path-1);
	}

%}

/*TODO : Look at Escape Sequences...though if they are included (appropriately escaped) it is fine too.*/

/* Basic Sequences */
INTEGER							([0-9]+[0-9]*)
DECIMAL							([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)|{INTEGER}
FRACTION						([0-9]+\/[0-9]*)
HEX								[a-fA-F0-9]+
WHITE_SPACE						[ \t\v\n\f]
COEFFICIENTS					(u8|u|U|L)
F_SEQ							(f|F|l|L)
I_SEQ							(((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
ESCAPE_S						(\\([\'\"\?\\abfnrtv]|[0-7]{1,3}|x{HEX}))
/* Constants */
DECIMAL_constant 				{DECIMAL}+{I_SEQ}?
HEX_constant					0[xX]{HEX}({I_SEQ}?)
OCTAL_constant					0[0-7]*
NUMBER_constant					{DECIMAL}|{HEX_constant}|{OCTAL_constant}({I_SEQ})?
CHAR_LITERAL					L?\'(\\.|[^\\'])+\'
EXP_const						[eE][-\+]?[0-9]+
F_const							({FRACTION}{EXP_const}?|[0-9]+{EXP_const}){F_SEQ}?
/*Differentiate between an actual string and variable */
STRING_LITERAL					{COEFFICIENTS}?\"([^"\\\n]|{ESCAPE_S})*\"
CONSTANT 						({NUMBER_constant}|{CHAR_LITERAL}|{F_const})
IDENTIFIER						[a-zA-Z_][a-zA-Z0-9_]*





%%
\#\ [0-9]+\ \"([^\"\n])+\.[ch]\".*				{	SourceFile = get_file(yytext); 
													SourceLine = get_num(yytext)-1;	}
\#[^\n]*										{ 	SourceLine--;					}
"//".*											{ 	SourceLine--;					}
"/*".*											{   multi_line_comment = true;		}
"*/".*											{   multi_line_comment = false;		}


"continue"										{   return Continue_KEY;}
"default"										{   return Default_KEY;}
"short"											{   return Short_KEY;}
"goto"											{   return Goto_KEY;}
"if"											{   return If_KEY;}
"extern"										{   return Extern_KEY;}
"float"											{   return Float_KEY;}
"unsigned"										{   return Unsigned_KEY;}
"void"											{   return Void_KEY;}
"long"											{   return Long_KEY;}
"volatile"										{   return Volatile_KEY;}
"while"											{   return While_KEY;}
"const"											{   return Const_KEY;}
"char"											{   return Char_KEY;}
"for"											{   return For_KEY;}
"auto"											{   return Auto_KEY;}
"do"											{   return Do_KEY;}
"sizeof"										{   return Sizeof_KEY;}
"union"											{   return Union_KEY;}
"double"										{   return Double_KEY;}
"int"											{   return Int_KEY;}
"typedef"										{   return Typedef_KEY;}
"else"											{   return Else_KEY;}
"return"										{   return Return_KEY;}
"static"										{   return Static_KEY;}
"enum"											{   return Enum_KEY;}
"case"											{   return Case_KEY;}
"register"										{   return Register_KEY;}
"restrict"										{   return Restrict_KEY;}
"break"											{   return Break_KEY;}
"signed"										{   return Signed_KEY;}
"switch"										{   return Switch_KEY;}
"struct"										{   return Struct_KEY;}
"string"										{   return String_KEY;}



\+												{   return Plus_MATH;}
\-												{   return Subtract_MATH;}
\*												{   return Multiply_MATH;}
\/												{   return Divide_MATH;}
\%												{   return Percentage_MATH;}
\+\+											{   return Increment_MATH;}
\-\-											{   return Decrement_MATH;}	
\&												{   return And_BIT;}
\|												{   return Or_BIT;}
\^												{   return Xor_BIT;}
\~												{   return Tilde_BIT;}
\!												{   return Not_BIT;}
\&\&											{   return AndAnd_BIT;}
\|\|											{   return OrOr_BIT;}
\<\<											{   return LShift_BIT;}
\>\>											{   return RShift_BIT;}
\?												{   return Question_BIT;}
\<												{   return Less_COMP;}
\>												{   return Greater_COMP;}
\=\=											{   return Equal_COMP;}
\!\=											{   return NEqual_COMP;}
\>\=											{   return GEqual_COMP;}
\<\=											{   return LEqual_COMP;}
\(												{   return Open_BRACKET;}
\)												{   return Close_BRACKET;}
(\[)|(\<\:)										{   return OSquare_BRACKET;}
(\])|(\:\>)										{   return CSquare_BRACKET;}
(\{)|(\<\%)										{   return OCurly_BRACKET;}
(\})|(\%\>)										{   return CCurly_BRACKET;}
\+\=											{   return Add_CURRENT;}
\-\=											{   return Sub_CURRENT;}
\*\=											{   return Mul_CURRENT;}
\/\=											{   return Div_CURRENT;}
\%\=											{   return Mod_CURRENT;}
\&\=											{   return And_CURRENT;}
\^\=											{   return Xor_CURRENT;}
\|\=											{   return Or_CURRENT;}
\<\<\=											{   return LShift_CURRENT;}
\>\>\=											{   return RShift_CURRENT;}
\=												{	return Equal;}
\.\.\.											{   return Ellipses;}
\;												{   return Semicolon;}
\-\>											{   return PTR_Ref;}
\:												{   return Colon;}
\,												{   return Comma;}
\.												{   return Dot_Ref;}


{DECIMAL}										{ 	yylval.number_ast= new ast_number(strtod(yytext, 0)); return NUMBER; 				}
{IDENTIFIER}									{ 	yylval.identifier_ast=new ast_identifier(std::string(yytext)); return IDENTIFIER; 	}
{STRING_LITERAL}								{	yylval.str_ast = new ast_string(std::string(yytext)); return String_literal; 		}
{CHAR_LITERAL} 									{ 	yylval.char_ast = new ast_char(yytext[1]); return Char_literal; 						}
{OCTAL_constant} 								{	yylval.number_ast= new ast_number(strtod(yytext, 0)); return NUMBER; 				}
{HEX_constant}									{	yylval.number_ast= new ast_number(strtod(yytext, 0)); return NUMBER; 				}

[ \s]											{	SourceCol += 1;					}
[\t]                							{ 	SourceCol += 8; 				}
[\n]											{	StreamLine++; SourceCol = 1;
													SourceLine++;					}
[\v\f]											{ ; }
.												{ 	; 		}

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
