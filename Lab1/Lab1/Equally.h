#pragma once

#include "DateTime.h"

bool Equally(int a, int b)
{
	if (a == b) return true;
	else return false;
}


bool Equally(double a, double b)
{
	if (a - b < 0.000005) return true;
	else return false;
}

bool Equally(DateTime a, DateTime b)
{
	if (a.get_year() != b.get_year()) return false;
	if (a.get_month() != b.get_month()) return false;
	if (a.get_day() != b.get_day()) return false;
	if (a.get_hour() != b.get_hour()) return false;
	if (a.get_minute() != b.get_minute()) return false;
	if (a.get_second() != b.get_second()) return false;
	return true;
}