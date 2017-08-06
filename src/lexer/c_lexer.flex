%option noyywrap

%{
	#include <iostream>
	#include <string>
	#include <algorithm>
	#include <sstream>
	#include <regex>

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
	}

	int first_pos(std::string str, char my_char) {
		for (int i = 0; i < str.size(); i ++) {
			if (str[i] == my_char) {
				return i;
			}
		}
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
INTEGER							([1-9]+[0-9]*)
DECIMAL							([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)|{INTEGER}
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
NUMBER_constant					({DECIMAL}|{HEX_constant}|{OCTAL_constant})({I_SEQ})?
CHAR_LITERAL					L?'(\\.|[^\\'])+'
EXP_const						[eE][-\+]?[0-9]+
F_const							({DECIMAL}{EXP_const}){F_SEQ}?
/*Differentiate between an actual string and variable */
STRING_LITERAL					{COEFFICIENTS}?\"([^\"\\\n]|{ESCAPE_S})*\"
CONSTANT 						({NUMBER_constant}|{CHAR_LITERAL}|{F_const})
IDENTIFIER						[a-zA-Z_][a-zA-Z0-9_]*
KEYWORDS 						(continue|default|short|goto|if|extern|float|unsigned|void|long|volatile|while|const|char|for|auto|do|union|double|int|typedef|else|return|static|enum|case|register|restrict|break|signed|switch|struct|sizeof)
OPERATORS						(\+)|(\-)|(\*)|(\/)|(\%)|(\+\+)|(\-\-)|(\&)|(\|)|(\^)|(\~)|(\!)|(\&\&)|(\|\|)|(\<\<)|(\>\>)|(\?)|(\<)|(\>)|(\=\=)|(\!\=)|(\>\=)|(\<\=)|(\()|(\))|(\[)|(\])|(\{)|(\})|(\+\=)|(\-\=)|(\*\=)|(\/\=)|(\%\=)|(\&\=)|(\^\=)|(\|\=)|(\<\<\=)|(\>\>\=)|(\=)|(\.\.\.)|(\;)|(\-\>)|(\:)|(\,)|(\.)|(\<\%)|(\%\>)|(\<\:)|(\:\>)



%%
\#\ [0-9]+\ \"([^\"\n])+\.[ch]\".*				{	SourceFile = get_file(yytext); 
													SourceLine = get_num(yytext)-1;	}
\#[^\n]*										{ 	SourceLine--;					}
"//".*											{ 	SourceLine--;					}
"/*".*											{   multi_line_comment = true;		}
"*/".*											{   multi_line_comment = false;		}


{CONSTANT}										{	JSON_conversion("Constant");	}
{OPERATORS}										{	JSON_conversion("Operator"); 	}
{KEYWORDS}										{   JSON_conversion("Keyword");		}
{IDENTIFIER}									{ 	JSON_conversion("Identifier");	}
{STRING_LITERAL}								{   JSON_conversion("StringLiteral");}				

[ \s]											{	SourceCol += 1;					}
[\t]                							{ 	SourceCol += 8; 				}
[\n]											{	StreamLine++; SourceCol = 1;
													SourceLine++;					}
[\v\f]											{ ; }
.												{ 	JSON_conversion("Error"); 		}

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

int main()
{
	std::cout << "[ ";
    yylex();
    printf("\t{}\n]\n");
    return 0;
}
