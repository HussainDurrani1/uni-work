#include "BankAccount.h"
#include <iostream>
using namespace std;

int BankAccount::totalAccounts = 0;

int main() {

	int aNum;
	double bal;
	cout << "Enter the name of Account Holder 1: ";
	char temp[100];
	cin.getline(temp, 100);
	cout << "Enter the account number of Account Holder 1: ";
	cin >> aNum;
	cout << "Enter the balance of Account holder 1: ";
	cin >> bal;

	BankAccount bA1(temp, aNum, bal);

	cout << "Enter the name of Account Holder 2: ";
	char temp1[100];
	cin.ignore();
	cin.getline(temp1, 100);
	cout << "Enter the account number of Account Holder 2: ";
	cin >> aNum;
	cout << "Enter the balance of Account holder 2: ";
	cin >> bal;

	BankAccount bA2(temp1, aNum, bal);


	cout << "Total Bank Accounts: " << BankAccount::getTotalAccounts() << endl;

	cout << "Account Holder Name: " << bA1.getAccountHolderName() << ", Balance: " << bA1.getBalance() << endl;

	cout << "Account Holder Name: " << bA2.getAccountHolderName() << ", Balance: " << bA2.getBalance() << endl;


	cout << "Enter the name of Account Holder 2: ";
	char temp2[100];
	cin.ignore();
	cin.getline(temp2, 100);
	cout << "Enter the account number of Account Holder 3: ";
	cin >> aNum;
	cout << "Enter the balance of Account holder 3: ";
	cin >> bal;

	BankAccount bA3(temp2, aNum, bal);
	cout << "Total Bank Accounts after 3rd creation: " << BankAccount::getTotalAccounts() << endl;

	bA3.display();

	return 0;
}