// Workshop <Workshop #1>
// Name: <Citlalli Melody Mastache>
// Student #: <126275189>
// Course: OOP244 Winter 2018
// File: <tools.cpp>

//namespace sict {

#include "tools.h"
#include <iostream>
using namespace std;
namespace sict {
	// displays the user interface menu
	int menu() {
		cout << "1- Number of Samples" << endl;
		cout << "2- Sample Entry" << endl;
		cout << "3- Draw Graph" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";
		return getInt(0, 3);
	}

	// Performs a fool-proof integer entry
	int getInt(int min, int max) {
		int val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				if (val < min || val > max) {
					cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}

}
