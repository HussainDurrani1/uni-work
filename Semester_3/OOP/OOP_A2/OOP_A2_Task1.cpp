#include "BankAccount.h"
#include "Loan.h" 
#include <iostream>

using namespace std;

// Passing object by value (Q2)
void passByValue(BankAccount obj) {
    cout << "\n(PASS BY VALUE) Copy Constructor Runs Here.\n";
    obj.display();
}

// Passing object by reference (Q2)
void passByReference(BankAccount& obj) {
    cout << "\n(PASS BY REFERENCE) No Copy Constructor.\n";
    obj.display();
}

void shallowDeepDemo() {
    cout << "\nSHALLOW vs DEEP COPY DEMO (Q2):\n";
    BankAccount a("Ali", 101, 5000.0f);
    BankAccount b = a;    // Calls Copy Constructor

    cout << "\nOriginal Account A:\n"; a.display();
    cout << "Copied Account B:\n"; b.display();

    cout << "\nModifying A's Name (uses setHolderName())...\n";
    cin.ignore(1000, '\n');
    a.setHolderName();

    cout << "\nAfter modification:\n";
    cout << "A: "; a.display();
    cout << "B: "; b.display();

    cout << "This demonstrates **Deep Copy**: B's name remains unchanged because 'b' has its own separate memory for 'holderName'.\n";
}

// Helper for input
void setAccountDetails(char(&name)[100], int& accNum, float& balance) {
    cout << "Enter Holder Name: ";
    cin.ignore(1000, '\n');
    cin.getline(name, 100);
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Initial Balance: ";
    cin >> balance;
}

// Helper for input
void setLoanDetails(int& ID, float& amount, float& interestRate, int& durationMonths) {
    cout << "Enter Loan ID: ";
    cin.ignore(1000, '\n');
    cin >> ID;
    cout << "Enter Amount for Loan: ";
    cin >> amount;
    cout << "Enter Interest Rate: ";
    cin >> interestRate;
    cout << "Enter Duration in Months: ";
    cin >> durationMonths;
}


// Initialize Static Members (Required outside the class definition)
int BankAccount::totalAccounts = 0;
float BankAccount::totalBankBalance = 0.0;

int main() {
    char name[100];
    int accNum = 0;
    float balance = 0;
    int ID;
    float amount;
    float interestRate;
    int durationMonths;
    int accountIndex = 0;

    int NoOfAccounts = 0;
    cout << "How many Bank Accounts you want to create (Max Capacity): ";
    cin >> NoOfAccounts;

    BankAccount** bankAccounts = new BankAccount * [NoOfAccounts];
    Loan** loans = new Loan * [NoOfAccounts];

    for (int i = 0; i < NoOfAccounts; i++) {
        bankAccounts[i] = nullptr;
        loans[i] = nullptr;
    }

    int index = 0, LoanIndex = 0;

    int choice = 0;
    do {
        cout << "\n======================================================\n";
        cout << "BANKING SYSTEM MENU\n";
        cout << "1) Add an Account \n";
        cout << "2) Display All Accounts \n";
        cout << "3) DEPOSIT Funds\n";
        cout << "4) WITHDRAW Funds\n";
        cout << "5) Get Loan \n";
        cout << "6) Show Loan Details (Friend Function)\n";
        cout << "7) Pass Object by VALUE\n";
        cout << "8) Pass Object by REFERENCE\n";
        cout << "9) Deep vs Shallow Copy Demo\n";
        cout << "10) Const Object & Static Function Demo\n";
        cout << "11) Bank Stats (Static Member Demo)\n";
        cout << "12) To Exit \n";
        cout << "Enter your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            index = BankAccount::getTotalAccounts();
            if (index >= NoOfAccounts) { cout << "Cannot add more Accounts...\n"; continue; }
            cout << "Enter Details for creating Bank Account " << index + 1 << ": \n";
            setAccountDetails(name, accNum, balance);
            bankAccounts[index] = new BankAccount(name, accNum, balance);
            cout << "Account Created Successfully\n";
        }
        else if (choice == 2) {
            cout << "\nDisplaying All Accounts:\n";
            for (int i = 0; i < BankAccount::getTotalAccounts(); i++) {
                if (bankAccounts[i] != nullptr) {
                    bankAccounts[i]->display();
                }
            }
        }
        else if (choice == 3) {
            if (BankAccount::getTotalAccounts() == 0) { cout << "No accounts to deposit to!\n"; continue; }
            float depositAmount;
            cout << "Enter Account Index to Deposit to (0-" << BankAccount::getTotalAccounts() - 1 << "): ";
            cin >> accountIndex;

            if (accountIndex < 0 || accountIndex >= BankAccount::getTotalAccounts() || bankAccounts[accountIndex] == nullptr) {
                cout << "Invalid Account Index!\n"; continue;
            }

            cout << "Enter Amount to Deposit: $";
            cin >> depositAmount;

            bankAccounts[accountIndex]->deposit(depositAmount);
        }
        else if (choice == 4) {
            if (BankAccount::getTotalAccounts() == 0) { cout << "No accounts to withdraw from!\n"; continue; }
            float withdrawAmount;
            cout << "Enter Account Index to Withdraw from (0-" << BankAccount::getTotalAccounts() - 1 << "): ";
            cin >> accountIndex;

            if (accountIndex < 0 || accountIndex >= BankAccount::getTotalAccounts() || bankAccounts[accountIndex] == nullptr) {
                cout << "Invalid Account Index!\n"; continue;
            }

            cout << "Enter Amount to Withdraw: $";
            cin >> withdrawAmount;

            bankAccounts[accountIndex]->withdraw(withdrawAmount);
        }
        else if (choice == 5) {
            if (BankAccount::getTotalAccounts() == 0) { cout << "There is no Bank Account...\n"; continue; }
            cout << "Enter Account Index for Loan (0-" << BankAccount::getTotalAccounts() - 1 << "): ";
            cin >> accountIndex;

            if (accountIndex < 0 || accountIndex >= BankAccount::getTotalAccounts()) {
                cout << "Invalid Account Index!\n"; continue;
            }
            LoanIndex = accountIndex;

            setLoanDetails(ID, amount, interestRate, durationMonths);
            loans[LoanIndex] = new Loan(ID, amount, interestRate, durationMonths);

            cout << "Loan Created Successfully!\n";
        }
        else if (choice == 6) {
            cout << "Enter Account Index to show Loan Details: ";
            cin >> accountIndex;

            if (accountIndex < 0 || accountIndex >= BankAccount::getTotalAccounts()) {
                cout << "Invalid Account Index!\n"; continue;
            }

            if (bankAccounts[accountIndex] && loans[accountIndex])
                showLoanDetails(*bankAccounts[accountIndex], *loans[accountIndex]);
            else
                cout << "Loan or Account not found!\n";
        }
        else if (choice == 7) {
            if (BankAccount::getTotalAccounts() == 0) { cout << "No accounts!\n"; continue; }
            passByValue(*bankAccounts[0]);
        }
        else if (choice == 8) {
            if (BankAccount::getTotalAccounts() == 0) { cout << "No accounts!\n"; continue; }
            passByReference(*bankAccounts[0]);
        }
        else if (choice == 9) {
            shallowDeepDemo();
        }
        else if (choice == 10) {
            cout << "\n====== CONST OBJECT + CONST FUNCTION DEMO ======\n";
            const BankAccount obj("ConstantUser", 777, 9000.0f);
            cout << "This const object's values cannot be changed now...\n";
            obj.display();

            cout << "\nStatic Function Called Directly:\n";
            BankAccount::showBankStats();

            cout << "Destructor will run for 'obj' after this scope...\n";
        }
        else if (choice == 11) {
            BankAccount::showBankStats();
        }
        else {
            cout << "Invalid Input\n";
            continue;
        }

    } while (choice != 12);

    // Q4: Memory Deallocation
    cout << "\n\nCLEANUP: Deleting dynamically allocated objects...\n";
    for (int i = 0; i < NoOfAccounts; i++) {
        delete bankAccounts[i];
        delete loans[i];
    }
    delete[] bankAccounts;
    delete[] loans;

    cout << "\nProgram Exit.\n";
    return 0;
}