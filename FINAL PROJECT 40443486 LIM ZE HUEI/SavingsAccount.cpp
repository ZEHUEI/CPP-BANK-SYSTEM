#include "SavingsAccount.h"
#include <iostream>

// Constructor for the SavingsAccount class
SavingsAccount::SavingsAccount(const std::string& name, const std::string& num, double bal, double rate)
    : Account(name, num, bal), interestRate(rate) {}

// Method to apply monthly interest
void SavingsAccount::applyMonthlyChanges() {
    if (interestRate > 0) {
        double monthlyInterest = balance * (interestRate / 12) / 100; //Interest rate is given in percentage annualy 
        balance += monthlyInterest;
        std::cout << "Monthly interest applied: $" << monthlyInterest << "\n";
    } else {
        std::cerr << "Invalid interest rate.\n";
    }
}
