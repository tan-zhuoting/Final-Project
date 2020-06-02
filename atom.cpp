#include "atom.h"
#include <iostream>
#include <cmath>

atom::atom() : x(0), y(0), z(0), num(0), element("empty") {}

atom::atom(std::string e, double xx, double yy, double zz) : x(xx), y(yy), z(zz), num(0), element(e) {}

void atom::set_coord(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}

double atom::cal_dis(std::vector<atom> m) {
	
	for (size_t i = 0; i < m.size(); i++) {

		distances.push_back(sqrt(pow((x - m[i].x), 2) + pow((y - m[i].y), 2) + pow((z - m[i].z), 2)));

	}

	for (size_t k = 0;  k < distances.size();  k++)
	{
		std::cout << distances[k] << "  ";

	}
		
}


//void atom::set_num(int n) {
//	num = n;
//}
