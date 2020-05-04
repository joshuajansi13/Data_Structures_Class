#include <stack>
#include <iostream>
#include <string>
using namespace std;

void print(stack<int> st) {
	stack<int> temp = st; // make a copy of stack first so you can modify the copy instead of the original stack; not necessary since the stack is passed by value
	while(!temp.empty()) {
		cout << temp.top() << endl;
		temp.pop();
	}
}

int main() {
	stack<int> s;
	s.push(1); // adds items to the top of the stack
	s.push(2);
	s.push(3);
	print(s); 
	
	int temp = s.top(); // returns the very last item pushed onto the stack (without changing stack)
	s.pop(); // removes the very last item pushed onto stack; exposes next item
	
	cout << "top item: " << temp << endl;
	cout << "rest of stack: " << endl;
	print(s);

	s.empty(); 
}

