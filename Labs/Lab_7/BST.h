//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include <iostream>
#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST: public BSTInterface {

private:
	Node* root;

public:
	BST() {
		//cout << "In BST Constructor" << endl;
		root = NULL;
	}
	~BST() {
		//cout << "In BST Destructor" << endl;
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node* getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	bool insert(Node*& local_root, int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	bool erase(Node*& local_root, int data);

	void replace_parent(Node*& old_root, Node*& local_root);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();

	void recursive(Node*& local_root);
};