#pragma once
//#include "vList.h"
using std::function;


//list of whatever type
template<typename T> 
class List //:public vList<T> 
{
	template<typename T> class Node  {
	public:
		T datà;
		Node *next;
	};

	int kol;

	Node<T> *head;
	Node<T> *tail;


public:

	//designer
	List() { 
		kol = 0; 
		head = nullptr;
		tail = nullptr; 
	}

	//destructor
	~List() {
		tail->next = nullptr;
		while (head->next)
		{
			tail = head;
			head = head->next;
			delete tail;
		}
		delete tail;
		delete head;
	}

	//size of the list
	int size() {
		return kol;
	}


	//add an item to the end of the list
	bool add_end(T d) {
		kol++;
		if (!head)
		{
			head = new Node<T>;
			
			tail = head;
			tail->data = d;
			tail->next = tail;
			return true;
		}
		else
		{
			Node<T> *tmp = new Node<T>;
			
			tmp->next = head;
			tmp->data = d;
			head = tmp;
			tail->next = head;
			return true;
		}

	}

	//delete all elements of the list
	void dell_all() {
		tail->next = nullptr;
		while (head->next)
		{
			tail = head;
			head = head->next;
			delete tail;
		}
	}

	//delete k(th) element of the list
	void del_k(int k) {
		Node<T> *tmp = head;
		
		if (k >= kol || k < 0) return;
		kol--;
		if (k == 0)
		{
			head = head->next;
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
	Node<T> *tmp = head;

	for (int i = 0; i < k; i++)
	{
		tmp = tmp->next;
	}
	std::cout << tmp->datà << " ";
	std::cout << std::endl;
}

	//find by value
	int find_by_value(T d) {
		int j = 0;
		Node<T> *tmp = head;

		while (tmp)
		{
			if (tmp->datà == d) return j;
			tmp = tmp->next;
			if (j > kol) return -1;
			j++;
		}
		return -1;
	}

	//find by if
	int find_by_if(function<bool(T)> f) {
		Node<T> *tmp = head;

		for (int i = 0; i < kol; i++)
		{

			if (f(tmp->data)) return i;
			tmp = tmp->next;
		}
		return -1;
	}

	//print the entire array
	void print() {
		Node<T> *tmp = head;
	
		for (int i = 0; i < kol; i++)
		{
			std::cout << tmp->datà << "";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}

};