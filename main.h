
#ifndef OBJECTS_AND_CLASSES_1_MAIN_H
#define OBJECTS_AND_CLASSES_1_MAIN_H
#include <string>

class BankAccount {

public:
    BankAccount();
    BankAccount(std::string accountNumber, std::string accountHolderName, double balance);
    bool Deposit(double amount) {
        if (amount > 0) {
            BankAccount::balance += amount;
            return true;
        }
        return false;  // Invalid amount
    };
    bool Withdraw(double amount) {
        if (amount > 0 && amount <= BankAccount::balance) {
            BankAccount::balance -= amount;
            return true;
        }
        return false;  // Insufficient funds or invalid amount
    };

    //Setters
    void SetBalance(double balance) {
        BankAccount::balance = balance;
    };
    void SetAccountNumber(std::string accountNumber) {
        BankAccount::accountNumber = accountNumber;
    };
    void SetAccountHolderName(std::string accountHolderName) {
        BankAccount::accountHolderName = accountHolderName;
    };

    //Getters
    double GetBalance() const {
        return BankAccount::balance;
    };
    std::string GetAccountNumber() const {
        return BankAccount::accountNumber;
    };
    std::string GetAccountHolderName() const {
        return BankAccount::accountHolderName;
    };

private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
};
#endif //OBJECTS_AND_CLASSES_1_MAIN_H