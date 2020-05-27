#include "VectorInterface.h"
#include <stdexcept>
#define STARTSIZE 4
template <class T>
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
	
	/* Insert value at given index */
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

	/* Remove the element at index */
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
	void printit()
	{
		for(Node *ptr =mylist; ptr != NULL; ptr = ptr->next){
			cout <<"ptr "<<ptr<<" val "<<ptr->data<<" next "<<ptr->next<<endl;
		}
	};
	int size(){
		//cout << "In size"<<endl; 
		return(num_items);
	};
};