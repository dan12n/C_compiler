%code requires{
  #include "ast.hpp"

  #include <cassert>
  #include <string>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token  NUMBER Continue_KEY Default_KEY Short_KEY Goto_KEY If_KEY Extern_KEY Float_KEY Unsigned_KEY Void_KEY Long_KEY Volatile_KEY While_KEY Const_KEY Char_KEY For_KEY Auto_KEY Do_KEY Sizeof_KEY Union_KEY Double_KEY Int_KEY Typedef_KEY Else_KEY Return_KEY Static_KEY Enum_KEY Case_KEY Register_KEY Restrict_KEY Break_KEY Signed_KEY Switch_KEY Struct_KEY Plus_MATH Subtract_MATH Multiply_MATH Divide_MATH Percentage_MATH Increment_MATH Decrement_MATH  And_BIT Or_BIT Xor_BIT Tilde_BIT Not_BIT AndAnd_BIT OrOr_BIT LShift_BIT RShift_BIT Question_BIT Less_COMP Greater_COMP Equal_COMP NEqual_COMP GEqual_COMP LEqual_COMP Open_BRACKET Close_BRACKET OSquare_BRACKET CSquare_BRACKET OCurly_BRACKET CCurly_BRACKET Add_CURRENT Sub_CURRENT Mul_CURRENT Div_CURRENT Mod_CURRENT And_CURRENT Xor_CURRENT Or_CURRENT LShift_CURRENT RShift_CURRENT Equal Ellipses Semicolon PTR_Ref Colon Comma Dot_Ref IDENTIFIER

%type <expr> EXPR TERM FACTOR DECLARATION
%type <number> NUMBER
%type <string> IDENTIFIER

%start ROOT

%%
ROOT                      : DECLARATION
                          | FUNCTION_DEFINTION
                          ;   
                
EXPR                      : TERM                                          {   std::cout << "EXPR" << std::endl;                  }
                          | EXPR Plus_MATH TERM                           {   std::cout << "EXPR" << std::endl;                  }
                          | EXPR Subtract_MATH TERM                       {   std::cout << "EXPR" << std::endl;                  }
                          ;             

COMPARISON_OPERATORS      : FACTOR Less_COMP FACTOR
                          | FACTOR Greater_COMP FACTOR
                          | FACTOR Equal_COMP FACTOR
                          ;
                                                    
TERM                      : FACTOR                                        {   std::cout << "TERM" << std::endl;                  }
                          | TERM Multiply_MATH FACTOR                     {   std::cout << "TERM" << std::endl;                  }
                          | TERM Divide_MATH FACTOR                       {   std::cout << "TERM" << std::endl;                  }
                          ;           
                                          
                                            
FACTOR                    : NUMBER                                        {   std::cout << "FACTOR" << std::endl;                 }
                          | IDENTIFIER                                    {   std::cout << "FACTOR" << std::endl;                 }
                          | Open_BRACKET EXPR Close_BRACKET               {   std::cout << "FACTOR" << std::endl;                 }
                          ;   
              
  
DECLARATION               : TYPE_VARIABLE DECLARATOR                     {   std::cout << "DECLARATION" << std::endl;            }
                          | DECLARATION Semicolon ROOT                   {   std::cout << "DECLARATION" << std::endl;            }
                          | DECLARATION Semicolon 
                          ; 
  
DECLARATOR                : DECLARATOR Comma DECLARATOR                   {   std::cout << "Declrator" << std::endl;              }
                          | IDENTIFIER Equal EXPR                         {   std::cout << "Declrator" << std::endl;              }
                          | IDENTIFIER                                    {   std::cout << "Declrator" << std::endl;              }
                          ; 
  
  
TYPE_VARIABLE             : Void_KEY                                      {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Char_KEY                                      {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Short_KEY                                     {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Int_KEY                                       {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Long_KEY                                      {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Float_KEY                                     {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Double_KEY                                    {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Signed_KEY                                    {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Unsigned_KEY                                  {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Struct_KEY                                    {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Enum_KEY                                      {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          | Typedef_KEY                                   {   std::cout << "TYPE_VARIABLE" << std::endl;           }
                          ;

INSIDE_BRACKET            : TYPE_VARIABLE IDENTIFIER Comma INSIDE_BRACKET {   std::cout << "DECLARATION" << std::endl;            }
                          | TYPE_VARIABLE IDENTIFIER                      {   std::cout << "DECLARATION" << std::endl;            }

FUNCTION_DEFINTION        : TYPE_VARIABLE IDENTIFIER Open_BRACKET INSIDE_BRACKET Close_BRACKET compound_statement   {   std::cout << "DECLARATION" << std::endl;            }
                          | TYPE_VARIABLE IDENTIFIER Open_BRACKET Close_BRACKET compound_statement                  {   std::cout << "DECLARATION" << std::endl;            }
                          ;

statement                 : expression_statement                     
                          | compound_statement                       
                          | if_else_statement                    
                          | for_while_statement                    
                          | return_statement                         
                          ;

if_else_statement         : If_KEY Open_BRACKET COMPARISON_OPERATORS Close_BRACKET statement
                          | If_KEY Open_BRACKET COMPARISON_OPERATORS Close_BRACKET statement Else_KEY statement
                          ;

for_while_statement       : For_KEY Open_BRACKET expression_statement COMPARISON_OPERATORS Semicolon IDENTIFIER Increment_MATH Close_BRACKET statement
                          | For_KEY Open_BRACKET expression_statement COMPARISON_OPERATORS Semicolon IDENTIFIER  Decrement_MATH Close_BRACKET statement
                          | While_KEY Open_BRACKET TYPE_VARIABLE COMPARISON_OPERATORS Close_BRACKET statement
                          ;

return_statement          : Continue_KEY Semicolon
                          | Break_KEY Semicolon
                          | Return_KEY Semicolon
                          | Return_KEY EXPR Semicolon
                          ;

statement_list            : statement
                          | statement_list statement
                          ;

expression_statement      : Semicolon      
                          | EXPR Semicolon
                          ;


compound_statement        : OCurly_BRACKET CCurly_BRACKET ROOT
                          | OCurly_BRACKET statement_list CCurly_BRACKET ROOT
                          | OCurly_BRACKET DECLARATION CCurly_BRACKET ROOT
                          | OCurly_BRACKET DECLARATION statement_list CCurly_BRACKET ROOT
                          | OCurly_BRACKET CCurly_BRACKET
                          | OCurly_BRACKET statement_list CCurly_BRACKET
                          | OCurly_BRACKET DECLARATION CCurly_BRACKET
                          | OCurly_BRACKET DECLARATION statement_list CCurly_BRACKET
                          ;

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
