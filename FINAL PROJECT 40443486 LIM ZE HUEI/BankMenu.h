#ifndef BANKMENU_H
#define BANKMENU_H

#include <vector>
#include "account.h"

// Function declarations
void displayMainMenu();
void clearScreen();
void createSavingsAccount(std::vector<Account*>& accounts);
void createCheckingAccount(std::vector<Account*>& accounts);
void depositMoney(std::vector<Account*>& accounts);
void withdrawMoney(std::vector<Account*>& accounts);
void displayAllAccounts(const std::vector<Account*>& accounts);
void applyMonthlyUpdates(std::vector<Account*>& accounts);
std::string getCurrentDateTime();
void saveAccountsToFile(const std::vector<Account*>& accounts);
void loadAccountsFromFile(std::vector<Account*>& accounts);

#endif // UTILITY_H
