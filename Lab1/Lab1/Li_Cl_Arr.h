#pragma once


//array of whatever type
template<typename T> class Li_Arr {
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

		//return k(th) item
		T return_k_el(int k) { 
			if(k < kol && k>=0)return arr[k];
			else return (T)nullptr;
		}

		//add an item to the end of the array
		bool add_L(T d) {
			if (kol == N-1) return false;
			arr[kol] = d;
			kol++;
			return true;
		}

		//delete all elements of the array
		void del_all_el() {
			while (kol > 0) {
				kol--;
				arr[kol] = (T)nullptr;
			}
		}

		//delete k(th) element of the array
		void del_k_L(int k) {
			if (k >= kol) return;
			for (int j = k; j < kol; j++) {
				arr[j] = arr[j + 1];
			}
			kol--;
		}

		//find the index of the element with the value of d
		int find_first_el(T d) {
			for (int i = 0; i < kol; i++) {
				if (d == arr[i])return i;
			}
			std::cout << "not found" << std::endl;
			return -1;
		}

		//print the entire array
		void printArr()
		{
			for (int i = 0; i < kol; i++)
				std::cout << arr[i] << "";
			std::cout << std::endl;
		}


private:
		T *arr = nullptr;
		int kol = 0; //the current number of elements in the array
		int N = 10000; //maximum number of elements in the array
};