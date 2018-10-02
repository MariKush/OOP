#include <iostream>
#include "Array.h"
#include "List.h"

using std::cout;
using std::endl;

int main()
{
	List<int> L;


	L.add_end(7);
	L.add_end(3);
	L.add_end(8);
	L.add_end(0);
	L.add_end(1);
	L.add_end(4);
	L.add_end(1);
	L.add_end(8);

	L.print();

	int a = L.find_by_index(4);

	cout << "a = " << a << endl;

	L.del_k(4);

	L.print();

	int ind = L.find_by_value(0);

	cout << "ind = " << ind << endl;

	int kol = L.size();

	cout << "kol = " << kol << endl;

	L.print();

	L.dell_all();

	L.print();

	system("pause");

	return 0;
}