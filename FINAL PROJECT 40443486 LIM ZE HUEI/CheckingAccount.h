#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "account.h"

// CheckingAccount class derived from the Account class
class CheckingAccount : public Account {
private:
    double transactionFee; // Fee charged for transactions over a specified amount

public:
    // Constructor
    CheckingAccount(const std::string& name, const std::string& num, double bal, double fee);

    // Method to apply transaction fees if applicable
    void applyMonthlyChanges() override;//override function for SavingsAccount 

    // Getters
    double getTransactionFee() const {
        return transactionFee;
    }
};

#endif // CHECKINGACCOUNT_H
