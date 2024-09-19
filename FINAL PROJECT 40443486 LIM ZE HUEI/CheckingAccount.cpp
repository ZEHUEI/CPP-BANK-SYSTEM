#include "CheckingAccount.h"
#include <iostream>

// Constructor for CheckingAccount class
CheckingAccount::CheckingAccount(const std::string& name, const std::string& num, double bal, double fee)
    : Account(name, num, bal), transactionFee(fee) {}

// Method to apply transaction fees if applicable
void CheckingAccount::applyMonthlyChanges() {
    // Apply transaction fee if balance is under £1000
    if (transactionFee < 0) {
        std::cerr << "Invalid transaction fee.\n";
        return;
    }

    if (balance < 1000) {
        balance -= transactionFee;
        std::cout << "Transaction fee of $" << transactionFee << " applied.\n";
    } else {
        std::cout << "No transaction fee applied. Balance is sufficient.\n";
    }
}
