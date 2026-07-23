#include "BankAccount.h"
#include <iostream>
using namespace std;

int main() {
	int accNum, branchNum;
	double balance;
	cout << "Enter ACCOUNT NUMBER: ";
	cin >> accNum;
	cout << "Enter BALANCE: ";
	cin >> balance;
	cout << "Enter BRANCH NUMBER: ";
	cin >> branchNum;
	BankAccount acc1(accNum, balance, branchNum);
	
	cout << "\nEnter ACCOUNT NUMBER: ";
	cin >> accNum;
	cout << "Enter BALANCE: ";
	cin >> balance;
	cout << "Enter BRANCH NUMBER: ";
	cin >> branchNum;
	BankAccount acc2(accNum, balance, branchNum);

	cout << "--- Initial Account Status ---\n";
	acc1.display();
	acc2.display();

	cout << "\n--- Depositing to Account 1 ---\n";
	double amount;
	cout << "Enter the amount you want to deposit: ";
	cin >> amount;
	acc1.deposit(amount);
	acc1.display();

	cout << "\n--- Withdrawing from Account 1 ---\n";
	cout << "Enter amount you want to withdraw: ";
	cin >> amount;
	acc1.withdraw(amount);
	acc1.display();

	cout << "\n--- Withdrawing from Account 2 ---\n";
	cout << "Enter amount you want to withdraw: ";
	cin >> amount;
	acc2.withdraw(amount);
	acc2.display();

	cout << "\n--- Bank Transfer from 1 to 2 ---\n";
	cout << "Enter amount you want to Transfer: ";
	cin >> amount;
	acc1.bankTransfer(acc2, amount);
	acc1.display();
	acc2.display();

	cout << "\n--- Bill Payment from Account 2 ---\n";
	cout << "Enter Bill Number: ";
	int billNo;
	cin >> billNo;
	cin.ignore();
	char billType[100];
	cout << "Enter the Bill Type: ";
	cin.getline(billType, 100);
	cout << "Enter the amount: ";
	cin >> amount;
	acc2.billPayment(billNo, billType, amount);
	acc2.display();

	cout << "\n--- Testing Setters ---\n";
	cout << "Enter new ACCOUNT NUMBER: ";
	cin >> accNum;
	acc1.setAccountNumber(accNum);
	cout << "Enter new BALANCE: ";
	cin >> amount;
	acc1.setBalance(amount);
	acc1.display(); 

	return 0;
}