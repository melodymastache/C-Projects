// Workshop 8
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Allocator.cpp

#include <iostream>
#include "iAccount.h"
#define INTEREST 0.05

namespace sict {
    iAccount* iAccount::CreateAccount(const char* acctype, double bal) {
        if (acctype[0] == 'S') {
            //create savings account in dynamic mem
        }
        else {
            return nullptr;
        }
        return *this;
    }
}
