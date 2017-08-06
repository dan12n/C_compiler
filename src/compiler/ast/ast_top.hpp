//ast_top

//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_TOP_HPP
#define AST_AST_TOP_HPP


#include "ast_base_expression.hpp"
#include "ast_base.hpp"


class ast_top {
public:
	ast_top() ;

	void add_new(ast_base* in_base) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const ;

private:
	std::vector<ast_base*> all_list;

};

#endif //AST_AST_TOP_HPP
