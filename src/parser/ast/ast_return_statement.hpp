//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_RETURN_STATEMENT_HPP
#define AST_AST_RETURN_STATEMENT_HPP

#include "ast_base_statement.hpp"
#include "ast_base_expression.hpp"

class ast_return_statement : public ast_base_statement{
public:
	ast_return_statement(ast_base_expression* in_id) 
	{
		id = in_id;
	}

    void xmlprint() const {
    	//if (id != NULL)
    	//	id->xmlprint();
    }

private:
	ast_base_expression* id;
};


class ast_expression_statement : public ast_base_statement{
public:
	ast_expression_statement(ast_base_expression* in_id) 
	{
		id = in_id;
	}

    void xmlprint() const {
    	//if (id != NULL) {
    	//	id->xmlprint();
    	//}
    }

private:
	ast_base_expression* id;
};


#endif //AST_AST_RETURN_STATEMENT_HPP
