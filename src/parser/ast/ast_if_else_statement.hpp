//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_IF_ELSE_STATEMENT_HPP
#define AST_AST_IF_ELSE_STATEMENT_HPP

#include "ast_compound_statement.hpp"
#include "ast_binary_operators.hpp"
#include "ast_logical_expressions.hpp"
#include "ast_base_statement.hpp"


class ast_if_else_statement : public ast_base_statement{
public:
	ast_if_else_statement(ast_base_expression* in_binary_comparison){
		binary_comparison = in_binary_comparison;
		if_expressions = NULL;
		else_expressions = NULL;
	}
	//~ast_if_else_statement() {}

	void push_back_if(ast_base_statement* in_expr) {
		if_expressions = in_expr;
	}

	void push_back_else(ast_base_statement* in_expr) {
		else_expressions = in_expr;
	}

    void xmlprint() const {
    	if (if_expressions != NULL) {
    		std::cout << "<Scope>" << std::endl;
    		if_expressions->xmlprint();
    		std::cout << "</Scope>" << std::endl;
    	}

    	if (else_expressions != NULL) {
    		std::cout << "<Scope>" << std::endl;
    		else_expressions->xmlprint();
    		std::cout << "</Scope>" << std::endl;
    	}

    }


private:
	ast_base_statement* if_expressions;
	ast_base_statement* else_expressions;

	ast_base_expression* binary_comparison;	
};


#endif //AST_AST_IF_ELSE_STATEMENT_HPP
