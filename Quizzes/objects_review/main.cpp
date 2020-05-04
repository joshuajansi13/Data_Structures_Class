#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
	Book rothfuss("Name of the Wind", "Rothfuss");
	Book sanderson("Oathbringer", "Sanderson");
	Book rowling("Harry Potter and the Prisoner of Azkaban", "Rowling");

	cout << "Title: " << rothfuss.getTitle() << ", Author: " << rothfuss.getAuthor() << endl;
	cout << "Title: " << sanderson.getTitle() << ", Author: " << sanderson.getAuthor() << endl;

	sanderson.setTitle("Words of Radiance");

	cout << "Title: " << sanderson.getTitle() << ", Author: " << sanderson.getAuthor() << endl;
}