// Workshop 8
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Account.cpp

#include <iostream>
#include "Account.h"

namespace sict {
    Account::Account(double num) {
        if (num < 0 || num = 0) {
            currentbalance = 0.0;
        }
        else if (num > 0) {
            currentbalance = num;
        }
    }

    bool Account::credit(double num) {
        if (num > 0) {
            currentbalance += num;
            return true;
        }
        else if (num < 0) {
            return false;
        }
    }

    bool Account::debit(double num) {
        if (num > 0) {
            currentbalance -= num;
            return true;
        }
        else if (num < 0) {
            return false;
        }
    }

    double Account::balance() const {
        return currentbalance;
    }
}
