#include <iostream>
using namespace std;
int main()
{
	int *badptr = new int[10];
	
	cout << "everything worked" << endl;
	delete [] badptr;
}
