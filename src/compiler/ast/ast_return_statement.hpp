//
// Created by Divyansh Manocha on 09/02/2017.
//

#ifndef AST_AST_RETURN_STATEMENT_HPP
#define AST_AST_RETURN_STATEMENT_HPP

#include "ast_base_statement.hpp"
#include "ast_base_expression.hpp"

class ast_return_statement : public ast_base_statement{
public:
	ast_return_statement(ast_base_expression* in_id);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

private:
	ast_base_expression* id;
};


class ast_break_statement : public ast_base_statement {
public:
    ast_break_statement();

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const;

    void allocate_memory(int& allocated_mem) const;
};


class ast_expression_statement : public ast_base_statement{

public:
	ast_expression_statement(ast_base_expression* in_id);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

private:
	ast_base_expression* id;
};


#endif //AST_AST_RETURN_STATEMENT_HPP
