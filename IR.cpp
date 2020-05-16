#include "IR.h"
#include <string>
#include <cassert>

IR::IR() {}

IR::IR(std::string s) : article_(s) {
	std::string freq_str = s.substr(0, 20);
	size_t pos_line = freq_str.find_first_of('-');
	size_t pos_quote = freq_str.find_first_of('(');

	if (pos_line == std::string::npos) { //reach the end of string
		if (pos_quote == std::string::npos) {
			assert(0);
			return;
		}
		else {
			std::string max_str = freq_str.substr(0, pos_quote);
			maxFreq_ = stoi(max_str);
			minFreq_ = maxFreq_;
		}
	}
	else {
		std::string max_str = freq_str.substr(0, pos_line);
		maxFreq_ = stoi(max_str);
		if (pos_quote == std::string::npos) {
			minFreq_ = maxFreq_;
		}
		else {
			std::string min_str = freq_str.substr(pos_line + 1, pos_quote);
			minFreq_ = stoi(min_str);
		}
	}
}

bool IR::MatchFreq(int freq) { return freq >= minFreq_ && freq <= maxFreq_; }