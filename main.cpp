#include "Data.hpp"
#include <exception>


std::string    trim(std::string& str)
{
    const std::string& whitespaces = "\t\n\r";
    size_t  begin = str.find_first_not_of(whitespaces);
    size_t  end = str.find_last_not_of(whitespaces);
    return str.substr(begin, (end - begin + 1));
}

int main(int argc, char **argv)
{
    try
    {
        std::map<std::string, float> exchange;
        if(argc != 2)
        {
            throw std::invalid_argument("invalid number of arguments");    
        }
        else
        {
            std::stringstream sstring(argv[1]);
            std::string key;
            std::string val;
            while (std::getline(sstring, key, '|'))
            {
                if(!std::getline(sstring, val))
                    throw std::invalid_argument("bad input => " + key);
            }
            
        }
        Data db;
        std::cout << db.getVal("2009-01-02");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error " << e.what() << '\n';
    }
}