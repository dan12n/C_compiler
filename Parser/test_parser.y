%token ...
%type ...


%%

CONSTANT 						:	Number_l
								|	Character_l
								;
								
primary_expression				: 	IDENTIFIER
								| 	CONSTANT
								| 	String_l
								| 	Open_BRACKET expression Close_BRACKET
								;	
	
postfix_expression				: 	primary_expression
								| 	postfix_expression OSquare_BRACKET expression CSquare_BRACKET
								| 	postfix_expression Open_BRACKET Close_BRACKET
								| 	postfix_expression Open_BRACKET argument_expression_list Close_BRACKET
								| 	postfix_expression Dot_Ref IDENTIFIER
								| 	postfix_expression PTR_OP IDENTIFIER
								| 	postfix_expression INC_OP
								| 	postfix_expression DEC_OP
								;	

type_variable 					: 	Void_KEY
								| 	Char_KEY
								| 	Short_KEY
								| 	Int_KEY
								| 	Long_KEY
								| 	Float_KEY
								| 	Double_KEY
								| 	Signed_KEY
								| 	Unsigned_KEY
								| 	Struct_KEY
								| 	enum_KEY
								| 	Typedef_KEY
								;	

argument_expression_list		: 	assignment_expression
								| 	argument_expression_list Comma assignment_expression
								;	
	
unary_expression				: 	postfix_expression
								| 	INC_OP unary_expression
								| 	DEC_OP unary_expression
								| 	unary_operator cast_expression
								| 	SIZEOF unary_expression
								| 	SIZEOF Open_BRACKET type_name Close_BRACKET
								;	
	
unary_operator					: 	And_BIT
								| 	Multiply_MATH
								| 	Plus_MATH
								| 	Subtract_MATH
								| 	Tilde_BIT
								| 	Not_BIT
								;	
	
cast_expression 				: 	unary_expression
								| 	Open_BRACKET type_name Close_BRACKET cast_expression
								;	
	
multiplicative_expression		: 	cast_expression
								| 	multiplicative_expression Multiply_MATH cast_expression
								| 	multiplicative_expression Divide_MATH cast_expression
								| 	multiplicative_expression Percentage_MATH cast_expression
								;	
	
additive_expression				: 	multiplicative_expression
								| 	additive_expression Plus_MATH multiplicative_expression
								| 	additive_expression Subtract_MATH multiplicative_expression
								;	
	
shift_expression				: 	additive_expression
								| 	shift_expression LEFT_OP additive_expression
								| 	shift_expression RIGHT_OP additive_expression
								;	
	
relational_expression 			: 	shift_expression
								| 	relational_expression Less_COMP shift_expression
								| 	relational_expression Greater_COMP shift_expression
								| 	relational_expression LE_OP shift_expression
								| 	relational_expression GE_OP shift_expression
								;	
	
equality_expression 			: 	relational_expression
								| 	equality_expression EQ_OP relational_expression
								| 	equality_expression NE_OP relational_expression
								;	
	
and_expression 					: 	equality_expression
								| 	and_expression And_BIT equality_expression
								;	
	
exclusive_or_expression 		: 	and_expression
								| 	exclusive_or_expression Xor_BIT and_expression
								;	
	
inclusive_or_expression	 		: 	exclusive_or_expression
								| 	inclusive_or_expression Or_BIT exclusive_or_expression
								;	
	
logical_and_expression 			: 	inclusive_or_expression
								| 	logical_and_expression AND_OP inclusive_or_expression
								;	
	
logical_or_expression 			: 	logical_and_expression
								| 	logical_or_expression OR_OP logical_and_expression
								;	
	
conditional_expression			: 	logical_or_expression
								| 	logical_or_expression Question_BIT expression Colon conditional_expression
								;	
	
assignment_expression 			: 	conditional_expression
								| 	unary_expression assignment_operator assignment_expression
								;	
	
assignment_operator 			: 	Equal
								| 	MUL_ASSIGN
								| 	DIV_ASSIGN
								| 	MOD_ASSIGN
								| 	ADD_ASSIGN
								| 	SUB_ASSIGN
								| 	LEFT_ASSIGN
								| 	RIGHT_ASSIGN
								| 	AND_ASSIGN
								| 	XOR_ASSIGN
								| 	OR_ASSIGN
								;	
	
expression 						: 	assignment_expression
								| 	expression Comma assignment_expression
								;	
	
constant_expression 			: 	conditional_expression
								;	
	
declaration 					: 	declaration_specifiers Semicolon
								| 	declaration_specifiers init_declarator_list Semicolon
								;	
	
declaration_specifiers 			: 	storage_class_specifier
								| 	storage_class_specifier declaration_specifiers
								| 	type_specifier
								| 	type_specifier declaration_specifiers
								| 	type_qualifier
								| 	type_qualifier declaration_specifiers
								;	
	
init_declarator_list 			: 	init_declarator
								| 	init_declarator_list Comma init_declarator
								;	
	
init_declarator 				: 	declarator
								| 	declarator Equal initializer
								;	
	
storage_class_specifier 		: 	TYPEDEF
								| 	EXTERN
								| 	STATIC
								| 	AUTO
								| 	REGISTER
								;	
	
type_variable 					: 	Void_KEY
								| 	Char_KEY
								| 	Short_KEY
								| 	Int_KEY
								| 	Long_KEY
								| 	Float_KEY
								| 	Double_KEY
								| 	Signed_KEY
								| 	Unsigned_KEY
								| 	Struct_KEY
								| 	enum_KEY
								| 	Typedef_KEY
								;	
	
struct_or_union_specifier 		: 	struct_or_union IDENTIFIER OCurly_BRACKET struct_declaration_list CCurly_BRACKET
								| 	struct_or_union OCurly_BRACKET struct_declaration_list CCurly_BRACKET
								| 	struct_or_union IDENTIFIER
								;	
	
struct_or_union 				: 	STRUCT
								| 	UNION
								;	
	
struct_declaration_list 		: 	struct_declaration
								| 	struct_declaration_list struct_declaration
								;	
	
struct_declaration 				: 	specifier_qualifier_list struct_declarator_list Semicolon
								;	
	
specifier_qualifier_list 		: 	type_specifier specifier_qualifier_list
								| 	type_specifier
								| 	type_qualifier specifier_qualifier_list
								| 	type_qualifier
								;	
	
struct_declarator_list 			: 	struct_declarator
								| 	struct_declarator_list Comma struct_declarator
								;	
	
struct_declarator 				: 	declarator
								| 	Colon constant_expression
								| 	declarator Colon constant_expression
								;	
	
enum_specifier 					: 	ENUM OCurly_BRACKET enumerator_list CCurly_BRACKET
								| 	ENUM IDENTIFIER OCurly_BRACKET enumerator_list CCurly_BRACKET
								| 	ENUM IDENTIFIER
								;	
	
enumerator_list 				: 	enumerator
								| 	enumerator_list Comma enumerator
								;	
	
enumerator 						: 	IDENTIFIER
								| 	IDENTIFIER Equal constant_expression
								;	
	
type_qualifier 					: 	CONST
								| 	VOLATILE
								;	
	
declarator 						: 	pointer direct_declarator
								| 	direct_declarator
								;	
	
direct_declarator 				: 	IDENTIFIER
								| 	Open_BRACKET declarator Close_BRACKET
								| 	direct_declarator OSquare_BRACKET constant_expression CSquare_BRACKET
								| 	direct_declarator OSquare_BRACKET CSquare_BRACKET
								| 	direct_declarator Open_BRACKET parameter_type_list Close_BRACKET
								| 	direct_declarator Open_BRACKET identifier_list Close_BRACKET
								| 	direct_declarator Open_BRACKET Close_BRACKET
								;	
	
pointer 						: 	Multiply_MATH
								| 	Multiply_MATH type_qualifier_list
								| 	Multiply_MATH pointer
								| 	Multiply_MATH type_qualifier_list pointer
								;	
	
type_qualifier_list 			: 	type_qualifier
								| 	type_qualifier_list type_qualifier
								;	
	
	
parameter_type_list 			: 	parameter_list
								| 	parameter_list Comma ELLIPSIS
								;	
	
parameter_list 					: 	parameter_declaration
								| 	parameter_list Comma parameter_declaration
								;	
	
parameter_declaration 			: 	declaration_specifiers declarator
								| 	declaration_specifiers abstract_declarator
								| 	declaration_specifiers
								;	
	
identifier_list 				: 	IDENTIFIER
								| 	identifier_list Comma IDENTIFIER
								;	
	
type_name 						: 	specifier_qualifier_list
								| 	specifier_qualifier_list abstract_declarator
								;	
	
abstract_declarator 			: 	pointer
								| 	direct_abstract_declarator
								| 	pointer direct_abstract_declarator
								;	
	
direct_abstract_declarator 		: 	Open_BRACKET abstract_declarator Close_BRACKET
								| 	OSquare_BRACKET CSquare_BRACKET
								| 	OSquare_BRACKET constant_expression CSquare_BRACKET
								| 	direct_abstract_declarator OSquare_BRACKET CSquare_BRACKET
								| 	direct_abstract_declarator OSquare_BRACKET constant_expression CSquare_BRACKET
								| 	Open_BRACKET Close_BRACKET
								| 	Open_BRACKET parameter_type_list Close_BRACKET
								| 	direct_abstract_declarator Open_BRACKET Close_BRACKET
								| 	direct_abstract_declarator Open_BRACKET parameter_type_list Close_BRACKET
								;	
	
initializer 					: 	assignment_expression
								| 	OCurly_BRACKET initializer_list CCurly_BRACKET
								| 	OCurly_BRACKET initializer_list Comma CCurly_BRACKET
								;	
	
initializer_list 				: 	initializer
								| 	initializer_list Comma initializer
								;	
	
statement 						: 	labeled_statement
								| 	compound_statement
								| 	expression_statement
								| 	selection_statement
								| 	iteration_statement
								| 	jump_statement
								;	
	
labeled_statement 				: 	IDENTIFIER Colon statement
								| 	CASE constant_expression Colon statement
								| 	DEFAULT Colon statement
								;	
	
compound_statement 				: 	OCurly_BRACKET CCurly_BRACKET
								| 	OCurly_BRACKET statement_list CCurly_BRACKET
								| 	OCurly_BRACKET declaration_list CCurly_BRACKET
								| 	OCurly_BRACKET declaration_list statement_list CCurly_BRACKET
								;	
	
declaration_list 				: 	declaration
								| 	declaration_list declaration
								;	
	
statement_list 					: 	statement
								| 	statement_list statement
								;	
	
expression_statement 			: 	Semicolon
								| 	expression Semicolon
								;	
	
selection_statement 			: 	IF Open_BRACKET expression Close_BRACKET statement
								| 	IF Open_BRACKET expression Close_BRACKET statement ELSE statement
								| 	SWITCH Open_BRACKET expression Close_BRACKET statement
								;	
	
iteration_statement 			: 	WHILE Open_BRACKET expression Close_BRACKET statement
								| 	DO statement WHILE Open_BRACKET expression Close_BRACKET Semicolon
								| 	FOR Open_BRACKET expression_statement expression_statement Close_BRACKET statement
								| 	FOR Open_BRACKET expression_statement expression_statement expression Close_BRACKET statement
								;	
	
jump_statement 					: 	GOTO IDENTIFIER Semicolon
								| 	CONTINUE Semicolon
								| 	BREAK Semicolon
								| 	RETURN Semicolon
								| 	RETURN expression Semicolon
								;	
	
translation_unit 				: 	external_declaration
								| 	translation_unit external_declaration
								;	
	
external_declaration 			: 	function_definition
								| 	declaration
								;	
	
function_definition 			: 	declaration_specifiers declarator declaration_list compound_statement
								| 	declaration_specifiers declarator compound_statement
								| 	declarator declaration_list compound_statement
								| 	declarator compound_statement
								;
IDENTIFIER

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}