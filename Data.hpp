#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class Data
{
    private:
        std::map<std::string, float> db;
    public:
        Data();
        Data(const Data& obj);
        Data& operator=(const Data& obj);
        ~Data();

        float getVal(std::string key);
};
