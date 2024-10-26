#include <vector>
#include <iostream>

bool comp(const std::vector<std::string> &a, const std::vector<std::string> &b)
{
    for(size_t i=0; i < a.size(); i++)
    {
        if (std::stoi(a[i]) != std::stoi(b[i])) 
        {
            return std::stoi(a[i]) < std::stoi(b[i]);
        }
    }
    return false;
}