//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_COMPOUND_STATEMENT_HPP
#define AST_AST_COMPOUND_STATEMENT_HPP

#include "ast_base_statement.hpp"

class ast_statement_list : public ast_base_statement{
public:
    ast_statement_list(){
    }

    void add_new(ast_base_statement* in_stat) {
        all_statements.push_back(in_stat);
    }
    //~ast_compound_statement() {}


    void xmlprint() const {
        for (unsigned int i =0; i < all_statements.size(); i++) {
          if (all_statements[i] != NULL)
            all_statements[i]->xmlprint();
        }
    }

private:
    std::vector<ast_base_statement*> all_statements;

};

class ast_compound_statement : public ast_base_statement{
public:
    ast_compound_statement(ast_statement_list* in_stat){
        all_statements = in_stat;
        empty_function = false;
    }

    ast_compound_statement(){
        empty_function = true;
    }

    //~ast_compound_statement() {}


    void xmlprint() const {
        std::cout << "<Scope>" << std::endl;
        if (!empty_function && all_statements != NULL) {
            all_statements->xmlprint();
        }
        std::cout << "</Scope>" << std::endl;

    }

private:
    ast_statement_list* all_statements;

    bool empty_function;
};



#endif //AST_AST_COMPOUND_STATEMENT_HPP
