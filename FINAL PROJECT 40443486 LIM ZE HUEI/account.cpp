//
// Created by Samuel Adebayo on 22/06/24.
//
#include "account.h"
#include <iostream>
#include <iomanip>

Account::Account(const std::string& name, const std::string& num, double bal)
        : accountName(name), accountNumber(num), balance(bal) {}

void Account::setAccountName(const std::string& name) {
    accountName = name;
}

void Account::setAccountNumber(const std::string& num) {
    accountNumber = num;
}

void Account::setBalance(double bal) {
    balance = bal;
}

std::string Account::getAccountName() const {
    return accountName;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << " successfully.\n";
    } else {
        std::cerr << "Deposit amount must be positive.\n";
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << " successfully.\n";
        return true;
    } else {
        std::cerr << "Invalid withdrawal amount.\n";
        return false;
    }
}

void Account::display() const {
    std::cout << std::fixed << std::setprecision(2); 
    std::cout << "Account Name: " << accountName
              << "\nAccount Number: " << accountNumber
              << "\nBalance: $" << balance << std::endl;
}
