/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser/c_parser.y" /* yacc.c:1909  */

  #include "ast.hpp"

  #include <cassert>
  #include <string>
  #include <vector>

  extern const ast_top *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 60 "src/parser/c_parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Continue_KEY = 258,
    String_KEY = 259,
    Default_KEY = 260,
    Short_KEY = 261,
    Goto_KEY = 262,
    If_KEY = 263,
    Extern_KEY = 264,
    Float_KEY = 265,
    Unsigned_KEY = 266,
    Void_KEY = 267,
    Long_KEY = 268,
    Volatile_KEY = 269,
    While_KEY = 270,
    Const_KEY = 271,
    Char_KEY = 272,
    For_KEY = 273,
    Auto_KEY = 274,
    Do_KEY = 275,
    Sizeof_KEY = 276,
    Union_KEY = 277,
    Double_KEY = 278,
    Int_KEY = 279,
    Typedef_KEY = 280,
    Else_KEY = 281,
    Return_KEY = 282,
    Static_KEY = 283,
    Enum_KEY = 284,
    Case_KEY = 285,
    Register_KEY = 286,
    Restrict_KEY = 287,
    Break_KEY = 288,
    Signed_KEY = 289,
    Switch_KEY = 290,
    Struct_KEY = 291,
    Plus_MATH = 292,
    Subtract_MATH = 293,
    Multiply_MATH = 294,
    Divide_MATH = 295,
    Percentage_MATH = 296,
    Increment_MATH = 297,
    Decrement_MATH = 298,
    And_BIT = 299,
    Or_BIT = 300,
    Xor_BIT = 301,
    Tilde_BIT = 302,
    Not_BIT = 303,
    AndAnd_BIT = 304,
    OrOr_BIT = 305,
    LShift_BIT = 306,
    RShift_BIT = 307,
    Question_BIT = 308,
    Less_COMP = 309,
    Greater_COMP = 310,
    Equal_COMP = 311,
    NEqual_COMP = 312,
    GEqual_COMP = 313,
    LEqual_COMP = 314,
    Open_BRACKET = 315,
    Close_BRACKET = 316,
    OSquare_BRACKET = 317,
    CSquare_BRACKET = 318,
    OCurly_BRACKET = 319,
    CCurly_BRACKET = 320,
    Add_CURRENT = 321,
    Sub_CURRENT = 322,
    Mul_CURRENT = 323,
    Div_CURRENT = 324,
    Mod_CURRENT = 325,
    And_CURRENT = 326,
    Xor_CURRENT = 327,
    Or_CURRENT = 328,
    LShift_CURRENT = 329,
    RShift_CURRENT = 330,
    Equal = 331,
    Ellipses = 332,
    Semicolon = 333,
    PTR_Ref = 334,
    Colon = 335,
    Comma = 336,
    Dot_Ref = 337,
    IDENTIFIER = 338,
    string_literal = 339,
    NUMBER = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "src/parser/c_parser.y" /* yacc.c:1909  */

  ast_base* base;
  std::string *string;

  ast_base_expression* p_base_expr;
  ast_expression* p_expr;
  ast_compound_statement* p_compound_statement;
  ast_declaration* p_declaration;
  ast_loops* p_loop_statement;
  ast_declarator* p_declarator;

  ast_function_parameters* p_function_params;
  ast_if_else_statement* p_if_else_statement;
  ast_return_statement* p_ast_return_statement;
  ast_base_statement* p_ast_base_statement;
  ast_function* p_functions;
  ast_type* type_ast;
  ast_number* number_ast;
  ast_identifier* identifier_ast;
  ast_string* str_ast;
  ast_binary_operators* p_comparison;
  ast_math_operators* p_maths;
  ast_expression_statement* p_expr_stat;
  ast_statement_list* p_stat_list;
  ast_function_call* p_func_call;
  ast_initialisers_declarator* p_init_dec;

  std::vector<ast_function_parameters*>* func_list;
  std::vector<ast_base_expression*>* arg_list;
  std::vector<ast_base_statement*>* statment_vector;
  std::vector<ast_declaration*>* dec_list;
  std::vector<ast_initialisers_declarator*>* init_dec_list;

  ast_top* top_ast;


#line 195 "src/parser/c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_C_PARSER_TAB_HPP_INCLUDED  */
