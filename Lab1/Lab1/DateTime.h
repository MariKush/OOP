#pragma once

class DateTime
{
	int year, month, day, hour, minute, second;
	
public:
	DateTime()
	{
		year = 1;
		month = 1;
		day = 1;
		hour = 0;
		minute = 0;
		second = 0;
	};
	DateTime(int y, int mon, int d, int h, int min, int s)
	{
		year = y;
		month = mon;
		day = d;
		hour = h;
		minute = min;
		second = s;
	};
};