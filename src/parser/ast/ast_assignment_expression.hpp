#ifndef AST_ASSIGNMENT_EXPRESSION_HPP
#define AST_ASSIGNMENT_EXPRESSION_HPP


class ast_assignment_expression : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;

	virtual ~ast_assignment_expression()
	{
	    delete left;
	    delete right;
	}

private:
    const ast_base_expression *left;
    const ast_base_expression *right;

protected:
    ast_assignment_expression(const ast_base_expression *_left, const ast_base_expression *_right)
        : left(_left)
        , right(_right)
    {}
};


class ast_assign_equal : public ast_assignment_expression{
public:
	ast_assign_equal(const ast_base_expression *_left, const ast_base_expression *_right) 
	: ast_assignment_expression(_left, _right) { }

    void xmlprint() const {
    	
    }

};

#endif