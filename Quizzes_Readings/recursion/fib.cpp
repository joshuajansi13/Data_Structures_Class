#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;


int fib(int current, int previous, int n) {
	if (n <= 1) {
  		return current;
	}
	else {
	        return fib(current + previous, current, n-1);
	}
}

int recursive_start(int n) {
	return fib(1, 1, n);
}


int main() {
	clock_t oldtime, newtime;
	double seconds;
	int n;
	int rval;	        
		        
	cout << "Enter an integer "<<endl;
	cin >> n;
	oldtime = clock();
	rval = recursive_start(n);
	newtime = clock();
	seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
	cout << "Fib "<<n<<" = "<<rval<<"  took "<<seconds<<endl;
}
