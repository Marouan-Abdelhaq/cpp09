#include "Data.hpp"

Data::Data()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        throw "Impossibl open the csv";
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream stream_line(line);
        std::string key;
        std::string val;
        if(std::getline(stream_line, key, ',') && std::getline(stream_line, val))
        {
            this->db[key] = std::atof(val.c_str());
        }
    }
}

Data& Data::operator=(const Data& obj)
{
    if (this == &obj)
        return *this;
    this->db = obj.db;
    return *this;
}

Data::Data(const Data& obj)
{
    *this = obj;
}

float Data::getVal(std::string key)
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

Data::~Data()
{
}