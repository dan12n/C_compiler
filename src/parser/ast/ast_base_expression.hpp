//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_EXPRESSION_HPP
#define AST_AST_EXPRESSION_HPP

#include "ast_base.hpp"

class ast_base_expression : public ast_base{
public:
    virtual void xmlprint() const =0;
    
};


class ast_expression : public ast_base_expression {
public:
	ast_expression() { }

	void add_new(ast_base_expression* in_expr) {
		all_expr.push_back(in_expr);
	}

	void xmlprint() const{

	}

private:
	std::vector<ast_base_expression*> all_expr;
};


//HACK
class ast_expression_number : public ast_base_expression {
public:
	ast_expression_number(ast_number* in_num) {
		num = in_num;
	}
	

    void xmlprint() const{
    	num->xmlprint();
    }

private:
	ast_number* num;
};

class ast_expression_identifier  : public ast_base_expression {
public:
	ast_expression_identifier(ast_identifier* in_ID) {
		ID = in_ID;
	}
	

    void xmlprint() const {
    	ID->xmlprint();
    }

private:
	ast_identifier* ID;
};


class ast_expression_string  : public ast_base_expression {
public:
	ast_expression_string(ast_string* in_str) {
		my_str = in_str;
	}

    void xmlprint() const {
    	my_str->xmlprint();
    }

private:
	ast_string* my_str;
};


class ast_reassign_variable : public ast_base_expression {
public:
	ast_reassign_variable(ast_base_expression* in_expr) {
		expr = in_expr;
	}

	void xmlprint() const {
		//ID->xmlprint();
	}

private:
	ast_base_expression* expr;
};


class ast_constant_expression : public ast_base_expression {
public:
	ast_constant_expression(ast_base_expression* in_binary_comparison, ast_base_expression* in_expr_1, ast_base_expression* in_expr_2){
		binary_comparison = in_binary_comparison;
		if_expressions = in_expr_1;
		else_expressions = in_expr_2;
	}
	//~ast_if_else_statement() {}

    void xmlprint() const {

    }


private:
	ast_base_expression* if_expressions;
	ast_base_expression* else_expressions;

	ast_base_expression* binary_comparison;	
};



#endif //AST_AST_EXPRESSION_HPP
