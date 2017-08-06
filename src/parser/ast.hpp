#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_base_expression.hpp"
#include "ast/ast_base_statement.hpp"
#include "ast/ast_base.hpp"
#include "ast/ast_basic_tokens.hpp"
#include "ast/ast_compound_statement.hpp"
#include "ast/ast_for_while_statement.hpp"
#include "ast/ast_function_parameters.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_if_else_statement.hpp"
#include "ast/ast_return_statement.hpp"
#include "ast/ast_binary_operators.hpp"
#include "ast/ast_math_operators.hpp"
#include "ast/ast_logical_expressions.hpp"
#include "ast/ast_top.hpp"
#include "ast/ast_assignment_expression.hpp"


extern const ast_top *parseAST();

#endif
