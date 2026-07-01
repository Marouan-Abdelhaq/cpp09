#include "RPN.hpp"
#include <sstream>
RPN::RPN()
{
    this->stack.push(0);
}

RPN::RPN(const RPN& obj)
{
    *this = obj;
}

RPN&    RPN::operator=(const RPN& obj)
{
    if(this == &obj)
        return *this;
    this->stack = obj.stack;
    return *this;
}

bool    RPN::is_operator(std::string& c)
{
    if(c == "-" || c == "+" || c == "/" || c == "*")
        return true;
    return false;
}

void    RPN::push_stack(std::string& c)
{
    std::stringstream ss(c);
    int num = 0;
    if(ss >> num)
        this->stack.push(num);
}

void    RPN::calcule_operator(std::string& c)
{
    int b = this->stack.top();
    this->stack.pop();
    int a = this->stack.top();
    this->stack.pop();
    if(c == "+")
        this->stack.push(a + b);
    else if(c == "-")
        this->stack.push(a - b);
    else if(c == "/")
    {
        if(b != 0)
            this->stack.push(a / b);
        else
            throw std::invalid_argument("Error");
    }
    else
        this->stack.push(a * b);

}

bool    RPN::is_num(std::string& str)
{
    std::stringstream ss(str);
    int num = 0;
    if(ss >> num)
        return true;
    return false;
}

void    RPN::calculRPN(const std::string& str)
{
    std::stringstream ss(str);
    std::string    c;
    int num = 0;
    int ch = 0;
    while (ss >> c)
    {
        if(is_num(c))
        {
            push_stack(c);
            num++;
        }
        else if(is_operator(c))
        {
            calcule_operator(c);
            ch++;
        }
        else
            throw std::invalid_argument("Error");
    }
    if((num - ch) != 1)
            throw std::invalid_argument("Error");
    std::cout << this->stack.top() << std::endl;
}

RPN::~RPN()
{
}