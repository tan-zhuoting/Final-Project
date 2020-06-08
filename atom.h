#pragma once
#include<iostream>
#include<vector>

struct atom
{
	atom();
	atom(std::string e, double xx, double yy, double zz);
	void set_coord(double xx, double yy, double zz);
	std::string element;

	void print();
	std::vector<double> distances;
	void cal_dis(std::vector<atom>& m);

	double x;
	double y;
	double z;
};

// functions for Degree of Unsaturation calculations
int parse_number(const std::string& str, unsigned pos, unsigned& next_pos);
int parse_elem(const std::string& str, unsigned pos, unsigned& next_pos);
void print_error(const std::string& reason, const std::string& str, unsigned pos);

// use for each elements in Degree of Unsaturation calculations
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
	ELEM_S,
	ELEM_MAX
}; 