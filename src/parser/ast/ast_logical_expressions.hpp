
#ifndef AST_LOGICAL_EXPRESSIONS_HPP
#define AST_LOGICAL_EXPRESSIONS_HPP

#include "ast_base_expression.hpp"


class ast_logical_expressions : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;
	virtual ~ast_logical_expressions() {
	    delete left;
		delete right;
	}

	private:
	    const ast_base_expression *left;
	    const ast_base_expression *right;

	protected:
	    ast_logical_expressions(const ast_base_expression *_left, const ast_base_expression *_right)
	        : left(_left)
	        , right(_right)
	    {}
};


class ast_or_comp : public ast_logical_expressions{
public:
	ast_or_comp(const ast_base_expression *_left, const ast_base_expression *_right)
	: ast_logical_expressions(_left, _right) { }
	
    void xmlprint() const {
    	
    }
};

class ast_and_comp : public ast_logical_expressions{
public:
	ast_and_comp(const ast_base_expression *_left, const ast_base_expression *_right)
	: ast_logical_expressions(_left, _right) { }
	
    void xmlprint() const {
    	
    }
};


#endif //AST_LOGICAL_EXPRESSIONS_HPP