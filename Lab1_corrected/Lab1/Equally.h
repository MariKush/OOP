#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: check for the equality of two values for different types

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/


#include <cmath>
#include "DateTime.h"


/**
	Checking equality for integers

	@param two int variables 
	@return true, if they equality, else false
*/
bool Equally(int a, int b) {
	if (a == b) return true;
	else return false;
}

/**
	Checking equality for double

	@param two double variables
	@return true, if they equality, else false
*/
bool Equally(double a, double b) {
	if (abs(a - b) < 0.00005) return true;
	else return false;
}

/**
	Checking equality for string

	@param two string variables
	@return true, if they equality, else false
*/
bool Equally(string a, string b) {
	if (a == b) return true;
	return false;
}

/**
	Checking equality for DateTime

	@param two DateTime variables
	@return true, if they equality, else false
*/
bool Equally(DateTime a, DateTime b) {
	if (a.get_year() != b.get_year()) return false;
	if (a.get_month() != b.get_month()) return false;
	if (a.get_day() != b.get_day()) return false;
	if (a.get_hour() != b.get_hour()) return false;
	if (a.get_minute() != b.get_minute()) return false;
	if (a.get_second() != b.get_second()) return false;
	return true;
}