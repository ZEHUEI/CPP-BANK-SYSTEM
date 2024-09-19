#include <iostream>
#include <vector> //dynamic array
#include <iomanip> //header providing parametric manipulators
#include <chrono>//functions that works with time
#include <ctime>//time converted to string
#include "account.h"//this h file is included
#include "SavingsAccount.h"// ""
#include "CheckingAccount.h"//""
#include "check_credential.h"//""
#include "BankMenu.h"//""

int main() {
    std::vector<Account*> accounts;//initialize from another vector

    // Load accounts from file
    loadAccountsFromFile(accounts);

    // Authenticate admin with if statement
    if (!checkAdminCredentials()) {
        std::cerr << "Authentication prohibited. Exiting program.\n";
        return 1;
    }
    std::cout << "Authentication successful. Welcome to the LIM's Bank Management System.\n";
    std::cout << "Current Date and Time: " << getCurrentDateTime() << "\n";
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                createSavingsAccount(accounts);
            break;
            case 2:
                createCheckingAccount(accounts);
            break;
            case 3:
                depositMoney(accounts);
            break;
            case 4:
                withdrawMoney(accounts);
            break;
            case 5:
                displayAllAccounts(accounts);
            break;
            case 6:
                applyMonthlyUpdates(accounts);
            break;
            case 7:
                std::cout << "Saving data and exiting program. Goodbye!\n";
            saveAccountsToFile(accounts);
            // Release memory
            for (auto& account : accounts) {
                delete account;
            }
            accounts.clear();//clear screen
            break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
