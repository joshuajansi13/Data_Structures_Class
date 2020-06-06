#pragma once

#include "Node.h"
#include "AVLInterface.h"

using namespace std;

class AVL: public AVLInterface {

private:
	Node* root;

public:
	AVL() {
		root = NULL;
	}
	~AVL() {
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
	* Attempts to add the given int to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	bool insert(Node*& local_root, int data);

	/*
	* Attempts to remove the given int from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);
	bool erase(Node*& local_root, int data);
	Node* findRight(Node*& local_root);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void clear_helper(Node*& local_root);

	void rebalance(Node*& local_root);
	void rotate_left(Node*& local_root);
	void rotate_right(Node*& local_root);
	int getHeight(Node*& local_root);
	int getBalance(Node*& local_root);
};
