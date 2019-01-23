// Workshop 8
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: iAccount.h

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict {
    class iAccount {
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(Std::ostream&) const = 0;
        
        public:
        virtual ~iAccount();
    };
    iAccount* CreateAccount(const char*, double);
}

#endif
