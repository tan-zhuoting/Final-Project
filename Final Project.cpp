#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
#include "atom.h"
#include "IR.h"
#include "IRResolver.hpp"


int main()
{
	system("chcp 65001");
	char choice;
	std::string input;
	std::cout << std::endl << "  Welcome to Geometry Analyzer!";
	while (true) {
		while (true) {
			std::cout << std::endl << "  a. Upload a .xyz file for geometry analysis." << std::endl
				<< "  b. Enter molecular formula to check degrees of unsaturation." << std::endl
				<< "  c. Enter IR frequency, check the range for functional groups." << std::endl
				<< "  d. IR frequency check using set (new method)." << std::endl
				<< "  e. Quit." << std::endl;

			std::cout << " Do you want to: ";
			std::cin >> choice;

			if (choice != 'e' && choice != 'd' && choice != 'c' && choice != 'b' && choice != 'a')
				std::cout << std::endl << "  Wrong letter, try again.";
			else break;
		}

		if (choice == 'e') {
			std::cout << " OK, bye!" << std::endl;
			return 0;
		}
		std::cin.ignore();
		while (true)
		{
			std::cout << " Enter your input (empty to go back): ";
			std::getline(std::cin, input);

			if (input.empty()) {
				//std::cout << " Input is empty." << std::endl;
				break;
			}

			//below are codes for geometry analysis
			if (choice == 'a')
			{
				std::ifstream ifs(input.c_str());

				if (!ifs.is_open()) {
					std::cout << "fail to open file";
					return 0;
				}

				std::vector<atom> molecule;
				std::string line, ele;
				int total;
				double xx, yy, zz;
				ifs >> total;
				for (size_t i = 0; i < total; i++)
				{
					ifs >> ele >> xx >> yy >> zz;
					molecule.push_back(atom(ele, xx, yy, zz));
				}
				ifs.close();

				std::cout << std::endl << std::setprecision(2) << std::fixed;

				for (size_t k = 0; k < molecule.size(); k++)
				{
					std::cout << std::setw(5) << molecule[k].element << " ";

				}

				for (size_t j = 0; j < molecule.size(); j++)
				{
					molecule[j].cal_dis(molecule);
					molecule[j].print();
				}
				unsigned num;
				std::cout << std::endl << std::endl << " Enter the atom number you want to see (1-" << total << "): ";
				std::cin >> num;
				std::cout << " ";
				molecule[num - unsigned(1)].print();
				std::cout << std::endl;

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
						<< std::endl;
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

				int count = 0;
				for (auto& ir : irs) {
					if (ir.MatchFreq(stoi(input))) {
						++count;
						std::cout << ir.functional_group << std::endl;
					}
				}
				if (count == 0)
					std::cout << "No Match" << std::endl;
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
			
			input.clear();
			std::cout << std::endl << " OK. Now,";

		}
	}

}


