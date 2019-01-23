// Workshop 8
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: SavingsAccount.cpp

#include <iostream>
#include "SavingsAccount.h"

namespace sict {
    SavingsAccount::SavingsAccount(double bal, double interest) {
        if (interest > 0) {
            interestRate = interest;
        }
        else {
            interestRate = 0.0;
        }
    }

    void SavingsAccount::monthEnd() {
        currentbalance *= interestRate;
    }

    void SavingsAccount::display(std::ostream& os) const {
        os.setf(ios::fixed);
        os.precision(2);
        os << "Account type: Savings" << std::endl;
        os << "Balance: $" << currentbalance << std::endl;
        os << "Interest Rate (%):" << interestRate x 100 << std::endl;
    }
}
