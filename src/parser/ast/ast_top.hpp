//ast_top

//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_AST_TOP_HPP
#define AST_AST_TOP_HPP


#include "ast_base_expression.hpp"
#include "ast_base.hpp"


class ast_top {
public:
	ast_top() {}

	//~ast_top() {}


	void add_new(ast_base* in_base) {
		all_list.push_back(in_base);
	}

    void xmlprint() const{
    	for (unsigned int i =0; i < all_list.size(); i++) {
    		all_list[i]->xmlprint(); 
    		std::cout << std::endl;
    	}
    }

private:
	std::vector<ast_base*> all_list;

};

#endif //AST_AST_TOP_HPP
