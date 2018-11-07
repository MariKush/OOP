#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: cout for different types

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/

#include <iostream>
#include <string>

#include "DateTime.h"

using std::cout;
using std::endl;
using std::string;

void Cout(int i) {
	cout << i << " ";
}

void Cout(double i) {
	cout << i << " ";
}

void Cout(string i) {
	cout << i << " ";
}

void Cout(DateTime D) {
	cout << D.get_year() << "\t";
	cout << D.get_month() << "\t";
	cout << D.get_day() << "\t";
	cout << D.get_hour() << "\t";
	cout << D.get_minute() << "\t";
	cout << D.get_second() << endl;
}
