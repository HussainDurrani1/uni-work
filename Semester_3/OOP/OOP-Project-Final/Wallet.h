#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Wallet {
private:
    double balance;
    char** transactionHistory;
    int historySize;
    int historyCapacity;

    void resizeHistory() {
        int newCapacity = (historyCapacity == 0) ? 5 : historyCapacity * 2;
        char** newHistory = new char* [newCapacity];

        for (int i = 0; i < historySize; i++) {
            newHistory[i] = transactionHistory[i];
        }

        delete[] transactionHistory;
        transactionHistory = newHistory;
        historyCapacity = newCapacity;
    }

    void addTransaction(const char* description, double amount) {
        if (historySize == historyCapacity) {
            resizeHistory();
        }
        
        transactionHistory[historySize] = copyString(description);
        historySize++;
    }

public:

    void addFunds(double amount, const char* reason = "Credit") {
        if (amount > 0) {
            balance += amount;
            cout << "Wallet: Added $" << amount << " (" << reason << "). New Balance: $" << balance << endl;
            addTransaction(reason, amount);
        }
        else {
            cout << "Wallet: Invalid amount to add." << endl;
        }
    }

    bool deductFunds(double amount, const char* reason = "Debit") {
        if (amount <= 0) {
            cout << "Wallet: Invalid amount to deduct." << endl;
            return false;
        }

        if (balance >= amount) {
            balance -= amount;
            cout << "Wallet: Deducted $" << amount << " (" << reason << "). New Balance: $" << balance << endl;
            addTransaction(reason, amount);
            return true;
        }
        else {
            cout << "Wallet: Insufficient funds for " << reason << ". Balance: $" << balance << endl;
            return false;
        }
    }

public:
    Wallet() {
        balance = 0.0;
        historySize = 0;
        historyCapacity = 0;
        transactionHistory = nullptr;
    }

    Wallet(const Wallet& other) {
        balance = other.balance;
        historySize = other.historySize;
        historyCapacity = other.historyCapacity;

        if (other.historyCapacity > 0) {
            transactionHistory = new char* [historyCapacity];
            for (int i = 0; i < historySize; i++) {
                transactionHistory[i] = copyString(other.transactionHistory[i]);
            }
        }
        else {
            transactionHistory = nullptr;
        }
    }

    Wallet& operator=(const Wallet& other) {
        if (this != &other) {

            if (transactionHistory != nullptr) {
                for (int i = 0; i < historySize; i++) {
                    delete[] transactionHistory[i];
                }
                delete[] transactionHistory;
            }

            balance = other.balance;
            historySize = other.historySize;
            historyCapacity = other.historyCapacity;

            if (other.historyCapacity > 0) {
                transactionHistory = new char* [historyCapacity];
                for (int i = 0; i < historySize; i++) {
                    transactionHistory[i] = copyString(other.transactionHistory[i]);
                }
            }
            else {
                transactionHistory = nullptr;
            }
        }
        return *this;
    }

    ~Wallet() {
        if (transactionHistory != nullptr) {
            for (int i = 0; i < historySize; i++) {
                delete[] transactionHistory[i];
            }
            delete[] transactionHistory;
        }
    }



    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "--- Wallet Info ---" << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Transaction History (" << historySize << "):" << endl;
        for (int i = 0; i < historySize; i++) {
            cout << "  " << (i + 1) << ". " << transactionHistory[i] << endl;
        }
    }
};
