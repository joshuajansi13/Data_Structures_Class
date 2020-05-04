#include "Book.h"

Book::Book(string t, string a) : title(t), author(a) {}

string Book::getTitle() const {
	return title;
}

string Book::getAuthor() const {
	return author;
}

void Book::setTitle(string title) {
	this->title = title;
}

void Book::setAuthor(string author) {
	this->author = author;
}