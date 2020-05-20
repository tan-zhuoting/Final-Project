
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
#include "IR.h"
#include "IRResolver.hpp"


int parse_number(const std::string& str, unsigned pos, unsigned& next_pos);
int parse_elem(const std::string& str, unsigned pos, unsigned& next_pos);
void print_error(const std::string& reason, const std::string& str, unsigned pos);
enum ELEM
{
	ELEM_C = 0,
	ELEM_N,
	ELEM_H,
	ELEM_F,
	ELEM_Cl,
	ELEM_Br,
	ELEM_I,
	ELEM_O,
	ELEM_MAX
}; // use for each elements

int main()
{
	char choice;
	std::string input;
	std::cout << std::endl << "  Welcome to Geometry Analyzer!";
	while (true) {
		std::cout << std::endl << "  a. Upload a .xyz file for geometry analysis." << std::endl
			<< "  b. Enter molecular formula to check degrees of unsaturation." << std::endl
			<< "  c. Enter IR frequency, check the range for functional groups." << std::endl
			<< "  d. IR frequency check set(faster)." << std::endl
			<< "  e. Quit." << std::endl;

		std::cout << " Do you want to: ";
		std::cin >> choice;

		if (choice == 'e') return 0;

		std::cout << " Enter your input (empty to quit): ";
		std::cin.ignore();
		std::getline(std::cin, input);

		if (input.empty()) {
			std::cout << " Input is empty." << std::endl;
			return 0;
		}

		//below are codes for geometry analysis
		if (choice == 'a')
		{







		}

		//below are codes for degrees of unsaturation
		if (choice == 'b') {

			int elem_arr[ELEM_MAX] = { 0 };

			bool is_success = true;
			unsigned i = 0;
			while (i < input.size()) {
				ELEM e;
				unsigned next_i = 0;
				int ret = parse_elem(input, i, next_i);
				if (ret == -1) {
					is_success = false;
					print_error("illegal element", input, i);
					break;
				}
				e = (ELEM)ret;
				i = next_i;
				ret = parse_number(input, i, next_i);
				if (ret == -1) {
					elem_arr[e] += 1;
				}
				else {
					elem_arr[e] += ret;
					i = next_i;
				}
			}

			if (is_success) {
				unsigned elem_x = elem_arr[ELEM_F] + elem_arr[ELEM_Cl] + elem_arr[ELEM_Br] + elem_arr[ELEM_I];
				std::cout << " Degree of Unsaturation is: "
					<< ((2 * elem_arr[ELEM_C] + 2) - elem_arr[ELEM_H] + elem_arr[ELEM_N] - elem_x) / 2.0
					<< std::endl << std::endl;
			}
		}

		//below are codes for IR frequency anaylysis
		if (choice == 'c')
		{
			std::cout << "Searching..." << std::endl;
			std::vector<IR> irs;

			std::ifstream ifs("data.txt");
			if (!ifs.is_open()) {
				std::cout << "fail to open file";
				return 0;
			}

			std::string s;
			while (getline(ifs, s)) {
				IR ir(s);
				irs.push_back(ir);
			}
			ifs.close();

			// 	for(int i = 0; i <10; ++i){
			// 		IR ir;
			// 		ir.minFreq_ = i;
			// 		ir.maxFreq_ = i + 10;
			// 		ir.article_ = to_string(ir.minFreq_) + "_" + to_string(ir.maxFreq_);
			// 		irs.push_back(ir);
			// 	}
			int count = 0;
			for (auto& ir : irs) {
				if (ir.MatchFreq(stoi(input))) {
					++count;
					std::cout << ir.article_ << std::endl;
					/*ofstream ofs("result.txt");
					ofs << ir.article_ << std::endl;
					ofs.close();*/
				}
			}
			if (count == 0)
				std::cout << "No Match" << std::endl;
			std::cout << std::endl;

		}

		//below are codes for faster IR frequency anaylysis
		if (choice == 'd') {
			IRResolver irr;
			std::ifstream ifs("data.txt");
			std::string line;
			if (!ifs.is_open()) {
				std::cout << "fail to open file";
				return 0;
			}
			while (std::getline(ifs, line)) {
				irr.add_record(line);
			}
			ifs.close();
			auto recs = irr.find_records(stoi(input));
			for (auto& r : recs) {
				std::cout << *r << std::endl;
			}
		}
	}

}

int parse_number(const std::string& str, unsigned pos, unsigned& next_pos)
{
	if (pos >= str.size() || !std::isdigit(str.at(pos))) {
		return -1;
	}
	next_pos = pos + 1;
	while (next_pos < str.size() && std::isdigit(str.at(next_pos))) {
		next_pos++;
	}
	std::string num_str = str.substr(pos, next_pos - pos);
	return std::atoi(num_str.c_str());
}

int parse_elem(const std::string& str, unsigned pos, unsigned& next_pos)
{
	if (pos >= str.size()) {
		return -1;
	}
	next_pos = pos + 1;
	switch (str.at(pos)) {
	case 'C':
		if (next_pos < str.size() && str.at(next_pos) == 'l') {
			next_pos++;
			return ELEM_Cl;
		}
		else {
			return ELEM_C;
		}
		break;
	case 'N':
		return ELEM_N;
		break;
	case 'H':
		return ELEM_H;
		break;
	case 'F':
		return ELEM_F;
		break;
	case 'B':
		if (next_pos < str.size() && str.at(next_pos) == 'r') {
			next_pos++;
			return ELEM_Br;
		}
		else {
			return -1;
		}
		break;
	case 'I':
		return ELEM_I;
		break;
	case 'O':
		return ELEM_O;
		break;
	default:
		return -1;
	}
	return -1;
}

void print_error(const std::string& reason, const std::string& str, unsigned pos)
{
	std::cout << "input error: " << reason << " at:" << std::endl;
	std::cout << str << std::endl;
	for (unsigned i = 0; i < pos; i++) {
		std::cout << " ";
	}
	std::cout << "^" << std::endl;
}
