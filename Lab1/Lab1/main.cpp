#include <iostream>

#include "Array.h"
#include "List.h"
#include "Vector.h"


#include "vList.h"
#include "iList.h"


#include "DateTime.h"

using std::cout;
using std::endl;


template <typename T> bool b(T d)
{
	if (d > 50)return true;
	return false;
}



void test1()
{
	iList<int> L(arr);

	L.fill_random(10);

	//L.add_end(5);
	//L.add_end(6);
	//L.add_end(9);
	//L.add_end(0);
	//L.add_end(23);
	//L.add_end(9);
	//L.add_end(1);
	//L.add_end(5);
	//L.add_end(8);
	//L.add_end(7);

	L.print();

	int kol = L.size();
	cout << "kol = " << kol << endl;


	cout << "L.find_by_index(14) = " << L.find_by_index(14) << endl;

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

void testDateTimeR()
{
	iList<DateTime> L(cycl);

	L.fill_random(10);

	L.print();


}

void testDateTime2()
{
	DateTime D1;
	//DateTime D1(2016, 12, 17, 5, 6, 7);
	D1.cout_weekday();
	Cout(D1);

	DateTime D2;
	//DateTime D2(2018, 11, 6, 9, 0, 2);

	Cout(D2);

	cout << "D1.count() = " << D1.count() << endl;
	cout << "D2.count() = " << D2.count() << endl;


	int days = difference_days(D1, D2);

	D1.add_difference_days(days);

	cout << "days = " << days << endl;

	Cout(D1);

}

int main()
{
	srand(time(0));

	test1();

	//testDateTimeR();

	testDateTime2();

	system("pause");

	return 0;
}