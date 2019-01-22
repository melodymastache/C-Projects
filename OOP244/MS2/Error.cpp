// Milestone 2
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Error.cpp

#include <iostream>
#include <string.h>
#include "Error.h"
namespace aid {
    Error::Error(const char* error) {
        errorMessage = nullptr;
        message(error);
    }
    const char* Error::message() const {
        return errorMessage;
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
        return (errorMessage == nullptr);
    }
    void Error::clear() {
        delete errorMessage;
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
