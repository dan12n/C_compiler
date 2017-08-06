#include "ast.hpp"

int main()
{
    const ast_top* ast=parseAST();
    int dest_reg = 2;
    /*
    std::cout << "<?xml version=\"1.0\"?>" << std::endl;
    std::cout << "<Program>" << std::endl;
    ast->xmlprint();
    std::cout<<std::endl;
    std::cout << "</Program>" << std::endl;
    */
    int total_memory;
    total_memory+= 32;
    ast->allocate_memory(total_memory);

    mips_registers* registers= new mips_registers(total_memory);
   
    ast_context* context = new ast_context(std::cout);
    
    ast->prettyprint(std::cerr);

    ast->generate_assembly(context, registers, dest_reg);
    
    return 0;
}
