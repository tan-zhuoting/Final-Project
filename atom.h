#pragma once
#include<iostream>

class atom
{
public:
	atom();
	atom(std::string e, double xx, double yy, double zz);
	void set_coord(double xx, double yy, double zz);
private:
	int num;
	std::string element;
	//int atomic_num;
	double x;
	double y;
	double z;
};

