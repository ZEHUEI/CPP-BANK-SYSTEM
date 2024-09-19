#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "account.h"

class SavingsAccount : public Account {
private:
    double interestRate; // Annual interest rate

public:
    // Constructor
    SavingsAccount(const std::string& name, const std::string& num, double bal, double rate);

    // Method to apply monthly interest
    void applyMonthlyChanges() override;

    // Getters
    double getInterestRate() const {
        return interestRate;
    }
};

#endif
