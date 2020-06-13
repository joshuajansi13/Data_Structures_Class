#include <iostream>
#include "Hashmap.h"

unsigned int Hashmap::hash(string key) const {
	//cout << "In hash" << endl;
	unsigned char *ptr = (unsigned char *)key.c_str();
	int sum = 0;
	for (int i = 0; i < key.size(); i++) {
		sum += ptr[i];
	}
	int hashval = sum % BUCKETS;

	return hashval;
}

Hashmap::Hashmap() {
	//cout << "In constructor" << endl;
	for (int i = 0; i < BUCKETS; i++) {
		buckets[i] = NULL;
	}
	mapSize = 0;
}

Hashmap::~Hashmap() {
	cout << "In destructor" << endl;
	clear();
}

void Hashmap::insert(string key, int value) {
	//cout << "In insert" << endl;
	int hashval = hash(key);
	Node* ptr = buckets[hashval];
	Node* ptr_prev = NULL;

	if (buckets[hashval] == NULL) {
		buckets[hashval] = new Node();
		buckets[hashval]->key = key;
		buckets[hashval]->value = value;
		mapSize++;
		return;
	}

	while (ptr != NULL) {
		if (key == ptr->key) { // if key already exists in hashmap, update the value of that key
			ptr->value = value;
			return;
		}
		else { // iterate through bucket
			ptr_prev = ptr;
			ptr = ptr->next;
		}
	}

	if (ptr == NULL) { // if the key doesn't exist yet, make a new node for that key and value pair and put it in the correct place
		ptr = new Node(); // adds a new node with the key and value pair
		ptr->key = key;
		ptr->value = value;
		ptr->prev = ptr_prev;
		ptr_prev->next = ptr;
		mapSize++;
		return;
	}
}

bool Hashmap::contains(string key) const {
	//cout << "In contains" << endl;
	int hashval = hash(key);
	Node* ptr = buckets[hashval]; // look inside this bucket
	while (ptr != NULL) {
		if (key == ptr->key) { // key was found in this bucket
			return true;
		}
		else {
			ptr = ptr->next;
		}
	}
	return false; // key was not in the hashmap
}

int Hashmap::get(string key) const {
	//cout << "In get" << endl;
	int hashval = hash(key);
	Node* ptr = buckets[hashval];
	while (ptr != NULL) {
		if (key == ptr->key) {
			return ptr->value;
		}
		else {
			ptr = ptr->next; // iterate through bucket
		}
	}

	if (ptr == NULL) {
		throw std::invalid_argument("no matching key");
	}
}

int& Hashmap::operator [](string key)
{
	// Is the key in the map?
	unsigned int bucket = hash(key);
	Node* last = NULL;
	Node* current = buckets[bucket];
	while (current != NULL && current->key != key)
	{
		last = current;
		current = current->next;
	}
	// If current is not NULL, then that means I found it
	if (current != NULL) {
		return current->value;
	}

	// If current is NULL, then i did not find it and I need to add it
	Node* newNode = new Node();
	mapSize++;
	newNode->key = key;
	newNode->value = 0;
	if (last == NULL) // There is nothing in this bucket yet
	{
		// Update head pointer to point to new node
		buckets[bucket] = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return newNode->value;
	}

	// If there is something in this bucket, append newNode to the end
	last->next = newNode;
	newNode->prev = last;
	newNode->next = NULL;
	return newNode->value;
}

bool Hashmap::remove(string key) {
	//cout << "In remove" << endl;
	int hashval = hash(key);
	Node* ptr = buckets[hashval];
	Node* ptr_prev = NULL;
	if (!contains(key)) {
		return false;
	}

	while (ptr->key != key) {
		ptr = ptr->next;
	}

	Node* next = ptr->next;
	Node* prev = ptr->prev;

	if (prev == NULL) {
		buckets[hashval] = next;
	}
	else {
		prev->next = next;
	}

	if (next != NULL) {
		next->prev = prev;
	}

	delete ptr;
	ptr = NULL;
	mapSize--;
	return true;
}


void Hashmap::clear() {
	//cout << "In clear" << endl;
	if (mapSize == 0) {
		return;
	}
	for (int i = 0; i < BUCKETS; i++) {
		while (buckets[i] != NULL)
		{
			Node* temp = buckets[i];
			buckets[i] = temp->next;
			delete temp;
			temp = NULL;
		}
	}
	mapSize = 0;
}

string Hashmap::toString() const {
	//cout << "In toString" << endl;
	stringstream ss;
	for (int i = 0; i < BUCKETS; i++) {
		Node* ptr = buckets[i];
		ss << "[" << i << "]";
		while (ptr != NULL) {
			if (ptr->next == NULL) {
				ss << " " << ptr->key << " => " << ptr->value;
				break;
			}
			else {
				ss << " " << ptr->key << " => " << ptr->value << ", ";
				ptr = ptr->next;
			}
		}
		ss << endl;
	}
	return ss.str();
}

int Hashmap::size() const {
	//cout << "In size" << endl;
	return mapSize;
}

string Hashmap::toSortedString() const {
	cout << "In to SortedString" << endl;

	stringstream ss;
	priority_queue <Node*, vector<Node*>, NodeCompare> nodeHeap;
	for (int i = 0; i < BUCKETS; i++) {
		Node* ptr = buckets[i];
		while (ptr != NULL) {
			nodeHeap.push(ptr);
			ptr = ptr->next;
		}
	}
	while (!nodeHeap.empty())
	{
		Node* top = nodeHeap.top(); // Get top node (next node in sorted order)
		ss << top->key << " => " << top->value << endl; // Add node data to stringstream
		nodeHeap.pop(); // Pop it off
	}
	return ss.str();
}