#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: description class CyclicList (cyclic list of whatever type)

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/

#include "BaseList.h"
#include "Cout.h"
#include "Equally.h"


template<typename T>
class CyclicList :public BaseList<T> {
	using BaseList<T>::kol;
	using BaseList<T>::beg;
	using BaseList<T>::end;

public:
	//destructor
	~CyclicList() {
		while (kol != 0) {
			Node *temp = beg->next;
			delete beg;
			beg = temp;
			kol--;
		}
	}

	//add an item to the end of the array
	bool add_end(T d) {
		kol++;
		Node<T> *temp = new Node<T>;
		temp->next = beg;
		temp->v = d;
		if (beg != NULL) {
			end->next = temp;
			end = temp;
		}
		else beg = end = temp;
		return true;
	}

	//delete k(th) element of the list
	void del_k(int k) {
		Node<T> *tmp = beg;
		if (k >= kol || k < 0) return;
		kol--;
		if (k == 0) {
			beg = beg->next;
			delete tmp;
			return;
		}
		else {
			for (int i = 1; i < k; i++) {
				tmp = tmp->next;
			}
			Node<T> *tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			delete tmp2;
		}
	}
};
