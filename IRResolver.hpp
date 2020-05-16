#pragma once
#include<iostream>
#include<vector>
class IRResolver
{
public:
    IRResolver();
    ~IRResolver();
    bool add_record(std::string record);
    std::vector<std::shared_ptr<std::string>> find_records(unsigned freq);


};

