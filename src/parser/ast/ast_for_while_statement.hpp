//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_FOR_WHILE_STATEMENT_HPP
#define AST_AST_FOR_WHILE_STATEMENT_HPP

#include "ast_base_statement.hpp"
#include "ast_declaration.hpp"
#include "ast_binary_operators.hpp"
#include "ast_base_expression.hpp"
#include "ast_logical_expressions.hpp"

class ast_loops : public ast_base_statement {
public:
	virtual ~ast_loops() {}
	virtual void xmlprint() const = 0;
};

class ast_for_statement : public ast_loops {
public:
	ast_for_statement(ast_base_expression* in_condition, ast_base_expression* in_bin_op, ast_base_statement* stat) {
		first_condition = in_condition;
		bin_op = in_bin_op;
		base_expr = NULL;
		statement = stat;
	}

	ast_for_statement(ast_base_expression* in_condition, ast_base_expression* in_bin_op, ast_base_expression* in_base_expr, ast_base_statement* stat) {
		first_condition = in_condition;
		bin_op = in_bin_op;
		base_expr = in_base_expr;
		statement = stat;
	}

    void xmlprint() const {
    	if (first_condition != NULL) {
    		std::cout << "<Scope>" << std::endl;
    		first_condition->xmlprint();

    		if (statement != NULL)
    			statement->xmlprint();

    		std::cout << "</Scope>" << std::endl;
    	}
    	else {
    		std::cout << "<Scope>" << std::endl;
    		if (statement != NULL)
    			statement->xmlprint();

    		std::cout << "</Scope>" << std::endl;	
    	}
    }

private:
	ast_base_expression* bin_op;
	ast_base_expression* base_expr;
	ast_base_statement* statement;
	ast_base_expression* first_condition;
};



class ast_while_statement : public ast_loops {
public:

	ast_while_statement(ast_base_expression* in_comparison, ast_base_statement* in_stat, bool in_do_while) {
		statement = in_stat;
		comparison = in_comparison;
		do_while = in_do_while;
	}

    void xmlprint() const {
    	std::cout << "<Scope>" << std::endl;

    	if (statement != NULL)
    		statement->xmlprint();

    	std::cout << "</Scope>" << std::endl;

    }

private:
	ast_base_expression* comparison;
	ast_base_statement* statement;
	bool do_while;
};


#endif //AST_AST_FOR_WHILE_STATEMENT_HPP
