// Student Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: CRA_Account.cpp

#include <iostream>

#include <cstring>

#include "CRA_Account.h"

using namespace std;

namespace sict {

	// checks if sin is valid against max and min limits, stores empty state if not

	void CRA_Account::set(const char* family, const char* given, int num) {

		familyName[0] = '\0';
		givenName[0] = '\0';
		SIN = 0;

		int sin = num;
		
		if (sin >= min_sin && sin <= max_sin && family[0] != '\0' && given[0] != '\0') {

			int sum = 0;

			for (int i = 0; i < 5; ++i)
			{
				int temp = sin % 100;
				int even = temp / 10 * 2;
				sum += temp % 10 + even / 10 + even % 10;
				sin /= 100;
			}
			if (sum % 10 == 0) {
				SIN = num;
				strncpy(familyName, family, max_name_length + 1);
				familyName[max_name_length] = '\0';
				strncpy(givenName, given, max_name_length + 1);
				givenName[max_name_length] = '\0';
			}
		}
		for (int i = 0; i < max_yrs; ++i)
			balance[i] = 0;
		YEARS = 0;
	}

	void CRA_Account::set(int y, double b) {
		if (!isEmpty() && YEARS < max_yrs) {
			year[YEARS] = y;
			balance[YEARS] = b;
			YEARS++;
		}
	}

	bool CRA_Account::isEmpty() const {

		return !SIN;

	}

	void CRA_Account::display() const {

		if (!isEmpty()) {

			cout << "Family Name: " << familyName << endl;

			cout << "Given Name : " << givenName << endl;

			cout << "CRA Account: " << SIN << endl;

			for (int i = 0; i < YEARS; ++i) {
				cout << "Year (" << year[i] << ") ";
				if (balance[i] > 2.00) {
					cout << "balance owing: " << balance[i] << endl;
				}
				else if (balance[i] < -2.00) {
					cout << "refund due: " << -balance[i] << ".00" << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}

		}

		else {

			cout << "Account object is empty!" << endl;

		}

	}


}
