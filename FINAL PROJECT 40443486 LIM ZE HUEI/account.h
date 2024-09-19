#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string accountName;   // Account holder's name
    std::string accountNumber; // Unique identifier for the account
    double balance;            // Current balance in the account

public:
    // Constructor
    Account(const std::string& name, const std::string& num, double bal);

    // Setters
    void setAccountName(const std::string& name);
    void setAccountNumber(const std::string& num);
    void setBalance(double bal);

    // Getters
    std::string getAccountName() const;
    std::string getAccountNumber() const;
    double getBalance() const;

    // Methods
    void deposit(double amount);  // Method to deposit money
    bool withdraw(double amount); // Method to withdraw money
    void display() const;         // Method to display account details

    // Virtual method for applying monthly changes
    virtual void applyMonthlyChanges() = 0; //Override by a derived class allows the copy only one to derived class

    // Virtual destructor
    virtual ~Account() = default;
};

#endif // ACCOUNT_H
