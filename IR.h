#pragma once
#include <iostream>


struct IR
{
	IR();
	IR(std::string s); 

	bool MatchFreq(int freq);

	int minFreq_ = 0;
	int maxFreq_ = 0;
	std::string article_;
};

