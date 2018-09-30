#pragma once


//array of whatever type
template<typename T> class Li_Arr :{
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
		int size() { return i;}

		//return k(th) item
		T return_k_el(int k) { return arr[k]; }

		//add an item to the end of the array
		bool add_L(T d) {
			if (i < N) return false;
			arr[i] = d;
			i++;
			return true;
		}

		//delete all elements of the array
		void del_all_el() {
			while (i > 0) {
				i--;
				arr[i] = nullptr;
			}
		}

		//delete k(th) element of the array
		void del_k_L(int k) {
			if (k >= i) return;
			for (int j = k; j < i; j++) {
				arr[j] = arr[j + 1];
			}
			i--;
		}

		//find the index of the element with the value of d
		int find_el(T d) {
			int k = 0;
			while (k < i) {
				if (d == arr[k])return k;
			}
			std::cout << "not found" << std::endl;
			return -1;
		}


private:
		T *arr = nullptr;
		int i = 0; //the current number of elements in the array
		int N = 10000; //maximum number of elements in the array
};