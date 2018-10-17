#pragma once

#include <ctime>
//#include <cmath> 

#include "DateTime.h"

int Random(int r) {
	r = rand();

	return r;
}

int Random(int a, int b){
	int r = 0;
	if (a < b){
		r = a + rand() % (b - a + 1);
	}

	return r;
}

double Random(double res)
{
	int num = 1e5;
	int int_part = rand() % 100;
	int drob_part = rand() % num;
	double a = double(drob_part) / num;//rand drob_part
	res = double(int_part) + a;

	return res;

}
