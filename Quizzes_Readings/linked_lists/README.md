# List
## Implementing the Vector interface using a linked list.

To get started, you should grab the code from the [vector example](https://github.com/BYUCS235/Vector/tree/master/V1) and make sure it is running in your development environment.

Now we are going to remove the array data structure and replace it with a linked list.  To get started, we will need to insert a "Node" structure for our linked list.
```c++
class MyVector: public VectorInterface<T>
{
private:
	struct Node {
	 T data; // The data we are storing
	 Node* next; // A pointer to the next Node 
	 Node(const T& the_data, Node* next_val = NULL) :
	   data(the_data) {next = next_val;}
	};
	
	Node *mylist;
	int num_items;
```
Notice that the struct was inserted into the "private" part of our class, so it is not visible outside of the class.  Also notice that the constructor for Node is passed a value for the Node and a next pointer.  The constructor initializes the values using an initialization list and an assignment inside the body of the constructor.  

Now fill in the constructor and destructor for the MyVector class.  The constructor will assign our pointer "mylist" to NULL to indicate an empty list.  The destructor will start at the beginning of the list and delete all of the Nodes.
```c++
public:
	MyVector() {
		mylist = NULL;
		num_items = 0;
		//cout << "In constructor"<<endl;
	};
	~MyVector() {
		//cout << "In destructor"<<endl;
		while(mylist != NULL) {
			Node *current = mylist;
			mylist = mylist->next;
			delete current;
		};
	};
```
Now, lets look at the push_back function.  This is actually a little tricky since we have to deal with two situations, an empty and non-empty list.
```c++
void push_back(T value){
		cout << "In push_back"<<endl;
		Node *ptr = mylist;
		if(mylist == NULL){
			mylist = new Node(value, NULL);
		} else {
			while(ptr != NULL){
				cout << ptr<<" data "<<ptr->data<<" next "<<ptr->next<<endl;
				if(ptr->next == NULL) {
					ptr->next = new Node(value, NULL);
					break;
				} else {
					ptr = ptr->next;
				}
			}
		}
		num_items++;
		printit();
	};
```
We are going to put in a lot of debug statements to make sure that our list is filled in correctly.  Notice the call to a printit() function that will print out the whole list.  If there is nothing in the list, then we allocate a new Node and point to it.  If there is already something there, then we need to find the end and add the new node there.
```c++
	void printit()
	{
		for(Node *ptr =mylist; ptr != NULL; ptr = ptr->next){
			cout <<"ptr "<<ptr<<" val "<<ptr->data<<" next "<<ptr->next<<endl;
		}
	};
```
Lets do the at() function next so we can test our code.  We do bounds checking first so we dont have to check on every iteration of our loop.  We ought to check for negative values as well.
```c++
	T at(int index){
		cout << "In at"<<endl;
		printit();
		if(index >= num_items) {
			throw std::out_of_range("At Error");
		} else {
			Node *ptr = mylist;
			for(int i = 0; i <= index; i++) {
				cout << "["<<i<<"]="<<ptr->data<<endl;
		  		if(i == (index)) { 
		  			return(ptr->data);
		  		}else {
		  			ptr = ptr->next;
		  		}
			}
		}
	};
```
The next function is insertAt().  We have the same problem with needing to deal differently if we are at the start of the list or somewhere in the middle.  If we are inserting at position zero, then we need to assign the list pointer to the new node, otherwise, we find the position specified and insert after an existing node.
```c++
void insertAt(int index, T value){
		cout << "In insertAt"<<endl;
		if(index >= num_items) {
			throw std::out_of_range("insertAt Error");
		}
		Node *newnode = new Node(value,NULL);
		if(index == 0) {
			newnode->next = mylist;
			mylist = newnode;
		} else {
			Node *ptr = mylist;
			for(int i = 0; i <= index; i++) {
		  		if(i == (index-1)) { // Insert after this
		  			newnode->next = ptr->next;
		  			ptr->next = newnode;
		  			num_items++;
		  		} else {
		  			ptr = ptr->next;
		  		}
			}
		}
	};
```
remove() must also deal differently with position zero.  Notice that we are deallocating memory whenever we unlink a data element.
```c++
void remove(int index) {
		cout << "In remove"<<endl;
		if(index >= num_items) {
			throw std::out_of_range("remove Error");
		}
		if(index == 0) {
			Node *current = mylist;
			mylist = mylist->next;
			delete current;
		} else {
			Node *ptr = mylist;
			for(int i = 0; i < index; i++) {
		  		if(i == (index-1)) { // Delete after this
		  			Node *current = ptr->next;
		  			ptr->next = ptr->next->next;
		  			delete current;
		  			num_items--;
		  		}else {
		  			ptr = ptr->next;
		  		}
			}
		}
	};
```
You can see that some functions are easier with linked lists than with arrays.  Some are harder.  You should become familiar with both data structures so you can make wise choices when developing your code.
