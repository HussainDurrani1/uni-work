#pragma once
#include <iostream>
using namespace std;

class Loan; // forward declaration

// Helping Functions (Defined as static to prevent multiple definition errors when included, alternative to inline)
static int getLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

static char* copyString(const char* src) {
    int len = getLength(src);
    char* str = new char[len + 1];
    for (int i = 0; i < len; i++) str[i] = src[i];
    str[len] = '\0';
    return str;
}

static char* concatinateString(const char* str1, const char* str2) {
    int len1 = getLength(str1);
    int len2 = getLength(str2);
    char* combined = new char[len1 + len2 + 2];
    int index = 0;
    while (index < len1) combined[index] = str1[index++];
    combined[index++] = ' ';
    for (int j = 0; j < len2; j++) combined[index++] = str2[j];
    combined[index] = '\0';
    return combined;
}

class BankAccount {
private:
    char* holderName;
    int accountNumber;
    float balance;
    static int totalAccounts;
    static float totalBankBalance;

public:
    friend class Loan;
    friend void showLoanDetails(const BankAccount& obj, const Loan& l);

    // Default Constructor:
    BankAccount() : accountNumber(0), balance(0.0f) {
        holderName = copyString("Unknown");
        ++totalAccounts;
        cout << "Default Constructor\n";
    }

    // Parameterized Constructor:
    BankAccount(const char* name, int accNum, float b) : accountNumber(accNum), balance(b) {
        holderName = copyString(name);
        ++totalAccounts;
        totalBankBalance += balance;
        cout << "Parameterized Constructor\n";
    }

    // Copy Constructor (Deep Copy):
    BankAccount(const BankAccount& obj) : accountNumber(obj.accountNumber), balance(obj.balance) {
        holderName = copyString(obj.holderName);
        ++totalAccounts;
        totalBankBalance += obj.balance;
        cout << "Copy Constructor\n";
    }

    // Destructor:
    ~BankAccount() {
        delete[] holderName;
        holderName = nullptr;
        --totalAccounts;
        totalBankBalance -= balance;
        cout << "Destructor called for account " << accountNumber << "...\n";
    }

    // Static Getters:
    static int getTotalAccounts() { return totalAccounts; }
    static float getTotalBankBalance() { return totalBankBalance; }

    // Getters and Setters:
    const char* getHolderName() const { return holderName; }
    void setHolderName() {
        char nom[100];
        cout << "Enter NEW Holder Name: ";
        cin.getline(nom, 100);

        delete[] holderName;
        holderName = copyString(nom);
    }

    int getAccountNumber()  const { return accountNumber; }

    float getBalance()  const { return balance; }

    // Deposit Function:
    void deposit(float amount) {
        if (amount < 0) { cout << "Cannot deposit negative amount...\n"; }
        else if (amount == 0) { cout << "Depositing $0 (nothing) to your account...\n"; }
        else {
            this->balance += amount;
            totalBankBalance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << this->balance << endl;
        }
    }
    // Withdraw Function:
    void withdraw(float amount) {
        if (amount > this->balance) { cout << "Low Balance. Transaction not Successful...\n"; }
        else if (amount == 0) { cout << "Withdrawing $0 (nothing) from your account...\n"; }
        else {
            this->balance -= amount;
            totalBankBalance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << this->balance << endl;
        }
    }

    // Merges 2 Accounts: 
    BankAccount mergeAccounts(const BankAccount& a2) const {
        BankAccount result;

        delete[] result.holderName;

        result.balance = (this->balance + a2.balance);
        result.accountNumber = (this->accountNumber * 1000 + a2.accountNumber);
        result.holderName = concatinateString(this->holderName, a2.holderName);

        result.totalAccounts--;

        return result;
    }

    // Const Display Function:
    void showSummary() const {
        cout << "Summary: " << getHolderName() << " (Acc #" << accountNumber << ") has $" << balance << "\n";
    }

    // To show Bank's Summary (Static):
    static void showBankStats() {
        cout << "=== Bank Statistics ===\n";
        cout << "Total Bank Accouts: " << totalAccounts << ", Total Bank Balance: $" << totalBankBalance << "\n";
        cout << "=======================\n";
    }

    // Const Display Function:
    void display() const {
        cout << "------------------------------------------------------\n";
        cout << "Holder Name: " << holderName << ", Account Number: " << accountNumber << "\nBalance: " << balance << "\n";
        cout << "------------------------------------------------------\n";
    }
};