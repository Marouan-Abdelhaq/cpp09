#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>

bool kherya(int& n)
{
    n = 3;
    return true;
}

int main(int argc, char** argv) {
    (void *)argv;
    // std::ifstream file("BitcoinExchange.csv");
    // std::string line;
    // std::map<std::string, float> m;

    // while (std::getline(file, line)) {
    //     std::stringstream ss(line);
    //     std::string key;
    //     std::string val;
        
    //     if (std::getline(ss, key, ',') && std::getline(ss, val)) {
    //             m[key] = std::atof(val.c_str());
    //     }
    // }

    // std::ifstream input(argv[1]);
    // std::string l;
    // while (std::getline(input, l))
    // {
    //     std::stringstream ss(l);
    //     std::string key;
    //     std::string val;

    //     if (std::getline(ss, key, '|') && std::getline(ss, val))
    //     {
    //         if (std::atof(val.c_str()) < 0)
    //         {
    //             std::cout << "Error: not a positive number." << std::endl;
    //         }
    //         else if (std::atof(val.c_str()) > 1000)
    //         {
    //             std::cout << "Error: too large a number." << std::endl;
    //         }
            
    //         else
    //         {
    //             key.erase(key.length() - 1);
    //             std::map<std::string, float>::iterator i = m.find(key);
    //             if (i == m.end())
    //             {
    //                 i = m.lower_bound(key);
    //                 i--;
    //             }
    //             std::cout << i->first << " => " << val << " = " << i->second*std::atof(val.c_str());
    //             std::cout << std::endl;
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "Error: bad input => " << key << std::endl;
    //     }
    // }
    

    // std::stringstream ss("      01      ");
    // int num;
    // if(ss >> num)
    // {
    //     std::cout << num << std::endl;
    // }
    // else
    // {
    //     std::cout << "Error" << std::endl;
    // }

    int n = 8;
    if(kherya(n))
        std::cout << n << std::endl;
    return 0;
}
