#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: description class LinkedList (linked list of whatever type)

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/

#include "BaseList.h"
#include "Cout.h"
#include "Equally.h"


template<typename T>
class LinkedList :public BaseList<T> {
	using BaseList<T>::kol;
	using BaseList<T>::beg;
	using BaseList<T>::end;

public:
	//destructor
	~LinkedList() {
		if (end) {
			end->next = NULL;
			while (beg->next) {
				end = beg;
				beg = beg->next;
				delete end;
			}
			delete end;
			delete beg;
		}
	}

	//add an item d to the end of the list
	bool add_end(T d) {
		kol++;
		if (!beg) {
			beg = new Node<T>;
			end = beg;
			end->v = d;
			end->next = end;
			return true;
		}
		else {
			end->next = new Node<T>;
			end = end->next;
			end->v = d;
			end->next = beg;
			return true;
		}
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
			if (k == kol) tmp->next = NULL;
			else tmp->next = tmp->next->next;
			delete tmp2;
		}
	}
};