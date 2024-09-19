#include "check_credential.h"
#include <filesystem>
//
// Created by Samuel Adebayo on 24/06/2024.
//
bool checkAdminCredentials() {
    std::string storedUsername, storedPassword;
    std::string inputUsername, inputPassword;
    std::ifstream file("admin_password.txt");

    // Check if the password file is open
    if (!file.is_open()) {
        std::cerr << "Error opening password file." << std::endl;
//        std::cerr << "Current working directory: " << fs::current_path() << std::endl;
        return false;
    }

    // Prompt user to enter admin username
    std::cout << "Enter admin username: ";
    std::cin >> inputUsername;

    // Ensure the username is not empty
    if (inputUsername.empty()) {
        std::cerr << "Username cannot be empty." << std::endl;
        return false;
    }

    bool userFound = false;
    // Read stored usernames and passwords from the file
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == inputUsername) {
            userFound = true;
            // Prompt user to enter the password for the given username
            std::cout <<"Enter password for " << inputUsername << ": ";
            std::cin >> inputPassword;

            // Ensure the password is not empty
            if (inputPassword.empty()) {
                std::cerr << "Password cannot be empty." << std::endl;
                return false;
            }

            // Check if the input password matches the stored password
            if (inputPassword == storedPassword) {
                return true; // Authentication successful
            } else {
                std::cerr << "Incorrect password." << std::endl;
                return false; // Password mismatch
            }
        }
    }

    // If username is not found in the file
    if (!userFound) {
        std::cerr << "Username not found." << std::endl;
    }

    return false;
}
