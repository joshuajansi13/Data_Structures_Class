#include <iostream>
#include <map>


template<typename ItemType>
void print(ItemType items) {

	std::cout << '[';

	for (typename ItemType::iterator i = items.begin(); i != items.end(); i++) {
		if (i != items.begin())
			std::cout << ", ";
		std::cout << '\'' << *i << '\'';
	}

	std::cout << ']' << std::endl;

}


template<typename K, typename V>
void print(std::map<K, V> items) {

	std::cout << '{';

	for (typename std::map<K, V>::iterator i = items.begin(); i != items.end(); i++) {
		if (i != items.begin())
			std::cout << ", ";
		std::cout << i->first << '=' << i->second;
	}

	std::cout << '}' << std::endl;

}