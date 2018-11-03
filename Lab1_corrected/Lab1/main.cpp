#include <iostream>

#include "interfaceList.h"
#include "DateTime.h"

using std::cout;
using std::endl;

//for search by condition
template <typename T> bool b(T d) {
	if (d > 50)return true;
	return false;
}

//testing of the first part of the laboratory work(list) and functions for it
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

//fill in a list of random dates
void testDateTimeR() {
	cout << "___________________________testDateTimeR__________________________________" << endl;

	interfaceList<DateTime> L(array);
	L.fill_random(10);
	L.print();

	cout << endl;
}

//action on specific dates
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

int main() {
	srand(time(0));

	testNumbers();
	testDateTimeR();
	testDateTimeMy();

	system("pause");
	return 0;
}