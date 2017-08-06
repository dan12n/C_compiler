//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP


#include "ast_base_expression.hpp"
#include "ast_base_statement.hpp"
#include "ast_function_parameters.hpp"

class ast_declarator : public ast_base_statement {
public:
	virtual ~ast_declarator() {}

    virtual void xmlprint() const = 0;

protected:
	ast_identifier* ID;
	std::vector<ast_function_parameters*> all_parameters;
	std::vector<ast_identifier*> all_ids;

};


class ast_variable_declarator: public ast_declarator {
public:
	ast_variable_declarator(ast_identifier* in_ID) {
		ID = in_ID;
	}

	void xmlprint() const{
		if (ID != NULL)
			ID->xmlprint();
	}
private:

};

class ast_function_declarator: public ast_declarator {
public:
	ast_function_declarator(ast_identifier* in_ID, std::vector<ast_function_parameters*> in_parameters) {
		ID = in_ID;
		all_parameters = in_parameters;
	}

	ast_function_declarator(ast_identifier* in_ID) {
		ID = in_ID;
	}

	void xmlprint() const{

	}
};

class ast_initialisers_declarator : public ast_base_statement {
public:
	ast_initialisers_declarator(ast_declarator* in_dec, ast_base_expression* in_equal_expr) {
		declarator = in_dec;
		equal_expression = in_equal_expr;
	}

	void xmlprint() const{
    	std::cout << "<Variable id=\"";
		if (declarator != NULL)
			declarator->xmlprint();
    	std::cout <<"\" /> ";

	}

private:
	ast_declarator* declarator;
	ast_base_expression* equal_expression;
};


class ast_declaration : public ast_base_statement {
public:

	ast_declaration(ast_type* in_Type) {
		Type = in_Type;
	}

	ast_declaration(ast_type* in_Type, std::vector<ast_initialisers_declarator*> in_dec) {
		Type = in_Type;
		dec_list = in_dec;
	}

	//~ast_declaration() {}

    void xmlprint() const{
    	for (unsigned int i =0; i < dec_list.size(); i++) {
    		if (dec_list[i] != NULL)
    			dec_list[i]->xmlprint();
    	}
    	std::cout << std::endl;
    }

private:
	ast_type* Type;
	std::vector<ast_initialisers_declarator*> dec_list;

};


#endif //AST_DECLARATION_HPP
