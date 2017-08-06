#include "ast.hpp"

int main()
{
    const ast_top* ast=parseAST();

    std::cout << "<?xml version=\"1.0\"?>" << std::endl;
    std::cout << "<Program>" << std::endl;
    ast->xmlprint();
    std::cout<<std::endl;
    std::cout << "</Program>" << std::endl;

    return 0;
}
