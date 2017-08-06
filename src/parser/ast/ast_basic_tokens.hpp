//
// Created by Sanjeev Manocha on 09/02/2017.
//

#ifndef AST_BASIC_TOKENS_HPP
#define AST_BASIC_TOKENS_HPP

#include <string>
#include <iostream>
#include <map>
#include <vector>


class ast_identifier{
public:
	ast_identifier(std::string in_ID) {
		ID = in_ID;
	}
	

    void xmlprint() const {
    	std::cout << ID;
    }

private:
	std::string ID;
    
};


class ast_number {
public:
	ast_number(int in_num) {
		num = in_num;
	}
	

    void xmlprint() const{
    	std::cout << num;
    }

private:
	int num;
};

class ast_type {
public:
	ast_type(std::string in_type) {
		Type = in_type;
	}
	

    void xmlprint() const{
    	std::cout << Type;
    }

private:
	std::string Type;
};


class ast_operator {
public:
	ast_operator(char* in_op) {
		op = in_op;
	}


	void xmlprint() const{
    	std::cout << op;
	}

private:
	char* op;
};


class ast_string {
public:
	ast_string(std::string in_str) {
		Str = in_str;
	}

	void xmlprint() const{
    	//std::cout << op;
	}

private:
	std::string Str;
};

#endif

