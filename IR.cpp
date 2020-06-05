#include "IR.h"
#include <string>
#include <cassert>

IR::IR() {}

IR::IR(std::string s) : functional_group(s) { //do these when create an IR object
	std::string freq_str = s.substr(0, 20);
	size_t pos_line = freq_str.find_first_of('-');
	size_t pos_quote = freq_str.find_first_of('(');

	if (pos_line == std::string::npos) { //If "-" is not found, this is the case for single number (no interval)
		if (pos_quote == std::string::npos) { //"(" exists in every line of given data file
			assert(0);
			return;
		}
		else {	// frequency is the one before "(" 
			std::string max_str = freq_str.substr(0, pos_quote);
			max_freq = stoi(max_str);
			min_freq = max_freq;
		}
	}
	else {		// If "-" is found, this is the case for frequency interval
		std::string max_str = freq_str.substr(0, pos_line); // maximum freq is the one before"-"
		max_freq = stoi(max_str);
		if (pos_quote == std::string::npos) {
			min_freq = max_freq;
		}
		else {
			std::string min_str = freq_str.substr(pos_line + 1, pos_quote); //minimum freq is the one after"-"
			min_freq = stoi(min_str);
		}
	}
}

bool IR::MatchFreq(int freq) { 

	return freq >= min_freq && freq <= max_freq; 

}  //check if the input frequency is within the interval for certain functional group 