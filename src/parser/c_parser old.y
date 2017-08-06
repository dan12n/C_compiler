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

%token  NUMBER Continue_KEY Default_KEY Short_KEY Goto_KEY If_KEY Extern_KEY Float_KEY Unsigned_KEY Void_KEY Long_KEY Volatile_KEY While_KEY Const_KEY Char_KEY For_KEY Auto_KEY Do_KEY Sizeof_KEY Union_KEY Double_KEY Int_KEY Typedef_KEY Else_KEY Return_KEY Static_KEY Enum_KEY Case_KEY Register_KEY Restrict_KEY Break_KEY Signed_KEY Switch_KEY Struct_KEY Plus_MATH Subtract_MATH Multiply_MATH Divide_MATH Percentage_MATH Increment_MATH Subtract_MATH  And_BIT Or_BIT Xor_BIT Tilde_BIT Not_BIT AndAnd_BIT OrOr_BIT LShift_BIT RShift_BIT Question_BIT Less_COMP Greater_COMP Equal_COMP NEqual_COMP GEqual_COMP LEqual_COMP Open_BRACKET Close_BRACKET OSquare_BRACKET CSquare_BRACKET OCurly_BRACKET CCurly_BRACKET Add_CURRENT Sub_CURRENT Mul_CURRENT Div_CURRENT Mod_CURRENT And_CURRENT Xor_CURRENT Or_CURRENT LShift_CURRENT RShift_CURRENT Equal Ellipses Semicolon PTR_Ref Colon Comma Dot_Ref IDENTIFIER

%type <expr> FUNCTION_NAME
%type <number> NUMBER
%type <string> IDENTIFIER TYPE_VARIABLE

%start START

%%
START                     : FUNCTION_NAME
                          | DECLARATION
                          | START FUNCTION_NAME
                          | START DECLARATION
                          ;
   
TYPE_VARIABLE             : Void_KEY                                    {  std::cout << "TYPE_VARIABLE";    }
                          | Char_KEY                                    {  std::cout << "TYPE_VARIABLE";    }
                          | Short_KEY                                   {  std::cout << "TYPE_VARIABLE";    }
                          | Int_KEY                                     {  std::cout << "TYPE_VARIABLE";    }
                          | Long_KEY                                    {  std::cout << "TYPE_VARIABLE";    }
                          | Float_KEY                                   {  std::cout << "TYPE_VARIABLE";    }
                          | Double_KEY                                  {  std::cout << "TYPE_VARIABLE";    }
                          | Signed_KEY                                  {  std::cout << "TYPE_VARIABLE";    }
                          | Unsigned_KEY                                {  std::cout << "TYPE_VARIABLE";    }
                          | Struct_KEY                                  {  std::cout << "TYPE_VARIABLE";    }
                          | Enum_KEY                                    {  std::cout << "TYPE_VARIABLE";    }
                          | Typedef_KEY                                 {  std::cout << "TYPE_VARIABLE";    }
                          ;             
                                       

EXPR_LIST                 : DECLARATOR Comma EXPR_LIST                  {   std::cout << "EXPR_LIST";   }
                          | DECLARATOR                                  {   std::cout << "EXPR_LIST";   }
                          ;

FUNCTION_NAME             : TYPE_VARIABLE  IDENTIFIER Open_BRACKET EXPR_LIST Close_BRACKET OCurly_BRACKET   {  std::cout << "FUNCTION";        }
                          ;

FUNCTION_QUALIFIER        :   Const_KEY
                          |   Volatile_KEY
                          ; 

DECLARATION               :   TYPE_VARIABLE                                 { std::cout << "F";}
                          |   TYPE_VARIABLE DECLARATION                                 { std::cout << "F";}
                          |   FUNCTION_QUALIFIER                                  { std::cout << "F";}
                          |   FUNCTION_QUALIFIER DECLARATION                                  { std::cout << "F";}
                          ;

DECLARATOR                :   IDENTIFIER
                          |   DECLARATOR Open_BRACKET LIST_IDENTIFIER Close_BRACKET
                          |   DECLARATOR Open_BRACKET Close_BRACKET
                          ;

            
init_declarator           :   DECLARATOR
                          |   DECLARATOR Equal initialiser
                          ;


initialiser               :   Plus_MATH
                          |   Subtract_MATH
                          |   Multiply_MATH
                          |   Divide_MATH
                          ;

init_declarator_list      :   init_declarator
                          |   init_declarator_list Comma init_declarator
                          ;

/*Declaration is the parameter */
declaration               :   TYPE_VARIABLE Semicolon
                          |   TYPE_VARIABLE init_declarator_list Semicolon
                          ;

declaration_list          :   declaration
                          |   declaration_list declaration
                          ;

compound_statement        :   OCurly_BRACKET CCurly_BRACKET
                          |   OCurly_BRACKET declaration_list CCurly_BRACKET
                          |   OCurly_BRACKET declaration_list statement_list CCurly_BRACKET
                          ;

statement_list            :   statement_list compound_statement
                          |   compound_statement
                          ;


function_definition       :   TYPE_VARIABLE DECLARATOR declaration_list compound_statement
                          |   TYPE_VARIABLE DECLARATOR compound_statement
                          |   DECLARATOR declaration_list compound_statement
                          |   DECLARATOR compound_statement
                          ;

LIST_IDENTIFIER           : IDENTIFIER
                          | IDENTIFIER Comma LIST_IDENTIFIER
                          ;
%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
