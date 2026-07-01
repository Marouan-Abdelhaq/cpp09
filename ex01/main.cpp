#include "RPN.hpp"


int main(int argc, char **argv)
{
    try
    {
        if(argc != 2)
            throw std::invalid_argument("Bad input");
        RPN rpn;
        rpn.calculRPN(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}