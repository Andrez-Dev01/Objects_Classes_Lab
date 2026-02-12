/* Andrez De La Torre
* Mcsci-272
* 2-7-2026
* Lab Activities: Objects and Classes
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "main.h"



//This is the default constructor
BankAccount::BankAccount() {
    BankAccount::accountNumber = "";
    BankAccount::accountHolderName = "";
    BankAccount::balance = 0.0;
}

//This is the Parameterized Constructor Implementation
    BankAccount::BankAccount(std::string accountNumber, std::string accountHolderName, double balance) {
    BankAccount::accountNumber = accountNumber;
    BankAccount::accountHolderName = accountHolderName;
    BankAccount::balance = balance;
}

// Helper to find account index by account number. Returns -1 if not found.
int findAccountIndex(const std::vector<BankAccount>& accounts, const std::string& accountNumber) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].GetAccountNumber() == accountNumber) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {

    std::vector<BankAccount> accounts;

    int choice;
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

    do {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "1. Create a new account" << std::endl;
        std::cout << "2. Deposit money into an account" << std::endl;
        std::cout << "3. Withdraw money from an account" << std::endl;
        std::cout << "4. Display account information" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0;  
        }

        switch (choice) {
            case 1:
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter account holder name: ";
                std::cin >> accountHolderName;
                std::cout << "Enter balance: ";
                std::cin >> balance;
                if (balance >= 0) {
                    accounts.push_back(BankAccount(accountNumber, accountHolderName, balance));
                    std::cout << "Account created successfully." << std::endl;
                } else {
                    std::cout << "Invalid balance. Account not created." << std::endl;
                }
                break;
            case 2: {
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                int idx2 = findAccountIndex(accounts, accountNumber);
                if (idx2 >= 0) {
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> balance;
                    if (balance > 0 && accounts[idx2].Deposit(balance)) {
                        std::cout << "Deposit successful." << std::endl;
                    } else {
                        std::cout << "Invalid amount. Deposit must be positive." << std::endl;
                    }
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                int idx3 = findAccountIndex(accounts, accountNumber);
                if (idx3 >= 0) {
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> balance;
                    if (balance > 0) {
                        if (accounts[idx3].Withdraw(balance)) {
                            std::cout << "Withdrawal successful." << std::endl;
                        } else {
                            std::cout << "Insufficient funds." << std::endl;
                        }
                    } else {
                        std::cout << "Invalid amount. Withdrawal must be positive." << std::endl;
                    }
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                int idx4 = findAccountIndex(accounts, accountNumber);
                if (idx4 >= 0) {
                    std::cout << "Account information: " << accounts[idx4].GetAccountNumber() << " " << accounts[idx4].GetAccountHolderName() << " " << accounts[idx4].GetBalance() << std::endl;
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 5);

    return 0;
}