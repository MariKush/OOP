#pragma once
 
#include <iostream>
#include <cmath>

#include "Random.h"


bool intercalary(int y) {
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) return true;
	else return false;
}

int day_in_year(int year) {
	return 365 + intercalary(year);
}

int day_in_month(int year, int month) {
	if (month == 2) return 28 + intercalary(year);
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}

class DateTime
{
private:
	int year, month, day, hour, minute, second;
	
public:
	DateTime()
	{
		year = Random(1900, 2100);
		month = Random(1, 12);
		day = Random(1, day_in_month(year, month));
		hour = Random(0, 23);
		minute = Random(0, 59);
		second = Random(0, 59);
	};
	DateTime(int y, int mon, int d, int h, int min, int s)
	{
		year = y;
		month = mon;
		day = d;
		hour = h;
		minute = min;
		second = s;
		make_correct();
	};

	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
	int get_hour() { return hour; }
	int get_minute() { return minute; }
	int get_second() { return second; }

	void make_correct();


	bool is_correct() {
		if (month > 12 || month < 0 || hour > 23 || hour < 0 || minute > 59 || minute < 0 || second > 59 || second < 0) return false;
		if (day < 0 || day > day_in_month(year, month)) return false;
		return true;
	}

	void add_difference(int d, DateTime D1);
	void subtraction_difference(DateTime D1);

	void cout_weekday();
	int shift_weekday();

};

DateTime Random(DateTime R) {
	DateTime D;
	return D;
}



void DateTime::make_correct() {


		while (month < 1) {
			month += 12;
			year--;
		}
		while (month > 12) {
			month -= 12;
			year++;
		}

		while (day < 1) {
			month--;
			if (month < 1) {
				month += 12;
				year--;
			}
			day += day_in_month(year, month);
		}
		while (day > day_in_month(year, month)) {
			day -= day_in_month(year, month);
			month++;
			if (month > 12) {
				month -= 12;
				year++;
			}
		}

}

int DateTime::shift_weekday()
{
	if (!this->is_correct()) return -1;
	int shift = 1;
	for (int i = 1; i < year; i++)
		if (intercalary(i))shift += 2;//in intercalary years weekday shifts on 2 days
		else shift++;

	for (int i = 1; i < month; i++)
		shift += day_in_month(year, i);

	shift = shift + day - 1;

	return shift;
}


int difference_days(DateTime D1, DateTime D2)
{

	int d = abs(D2.shift_weekday() - D1.shift_weekday());

	return d;
}


void DateTime::add_difference(int d, DateTime D1)
{
	

	year += D1.get_year();
	month += D1.get_month();
	day += D1.get_day();
	hour += D1.get_hour();
	minute += D1.get_minute();
	second += D1.get_second();

	make_correct();
}

void DateTime::subtraction_difference(DateTime D1)
{
	year -= D1.get_year();
	month -= D1.get_month();
	day -= D1.get_day();
	hour -= D1.get_hour();
	minute -= D1.get_minute();
	second -= D1.get_second();

	make_correct();
}

void DateTime::cout_weekday()
{
	int shift = shift_weekday();
	if (shift < 0)
	{
		std::cout << "The date is not correct for now" << std::endl;
		return;
	}

	shift = shift % 7;
	switch (shift)
	{
	case 1: std::cout << "Monday"; break;
	case 2: std::cout << "Tuesday"; break;
	case 3: std::cout << "Wednesday"; break;
	case 4: std::cout << "Thursday"; break;
	case 5: std::cout << "Friday"; break;
	case 6: std::cout << "Saturday"; break;
	case 0: std::cout << "Sunday"; break;
	default:
		std::cout << "The date is not correct";
		break;
	}
	std::cout << std::endl;
}
