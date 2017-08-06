//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_MATH_OPERATORS_HPP
#define AST_MATH_OPERATORS_HPP

#include "ast_base_expression.hpp"

class ast_math_operators : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;

	virtual ~ast_math_operators()
	{
	    delete left;
	    delete right;
	}

private:
    const ast_base_expression *left;
    const ast_base_expression *right;

protected:
    ast_math_operators(const ast_base_expression *_left, const ast_base_expression *_right)
        : left(_left)
        , right(_right)
    {}
};

class ast_add_operator : public ast_math_operators{
public:
	ast_add_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};


class ast_subtract_operator : public ast_math_operators{
public:
	ast_subtract_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};


class ast_multiply_operator : public ast_math_operators{
public:
	ast_multiply_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }


};


class ast_divide_operator : public ast_math_operators{
public:
	ast_divide_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};


class ast_bitwise_and_operator : public ast_math_operators{
public:
	ast_bitwise_and_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};

class ast_bitwise_or_operator : public ast_math_operators{
public:
	ast_bitwise_or_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};

class ast_bitwise_xor_operator : public ast_math_operators{
public:
	ast_bitwise_xor_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};

class ast_bitwise_modulo_operator : public ast_math_operators{
public:
	ast_bitwise_modulo_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};


class ast_left_shift_bit : public ast_math_operators{
public:
	ast_left_shift_bit(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};


class ast_right_shift_bit : public ast_math_operators{
public:
	ast_right_shift_bit(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_math_operators(_left, _right) { }
	//~ast_if_else_statement() {}

    void xmlprint() const {
    	
    }

};

#endif //AST_MATH_OPERATORS_HPP

