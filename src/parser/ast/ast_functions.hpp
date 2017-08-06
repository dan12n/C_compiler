#ifndef ast_functions_hpp
#define ast_functions_hpp

#include "ast_base.hpp"
#include "ast_function_parameters.hpp"
#include "ast_compound_statement.hpp"

#include <cmath>

class ast_function : public ast_base
{
private:
    std::vector<ast_function_parameters*> ast_parameters;
    ast_compound_statement* statements;
    ast_type* return_type;
    ast_identifier* ID;

public:
    ast_function(ast_type* in_return_type, ast_identifier* in_id, std::vector<ast_function_parameters*> in_params, ast_compound_statement* in_stat) {
        ast_parameters = in_params;
        statements = in_stat;
        return_type = in_return_type;
        ID = in_id;
    }

    ast_function(ast_type* in_return_type, ast_identifier* in_id, ast_compound_statement* in_stat) {
        statements = in_stat;
        return_type = in_return_type;
        ID = in_id;
    }
    //~ast_function() { }

    void xmlprint() const {
        std::cout << "<Function id=\"";
        ID->xmlprint();
        std::cout << "\">" << std::endl;

    	for (unsigned int i =0; i < ast_parameters.size(); i++) {
    		if (ast_parameters[i] != NULL) {
                ast_parameters[i]->xmlprint();
            }
    	}
        
        if (statements != NULL)
            statements->xmlprint();
        
        std::cout << "</Function>" << std::endl;
    }

};



class ast_function_call : public ast_base_expression
{
private:
    std::vector<ast_base_expression*> args_list;
    ast_base_expression* ID;


public:
    ast_function_call(ast_base_expression* in_ID, std::vector<ast_base_expression*> in_args_list) {
        ID = in_ID;
        args_list = in_args_list;

    }

    ast_function_call(ast_base_expression* in_ID) {
        ID = in_ID;

    }

    //~ast_function() { }

    void xmlprint() const {
        //for (int i = 0; i < args_list.size(); ++i)
        //{
        //    args_list[i]->xmlprint();
        //}
    }

};

#endif
