//Functions for the main page of the bank
#include "BankMenu.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>//to create a file 
#include <sstream>//stringstream
#include <chrono>
#include <ctime>
#include <iomanip>//manage input and output formatting

// Function to display the main menu
void displayMainMenu() {
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Create Savings Account\n";
    std::cout << "2. Create Checking Account\n";
    std::cout << "3. Deposit Money\n";
    std::cout << "4. Withdraw Money\n";
    std::cout << "5. Display All Accounts\n";
    std::cout << "6. Apply Monthly Updates\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to create a new savings account
void createSavingsAccount(std::vector<Account*>& accounts) {  //pass by reference which detonates pointer on account
    std::string name, number;
    double balance, interestRate;
    std::cout << "Enter account holder's name: ";
    std::cin >> name;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//read strings with spaces. ignore=ignore characters in the input buffer espiacially in the end 
    //numeric_limits<std::streamsize>::max() specifies the maximum number of characters to ignore where max() is not defined
    //std::getline(std::cin,name);//get the string with spaces(input of entire line) and apply to it
    //when using std::cin >> name; instead, when a space is typed in the function, it will run infnitly hence breaking the program
    std::cout << "Enter account number: ";
    std::cin >> number;
    std::cout << "Enter initial balance: ";
    std::cin >> balance;
    std::cout << "Enter annual interest rate (in %): ";
    std::cin >> interestRate;

    accounts.push_back(new SavingsAccount(name, number, balance, interestRate));
    std::cout << "Savings account created successfully.\n";
}

// Function to create a new checking account
void createCheckingAccount(std::vector<Account*>& accounts) {
    std::string name, number;
    double balance, transactionFee;
    std::cout << "Enter account holder's name: ";
    std::cin>>name;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //std::getline(std::cin,name);
    std::cout << "Enter account number: ";
    std::cin >> number;
    std::cout << "Enter initial balance: ";
    std::cin >> balance;
    std::cout << "Enter transaction fee: ";
    std::cin >> transactionFee;

    accounts.push_back(new CheckingAccount(name, number, balance, transactionFee));
    std::cout << "Checking account created successfully.\n";
}

// Function to deposit money into an account
void depositMoney(std::vector<Account*>& accounts) {
    std::string number;
    double amount;
    std::cout << "Enter account number: ";
    std::cin >> number;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;

    for (auto& account : accounts) {
        if (account->getAccountNumber() == number) {  //-> means access members through pointers (*account).getAccountNumber
            account->deposit(amount);
            std::cout << "Deposit successful.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

// Function to withdraw money from an account
void withdrawMoney(std::vector<Account*>& accounts) {
    std::string number;
    double amount;
    std::cout << "Enter account number: ";
    std::cin >> number;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;

    for (auto& account : accounts) {
        if (account->getAccountNumber() == number) {
            if (account->withdraw(amount)) {
                std::cout << std::fixed << std::setprecision(2); // Set display to two decimal places
                std::cout << "Withdrawal successful.\n";
            } else {
                std::cout << "Insufficient funds.\n";
            }
            return;
        }
    }
    std::cout << "Account not found.\n";
}

// Function to display all accounts
void displayAllAccounts(const std::vector<Account*>& accounts) {
    for (const auto& account : accounts) {
        account->display();
        std::cout << std::endl;
    }
}

// Function to apply monthly updates to all accounts
void applyMonthlyUpdates(std::vector<Account*>& accounts) {
    for (auto& account : accounts) {
        account->applyMonthlyChanges();
    }
    std::cout << "Monthly updates applied to all accounts.\n";
}

// Function to get the current date and time with seconds
std::string getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Function to save accounts to a file
void saveAccountsToFile(const std::vector<Account*>& accounts) {
    std::ofstream outFile("accounts.txt");
    outFile << std::fixed << std::setprecision(2); // Set display to two decimal places
    for (const auto& account : accounts) {
        const SavingsAccount* savingsAccount = dynamic_cast<const SavingsAccount*>(account);
        if (savingsAccount) {
            outFile << "S "
                    << savingsAccount->getAccountName() << " "
                    << savingsAccount->getAccountNumber() << " "
                    << savingsAccount->getBalance() << " "
                    << savingsAccount->getInterestRate() << "\n";
        } else {
            const CheckingAccount* checkingAccount = dynamic_cast<const CheckingAccount*>(account);
            if (checkingAccount) {
                outFile << "C "
                        << checkingAccount->getAccountName() << " "
                        << checkingAccount->getAccountNumber() << " "
                        << checkingAccount->getBalance() << " "
                        << checkingAccount->getTransactionFee() << "\n";
            }
        }
    }
}

// Function to load accounts from a file
void loadAccountsFromFile(std::vector<Account*>& accounts) {
    std::ifstream inFile("accounts.txt"); // ifstream reads file from accounts.txt
    std::string accountType;
    while (inFile >> accountType) {
        std::string name, number;
        double balance;
        if (accountType == "S") {
            double interestRate;
            inFile >> name >> number >> balance >> interestRate;
            accounts.push_back(new SavingsAccount(name, number, balance, interestRate));
        } else if (accountType == "C") {
            double transactionFee;
            inFile >> name >> number >> balance >> transactionFee;
            accounts.push_back(new CheckingAccount(name, number, balance, transactionFee));
        }
    }
}
