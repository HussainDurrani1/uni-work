#pragma once
#include <iostream>
using namespace std;

class BankAccount {
private:
	int accountNumber;
	double balance;
	int branchNumber;

public:
	BankAccount() {
		accountNumber = 0;
		balance = 0.0;
		branchNumber = 0;
	}

	BankAccount(int acc, double bal, int br) {
		accountNumber = acc;
		if (bal < 0.0) {
			balance = 0.0;
		}
		else {
			balance = bal;
		}
		branchNumber = br;
	}

	void setAccountNumber(int acc) {
		accountNumber = acc;
	}

	void setBalance(double bal) {
		if (bal >= 0.0) {
			balance = bal;
		}
		else {
			cout << "Error: Cannot set a negative balance.\n";
		}
	}

	int getAccountNumber() const { return accountNumber; }
	double getBalance() const { return balance; }
	int getBranchNumber() const { return branchNumber; }



	void deposit(double amount) {
		if (amount > 0.0) {
			balance += amount;
			cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
		}
		else {
			cout << "Error: Deposit amount must be positive.\n";
		}
	}

	bool withdraw(double amount) {
		if (amount <= 0.0) {
			cout << "Error: Withdrawal amount must be positive.\n";
			return false;
		}
		if (amount <= balance) {
			balance -= amount;
			cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
			return true;
		}
		else {
			cout << "Error: Insufficient funds for withdrawal of $" << amount << ".\n";
			return false;
		}
	}

	void bankTransfer(BankAccount& recipient, double amount) {
		cout << "--- Transferring $" << amount << " from " << accountNumber << " to " << recipient.accountNumber << " ---\n";
		if (this->withdraw(amount)) {
			recipient.deposit(amount);
			cout << "--- Transfer Successful ---\n";
		}
		else {
			cout << "--- Transfer Failed --- \n";
		}
	}

	void billPayment(int billNumber, const char* billType, double amount) {
		cout << "--- Paying Bill #" << billNumber << " (" << billType << ") of $" << amount << " ---\n";
		if (withdraw(amount)) {
			cout << "--- Bill Payment Successful ---\n";
		}
		else {
			cout << "--- Bill Payment Failed --- \n";
		}
	}

	void display() const {
		cout << "--------------------------------------\n";
		cout << "Account #: " << accountNumber << "\n";
		cout << "Branch #: " << branchNumber << "\n";
		cout << "Balance: $" << balance << "\n";
		cout << "--------------------------------------\n";
	}
};