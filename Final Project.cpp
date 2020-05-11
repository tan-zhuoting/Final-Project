
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
    std::cout << " Do you want to?";
        std::cin >> choice;
        std::cout << " Enter your input?";
        std::cin >> input;
    //below is codes for degrees of unsaturation
   if (choice == 'b'){
           if (input.empty()) {
               std::cout << "input is empty, bye" << std::endl;
               return 0;
           }      
       
   }

}


