#pragma once

/**
	K-28
	DataTime.cpp
	Purpose: description class virtualList of virtual functions for redefinition

	@author Mariia Kushnirenko
	@version 1.1 7/11/18
*/
template<typename T> class virtualList {
public:
	virtual bool add_end(T d) = 0;
	virtual int size() = 0;
	virtual void del_all() = 0;
	virtual	void del_k(int k) = 0;
	virtual	T find_by_index(int k) = 0;
	virtual	int find_by_value(T d) = 0;
	virtual int find_by_if(bool(*f)(T)) = 0;
	virtual void print() = 0;
};
