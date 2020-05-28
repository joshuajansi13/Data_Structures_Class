#pragma once
#include "LinkedListInterface.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;

template<class T>
class LinkedList: public LinkedListInterface<T>
{
private:
	struct Node {
		T value; // The data we are storing
		Node* next; // A pointer to the next Node 
		Node(T initValue) { // Constructor
			value = initValue; // set initial value
			next = NULL; // default next pointer to NULL
		}
	};

	Node* head;
	int num_items;

public:

	LinkedList(void) {
		//cout << "In constructor" << endl;
		head = NULL;
		num_items = 0;
	};

	~LinkedList(void) {
		//cout << "In destructor" << endl;
		clear();
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value) {
		//cout << "In insertHead" << endl;

		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) { // check to see if value already exists in list
			if (ptr->value == value) {
				return;
			}
		}

		Node* newNode = new Node(value);
		if (head == NULL) {
			newNode->next = NULL;
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		num_items++;
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
		//cout << "In insertTail" << endl;

		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) { // check to see if value already exists in list
			if (ptr->value == value) {
				return;
			}
		}

		if (head == NULL) { // if list is empty
			insertHead(value);
		}
		else {
			Node* newNode = new Node(value);
			newNode->next = NULL;
			Node* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = newNode;
			num_items++;
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
		//cout << "In insertAfter" << endl;

		Node* ptr;
		for (ptr = head; ptr != NULL; ptr = ptr->next) { // check to see if value already exists in list
			if (ptr->value == value) {
				return;
			}
		}

		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->value == insertionNode) {
				Node* newNode = new Node(value);
				newNode->next = ptr->next;
				ptr->next = newNode;
				num_items++;
			}
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
		//cout << "In remove" << endl;
		if (head == NULL) { // if list is empty
			return;
		}

		if (head->value == value) { // if the value we want removed is at the head
			Node* temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
			num_items--;
		}
		else {
			Node* temp1;
			for (temp1 = head; temp1->next != NULL; temp1 = temp1->next) {
				if (temp1->next->value == value) {
					Node* temp2 = temp1->next;
					temp1->next = temp2->next;
					delete temp2;
					temp2 = NULL;
					num_items--;
					break;
				}
			}
		}
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
		//cout << "In clear" << endl;
		while (head != NULL) {
			remove(head->value);
		}
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
		//cout << "In at" << endl;

		if (index >= num_items || index < 0) {
			throw std::out_of_range("out_of_range");
		}
		else {
			Node* ptr = head;
			for (int i = 0; i < num_items; i++) {
				if (i == index) {
					return ptr->value;
				}
				ptr = ptr->next;
			}
		}
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
		//cout << "In size" << endl;
		return num_items;
	}

	/*
	toString

	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString() {
		//cout << "In toString" << endl;
		stringstream ss;
		Node* ptr;

		if (head == NULL) {
			return "";
		}

		for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
			ss << ptr->value << " ";
		}
		ss << ptr->value;
		return ss.str();
	}

};
