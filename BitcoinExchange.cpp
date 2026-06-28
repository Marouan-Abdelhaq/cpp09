#include "BitcoinExchange.hpp"

void    BitcoinExchange::trim(std::string& str)
{
    if(!str.empty())
    {
        std::size_t first = str.find_first_not_of(" \n\t\r");
        std::size_t last = str.find_last_not_of(" \n\t\r");
        str = str.substr(first, last - first + 1);
    }
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        throw std::invalid_argument("Impossibl open the csv");
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream stream_line(line);
        std::string key;
        std::string val;
        if(std::getline(stream_line, key, ','))
        {
            if(handl_date(key))
            {
                if(!(stream_line >> this->db[key]))
                    throw std::invalid_argument("Invalid argument");
            }
            else
                throw std::invalid_argument("Invalid date");
        }
        stream_line.clear();
    }
    file.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this == &obj)
        return *this;
    this->db = obj.db;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    *this = obj;
}

float BitcoinExchange::getVal(std::string key)
{
    std::map<std::string, float>::iterator it = this->db.find(key);
    if (it == this->db.end())
    {
        it = this->db.lower_bound(key);
        if(it != this->db.begin())
            it--;
        else
            return 0;
        return it->second;
    }
    return this->db[key];
}
bool    is_validDate(const std::string& date)
{
    std::stringstream dateStream(date);
    int y, m, d;
    char    t1, t2;
    if(!(dateStream >> y >> t1 >> m >> t2 >> d))
        return false;
    if(y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}
bool    BitcoinExchange::handl_date(std::string& date)
{
    std::stringstream dateStream(date);
    std::string y, m, d;
    char    t1, t2;
    std::cout << date << std::endl;
    if(!(dateStream >> y >> t1 >> m >> t2 >> d))
        return false;
    trim(y);
    trim(m);
    trim(d);
    if(m.size() != 2 || d.size() != 2 || t1 != '-' || t2 != '-')
        return false;
    if(!is_validDate(date))
        return false;
    date = y + t1 + m + t2 + d;
    return true;
}

void    BitcoinExchange::exchange(char *str)
{
    std::ifstream file(str);
    if (!file.is_open())
    {
        throw std::invalid_argument("Impossibl open the file");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        std::stringstream lineStream(line);
        std::string key;
        float val;
        if(std::getline(lineStream, key, '|'))
        {
            if(handl_date(key))
            {
                if(lineStream >> val)
                {
                    if(val < 0)
                        std::cerr << "Error: not a positive number." << std::endl;
                    else if(val > 1000)
                        std::cerr << "Error: too large a number." << std::endl;
                    else
                        this->input[key] = val;
                }
                else
                    std::cerr << "Error: invalide argument";
                
            }
            else
                std::cerr << "Error: bad input => " << key << std::endl;
        }
        else
            std::cerr << "Error: bad input => " << key << std::endl;
    }
    float exchange;
    std::map<std::string, float>::iterator it;
    for (it = this->input.begin(); it != this->input.end(); ++it)
    {
        exchange = it->second * getVal(it->first);
        std::cout << it->first << " => " << getVal(it->first) << " = " << exchange << std::endl;
    }
    
}

BitcoinExchange::~BitcoinExchange()
{
}