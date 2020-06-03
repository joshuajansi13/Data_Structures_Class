#include "BST.h"

Node* BST::getRootNode() const {
	//cout << "In BST getRootNode" << endl;
	return root;
}


bool BST::add(int data) { // adds the data to the BST
	//cout << "In BST add" << endl;
	return insert(this->root, data);
}

bool BST::insert(Node*& local_root, int data) { // traverses through BST 
	//cout << "In BST insert" << endl;
	if (local_root == NULL) {
		local_root = new Node(data);
		return true;
	}
	else {
		if (local_root->data == data) { // This item is already in the tree (base case)
			return false;
		}
		else if (data < local_root->data) {
			return insert(local_root->leftChild, data); // traverse left (recursive call)
		}
		else {
			return insert(local_root->rightChild, data); // traverse right (recursive call)
		}
	}
}


bool BST::remove(int data) {
	//cout << "In BST remove" << endl;
	return erase(this->root, data);
}

bool BST::erase(Node*& local_root, int data) { // traverses through tree
	if (local_root == NULL) { // if the data can't be found in the tree
		return false;
	}
	if (data < local_root->getData()) { // traverse left
		return erase(local_root->leftChild, data);
	}
	else if (data > local_root->getData()) { // traverse right
		return erase(local_root->rightChild, data);
	}
	else { // if the data is in the local_root (where item actually gets deleted)
		Node* old_root = local_root;

		if (local_root->leftChild == NULL) {
			local_root = local_root->rightChild;
		}
		else if (local_root->rightChild == NULL) {
			local_root = local_root->leftChild;
		}
		else {
			replace_parent(old_root, old_root->leftChild);
		}

		delete old_root;
		old_root = NULL;
		return true;
	}
}

void BST::replace_parent(Node*& old_root, Node*& local_root) {
	if (local_root->rightChild != NULL) { // recursive case (traverse right)
		replace_parent(old_root, local_root->rightChild);
	}
	else { // base case (if local_root->rightChild is NULL)
		old_root->data = local_root->data;
		old_root = local_root;
		local_root = local_root->leftChild;
	}
}

void BST::clear() {
	//cout << "In BST clear" << endl;
	recursive(root);
}

void BST::recursive(Node*& local_root) {
	if (local_root == NULL) {
		return;
	}
	recursive(local_root->leftChild);
	recursive(local_root->rightChild);

	delete local_root;
	local_root = NULL;
	return;
}