#pragma once
#include <iostream>


struct IR //this represents the IR range (an interval of two integers) for certain functional groups
{
	IR();
	IR(std::string s); 

	bool MatchFreq(int freq); //check if the input frequency is within the interval for certain functional groups

	int min_freq = 0;
	int max_freq = 0;
	std::string functional_group;
};

