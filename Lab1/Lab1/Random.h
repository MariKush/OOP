#pragma once

#include <ctime>
//#include <cmath> 

int Random(int a, int b)
{
	int r = 0;

	if (a < b)
	{
		r = a + rand() % (b - a + 1);
	}

	return r;

}

double RandomD(int precision)
{
	int num = (int)pow(10, precision);

	int int_part = rand() % 100;
	int drob_part = rand() % num;
	double a = double(drob_part) / num;//rand drob_part
	double res = double(int_part) + a;
	
}
