#include "atom.h"
#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

atom::atom() : x(0), y(0), z(0), element("empty") {}

atom::atom(std::string e, double xx, double yy, double zz) : x(xx), y(yy), z(zz), element(e) {}

void atom::set_coord(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}

//calculate all possible bond distances from one atom to another atom
void atom::cal_dis(std::vector<atom>& m) { 

	for (size_t i = 0; i < m.size(); i++) {

		distances.push_back(sqrt(pow((x - m[i].x), 2) + pow((y - m[i].y), 2) + pow((z - m[i].z), 2)));

	}
}

//print out all calculation results
void atom::print() {  
	std::cout << std::endl << element << "  ";
	for (size_t k = 0; k < distances.size(); k++)
	{
		std::cout << distances[k] << "  ";
	}
}

//parse input string to number
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
	return std::stoi(num_str);
}

// parse input string to element
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
	case 'S':
		return ELEM_S;
		break;
	default:
		return -1;
	}
	return -1;
}

// indicate where the error is in the input
void print_error(const std::string& reason, const std::string& str, unsigned pos)
{
	std::cout << "input error: " << reason << " at:" << std::endl;
	std::cout << str << std::endl;
	for (unsigned i = 0; i < pos; i++) {
		std::cout << " ";
	}
	std::cout << "^" << std::endl;
}