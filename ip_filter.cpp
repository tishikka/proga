#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> ip_adress(const std::string& ip_str) {
    std::vector<std::string> ip;
    size_t start = 0;
    size_t end = ip_str.find('.');

    while (end != std::string::npos) {
        ip.push_back(ip_str.substr(start, end - start));
        start = end + 1;
        end = ip_str.find('.', start);
    }
    ip.push_back(ip_str.substr(start));
    return ip;
}

int main() {

    auto comp=[](const std::vector<std::string> &a, const std::vector<std::string> &b)->bool{
        for(size_t i=0;i<a.size();i++)
        {
            if (std::stoi(a[i]) != std::stoi(b[i])) 
            {
                return std::stoi(a[i]) < std::stoi(b[i]);
            }
        }
        return false;
    };

    std::vector<std::vector<std::string>> ip_list;
    std::string line;

    std::ifstream in("C:\\proga_sem3\\lab2\\ip_filter.tsv");

    while (std::getline(in, line)) {
        size_t tabul = line.find('\t');
        std::string ip_str = line.substr(0, tabul);
        ip_list.push_back(ip_adress(ip_str));
    }

    std::sort(ip_list.begin(), ip_list.end(), comp);
    for(auto ip : ip_list)
    {
        std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." <<ip[3] << std::endl;
    }


    for(const auto& ip : ip_list) 
    {
        if(ip[0] == "1")
        {
            std::cout<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<std::endl;
        }
    }

        for(auto ip : ip_list)
    {
        if(ip[0]=="46"&&ip[1]=="70")
        {
            std::cout<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<std::endl;
        }
    }

        for(auto ip : ip_list)
    {
        if(ip[0]=="46"||ip[1]=="46"||ip[2]=="46"||ip[3]=="46")
        {
            std::cout<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<std::endl;
        }
    }
    return 0;
}
