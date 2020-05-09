#pragma once
#include <string>
class atom
{
public:
	atom();
	atom(string e, double xx, double yy, double zz);
	void set_coord(double xx, double yy, double zz);
private:
	int num;
	string element;
	int atomic_num;
	double x;
	double y;
	double z;
};

