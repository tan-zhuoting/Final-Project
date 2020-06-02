#pragma once
#include<iostream>
#include<vector>

struct atom
{
	atom();
	atom(std::string e, double xx, double yy, double zz);
	void set_coord(double xx, double yy, double zz);
	//void set_num(int n);
	int num;
	std::string element;

	void print();
	std::vector<double> distances;
	double cal_dis(std::vector<atom> m);
	
	double x;
	double y;
	double z;
};

