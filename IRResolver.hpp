#pragma once
#include<iostream>
#include<vector>
#include <set>
#include <memory>
#include <string>

//This is a new version of IR, I want to try this so that I can apply the new concepts in class
//reference:https://en.cppreference.com/w/cpp/container/set/find

class IRResolver
{
public:
    IRResolver();
    ~IRResolver();
    bool add_record(std::string record);
    std::vector<std::shared_ptr<std::string>> find_records(unsigned freq);

private:
    struct IRFatKey
    {
        unsigned min_freq;
        unsigned max_freq;
        std::vector<std::shared_ptr<std::string>> records;

        IRFatKey() = default;

        IRFatKey(const IRFatKey& other) = default;
    };
    friend bool operator<(const IRFatKey& k1, const IRFatKey& k2)
    {
        return k1.max_freq < k2.min_freq;
    }
    friend bool operator<(const IRFatKey& k1, const unsigned& k2)
    {
        return k1.max_freq < k2;
    }
    friend bool operator<(const unsigned& k1, const IRFatKey& k2)
    {
        return k1 < k2.min_freq;
    }

    void do_insert(const IRFatKey& fat_key);

    std::set<IRFatKey, std::less<>> ir_set;
};

