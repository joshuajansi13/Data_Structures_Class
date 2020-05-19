#include <iostream>

using namespace std;

int main() {
	int length = 12;
	int my_array[length] = {23,14,65,3,19,2,71,12,8,61,5,25};
	for (int i = 0; i < length-2; i++) {
		int min = i;
		for (int j = i+1; j < length-1; j++) {
			if (my_array[j] < my_array[min]) {
				min = j;
			}
		}
		int temp = my_array[i];
		my_array[i] = my_array[min];
		my_array[min] = temp;
	}

	for (int i = 0; i < length; i++) {
		cout << my_array[i] << " ";
	}
	cout << endl;
}
