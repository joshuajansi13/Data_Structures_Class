#include "QS.h"

using namespace std;


void QS::sortAll() {
	if (table != NULL) {
		quicksort(0, num_items-1);
	}
}

void QS::quicksort(int first, int last) {
	if ((last - first) < 1) {
		return;
	}
	int pivot = medianOfThree(first, last);
	pivot = partition(first, last, pivot);
	quicksort(first, pivot - 1);
	quicksort(pivot + 1, last);
}

int QS::medianOfThree(int left, int right) {
	if (table == NULL || left < 0 || right >= num_items || left >= right) { //comprehensive tests and edge cases
		return -1;
	}
	int first, last, middle, temp;
	first = left;
	last = right;
	middle = (left + right) / 2;
	if (table[first] > table[middle]) {
		temp = table[first];
		table[first] = table[middle];
		table[middle] = temp;
	}
	if (table[last] < table[middle]) {
		temp = table[middle];
		table[middle] = table[last];
		table[last] = temp;
	}
	if (table[middle] < table[first]) {
		temp = table[first];
		table[first] = table[middle];
		table[middle] = temp;
	}
	return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
	if (table == NULL || left < 0 || right >= num_items || left >= right || 
		pivotIndex < left || pivotIndex > right) {
		return -1;
	}

	int first, last, tmp;
	first = left;
	last = right;
	tmp = table[pivotIndex];
	table[pivotIndex] = table[first];
	table[first] = tmp;

	int up = left + 1;
	int down = right;
	do {
		while ((table[up] <= table[first]) && (up < last)) {up++;}
		while ((table[down] > table[first]) && (down > first)) {down--;}
		if (up < down) {
			tmp = table[up];
			table[up] = table[down];
			table[down] = tmp;
		}
	} while (up < down);
	tmp = table[first];
	table[first] = table[down];
	table[down] = tmp;
	return down;
}

string QS::getArray() const {
	stringstream ss;
	if (table != 0) {
		for (int i = 0; i < num_items; i++) {
			if (i == num_items - 1) { // if last value in array
				ss << to_string(table[i]);
			}
			else {
				ss << to_string(table[i]) << ",";
			}
		}
	}
	else {
		return "";
	}
	return ss.str();
}

int QS::getSize() const {
	return num_items; 
}

bool QS::addToArray(int value) {
	if (num_items == max_items) {
		return false;
	}
	table[num_items] = value;
	num_items++;
	return true;
}

bool QS::createArray(int capacity) {
	if (table != 0) {
		delete [] table;
	}
	num_items = 0;
	table = new int[capacity];
	max_items = capacity;
}

void QS::clear() {
	delete [] table;
	table = NULL;
	num_items = 0;
}