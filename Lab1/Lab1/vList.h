#pragma once


template<typename T>class vList
{
public:
	virtual bool add_end(T d) = 0;
	virtual int size() = 0;
	virtual void dell_all() = 0;
	virtual	void del_k(int k) = 0;
	virtual	T find_by_index(T d) = 0;
	virtual	int find_by_value(T d) = 0;
	virtual int find_by_if(bool(*f)(T)) = 0;

};
