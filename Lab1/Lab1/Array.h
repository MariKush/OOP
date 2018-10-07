#pragma once
//#include "vList.h"
#include <thread>
using std::function;

//array of whatever type
template<typename T> class Array //:public vList<T> 
{
private:
	   	T *arr = nullptr;
		int kol; //the current number of elements in the array
		int N; //maximum number of elements in the array

public:
		//designer1
		Array() {
			N = 1000;
			kol = 0; 
			arr = new T[N]; 
		}

		//designer2
		Array(int n) {
			kol = 0;
			N = n;
			arr = new T[N];
		}

		//destructor
		~Array() { delete [] arr; }

		//size of the array
		int size() { return kol;}

		//find by index
		T find_by_index(int k) {
			if(k < kol && k>=0)return arr[k];
			else return (T)nullptr;
		}

		//add an item to the end of the array
		bool add_end(T d) {
			if (kol == N-1) return false;
			arr[kol] = d;
			kol++;
			return true;
		}

		//delete all elements of the array
		void dell_all() {
			while (kol > 0) {
				kol--;
				arr[kol] = (T)nullptr;
			}
		}

		//delete k(th) element of the array
		void del_k(int k) {
			if (k >= kol) return;
			for (int j = k; j < kol; j++) {
				arr[j] = arr[j + 1];
			}
			kol--;
		}


		//find by value
		int find_by_value(T d){
			for(int i = 0; i< kol;i ++)
				if (arr[i] == d)return i;
			std::cout << "not find" << std::endl;
			return -1;
		}

		//find by if
		int find_by_if(function<bool(T)> f){
			for (int i = 0; i < kol; i++)
			{
				if (f(arr[i])) return i;
			}
			return -1;
		}

		//print the entire array
		void print(){
			for (int i = 0; i < kol; i++)
				std::cout << arr[i] << "";
			std::cout << std::endl;
		}

};