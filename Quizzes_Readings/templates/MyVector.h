#include "VectorInterface.h"
#include <stdexcept>
#define STARTSIZE 4
template <class T>
class MyVector : public VectorInterface<T>
{
private:
	T *array;
	int current_capacity;
	int num_items;

public:

	MyVector(void) {
		array = new T[STARTSIZE];
		current_capacity = STARTSIZE;
		num_items = 0;
		cout << "In constructor" << endl;
	};
	~MyVector(void) {
		cout << "In destructor" << endl;
		delete[] array;
	};

	void push_back(T value) {
		//cout << "In push_back"<<endl;
		if (num_items >= current_capacity) { // We are out of room
			cout << "push_back Copying to bigger array" << endl;
			T *newarray = new T[current_capacity + STARTSIZE]; // allocate
			for (int i = 0; i < current_capacity; i++) { // Copy to new array
				newarray[i] = array[i];
			}
			cout << "push_back delete" << endl;

			delete[] array;
			array = newarray; // point to new space
			current_capacity += STARTSIZE;
		}
		array[num_items] = value; // put the new value in
		num_items++;
	};

	/* Insert value at given index */
	void insertAt(int index, T value) {
		//cout << "In insertAt"<<endl;
		if (index >= num_items) {
			throw std::out_of_range("insertAt Error");
		}
		if (num_items >= current_capacity) { // We are out of room
			cout << "insertAt Copying to bigger array" << endl;
			T *newarray = new T[current_capacity + STARTSIZE]; // allocate
			for (int i = 0; i < current_capacity; i++) { // Copy to new array
				newarray[i] = array[i];
			}
			cout << "insertAt delete" << endl;
			delete[] array; // delete old array
			array = newarray; // point to new space
			current_capacity += STARTSIZE;
		}
		//push everything back one space
		for (int i = num_items; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = value; // put the new value in
		num_items++;
	};

	/* Remove the element at index */
	void remove(int index) {
		//cout << "In remove"<<endl;
		if (index >= num_items) {
			throw std::out_of_range("remove Error");
		}
		// Shift everything down 
		num_items--;
		for (int i = index; i < num_items; i++) {
			array[i] = array[i + 1];
		}
	};

	T at(int index) {
		//cout << "In at"<<endl;
		if (index >= num_items) {
			throw std::out_of_range("At Error");
		}
		else {
			return(array[index]);
		}
	};

	int size() {
		//cout << "In size"<<endl; 
		return(num_items);
	};
};