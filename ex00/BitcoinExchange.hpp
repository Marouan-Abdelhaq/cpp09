#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> db;
        void    trim(std::string& str);
        bool    handl_date(std::string& date);
        void    calcul_exchange(float val, std::string key);
        void    print_erro(std::string key);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange&   operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        void    exchange(char *str);
        float   getVal(std::string key);
        
};
