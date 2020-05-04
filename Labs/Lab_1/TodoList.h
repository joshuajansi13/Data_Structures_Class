#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
	vector<string> tasks;
	TodoList() { // constructor
		//cout << "In Constructor" << endl;
		ifstream infile("TODOList.txt");
		string line;
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				//cout << line << '\n';
				tasks.push_back(line);
			}
			infile.close();
		}
	} 
	virtual ~TodoList() { // destructor
		//cout << "In Destructor" << endl;
		ofstream outfile;
		outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
		for (int i = 0; i < tasks.size(); i++) {
			//cout << tasks[i] << endl;
			outfile << tasks[i] << endl;
		}
		outfile.close();
	} 

	/*
	*   Adds an item to the todo list with the date specified by the string "_duedate" and the task specified by "_task"
	*/
	virtual void add(string _duedate, string _task) {
		//cout << "In add " << _duedate << " " << _task << endl;
		tasks.push_back(_duedate + " " + _task);
	}

	/*
	*   Removes an item from the todo list with the specified task name
	*
	*   Returns 1 if it removes an item, 0 otherwise
	*/
	virtual int remove(string _task) {
		//cout << "In remove" << endl;
		size_t pos;
		vector<string> temp;
		temp = tasks;

		for (int i = 0; i < temp.size(); i++) {
			pos = temp[i].find(_task);
			//cout << tasks[i] << endl;
			if (pos != string::npos) {
				tasks.erase(tasks.begin() + i);
				//cout << i << endl;
			}
		}
	}

	/*
	*   Prints out the full todo list to the console
	*/
	virtual void printTodoList() {
		//cout << "In printTodoList" << endl;
		for (int i = 0; i < tasks.size(); i++) {
			cout << tasks[i] << endl;
		}
	}

	/*
	*   Prints out all items of a todo list with a particular due date (specified by _duedate)
	*/
	virtual void printDaysTasks(string _date) {
		//cout << "In printDaysTasks" << endl;
		size_t pos;
		cout << _date << ": " << endl;
		for (int i = 0; i < tasks.size(); i++) {
			pos = tasks[i].find(_date);
			//cout << tasks[i] << endl;
			if (pos != string::npos) {
				vector<string> temp;
				istringstream ss(tasks[i]);
				string word;
				while (ss >> word) {
					temp.push_back(word);
				}
				for (int j = 1; j < temp.size(); j++) {
					cout << temp[j] << " ";
				}
				cout << endl;
			}
		}
	}
};

#endif