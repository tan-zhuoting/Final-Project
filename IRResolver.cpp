#define _CRT_SECURE_NO_WARNINGS
#include "IRResolver.hpp"
#include <iostream>
#include <cstdio>
//reference:sample codes from https://en.cppreference.com/w/cpp/container/set/find

IRResolver::IRResolver() {}

IRResolver::~IRResolver() {}

void IRResolver::do_insert(const IRFatKey& fat_key) //recursive insert
{
	auto iter = ir_set.find(fat_key);
	if (iter != ir_set.end()) {
		auto k(*iter);
		ir_set.erase(iter);

		IRFatKey left, intersection, right;

		intersection.min_freq = (fat_key.min_freq < k.min_freq) ?
			k.min_freq : fat_key.min_freq;
		intersection.max_freq = (fat_key.max_freq < k.max_freq) ?
			fat_key.max_freq : k.max_freq;

		for (const auto& r : fat_key.records) {
			intersection.records.push_back(r);
		}
		for (const auto& r : k.records) {
			intersection.records.push_back(r);
		}
		const IRFatKey* l = nullptr;
		const IRFatKey* r = nullptr;
		if (fat_key.min_freq < intersection.min_freq) {
			l = &fat_key;
		}
		else if (k.min_freq < intersection.min_freq) {
			l = &k;
		}
		if (fat_key.max_freq > intersection.max_freq) {
			r = &fat_key;
		}
		else if (k.max_freq > intersection.max_freq) {
			r = &k;
		}
		if (l != nullptr) {
			left.min_freq = l->min_freq;
			left.max_freq = intersection.min_freq - 1;
			for (const auto& r : l->records) {
				left.records.push_back(r);
			}
			do_insert(left);
		}
		if (r != nullptr) {
			right.min_freq = intersection.max_freq + 1;
			right.max_freq = r->max_freq;
			for (const auto& r : r->records) {
				right.records.push_back(r);
			}
			do_insert(right);
		}
		do_insert(intersection);

	}
	else {
		if (fat_key.records.empty()) {
			std::cout << "!!! " << fat_key.min_freq << " " << fat_key.max_freq << std::endl;
		}
		auto ret = ir_set.insert(fat_key);
		if (!ret.second) {
			std::cerr << "fat_key failed!\n";
			std::cerr << "fat_key.min = " << fat_key.min_freq << " "
				<< "fat_key.max = " << fat_key.max_freq << "\n";
			exit(0);
		}
	}
}

bool IRResolver::add_record(std::string record)
{
	size_t pos = record.find_first_of(' ');
	std::string sub = record.substr(0, pos);
	IRFatKey fat_key;
	int ret = std::sscanf(sub.c_str(), "%u-%u(", &fat_key.max_freq, &fat_key.min_freq);
	if (ret != 2) {
		ret = std::sscanf(sub.c_str(), "%u(", &fat_key.min_freq);
		if (ret != 1) {
			return false;
		}
		fat_key.max_freq = fat_key.min_freq;
	}
	else {
		if (fat_key.max_freq < fat_key.min_freq) {
			return false;
		}
	}
	std::shared_ptr<std::string> rptr = std::make_shared<std::string>(record);//use shared pointer
	fat_key.records.push_back(rptr);
	do_insert(fat_key);
	return true;
}


std::vector<std::shared_ptr<std::string>> IRResolver::find_records(unsigned freq) 
{
	auto iter = ir_set.find(freq);
	if (iter == ir_set.end()) {
		return {};
	}
	else {
		return iter->records;
	}
}