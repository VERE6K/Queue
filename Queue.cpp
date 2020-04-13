#include <iostream>
using namespace std;


class q 
{
private:
	int size;
	int capasity;
	int* arr;
public:
	queue() {
		size = 0;
		capasity = ceil(size / 4);
		// ceil - okruglenie v bolsh storonu
		arr = new int[0];
		for (int i = 0; i < size; ++i)
			arr[i] = 0;
	}
	~queue() {
		delete[] arr;
	}
	void put(int x) 
  {
		size++;
		int* new_arr = new int[size];
		for (int i = 0; i < size - 1; ++i) {
			new_arr[i] = arr[i];
		}
		new_arr[size - 1] = x;
		delete[] arr;
		arr = new int[size];
		for (int i = 0; i < size; ++i)
			arr[i] = new_arr[i];
		if (size < capasity)
			capasity *= 2;
		delete[] new_arr;
	}
	int get() 
  {
		size--;
		int first = arr[0];
		int* new_arr = new int[size];
		for (int i = 0; i < size; ++i) {
			new_arr[i] = arr[i + 1];
		}
		delete[] arr;
		arr = new int[size];
		for (int i = 0; i < size; ++i)
			arr[i] = new_arr[i];
		if (size < capasity)
			capasity *= 2;
		delete[] new_arr;
		return first;
	}
	int length() 
  {
		return size;
	}
};
