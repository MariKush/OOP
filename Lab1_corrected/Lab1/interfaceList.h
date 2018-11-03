#pragma once

#include "ArrayList.h"
#include "LinkedList.h"
#include "VectorList.h"
#include "CyclicList.h"

#include "virtualList.h"

/**
list modes
*/
enum mode { array, linked, vec, cyclicl };

/**
interface List
allows you to choose the modes of work with the list
*/
template<typename T> class interfaceList :public virtualList<T> {
private:
	virtualList<T> *p;
	T zn;

public:

	interfaceList(int mode) {
		switch (mode) {
		case array:	p = new ArrayList<T>; break;
		case linked: p = new LinkedList<T>; break;
		case vec: p = new VectorList<T>; break;
		case cyclicl:  p = new CyclicList<T>; break;
		}
	}

	bool add_end(T d) {
		return p->add_end(d);
	}

	int size() {
		return p->size();
	}

	void del_all() {
		return p->del_all();
	}

	void del_k(int k) {
		return p->del_k(k);
	}

	T find_by_index(int k) {
		return p->find_by_index(k);
	}

	int find_by_value(T d) {
		return p->find_by_value(d);
	}

	int find_by_if(bool(*f)(T)) {
		return p->find_by_if(f);
	}

	void print() {
		return p->print();
	}

	void fill_random(int n) {
		for (int i = 0; i < n; i++) {
			add_end(Random(zn));
		}
	}

};



