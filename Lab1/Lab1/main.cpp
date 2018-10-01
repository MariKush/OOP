#include <iostream>
#include "Li_Cl_Arr.h"

using std::cout;
using std::endl;

int main()
{
	Li_Arr <int> L;

	L.printArr();

	L.add_L(7);
	L.add_L(3);
	L.add_L(8);
	L.add_L(0);
	L.add_L(1);
	L.add_L(4);
	L.add_L(1);
	L.add_L(8);

	L.printArr();

	int a = L.return_k_el(4);

	cout << "a = " << a << endl;

	L.del_k_L(4);

	L.printArr();

	int ind = L.find_first_el(0);

	cout << "ind = " << ind << endl;

	int kol = L.size();

	cout << "kol = " << kol << endl;

	L.printArr();

	L.del_all_el();

	L.printArr();

	system("pause");

	return 0;
}