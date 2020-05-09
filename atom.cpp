#include "atom.h"
atom::atom() {
	x = 0;
	y = 0;
	z = 0;
	num = 0;
	element = "empty";
	atomic_num = 0;
}
atom::atom(string e, int n, double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
	num = n;
	element = e;
	atomic_num = 0;

}

void atom::set_coord(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}