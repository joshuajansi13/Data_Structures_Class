#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;


template<typename Item_Type>
int binary_search(const std::vector<Item_Type>& items, 
		    int first, int last, const Item_Type& target) {
	if (first > last) {
		return -1;     // Base case for unsuccessful search.
	}
	else {
		int middle = (first + last) / 2;  // Next probe index.
		if (target == items[middle]) {
			return middle;   // Base case for successful search.
		}
		else if (target < items[middle]) {
			return binary_search(items, first, middle - 1, target); 
		}
		else {
			return binary_search(items, middle + 1, last, target);
		}
	}
}


int search(int sval, vector <int> &svec, int spos) {
	// Base Cases
	if(svec[spos] == sval) {
		return spos;
	}
	if(spos >= svec.size()) {
		return -1;
	}
	// Recursive call with a smaller problem size
	return search(sval,svec,spos+1);
}


int main()
{
	vector <int> myvec;
	    
	int vecsize;
	int target_val;
	cout << "Enter vector size: ";
	cin >> vecsize;
	cout << endl;
	cout << "Enter target value between 0 and vector size: ";
	cin >> target_val;
	cout << endl;
        // Initialize the vector with random values
	for(int i = 0; i < vecsize; i++) {
		int nextval = rand() % vecsize;
		myvec.push_back(nextval);
	}
	sort(myvec.begin(), myvec.end());
	// Print out the vector values
	for(auto val : myvec) {
		cout << val<< " ";
	}
	cout << endl;

	// Find a specific number
	cout << binary_search(myvec, 0, myvec.size()-1, target_val)<< endl;


}
