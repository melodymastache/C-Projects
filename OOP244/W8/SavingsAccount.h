// Workshop 8
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: SavingsAccount.h

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

namespace sict {
    class SavingsAccount: public Account {
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}
