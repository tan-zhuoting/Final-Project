#include "atom.h"
#include <iostream>

atom::atom() : x(0), y(0), z(0), num(0), element("empty") {}

atom::atom(std::string e, double xx, double yy, double zz) : x(xx), y(yy), z(zz), num(0), element(e) {}

void atom::set_coord(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}

void atom::set_num(int n) {
	num = n;
}
