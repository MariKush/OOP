/**
	K-28
	main.cpp
	Purpose: main program file with tests

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/

#include <iostream>

#include "interfaceList.h"
#include "DateTime.h"

using std::cout;
using std::endl;


/**
	For search by condition (for int and double)

	@param variable type int or double d
	@return true, if d > 50, else false
*/
template <typename T> bool b(T d) {
	if (d > 50)return true;
	return false;
}

/**
	Testing of the first part of the laboratory work(list) and functions for it

	@param -
	@return -
*/
void testNumbers() {

	cout << "______________________________testNumbers()_____________________________" << endl;

	interfaceList<int> L(linked);
	L.fill_random(10);
	L.print();

	int kol = L.size();
	cout << "kol = " << kol << endl;

	cout << "L.find_by_index(4) = " << L.find_by_index(4) << endl;

	L.del_k(7);
	cout << "... del 7 el ..." << endl;

	L.print();

	kol = L.size();
	cout << "kol = " << kol << endl;

	int ind_by_value = L.find_by_value(9);
	cout << "ind_by_value(9) = " << ind_by_value << endl;

	int ind_by_if = L.find_by_if(b);
	cout << "ind_by_if = " << ind_by_if << endl;

	L.print();

	cout << endl;

	L.del_all();

}

void testString() {
	cout << "______________________________testString()_____________________________" << endl;

	interfaceList<string> L(linked);
	L.add_end("35146");
	L.add_end("3fg46");
	L.add_end("ad46");

	L.print();

	L.del_k(1);
	cout << "... del 1 el ..." << endl;

	L.print();

	cout << endl;

	L.del_all();


}

/**
	Fill in a list of random dates and print it

	@param -
	@return -
*/
void testDateTimeR() {
	cout << "___________________________testDateTimeR__________________________________" << endl;

	interfaceList<DateTime> L(vec);
	L.fill_random(10);

	L.print();

	L.del_k(1);
	cout << "... del 1 el ..." << endl;

	DateTime D(2018, 11, 10, 0, 0, 0);
	L.add_end(D);

	L.print();

	cout << endl;
}

/**
	Testing of the second part of the laboratory work(DateTime) and functions for it
	(action on specific dates)

	@param -
	@return -
*/
void testDateTimeMy() {
	cout << "___________________________testDateTimeMy__________________________________" << endl;

	DateTime D1(2018, 10, 19, 5, 6, 7);

	D1.cout_weekday();
	Cout(D1);

	DateTime D2(2018, 11, 6, 9, 0, 2);
	Cout(D2);

	//cout << "D1.count() = " << D1.count() << endl;
	//cout << "D2.count() = " << D2.count() << endl;

	int days = D1.difference_days(D2);

	D1.add_difference_days(days);

	cout << "days = " << days << endl;

	Cout(D1);

	interfaceList<string> L(cyclicl);
	L.add_end("Monday");
	L.add_end("Tuesday");
	L.add_end("Wednesday");
	L.add_end("Thursday");
	L.add_end("Friday");
	L.add_end("Saturday");
	L.add_end("Sunday");

	cout << "Day of the week: " << L.find_by_index(D1.count_days_from_beg()) << endl;

	cout << endl;

}

/**
	main function

	@param -
	@return -
*/
int main() {
	srand(time(0));

	testString();
	testNumbers();
	testDateTimeR();
	testDateTimeMy();

	system("pause");
	return 0;
}