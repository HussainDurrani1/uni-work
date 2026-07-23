#pragma once
#include <iostream>
using namespace std;

class BankAccount {

private:
	char* accountHolderName;
	int accountNumber;
	double balance;
	static int totalAccounts;
	const double MIN_BALANCE;

	int findLength(const char* src) {
		int len = 0;
		for (int i = 0; src[i]; i++) len++;
		return len;
	}

	char* copyString(const char* src) {
		if (src == nullptr) {
			return nullptr;
		}
		int length = findLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}

public:
	BankAccount() : MIN_BALANCE(500.0) {
		accountHolderName = copyString("Unknown");
		accountNumber = 0;
		balance = 1000.0;
		totalAccounts++;
	}

	BankAccount(const char* n, int an, double b) : accountNumber(an), MIN_BALANCE(500.0) {
		accountHolderName = copyString(n);
		if (b < MIN_BALANCE) {
			balance = MIN_BALANCE;
		}
		else {
			balance = b;
		}
		totalAccounts++;
	}

	BankAccount(const BankAccount& other) : accountNumber(other.accountNumber), balance(other.balance), MIN_BALANCE(other.MIN_BALANCE) {
		accountHolderName = copyString(other.accountHolderName);
		totalAccounts++;
	}

	~BankAccount() {
		delete[] accountHolderName;
		accountHolderName = nullptr;
		totalAccounts--;
	}

	void setAccountHolderName(const char* n) {
		if (accountHolderName != nullptr) {
			delete[] accountHolderName;
		}
		accountHolderName = copyString(n);
	}

	void setAccountNumber(int an) {
		accountNumber = an;
	}

	void setBalance(double b) {
		if (b < MIN_BALANCE) {
			balance = MIN_BALANCE;
		}
		else {
			balance = b;
		}
	}

	char* getAccountHolderName() const { return accountHolderName; }
	int getAccountNumber() const { return accountNumber; }
	double getBalance() const { return balance; }

	static int getTotalAccounts() {
		return totalAccounts;
	}

	void display() {
		cout << "Account Holder Name: " << accountHolderName << ", Balance: " << balance << " \n";
	}
};
