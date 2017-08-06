//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_IF_ELSE_STATEMENT_HPP
#define AST_AST_IF_ELSE_STATEMENT_HPP

#include "ast_compound_statement.hpp"
#include "ast_binary_operators.hpp"
#include "ast_logical_expressions.hpp"
#include "ast_base_statement.hpp"

//Not an optimising compiler, uses nop's everytime a delay slot is encountered.

class ast_if_else_statement : public ast_base_statement{
public:
    ast_if_else_statement(ast_base_expression* in_binary_comparison);

    void push_back_if(ast_base_statement* in_expr) ;

    void push_back_else(ast_base_statement* in_expr) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const;

private:
    ast_base_statement* if_expressions;
    ast_base_statement* else_expressions;

    ast_base_expression* binary_comparison; 
};


#endif //AST_AST_IF_ELSE_STATEMENT_HPP

