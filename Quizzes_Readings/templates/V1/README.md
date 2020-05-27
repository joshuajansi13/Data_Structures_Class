# Data Allocation for vector
## Once you have figured out how to create a template class and inherit from an interface template class, 
the next step in implementing the vector is to figure out how to allocate data.  We will talk about other ways of 
allocating space for your vector, but the most obvious method is to allocate an array.  But the array can't be static, 
because you do not know at compile time how big the array needs to be.  So, lets start with a small array, and make 
it bigger as we need more space.  In MyVector.h:
```c++
#include "VectorInterface.h"
using namespace std;
#define STARTSIZE 4
template <class T>
class MyVector: public VectorInterface<T>
{

public:

    MyVector(void) {
		  array = new T[STARTSIZE];
		  current_capacity = STARTSIZE;
		  num_items = 0;
		  //cout << "In constructor"<<endl;
	  };
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
Now we have the constructor working, we ought to look at implementing push_back.  
The trick will come in dealing with the case when we run out of space.
When this happens, we need to allocate more space and copy everything to the new array.
Then make sure and delete the old array so we dont have memory leaks.
```c++
	void push_back(T value){
		//cout << "In push_back"<<endl;
		if(num_items >= current_capacity) { // We are out of room
			cout << "push_back Copying to bigger array"<<endl;
			T *newarray = new T[current_capacity + STARTSIZE]; // allocate
			for(int i = 0; i < current_capacity; i++) { // Copy to new array
				newarray[i] = array[i];
			}
			delete [] array;
			array = newarray; // point to new space
			current_capacity += STARTSIZE;
		}
		array[num_items] = value; // put the new value in
		num_items++;
	};
```
Now we ought to do the easy member function size so we know if push_back worked
```c++
	int size(){
		//cout << "In size"<<endl; 
		return(num_items);
	};
```
Put some test code into vector.cpp to see if we are working.
```c++
    MyVector<int> myvecint;
    myvecint.push_back(5);
    cout << "at 0 "<<myvecint.at(0)<<endl;
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.push_back(10);
    cout << "at 1 "<<myvecint.at(1)<<endl;
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.push_back(15);
    cout << "at 2 "<<myvecint.at(2)<<endl;
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.push_back(20);
    cout << "at 3 "<<myvecint.at(3)<<endl;
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.push_back(25);
    cout << "at 4 "<<myvecint.at(4)<<endl;
    cout << "Size "<<myvecint.size()<<endl;
    for(int i = 0; i < 5; i++) {
        cout <<"["<<i<<"]="<<myvecint.at(i);
    }
```
Now run the test code and you should see that things are being inserted correctly.

insertAt will look a lot like push_back, except will will copy everything from the insert position on to the next location.  
Before we do this, we will need to make sure we have space for one more item.
```c++
  /* Insert value at given index */
	void insertAt(int index, T value){
		//cout << "In insertAt"<<endl;
		if(index >= num_items) {
			throw std::out_of_range("insertAt Error");
		}
		if(num_items >= current_capacity) { // We are out of room
			cout << "insertAt Copying to bigger array"<<endl;
			T *newarray = new T[current_capacity + STARTSIZE]; // allocate
			for(int i = 0; i < current_capacity; i++) { // Copy to new array
				newarray[i] = array[i];
			}
			delete [] array; // delete old array
			array = newarray; // point to new space
			current_capacity += STARTSIZE;
		}
		//push everything back one space
		for(int i = num_items; i > index; i--) { // Start at the end and move down
			array[i] = array[i-1];
		}
		array[index] = value; // put the new value in
		num_items++;
	};
```
Now insert some test code for insertAt
```c++
    myvecint.insertAt(0, 6);
    cout <<"after insertAt"<<endl;
    for(int i = 0; i < myvecint.size(); i++) {
        cout <<"["<<i<<"]="<<myvecint.at(i);
    }
    cout << "Size "<<myvecint.size()<<endl;
```
Remove will copy things the other way.  We will start at the remove index and copy everything from there back down.
```c++
	/* Remove the element at index */
	void remove(int index) {
		//cout << "In remove"<<endl;
		if(index >= num_items) {
			throw std::out_of_range("remove Error");
		}
		// Shift everything down 
		num_items--;
		for(int i = index; i < num_items; i++) {
			array[i] = array[i+1];
		}
	};
```
Now insert code to test remove.
```c++
    myvecint.remove(0);
    cout <<"after remove"<<endl;
    for(int i = 0; i < myvecint.size(); i++) {
        cout <<"["<<i<<"]="<<myvecint.at(i);
    }
    cout << "Size "<<myvecint.size()<<endl;
```
Finally, lets fill in the destructor.  We will need to delete everything we have created with new.
```c++
	~MyVector(void) {
		//cout << "In destructor"<<endl;
		delete [] array;
	};
```
Now you should run "valgrind ./vector" to look for memory leaks.  We will look at this next time.
