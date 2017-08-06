//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_BASE_STATEMENT_HPP
#define AST_BASE_STATEMENT_HPP

#include "ast_base.hpp"

class ast_base_statement : public ast_base{
public:
	virtual ~ast_base_statement();
	
    virtual void xmlprint() const = 0;
    virtual void prettyprint(std::ostream &stream) const =0;
    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;
    virtual void allocate_memory(int& allocated_mem) const = 0;

    virtual std::string statement_type() const = 0;
};

#endif //AST_DECLARATION_HPP
