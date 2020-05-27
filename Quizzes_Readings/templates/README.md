# Vector
In this learning activity, we will explore templates which will be used in developing a vector template class.  This will be very similar to the list class that you will be developing for Lab 2.

Lets first remember how template classes work by looking at the std vector class.  You can declare a vector of ints and can access it with either the square braces or the at function.
```c++
    vector<int> intvec;
    intvec.push_back(17);
    cout << "Position 0 "<<intvec[0]<<endl;
    cout << "Position 0 "<<intvec.at(0)<<endl;
```
Or you can declare a vector of strings and the internal code for the vector class is the same.
```c++
    vector<string> stringvec;
    stringvec.push_back("Hello");
    cout << "Position 0 "<<stringvec[0]<<endl;
    cout << "Position 0 "<<stringvec.at(0)<<endl;
```
To get started on the lab, you should be aware of the [sample code included with the book](http://bcs.wiley.com/he-bcs/Books?action=resource&bcsId=2949&itemId=0471467553&resourceId=7105&chapterId=21528).  It will give you a lot of help in how to implement your list class and we will use it to implement our vector class as well.  I suggest that you upload the material for chapter 4 to c9.io or your development environment now.

Take a look at the way they declare a vector in "vector.h" in the code from the book and notice how they implement the [] operator.  Notice that the code uses the type specified in the "template" statement to create a class for a particular type.
```c++
 template <typename Item_Type>
    class vector {
  private:
    /** The array to contain the data */
    Item_Type* the_data;
  public:
    const Item_Type& operator[](size_t index) const {
      return the_data[index];
    }
```
To get started with writing our vector class, we need to understand templates.  Templates allow us to create a class that can contain any other class.  So, if we are building a vector container, it should be able to handle ints, strings or any other type.  The syntax is a bit confusing, so lets start with a simple example
```c++
template <class T>
class MV {
    T element;
  public:
    void put(T arg) {element = arg;};
    T get () {return element;}
};
```
We declare a template and indicate that the type will be contained in a variable "T". The "T" will be replaced by the actual class name anywhere it is used in the rest of this class.
So, "T element" will be replaced with "int element" when we instantiate this class with an integer.  And "put(T arg)" will be replaced with "put(int arg)".

To use this class, we declare a variable in the same way we would declare a vector.
```c++
#include <iostream>
#include "MV.h"
using std::cout;
using std::endl;
int main()
{
    MV<int> container;
    cout << "Inserting"<<endl;
    container.put(5);
    cout << "Getting"<<container.get()<<endl;
    
}
```
We could also declare a MV or type string.
```c++
    MV<string> container;
    cout << "Inserting"<<endl;
    container.put("Hello");
    cout << "Getting "<<container.get()<<endl;
```
If you want to inherit from a template class (which you will want to do for lab 2), you can do this in the same way you inherited from non-template classes.  Assuming you have the following interface file:
```c++
#pragma once

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
```
You can create a subclass like this:
```c++
#include "VectorInterface.h"
template <class T>
class MyVector: public VectorInterface<T>
{

public:

	MyVector(void) {cout << "In constructor"<<endl;};
	~MyVector(void) {cout << "In destructor"<<endl;};

	void push_back(T value){cout << "In push_back"<<endl;};
	
	/* Insert value after given index */
	void insertAt(int index, T value){cout << "In insertAt"<<endl;};

	/* Remove the element at index */
	void remove(int index) {cout << "In remove"<<endl;};
	
	T at(int index){cout << "In at"<<endl;};

	int size(){cout << "In size"<<endl; return(0);};
};
```
And you can use this new MyVector class in the same way you would use the std vector.
```c++
    MyVector<int> myvecint;
    myvecint.push_back(5);
    myvecint.insertAt(0, 6);
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.remove(0);
    cout << "Zero " << myvecint.at(0)<<endl;
```
Now, you will want to [fill in](https://github.com/BYUCS235/Vector/blob/master/V1/README.md) the functions that are stubbed out.
