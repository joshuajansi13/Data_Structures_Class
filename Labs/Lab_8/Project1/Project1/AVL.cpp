#include "AVL.h"

Node* AVL::getRootNode() const {
	return root;
}


bool AVL::add(int data) { // adds the data to the BST
	return insert(this->root, data);
}

bool AVL::insert(Node*& local_root, int data) { // traverses through BST 
	if (local_root == NULL) {
		local_root = new Node(data);
		return true;
	}
	else {
		if (data < local_root->data) {
			bool return_value = insert(local_root->leftChild, data); // traverse left (recursive call)
			rebalance(local_root);
			return return_value;
		}
		else if (data > local_root->data) {
			bool return_value = insert(local_root->rightChild, data); // traverse right (recursive call)
			rebalance(local_root);
			return return_value;
		}
		else { // This item is already in the tree (base case)
			return false;
		}
	}
}


bool AVL::remove(int data) {
	return erase(this->root, data);
}

bool AVL::erase(Node*& local_root, int data) { // traverses through tree
	if (local_root == NULL) { // if the data can't be found in the tree
		return false;
	}
	if (data < local_root->getData()) { // traverse left
		bool return_value = erase(local_root->leftChild, data);
		rebalance(local_root);
		return return_value;
	}
	else if (data > local_root->getData()) { // traverse right
		bool return_value = erase(local_root->rightChild, data);
		rebalance(local_root);
		return return_value;
	}
	else { // if the data is in the local_root (where item actually gets deleted)
		Node* old_root = local_root;

		if (local_root->leftChild == NULL) {
			local_root = local_root->rightChild;
		}
		else if (local_root->rightChild == NULL) {
			local_root = local_root->leftChild;
		}
		else { // two children
			Node* inorder = findRight(old_root->leftChild);
			local_root->data = inorder->data;
			bool return_value = erase(local_root->leftChild, inorder->data);
			rebalance(local_root);
			return return_value;
		}

		delete old_root;
		old_root = NULL;
		return true;
	}
}

Node* AVL::findRight(Node*& local_root) {
	if (local_root->rightChild == NULL) { // base case
		return local_root;
	}
	else { // traverse right
		return findRight(local_root->rightChild);
	}
}

void AVL::clear() {
	clear_helper(root);
}

void AVL::clear_helper(Node*& local_root) {
	if (local_root == NULL) {
		return;
	}
	clear_helper(local_root->leftChild);
	clear_helper(local_root->rightChild);

	delete local_root;
	local_root = NULL;
	return;
}

void AVL::rebalance(Node*& local_root) {
	int parent = getBalance(local_root);
	int left_child = getBalance(local_root->leftChild);
	int right_child = getBalance(local_root->rightChild);
	if (parent < -1 || parent > 1) { // unbalanced
		if (parent == -2 && left_child <= 0) { // Left-Left
			rotate_right(local_root);
		}
		else if (parent == -2 && left_child == 1) { // Left-Right
			rotate_left(local_root->leftChild);
			rotate_right(local_root);
		}
		else if (parent == 2 && right_child >= 0) { // Right-Right
			rotate_left(local_root);
		}
		else if (parent == 2 && right_child == -1) { // Right-Left
			rotate_right(local_root->rightChild);
			rotate_left(local_root);
		}
	}
	else { // balanced -> do nothing
		return;
	}

	if (parent < -2 || parent > 2) { // error check
	cout << "ERROR" << endl;
	}
}

void AVL::rotate_left(Node*& local_root) {
	Node* temp = local_root->rightChild;
	local_root->rightChild = temp->leftChild;
	temp->leftChild = local_root;
	local_root = temp;
	getHeight(local_root);
}

void AVL::rotate_right(Node*& local_root) {
	Node* temp = local_root->leftChild;
	local_root->leftChild = temp->rightChild;
	temp->rightChild = local_root;
	local_root = temp;
	getHeight(local_root);
}

int AVL::getHeight(Node*& local_root) {
	if (local_root != NULL) { // recursive calls
		int left_height = getHeight(local_root->leftChild);
		int right_height = getHeight(local_root->rightChild);
		if (left_height > right_height) {
			local_root->height = left_height + 1;
		}
		else {
			local_root->height = right_height + 1;
		}
		return local_root->height;
	}
	else {
		return 0;
	}
}

int AVL::getBalance(Node*& local_root) {
	if (local_root == NULL) {
		return 0;
	}

	return getHeight(local_root->rightChild) - getHeight(local_root->leftChild);
}
