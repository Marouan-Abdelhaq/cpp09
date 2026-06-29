#include "BitcoinExchange.hpp"

void    BitcoinExchange::trim(std::string& str)
{
    if(!str.empty())
    {
        std::size_t first = str.find_first_not_of(" \n\t\r");
        if(first == std::string::npos)
        {
            str.clear();
            return;
        }
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
    std::getline(file, line);
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
            return -1;
        return it->second;
    }
    return this->db[key];
}
bool    is_validDate(const std::string& date)
{
    std::stringstream dateStream(date);
    int y, m, d;
    char    t1, t2;
    std::string last;
    if(!(dateStream >> y >> t1 >> m >> t2 >> d))
        return false;
    if(y < 0 || m < 1 || m > 12 || d < 1 || d > 31 || t1 != '-' || t2 != '-')
        return false;
    if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;
    if(m == 2)
    {
        int max = 28;
        if(!(y % 400) || (!(y % 4) && (y % 100)))
            max = 29;
        if(d > max)
            return false;
    }
    return true;
}
bool    BitcoinExchange::handl_date(std::string& date)
{
    std::stringstream dateStream(date);
    std::string y, m, d;
    if(!is_validDate(date))
        return false;
    if(!std::getline(dateStream, y, '-') || !std::getline(dateStream, m, '-') || !std::getline(dateStream, d))
    trim(y);
    trim(m);
    trim(d);
    if(m.size() != 2 || d.size() != 2)
        return false;
    
    date = y + "-" + m + "-" + d;
    return true;
}

void    BitcoinExchange::print_erro(std::string key)
{
    std::cerr << "Error: bad input";
    if(!key.empty())
        std::cout << " => " << key;
    std::cout << std::endl;
}

void    BitcoinExchange::calcul_exchange(float val, std::string key)
{
    if(val < 0)
        std::cerr << "Error: not a positive number." << std::endl;
    else if(val > 1000)
        std::cerr << "Error: too large a number." << std::endl;
    else
    {
        float exchangeVal = this->getVal(key);
        if(exchangeVal < 0)
        {
            std::cerr << "Error: bad input";
            if(!key.empty())
                std::cout << " => " << key;
            std::cout << std::endl;
        }
        else
        {
            exchangeVal *= val;
            std::cout << key << " => " << val << " = " << exchangeVal << std::endl;
        }
    }
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
        std::stringstream lineStream(line);
        std::string key;
        float val;
        std::string    other;
        if(line.empty())
            continue;
        else if(std::getline(lineStream, key, '|'))
        {
            if(handl_date(key))
            {
                if(lineStream >> val)
                {
                    if(std::getline(lineStream, other))
                    {
                        trim(other);
                        if(!other.empty())
                            this->print_erro(key);
                        else
                            this->calcul_exchange(val, key);
                    }
                    else
                        this->calcul_exchange(val, key);
                }
                else
                    this->print_erro(key);
            }
            else
                this->print_erro(key);
        }
        else
            this->print_erro(key);
    }
    
}

BitcoinExchange::~BitcoinExchange()
{
}