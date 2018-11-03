#pragma once

/**
random for different types
*/

#include <ctime>

//random integer
inline int Random(int r) {
	r = rand();
	return r;
}

//random integer on interval [a,b]
inline int Random(int a, int b) {
	int r = 0;
	if (a < b) {
		r = a + rand() % (b - a + 1);
	}
	return r;
}

//random fractional number
inline double Random(double res) {
	int num = 1e5;
	int int_part = rand() % 100;
	int drob_part = rand() % num;
	double a = double(drob_part) / num;//rand drob_part
	res = double(int_part) + a;
	return res;
}

