#pragma once

#include "NodeInterface.h"
using namespace std;

class Node: public NodeInterface {
	friend class BST;

private:
	int data;
	Node* leftChild;
	Node* rightChild;

public:
	Node(int value) { //Constructor
		//cout << "In Node Constructor" << endl;
		data = value;
		leftChild = NULL;
		rightChild = NULL;
	}
	~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const {
		//cout << "In Node getData" << endl;
		return data;
	}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node* getLeftChild() const {
		//cout << "In Node getLeftChild" << endl;
		return leftChild;
	}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node* getRightChild() const {
		//cout << "In Node getRightChild" << endl;
		return rightChild;
	}
};