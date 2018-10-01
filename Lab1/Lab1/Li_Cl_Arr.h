#pragma once
#include "modeL.h"
#include <thread>
using std::function;

//array of whatever type
template<typename T> class Li_Arr :public Li_Cl<T> {
public:
		//designer1
		Li_Arr() { arr = new T[N];}

		//designer2
		Li_Arr(int n) {
			N = n;
			arr = new T[N];
		}

		//destructor
		~Li_Arr() { delete [] arr; }

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
			int k = 0;
			while (k < kol)
			{
				if (d == data[k])return k;
			}
			std::cout << "not find" << std::endl;
			return -1;
		}

		//find by if
		int find_by_if(function<bool(T)> f){
			for (int i = 0; i < kol; i++)
			{
				if (f(data[i])) return i;
			}
			return -1;
		}

		//print the entire array
		void printArr(){
			for (int i = 0; i < kol; i++)
				std::cout << arr[i] << "";
			std::cout << std::endl;
		}


private:
		T *arr = nullptr;
		int kol = 0; //the current number of elements in the array
		int N = 10000; //maximum number of elements in the array
};