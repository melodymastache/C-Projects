/******************************/
/* Name: Citlalli Mastache    */
/* Student Number: 126275189  */
/* Date: January 21st, 2019.  */
/* File: String.cpp           */
/* Course: OOP 345            */
/* Professor: Asam Gulaid     */
/******************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"
#include "process.h"

namespace sict {
	bool String::empty() const {
		return (String::str == nullptr || String::str[0] == '\0');
	}
	String::String(const char* s) {
		if (empty()) {
			str = nullptr;
		}
		else {
			int size = strlen(s);
			str = new char[size + 1];
			strncpy(str, s, size);
			str[size + 1] = '\0';
		}
	}
	void String::display(std::ostream& os) const {
		if (empty()) {
			return;
		}
		else {
			os << str;
		}
	}
	std::ostream& operator<<(std::ostream& os, const String& obj) {
		static int item = INITIAL;
		os << item << ": ";
		obj.display(os);
		item++;
		return os;
	}
}
