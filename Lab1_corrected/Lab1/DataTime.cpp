/**
	K-28
	DataTime.cpp
	Purpose: implementation functions for class DataTime

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/

#include "DateTime.h"


/**
	Checking the year fo intercalary

	@param year
	@return true, if year is intercalary, else false
*/
bool DateTime::intercalary(int y) {
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) return true;
	else return false;
}


/**
	Number of days in a year

	@param year
	@return number of days in a year
*/
int DateTime::day_in_year(int year) {
	return 365 + intercalary(year);
}

/**
	Number of days in a month

	@param year and month
	@return number of days in a month
*/
int DateTime::day_in_month(int year, int month) {
	if (month == 2) return 28 + intercalary(year);
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}

/**
	Checking the correctness of the date

	@param -
	@return true if date is correct, else false
*/
bool DateTime::date_is_correct() {
	if (month > 12 || month < 0 || hour > 23 || hour < 0 || minute > 59 || minute < 0 || second > 59 || second < 0) return false;
	if (day < 0 || day > day_in_month(year, month)) return false;
	return true;
}

/**
	Number of days from the beginning of the calendar to the date

	@param -
	@return number of days from the beginning of the calendar
*/
long int DateTime::count_days_from_beg() {
	long int d = 0;
	for (int i = 1; i < year; i++) d = d + day_in_year(i);
	for (int j = 1; j < month; j++) d = d + day_in_month(year, j);
	return d + day;
}

/**
	Number of days between two dates

	@param class DateTime
	@return number of days from the beginning of the calendar
*/
int DateTime::difference_days(DateTime D) {
	int d = abs(D.count_days_from_beg() - count_days_from_beg());
	return d;
}

/**
	Add difference of days to date

	@param number of days
	@return -
*/
void DateTime::add_difference_days(int d) {
	for (int i = 0; i < d; i++) {
		day++;
		if (day > day_in_month(year, month)) {
			day = 1;
			month++;
		}
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}


/**
	Shifting the day of the week counting from the beginning of the calendar

	@param -
	@return shift - shifting the day of the week counting from the beginning of the calendar
*/
int DateTime::shift_weekday() {
	if (!this->date_is_correct()) return -1;
	int shift = 1;
	for (int i = 1; i < year; i++)
		if (intercalary(i))shift += 2;//in intercalary years weekday shifts on 2 days
		else shift++;
	for (int i = 1; i < month; i++)
		shift += day_in_month(year, i);
	shift = shift + day - 1;
	return shift;
}

/**
	Ñout day of the week

	@param -
	@return -
*/

void DateTime::cout_weekday() {
	int shift = shift_weekday();
	if (shift < 0) {
		std::cout << "The date is not correct for now" << std::endl;
		return;
	}

	shift = shift % 7;
	switch (shift) {
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