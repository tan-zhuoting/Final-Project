
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

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
    std::cout << "  Welcome to Geometry analyzer!" << std::endl
        << "  a. Upload an xyz file for geometry analysis." << std::endl
        << "  b. Enter molecular formula to check degrees of unsaturation." << std::endl
        << "  c. Enter IR frequency, check ." << std::endl
        << "  d. Quit." << std::endl;
    std::cout << " Do you want to: ";
        std::cin >> choice;
        std::cout << " Enter your input: ";
        std::cin >> input;
    //below is codes for degrees of unsaturation
   if (choice == 'b'){
           if (input.empty()) {
               std::cout << "input is empty, bye" << std::endl;
               return 0;
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

