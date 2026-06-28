#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> db;
        std::map<std::string, float> input;
        void    trim(std::string& str);
        bool    handl_date(std::string& date);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange&   operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        void    exchange(char *str);
        
        // void    load_input(char *str);
        float   getVal(std::string key);
        
};
