#ifndef ast_base_hpp
#define ast_base_hpp

#include "ast_basic_tokens.hpp"

class ast_base
{
public:
    virtual ~ast_base()
    {}

    virtual void xmlprint() const =0;
};


class ast_base_empty : public ast_base
{
public:
	ast_base_empty();
	
    void xmlprint(){

    }
};


#endif
