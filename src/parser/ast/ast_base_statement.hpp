//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_BASE_STATEMENT_HPP
#define AST_BASE_STATEMENT_HPP

#include "ast_base.hpp"

class ast_base_statement : public ast_base{
public:
    virtual void xmlprint() const = 0;
};

#endif //AST_DECLARATION_HPP
