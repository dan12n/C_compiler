%code requires{
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
}

// Represents the value associated with any kind of
// AST node.
%union{
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
  ast_char* char_ast;
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

}

%token  Continue_KEY String_KEY Default_KEY Short_KEY Goto_KEY If_KEY Extern_KEY Float_KEY Unsigned_KEY Void_KEY Long_KEY Volatile_KEY While_KEY Const_KEY Char_KEY For_KEY Auto_KEY Do_KEY Sizeof_KEY Union_KEY Double_KEY Int_KEY Typedef_KEY Else_KEY Return_KEY Static_KEY Enum_KEY Case_KEY Register_KEY Restrict_KEY Break_KEY Signed_KEY Switch_KEY Struct_KEY Plus_MATH Subtract_MATH Multiply_MATH Divide_MATH Percentage_MATH Increment_MATH Decrement_MATH  And_BIT Or_BIT Xor_BIT Tilde_BIT Not_BIT AndAnd_BIT OrOr_BIT LShift_BIT RShift_BIT Question_BIT Less_COMP Greater_COMP Equal_COMP NEqual_COMP GEqual_COMP LEqual_COMP Open_BRACKET Close_BRACKET OSquare_BRACKET CSquare_BRACKET OCurly_BRACKET CCurly_BRACKET Add_CURRENT Sub_CURRENT Mul_CURRENT Div_CURRENT Mod_CURRENT And_CURRENT Xor_CURRENT Or_CURRENT LShift_CURRENT RShift_CURRENT Equal Ellipses Semicolon PTR_Ref Colon Comma Dot_Ref

%token<identifier_ast> IDENTIFIER
%token<str_ast> String_literal
%token<number_ast> NUMBER
%token<char_ast> Char_literal


%type<top_ast> top_declaration
%type<base> root abstract_declarator
%type<p_functions> function_definition
%type<type_ast> all_type_specifiers type_specifier type_name specifier_qualifier_list
%type<p_base_expr> primary_expression postfix_expression assign_expressions constant_expression shift_expression additive_expression multiplicative_expression cast_expression relational_expression equality_expression and_expression exclusive_or_expression  inclusive_or_expression logical_and_expression conditional_logical_or unary_expression
%type<p_expr_stat> expression_statement
%type<p_expr> expression
%type<p_declarator> declarator direct_declarator
%type<p_compound_statement> compound_statement
%type<p_ast_base_statement> statement labeled_statement return_statement
%type<p_if_else_statement> if_else_statement
%type<p_loop_statement> for_while_statement
%type<p_declaration> declaration
%type<p_init_dec> initialisers_declarator

%type<p_stat_list>statement_list
%type<func_list> parameter_type_list parameter_list
%type<init_dec_list> initialisers_list
%type<p_function_params> parameter_declaration
%type<arg_list> argument_expression_list

%start root

%%
root                      : top_declaration                                                     {g_root = $1;                       }
                          ;

top_declaration           : top_declaration declaration                                             {$$->add_new(new ast_global_declaration($2));               }
                          | top_declaration function_definition                                     {$$->add_new($2);               }
                          | top_declaration Semicolon
                          | declaration                                                             {$$ = new ast_top(); $$->add_new(new ast_global_declaration($1));               }
                          | Semicolon                                                               {$$ = new ast_top();                }
                          | function_definition                                                     {$$ = new ast_top(); $$->add_new($1);               }
                          ;                    
                           
expression                : assign_expressions                                                    { $$ = new ast_expression(); $$->add_new(($1));                  }
                          | expression Comma assign_expressions                                   { $$->add_new(($3));                                             }
                          ;

assign_expressions        : constant_expression                                                      { $$ = $1; }
                          | unary_expression Equal assign_expressions                             { $$ = new ast_assign_equal($1, $3); }
                          | unary_expression Add_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_add_operator($1, $3)); }
                          | unary_expression Sub_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_subtract_operator($1, $3));}
                          | unary_expression Mul_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_multiply_operator($1, $3));}
                          | unary_expression Div_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_divide_operator($1, $3));}
                          | unary_expression Mod_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_bitwise_modulo_operator($1, $3));}
                          | unary_expression And_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_bitwise_and_operator($1, $3));}
                          | unary_expression Xor_CURRENT assign_expressions                       { $$ = new ast_assign_equal($1, new ast_bitwise_xor_operator($1, $3));}
                          | unary_expression Or_CURRENT assign_expressions                        { $$ = new ast_assign_equal($1, new ast_bitwise_or_operator($1, $3));}
                          | unary_expression LShift_CURRENT assign_expressions                    { $$ = new ast_assign_equal($1, new ast_left_shift_bit($1, $3));}
                          | unary_expression RShift_CURRENT assign_expressions                    { $$ = new ast_assign_equal($1, new ast_right_shift_bit($1, $3));}
                          | OCurly_BRACKET argument_expression_list CCurly_BRACKET                { $$ = new ast_array_initialiser( *$2 ); }
                          ;
                          //Hacked to identifier instead of Unary Expression --> to make it easier

constant_expression       : conditional_logical_or                                                    { $$ = $1; }
                          | conditional_logical_or Question_BIT expression Colon constant_expression  { $$ = new ast_constant_expression($1, $3, $5);     }
                          ;

argument_expression_list  : assign_expressions                                                    { $$ = new std::vector<ast_base_expression*>; $$->push_back($1); }
                          | argument_expression_list Comma assign_expressions                     { $$->push_back($3);                                 }
                          ;

function_definition       : all_type_specifiers IDENTIFIER Open_BRACKET parameter_type_list Close_BRACKET compound_statement              { $$ = new ast_function ($1, $2, *$4, $6);         }
                          | all_type_specifiers IDENTIFIER Open_BRACKET Close_BRACKET compound_statement                                  { $$ = new ast_function ($1, $2, $5);       }
                          | IDENTIFIER Open_BRACKET parameter_type_list Close_BRACKET compound_statement                                  { $$ = new ast_function (new ast_type("Int"), $1, *$3, $5);             }
                          | IDENTIFIER Open_BRACKET Close_BRACKET compound_statement                                                      { $$ = new ast_function (new ast_type("Int"),$1 ,$4);           }
                          ;

//TODO: Replace all NULLS with empty base (already created)

all_type_specifiers       : storage_specifiers all_type_specifiers                                {;        }
                          | type_specifier                                                        { $$ = ($1);        }
                          | type_specifier all_type_specifiers                                    { $$ = ($1);        }
                          | type_qualifier all_type_specifiers                                    { ;        }
                          ;

direct_declarator         : Open_BRACKET declarator Close_BRACKET                                    { $$ = $2; }
                          | IDENTIFIER OSquare_BRACKET constant_expression CSquare_BRACKET           { $$ = new ast_array_declarator($1, $3);         }
                          | IDENTIFIER OSquare_BRACKET CSquare_BRACKET                               { $$ = new ast_array_declarator($1, NULL);       }
                          | IDENTIFIER Open_BRACKET parameter_type_list Close_BRACKET                { $$ = new ast_function_declarator($1, *$3); }
                          | IDENTIFIER Open_BRACKET Close_BRACKET                                    { $$ = new ast_function_declarator($1);      }
                          | IDENTIFIER                                                               { $$ = new ast_variable_declarator($1);      }
                          ;
                          //USED HACK FOR JUST IDENTIFIER

declarator                : pointer direct_declarator                                                 { $$ = $2; }
                          | direct_declarator                                                         { $$ = $1; }
                          ;
                          //CHANGED ABOVE FROM DECLARATOR TO IDENTIFIER

pointer                   : Multiply_MATH                                                             { ; }
                          | Multiply_MATH specifier_qualifier_list                                    { ; }
                          | Multiply_MATH pointer                                                     { ; }
                          | Multiply_MATH specifier_qualifier_list pointer                            { ; }
                          ;

declaration               : all_type_specifiers Semicolon                                      { $$ = new ast_declaration($1);       }
                          | all_type_specifiers initialisers_list Semicolon                    { $$ = new ast_declaration($1, *$2);   }
                          ;

initialisers_list         : initialisers_declarator                                               { $$ = new std::vector<ast_initialisers_declarator*>; $$->push_back($1); }
                          | initialisers_list Comma initialisers_declarator                       { $$->push_back($3);                                        }
                          ;

initialisers_declarator   : declarator                                                            { $$ = new ast_initialisers_declarator($1, new ast_expression_number(new ast_number(0)));    }
                          | declarator Equal assign_expressions                                   { $$ = new ast_initialisers_declarator($1, $3);      }
                          ;

shift_expression          : additive_expression                                                     
                          | shift_expression LShift_BIT additive_expression                          { $$ = new ast_left_shift_bit($1, $3);               }
                          | shift_expression RShift_BIT additive_expression                          { $$ = new ast_right_shift_bit($1, $3);              }
                          ;

additive_expression       : multiplicative_expression                                                
                          | additive_expression Plus_MATH multiplicative_expression                  { $$ = new ast_add_operator($1, $3);                    }
                          | additive_expression Subtract_MATH multiplicative_expression              { $$ = new ast_subtract_operator($1, $3);               }
                          ;

multiplicative_expression : cast_expression                                                          
                          | multiplicative_expression Multiply_MATH cast_expression                  { $$ = new ast_multiply_operator($1, $3);               }
                          | multiplicative_expression Divide_MATH cast_expression                    { $$ = new ast_divide_operator($1, $3);                  }
                          | multiplicative_expression Percentage_MATH cast_expression                { $$ = new ast_bitwise_modulo_operator($1, $3);          }
                          ;

cast_expression           : unary_expression                                                         { $$ = $1; }
                          | Open_BRACKET type_name Close_BRACKET cast_expression                     { $$ = $4; }
                          ;

relational_expression     : shift_expression                                                        
                          | relational_expression Less_COMP shift_expression                         { $$ = new ast_less_comp($1, $3);                     }
                          | relational_expression Greater_COMP shift_expression                      { $$ = new ast_greater_comp($1, $3);                  } 
                          | relational_expression LEqual_COMP shift_expression                       { $$ = new ast_less_equal_comp($1, $3);               }
                          | relational_expression GEqual_COMP shift_expression                       { $$ = new ast_greater_equal_comp($1, $3);            }
                          ;

equality_expression       : relational_expression                                                    
                          | equality_expression Equal_COMP relational_expression                     { $$ = new ast_equal_comp($1, $3);              }
                          | equality_expression NEqual_COMP relational_expression                    { $$ = new ast_not_equal_comp($1, $3);          }
                          ;

and_expression            : equality_expression   
                          | and_expression And_BIT equality_expression                               { $$ = new ast_bitwise_and_operator($1, $3);      }
                          ;

exclusive_or_expression   : and_expression
                          | exclusive_or_expression Xor_BIT and_expression                           { $$ = new ast_bitwise_xor_operator($1, $3);      }
                          ;

inclusive_or_expression   : exclusive_or_expression
                          | inclusive_or_expression Or_BIT exclusive_or_expression                   { $$ = new ast_bitwise_or_operator($1, $3);       }
                          ;

logical_and_expression    : inclusive_or_expression
                          | logical_and_expression AndAnd_BIT inclusive_or_expression                { $$ = new ast_and_comp($1, $3);                  }
                          ;

conditional_logical_or    : logical_and_expression
                          | conditional_logical_or OrOr_BIT logical_and_expression                    { $$ = new ast_or_comp($1, $3);                   }
                          ;

primary_expression        : NUMBER                                                                   { $$ = new ast_expression_number($1);        }
                          | Char_literal                                                             { $$ = new ast_expression_char($1);          }
                          | Subtract_MATH primary_expression                                                     { $$ = new ast_subtract_operator(new ast_expression_number(new ast_number(0)), ($2));}
                          | IDENTIFIER                                                               { $$ = new ast_expression_identifier($1);    }
                          | Open_BRACKET expression Close_BRACKET                                    { $$ = $2;                                   }
                          | String_literal                                                           { $$ = new ast_expression_string($1);        }
                          ;

postfix_expression        : primary_expression                                                      { $$ = $1;  }
                          | postfix_expression OSquare_BRACKET expression CSquare_BRACKET   { $$ = new ast_expression_array($1, $3);   }
                          | IDENTIFIER Open_BRACKET Close_BRACKET                           { $$ = new ast_function_call($1);       }
                          | IDENTIFIER Open_BRACKET argument_expression_list Close_BRACKET  { $$ = new ast_function_call($1, *$3);  }
                          | primary_expression Dot_Ref IDENTIFIER 
                          | IDENTIFIER Increment_MATH                                             { $$ = new ast_assign_equal(new ast_expression_identifier($1), new ast_add_operator(new ast_expression_identifier($1), new ast_expression_number( new ast_number(1) ))); }
                          | IDENTIFIER Decrement_MATH                                             { $$ = new ast_assign_equal(new ast_expression_identifier($1), new ast_subtract_operator(new ast_expression_identifier($1), new ast_expression_number( new ast_number(1) ))); }
                          ;
                          // HACK: CHANGED ABOVE FROM PRIMARY EXPRESSION TO IDENTIFIER

unary_expression          : postfix_expression                                                    { $$ = $1; }
                          | Increment_MATH IDENTIFIER                                             { $$ = new ast_assign_equal(new ast_expression_identifier($2), new ast_add_operator(new ast_expression_identifier($2), new ast_expression_number( new ast_number(1) )));  }
                          | Decrement_MATH IDENTIFIER                                             { $$ = new ast_assign_equal(new ast_expression_identifier($2), new ast_subtract_operator(new ast_expression_identifier($2), new ast_expression_number( new ast_number(1) )));  }
                          // HACK: CHANGED ABOVE FROM PRIMARY EXPRESSION TO IDENTIFIER
                          | unary_operator cast_expression                                          { $$ = $2;  }
                          | Sizeof_KEY unary_expression                                             { $$ = new ast_size_of_expr($2); }
                          | Sizeof_KEY Open_BRACKET type_name Close_BRACKET                         { $$ = new ast_size_of_expr($3); }
                          ;

type_name                 : specifier_qualifier_list                                                { $$ = $1;}
                          | specifier_qualifier_list abstract_declarator                            { $$ = $1;}
                          ;

specifier_qualifier_list  : type_specifier                                                          { $$ = $1; }
                          | type_qualifier specifier_qualifier_list                                 { $$ = $2; }
                          | type_qualifier                                                          { $$ = new ast_type("Int");}
                          ;
//CHANGED ABOVE
abstract_declarator       : Open_BRACKET abstract_declarator Close_BRACKET                            { $$ = $2; }
                          | OSquare_BRACKET CSquare_BRACKET                                           {;}
                          | OSquare_BRACKET constant_expression CSquare_BRACKET                       { $$ = $2; }
                          | abstract_declarator OSquare_BRACKET CSquare_BRACKET                       { $$ = $1; }
                          | abstract_declarator OSquare_BRACKET constant_expression CSquare_BRACKET   { $$ = $1; }
                          | Open_BRACKET Close_BRACKET                                                {;}
                          | Open_BRACKET parameter_type_list Close_BRACKET                            {;}
                          //| abstract_declarator Open_BRACKET Close_BRACKET                     { ; }
                          //| abstract_declarator Open_BRACKET parameter_type_list Close_BRACKET { ; }  
                           ;              

parameter_type_list       : parameter_list                                                            {$$ = $1; }
                          | parameter_list Comma Ellipses                                             {$$ = $1; }
                          ;

parameter_list            : parameter_list  Comma parameter_declaration                               {$$->push_back(($3));         }
                          | parameter_declaration                                                     {$$ = new std::vector<ast_function_parameters*>; $$->push_back(($1));      }
                          ;

parameter_declaration     : all_type_specifiers declarator                                         {$$ = new ast_function_parameters($1, $2);  }
                          //| all_type_specifiers abstract_declarator                                {$$ = new ast_function_parameters($1, $2);  }
                          | all_type_specifiers                                                    {$$ = new ast_function_parameters($1, NULL);      }
                          ;


statement                 : expression_statement                          { $$ = $1; }
                          | compound_statement                            { $$ = $1; }
                          | if_else_statement                             { $$ = $1; }
                          | for_while_statement                           { $$ = $1; }
                          | return_statement                              { $$ = $1; }
                          | declaration                                   { $$ = $1;  }
                          | labeled_statement                             { ; }
                          | case_statement_list                           { ; }
                          ;

labeled_statement         : IDENTIFIER Colon statement                                                    { ;}
                          ;

case_statement_list       : case_statement_list Case_KEY constant_expression Colon statement              { ;}
                          | case_statement_list Case_KEY Default_KEY Colon statement                      { ;}
                          | Case_KEY constant_expression Colon statement                                  { ;}
                          | Default_KEY Colon statement                                                   { ;}
                          ;

//Returns if_else_statement type : public base_statement
if_else_statement         : If_KEY Open_BRACKET expression Close_BRACKET statement                    { $$ = new ast_if_else_statement($3); $$->push_back_if($5); $$->push_back_else(NULL); }
                          | If_KEY Open_BRACKET expression Close_BRACKET statement Else_KEY statement { $$ = new ast_if_else_statement($3); $$->push_back_if($5); $$->push_back_else($7);   }
                          | Switch_KEY Open_BRACKET expression Close_BRACKET statement                {;}// { $$ = new ast_switch_case_statement($3, $5);                                         }
                          ;

//Returns for_while_statement type : public ast_loops
for_while_statement       : For_KEY Open_BRACKET expression Semicolon expression Semicolon Close_BRACKET statement                  { $$ = new ast_for_statement($3, $5, $8);             }
                          | For_KEY Open_BRACKET expression Semicolon expression Semicolon expression Close_BRACKET statement       { $$ = new ast_for_statement($3, $5, $7, $9);  }
                          | While_KEY Open_BRACKET expression Close_BRACKET statement                                               { $$ = new ast_while_statement($3, $5, false);          }
                          | Do_KEY statement While_KEY Open_BRACKET expression Close_BRACKET Semicolon                              { $$ = new ast_while_statement($5, $2, true);            }
                          ;
//TODO: FIX ABOVE

//Returns return_statement type : public base_statement
return_statement          : Return_KEY Semicolon                          {$$ = new ast_return_statement(new ast_expression_number( new ast_number(0) ));}
                          | Return_KEY expression Semicolon               {$$ = new ast_return_statement($2); }
                          | Break_KEY Semicolon                           {$$ = new ast_break_statement();  }
                          | Continue_KEY Semicolon                        {;}
                          ;

//Returns expression_statement type : public base_statement
expression_statement      : Semicolon                                     {$$ = new ast_expression_statement(NULL);  }
                          | expression Semicolon                          {$$ = new ast_expression_statement($1);  }
                          ;

//Returns compound_statement type : public base_statement
compound_statement        : OCurly_BRACKET CCurly_BRACKET                 {$$ = new ast_compound_statement(NULL);                       }
                          | OCurly_BRACKET statement_list CCurly_BRACKET  {$$ = new ast_compound_statement($2);                         }
                          ;

//Returns ?? Same type as statement
statement_list            : statement                                     {$$ = new ast_statement_list(); $$->add_new($1);              }
                          | statement_list statement                      {$$->add_new($2);                                             }
                          ;

storage_specifiers        : Typedef_KEY
                          | Extern_KEY
                          | Static_KEY
                          | Auto_KEY
                          | Register_KEY
                          ;


type_specifier            : Void_KEY                                      {  $$ = new ast_type("Void");    }
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
                          | String_KEY                                    {  $$ = new ast_type("String");    }
                          ;        
//Type Specifiers give reduce reduce

unary_operator            : And_BIT
                          | Multiply_MATH
                          | Plus_MATH
                          | Subtract_MATH
                          | Tilde_BIT
                          | Not_BIT
                          ;

type_qualifier            : Const_KEY
                          | Volatile_KEY
                          ;

%%

const ast_top *g_root; // Definition of variable (to match declaration earlier)

const ast_top *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}