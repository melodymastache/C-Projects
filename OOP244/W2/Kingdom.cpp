// OOP244 Workshop 2: Dynamic Memory
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Kingdom.cpp

#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict {

	/*The following function displays the Kingdom struct member values to the screen.*/
	void display(Kingdom& king) {
		cout << king.m_name << ", population " << king.m_population << endl;
	}

}

