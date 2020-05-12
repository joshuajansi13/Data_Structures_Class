#include <iostream>
using namespace std;

int recursesize(string str)
{
	if (str == "") {
		cout << "Base Case"<<endl;
		return 0;
	} 
	else {
		int subsize = recursesize(str.substr(1));
		cout << "recurse "<< str << " subsize "<< subsize << endl;
		return 1 + subsize;
	}
}

int main()
{
	cout << "recursion "<<recursesize("byurules")<<endl;
}
