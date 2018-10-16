#pragma once

#include <ctime>

int Random(int a, int b)
{
	int r = 0;

	if (a < b)
	{
		r = a + rand() % (b - a + 1);
	}

	return r;

}
