#pragma once
#include <string>

using namespace std;

template<typename T>
class VectorInterface
{

public:

	VectorInterface(void) {};
	virtual ~VectorInterface(void) {};

	virtual void push_back(T value) = 0;
	
	/* Insert value after given index */
	virtual void insertAt(int index, T value) = 0;

	/* Remove the element at index */
	virtual void remove(int index) = 0;
	
	virtual T at(int index) = 0;

	virtual int size() = 0;
};