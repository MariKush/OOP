#pragma once
#include "vList.h"
#include <thread>
using std::function;


//list of whatever type
template<typename T> 
class List //:public vList<T> 
{
	template<typename T> class Node  {
	public:
		T v;
		Node *next;
	};

	int kol;

	Node<T> *beg;
	Node<T> *end;


public:

	//designer
	List() { 
		kol = 0; 
		beg = nullptr;
		end = nullptr; 
	}



	//destructor
	~List() {
		if (end)
		{
			end->next = nullptr;
			while (beg->next)
			{
				end = beg;
				beg = beg->next;
				delete end;
			}
			delete end;
			delete beg;
		}
	}

	//size of the list
	int size() {
		return kol;
	}


	//add an item to the end of the list
	bool add_end(T d) {
		kol++;
		if (!beg)
		{
			beg = new Node<T>;
			end = beg;
			end->v = d;
			end->next = end;
			
			return true;
		}
		else
		{
			end->next = new Node<T>;
			end = end->next;
			end->v = d;
			end->next = beg;
			return true;
		}

	}

	//delete all elements of the list
	void dell_all() {
		end->next = nullptr;
		while (beg->next)
		{
			end = beg;
			beg = beg->next;
			delete end;
		}
		kol = 0;
		delete beg;
		beg = end = nullptr;
	}

	//delete k(th) element of the list
	void del_k(int k) {
		Node<T> *tmp = beg;
		
		if (k >= kol || k < 0) return;
		kol--;
		if (k == 0)
		{
			beg = beg->next;
			delete tmp;
			return;
		}
		for (int i = 1; i < k; i++)
		{
			tmp = tmp->next;
			Node<T> *tmp2 = tmp->next;
			
			tmp->next = tmp->next->next;
			delete tmp2;
		}
	}

	//find by index
	T find_by_index(int k){
	Node<T> *tmp = beg;

	for (int i = 0; i < k; i++)
	{
		tmp = tmp->next;
	}
	return tmp->v;
	}

	//find by value
	int find_by_value(T d) {
		int j = 0;
		Node<T> *tmp = beg;

		while (tmp)
		{
			if (tmp->v == d) return j;
			tmp = tmp->next;
			if (j > kol) return -1;
			j++;
		}
		return -1;
	}

	//find by if
	int find_by_if(function<bool(T)> f) {
		Node<T> *tmp = beg;

		for (int i = 0; i < kol; i++)
		{

			if (f(tmp->v)) return i;
			tmp = tmp->next;
		}
		return -1;
	}

	//print the entire array
	void print() {
		Node<T> *tmp = beg;
	
		for (int i = 0; i < kol; i++)
		{
			std::cout << tmp->v << "";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}

};