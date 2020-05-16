#pragma once
#include<iostream>
#include<vector>
#include <set>
#include <memory>
class IRResolver
{
public:
    IRResolver();
    ~IRResolver();
    bool add_record(std::string record);
    std::vector<std::shared_ptr<std::string>> find_records(unsigned freq);
private:
    struct IRFatKey;

    void do_insert(const IRFatKey& fat_key);
    std::set<IRFatKey, std::less<>> ir_set;

};

