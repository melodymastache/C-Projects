// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Error.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Error.h"
namespace aid {
	Error::Error(const char* error) {
		if (error == nullptr) {
			errorMessage = nullptr;
		}
		else {
			message(error);
		}
	}
	const char* Error::message() const {
		if (errorMessage != nullptr && errorMessage[0] != '\0') {
			return errorMessage;
		}
		else {
			return nullptr;
		}
	}
	void Error::message(const char* str) {
		clear();

		if (str == nullptr || str[0] == '\0') {
			errorMessage = nullptr;
		}
		else {
			int size = strlen(str);
			errorMessage = new char[size + 1];
			strncpy(errorMessage, str, size);
			errorMessage[size] = '\0';
		}
	}
	bool Error::isClear() const {
		return (errorMessage == nullptr || errorMessage[0] == '\0');
	}
	void Error::clear() {
		delete[] errorMessage;
		errorMessage = nullptr;
	}
	std::ostream& operator<<(std::ostream& os, const Error& err) {
		if (!err.isClear()) {
			os << err.message();
		}
		return os;
	}
	Error::~Error() {
		clear();
	}
}
