%code requires{
  #include "ast.hpp"

  #include <cassert>
  #include <string>
  #include <vector>

  extern const ast_base *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const ast_base* base;
  std::string *string;

  ast_base_expression* p_base_expr;
  ast_compound_statement* p_compound_statement;
  ast_declaration* p_declaration;
  ast_for_statement* p_for_statement;
  ast_function_parameters* p_function_params;
  ast_if_else_statement* p_if_else_statement;
  ast_return_statement* p_ast_return_statement;
  ast_base_statement* p_ast_base_statement;
  ast_function* p_functions;
  ast_type* type_ast;
  ast_number* number_ast;
  ast_identifier* identifier_ast;
  std::vector<ast_function_parameters*>* func_list;

}

%token  Continue_KEY Default_KEY Short_KEY Goto_KEY If_KEY Extern_KEY Float_KEY Unsigned_KEY Void_KEY Long_KEY Volatile_KEY While_KEY Const_KEY Char_KEY For_KEY Auto_KEY Do_KEY Sizeof_KEY Union_KEY Double_KEY Int_KEY Typedef_KEY Else_KEY Return_KEY Static_KEY Enum_KEY Case_KEY Register_KEY Restrict_KEY Break_KEY Signed_KEY Switch_KEY Struct_KEY Plus_MATH Subtract_MATH Multiply_MATH Divide_MATH Percentage_MATH Increment_MATH Decrement_MATH  And_BIT Or_BIT Xor_BIT Tilde_BIT Not_BIT AndAnd_BIT OrOr_BIT LShift_BIT RShift_BIT Question_BIT Less_COMP Greater_COMP Equal_COMP NEqual_COMP GEqual_COMP LEqual_COMP Open_BRACKET Close_BRACKET OSquare_BRACKET CSquare_BRACKET OCurly_BRACKET CCurly_BRACKET Add_CURRENT Sub_CURRENT Mul_CURRENT Div_CURRENT Mod_CURRENT And_CURRENT Xor_CURRENT Or_CURRENT LShift_CURRENT RShift_CURRENT Equal Ellipses Semicolon PTR_Ref Colon Comma Dot_Ref

%token<identifier_ast> IDENTIFIER
%token<number_ast> NUMBER

%type<base> EXPR TERM FACTOR ROOT EXTERNAL_DECLARATION
%type<func_list> INSIDE_BRACKET
%type<p_functions> FUNCTION_DEFINTION
%type<type_ast> TYPE_VARIABLE
%type<p_declaration> DECLARATION


%start ROOT

%%
ROOT                      : EXTERNAL_DECLARATION                          {g_root = $1;}
                          | ROOT EXTERNAL_DECLARATION                     {g_root = $2;}
                          ;
                          //NEED TO GET DECLARATIONS WORKING

EXTERNAL_DECLARATION      : DECLARATION                                   {;}
                          | FUNCTION_DEFINTION                            {;}
                          ;
                
EXPR                      : TERM                                          { ;                  }
                          | EXPR Plus_MATH TERM                           { ;                  }
                          | EXPR Subtract_MATH TERM                       { ;                  }
                          ;             

COMPARISON_OPERATORS      : FACTOR Less_COMP FACTOR                       {   ; }
                          | FACTOR Greater_COMP FACTOR                    {   ; }
                          | FACTOR Equal_COMP FACTOR                      {   ; }
                          ;
                                                    
TERM                      : FACTOR                                        {   ;                  }
                          | TERM Multiply_MATH FACTOR                     {   ;                  }
                          | TERM Divide_MATH FACTOR                       {   ;                  }
                          ;           
                                          
                                            
FACTOR                    : NUMBER                                        {                 }
                          | IDENTIFIER                                    {                 }
                          | Open_BRACKET EXPR Close_BRACKET               {                 }
                          ;   
              
  
DECLARATION               : TYPE_VARIABLE DECLARATOR Semicolon            {              }
                          ; 
  
DECLARATOR                : DECLARATOR Comma DECLARATOR                   {              }
                          | IDENTIFIER Equal EXPR                         {              }
                          | IDENTIFIER                                    {              }
                          ; 
  
  
TYPE_VARIABLE             : Void_KEY                                      {  $$ = new ast_type("Void");    }
                          | Char_KEY                                      {  $$ = new ast_type("Char");    }
                          | Short_KEY                                     {  $$ = new ast_type("Short");    }
                          | Int_KEY                                       {  $$ = new ast_type("Int");    }
                          | Long_KEY                                      {  $$ = new ast_type("Long");    }
                          | Float_KEY                                     {  $$ = new ast_type("Float");    }
                          | Double_KEY                                    {  $$ = new ast_type("Double");    }
                          | Signed_KEY                                    {  $$ = new ast_type("Signed");    }
                          | Unsigned_KEY                                  {  $$ = new ast_type("Unsigned");    }
                          | Struct_KEY                                    {  $$ = new ast_type("Struct");    }
                          | Enum_KEY                                      {  $$ = new ast_type("Enum");    }
                          | Typedef_KEY                                   {  $$ = new ast_type("Typedef");    }
                          ;

INSIDE_BRACKET            : INSIDE_BRACKET Comma TYPE_VARIABLE IDENTIFIER {$$->push_back(new ast_function_parameters($3, $4));         }
                          | TYPE_VARIABLE IDENTIFIER                      {$$ = new std::vector<ast_function_parameters*>; $$->push_back(new ast_function_parameters($1, $2));      }
                          ;

FUNCTION_DEFINTION        : TYPE_VARIABLE IDENTIFIER Open_BRACKET INSIDE_BRACKET Close_BRACKET compound_statement   { $$ = new ast_function(); $$->add_parameter(*$4);           }
                          | TYPE_VARIABLE IDENTIFIER Open_BRACKET Close_BRACKET compound_statement                  { $$ = new ast_function();           }
                          ;

statement                 : expression_statement                          {}
                          | compound_statement                            {}
                          | if_else_statement                             {}
                          | for_while_statement                           {}
                          | return_statement                              {}
                          ;

if_else_statement         : If_KEY Open_BRACKET COMPARISON_OPERATORS Close_BRACKET statement {}
                          | If_KEY Open_BRACKET COMPARISON_OPERATORS Close_BRACKET statement Else_KEY statement {}
                          ;

for_while_statement       : For_KEY Open_BRACKET expression_statement COMPARISON_OPERATORS Semicolon IDENTIFIER Increment_MATH Close_BRACKET statement { }
                          | For_KEY Open_BRACKET expression_statement COMPARISON_OPERATORS Semicolon IDENTIFIER  Decrement_MATH Close_BRACKET statement { }
                          | While_KEY Open_BRACKET TYPE_VARIABLE COMPARISON_OPERATORS Close_BRACKET statement { }
                          ;

return_statement          : Continue_KEY Semicolon                        {}
                          | Break_KEY Semicolon                           {}
                          | Return_KEY Semicolon                          {}
                          | Return_KEY EXPR Semicolon                     {}
                          ;

statement_list            : statement                                     {}
                          | statement_list statement                      {}
                          ;

expression_statement      : Semicolon                                     {}
                          | EXPR Semicolon                                {}
                          ;


compound_statement        : OCurly_BRACKET CCurly_BRACKET                 {}
                          | OCurly_BRACKET statement_list CCurly_BRACKET  {}
                          | OCurly_BRACKET DECLARATION CCurly_BRACKET     {}
                          | OCurly_BRACKET DECLARATION statement_list CCurly_BRACKET {}
                          ;

%%

const ast_base *g_root; // Definition of variable (to match declaration earlier)

const ast_base *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}

