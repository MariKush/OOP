#pragma once

#include "Array.h"
#include "List.h"
#include "Vector.h"

#include "vList.h"

enum mode	{arr, list, vec};

template<typename T> class iList :public vList<T>
{
private:
	vList<T>*p;
	
public:

	iList(int mode) {	
		switch (mode){
			case arr:	p = new Array<T>; break;
			case list:	p = new List<T>; break;
			case vec:	p = new Vector<T>; break;
			default: p = new Array<T>; break;
		}
	}
	
	bool add_end(T d){	
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

};

