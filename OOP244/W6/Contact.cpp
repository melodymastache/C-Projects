// Workshop 6, at home
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Contact.cpp

#include <iostream>
#include <string.h>
#include "Contact.h"

namespace sict {

	// constructor for safe empty state
	Contact::Contact() {
	contactName[0] = '\0';
	phoneNums = nullptr;
	currentNums = 0;
	}

	// holds only valid phone numbers and copies into allocated array
	Contact::Contact(const char * name, const long long * phone, const int nums) {
		if (name != nullptr && name[0] != '\0') {
			strncpy(this->contactName, name, MAX_CHAR);
			this->contactName[MAX_CHAR] = '\0';
			currentNums = nums;
			phoneNums = new long long[nums];
			for (int i = 0; i < nums; i++) {
				phoneNums[i] = phone[i];
			}
		}
		else {
			*this = Contact();
		}
	}

	// deallocating all dynamic memory
	Contact::~Contact() {
		delete[] phoneNums;
	}

	int* Contact::breakNum(long long num) const {
		int* nums = new int[3];
		nums[0] = num / 10000000000;
		num = num % 10000000000;
		nums[1] = num / 10000000;
		num = num % 10000000;
		nums[2] = num / 10000;
		nums[3] = num % 10000;
		return nums;
	}

	// copy constructor: copies received object into new object
	Contact::Contact(const Contact& obj) {
		*this = obj;
	}

	// copy assignment operator: updates existing object
	Contact& Contact::operator=(const Contact& obj) {
		if (this != &obj) {
			strncpy(contactName, obj.contactName, MAX_CHAR);
			contactName[MAX_CHAR + 1] = '\0';
			currentNums = obj.currentNums;
			if (obj.phoneNums != nullptr) {
				phoneNums = new long long[currentNums];
				for (int i = 0; i < currentNums; i++) {
					phoneNums[i] = obj.phoneNums[i];
				}
			}
			else {
				phoneNums = nullptr;
			}
		}
		return *this;
	}

	// validates long long number
	bool Contact::valid(long long num) const {
		int* numbers = breakNum(num);
		if (numbers[0] > 99 || numbers[0] < 1) {
			return false;
		}
		if (numbers[1] < 100 || numbers[1] > 999) {
			return false;
		}
		if (numbers[2] < 100 || numbers[2] > 999) {
			return false;
		}
		if (numbers[3] < 1000 || numbers[3] > 9999) {
			return false;
		}
		return true;
	}

	// resizes array to accept new long long number
	Contact& Contact::operator+=(long long num) {
		if (valid(num)) {
			currentNums++;
			long long * arr = nullptr;
			arr = new long long[currentNums];
			if (currentNums > 0) {
				for (int i = 0; i < currentNums; i++) {
					arr[i] = phoneNums[i];
				}
			}
			arr[currentNums-1] = num;
			phoneNums = nullptr;
			delete[] phoneNums;
			phoneNums = arr;
			arr = nullptr;
			delete[] arr;
		}
		return *this;
	}

	// checks for safe empty state
	bool Contact::isEmpty() const {
		return (contactName == nullptr || contactName[0] == '\0');
	}

	// displays contact information to screen
	void Contact::display() const {
		if (isEmpty()) {
			std::cout << "Empty contact!" << std::endl;
		}
		else {
			std::cout << this->contactName << std::endl;
			for (int j = 0; j < currentNums; j++) {
				long long num = phoneNums[j];
				int* numbers = breakNum(num);
				std::cout << "(+" << numbers[0] << ") " << numbers[1] << " " << numbers[2] << "-" << numbers[3] << std::endl;
				numbers = nullptr;
				delete[] numbers;
			}
		}
	}
}
