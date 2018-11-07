#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: random for different types

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/

#include <ctime>

/**
	Random integer

	@param int variable
	@return random integer
*/
inline int Random(int r) {
	r = rand();
	return r;
}

/**
	Random integer on interval [a,b]

	@param two int variable a and b (beginning and end of the interval)
	@return random integer
*/
inline int Random(int a, int b) {
	int r = 0;
	if (a < b) {
		r = a + rand() % (b - a + 1);
	}
	return r;
}

/**
	Random double

	@param double variable 
	@return random double
*/
inline double Random(double res) {
	int num = 1e5;
	int int_part = rand() % 100;
	int drob_part = rand() % num;
	double a = double(drob_part) / num;//rand drob_part
	res = double(int_part) + a;
	return res;
}

