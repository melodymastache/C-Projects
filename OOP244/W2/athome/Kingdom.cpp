// OOP244 Workshop 2: Dynamic Memory: At Home
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

	/*second display function that accepts displays all records within the Kingdom array struct
	and calculates the total population*/
	void display(const Kingdom king[], int count) {
		int i, pop = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (i = 0; i < count; i++) {
			cout << i + 1 << ". " << king[i].m_name << ", population " << king[i].m_population << endl;
		}

		cout << "------------------------------" << endl;

		for (i = 0; i <= count; i++) {
			pop += king[i].m_population;
		}
		
		cout << "Total population of SICT: " << pop << endl;
		cout << "------------------------------" << endl;

	}

}


