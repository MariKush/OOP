#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: description class BaseList
	(base (identical for cyclic and non-cyclic) list whatever type,
	parent class for cyclic and linked list)

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/


#include "virtualList.h"
#include "Cout.h"
#include "Equally.h"

template<typename T> class Node {
public:
	T v;
	Node *next;
};

template<typename T>
class BaseList :public virtualList<T> {
protected:
	int kol;
	Node<T> *beg;
	Node<T> *end;

public:

	//designer
	BaseList() {
		kol = 0;
		beg = NULL;
		end = NULL;
	}

	//size of the list
	int size() {
		return kol;
	}

	//delete all elements 
	void del_all() {
		end->next = NULL;
		while (beg->next) {
			end = beg;
			beg = beg->next;
			delete end;
		}
		kol = 0;
		delete beg;
		beg = end = NULL;
	}


	//find by index
	T find_by_index(int k) {
		Node<T> *tmp = beg;
		for (int i = 0; i < k; i++) {
			tmp = tmp->next;
		}
		return tmp->v;
	}

	//find by value
	int find_by_value(T d) {
		int j = 0;
		Node<T> *tmp = beg;
		while (tmp) {
			if (Equally(tmp->v, d)) return j;
			tmp = tmp->next;
			if (j > kol) return -1;
			j++;
		}
		return -1;
	}

	//find by if
	int find_by_if(bool(*f)(T)) {
		Node<T> *tmp = beg;
		for (int i = 0; i < kol; i++) {
			if (f(tmp->v)) return i;
			tmp = tmp->next;
		}
		return -1;
	}

	//print the entire 
	void print() {
		Node<T> *tmp = beg;
		for (int i = 0; i < kol; i++) {
			Cout(tmp->v);
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}

};