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
	if (d % 4 == 0)return true;
	return false;
}



void test()
{
	iList<int> L(arr);

	L.add_end(7);
	L.add_end(3);
	L.add_end(9);
	L.add_end(0);
	L.add_end(1);
	L.add_end(4);
	L.add_end(1);
	L.add_end(8);

	L.print();

	int a = L.find_by_index(4);

	cout << "a = " << a << endl;

	int kol = L.size();

	cout << "kol = " << kol << endl;

	L.del_k(7);

	L.print();

	int ind_by_value = L.find_by_value(9);

	cout << "ind_by_value = " << ind_by_value << endl;

	kol = L.size();

	cout << "kol = " << kol << endl;

	int ind_by_if = L.find_by_if(b);

	cout << "ind_by_if = " << ind_by_if << endl;


	L.print();

	L.del_all();

	L.print();

	
}

void test_make_correct()
{
	DateTime A(0, 1, 75, 0, 0, 0);
	A.cout_DateTime();

	DateTime B(0, 4, 83, 0, 0, 0);
	B.cout_DateTime();

	DateTime C(5, 34, 5, 0, 0, 0);
	C.cout_DateTime();

	DateTime D(23, 56, 10, 0, 0, 0);
	D.cout_DateTime();

	DateTime E(0, 23, 657, 0, 0, 0);
	E.cout_DateTime();
}

void testDateTime()
{
	DateTime D1(2018, 10, 10, 0, 0, 0);
	D1.cout_weekday();

	DateTime D2(2018, 9, 9, 0, 0, 0);

	DateTime Dif = difference(D2, D1);

	Dif.cout_DateTime();

	D2.add_difference(Dif);

	D2.cout_DateTime();

	//D2.subtraction_difference(D1);

	//D2.cout_DateTime();


}

int main()
{
	test_make_correct();

	system("pause");

	return 0;
}