//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_BINARY_OPERATORS_HPP
#define AST_BINARY_OPERATORS_HPP

#include "ast_base_expression.hpp"

class ast_binary_operators : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;
	virtual ~ast_binary_operators() {
		delete left;
		delete right;
	}

	private:
	    const ast_base_expression *left;
	    const ast_base_expression *right;

	protected:
	    ast_binary_operators(const ast_base_expression *_left, const ast_base_expression *_right)
	        : left(_left)
	        , right(_right)
	    {}
};

class ast_less_comp : public ast_binary_operators{
public:
	ast_less_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_binary_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};

class ast_less_equal_comp : public ast_binary_operators{
public:
	ast_less_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_binary_operators(_left, _right) { }
	//~ast_if_else_statement() {}
	
    void xmlprint() const {
    	
    }
};


class ast_greater_comp : public ast_binary_operators{
public:
	ast_greater_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_binary_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};

class ast_greater_equal_comp : public ast_binary_operators{
public:
	ast_greater_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_binary_operators(_left, _right) { }
	//~ast_if_else_statement() {}
	
    void xmlprint() const {
    	
    }
};


class ast_equal_comp : public ast_binary_operators{
public:
	ast_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_binary_operators(_left, _right) { }
	//~ast_if_else_statement() {}
	
    void xmlprint() const {
    	
    }

};


class ast_not_equal_comp : public ast_binary_operators{
public:
	ast_not_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_binary_operators(_left, _right) { }
	//~ast_if_else_statement() {}
	
    void xmlprint() const {
    	
    }
};


class ast_comp_expr : public ast_binary_operators{
public:
	ast_comp_expr(const ast_base_expression* _left)
	: ast_binary_operators(_left, NULL) { }
	
    void xmlprint() const {
    	
    }
};

#endif //AST_BINARY_OPERATORS_HPP
