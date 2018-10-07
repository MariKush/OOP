#include <iostream>
#include "Array.h"
#include "List.h"

using std::cout;
using std::endl;


template <typename T> bool b(T d)
{
	if (d % 4 == 0)return true;
	return false;
}

int main()
{
	List<int> L;


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

	L.dell_all();

	L.print();

	system("pause");

	return 0;
}