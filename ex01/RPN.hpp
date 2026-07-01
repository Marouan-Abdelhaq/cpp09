#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN& obj);
        RPN&    operator=(const RPN& obj);
        ~RPN();

        void    calculRPN(const std::string& str);
        bool    is_num(std::string& str);
        bool    is_operator(std::string& c);
        void    push_stack(std::string& c);
        void    calcule_operator(std::string& c);
};


#endif