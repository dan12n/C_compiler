//
// Created by Sanjeev Manocha on 10/02/2017.
//

#ifndef AST_AST_FUNCTION_PARAMETERS_HPP
#define AST_AST_FUNCTION_PARAMETERS_HPP


#include "ast_declaration.hpp"

#include "ast_base.hpp"


class ast_function_parameters : public ast_base {
public:
    ast_function_parameters(ast_type* in_type, ast_base_statement* in_ID) {
        ID = in_ID;
        Type = in_type;
    }

    //~ast_function_parameters() {}

    void xmlprint() const {
        std::cout << "<Parameter id=\"";
        
        if (ID != NULL)
            ID->xmlprint();

        std::cout << "\" /> ";
    }

private:
	ast_type* Type;
    ast_base_statement* ID;
};

#endif //AST_AST_FUNCTION_PARAMETERS_HPP
