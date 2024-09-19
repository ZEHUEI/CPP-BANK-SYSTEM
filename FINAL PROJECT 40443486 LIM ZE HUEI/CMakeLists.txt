cmake_minimum_required(VERSION 3.27)
project(Project_Debug)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Project_Debug
        main.cpp
        account.cpp
        SavingsAccount.cpp
        CheckingAccount.cpp
        check_credential.cpp
        BankMenu.cpp
)
