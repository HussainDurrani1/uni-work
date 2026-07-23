#pragma once
#include <iostream>
#include "BankAccount.h" 
using namespace std;

class Loan {
private:
    int loanId;
    float amount;
    float interestRate;
    int durationMonths;

public:
    Loan() : loanId(0), amount(0.0f), interestRate(0.0f), durationMonths(0) {}
    Loan(int ID, float a, float interest, int duration) : loanId(ID), amount(a), interestRate(interest), durationMonths(duration) {}

    // declare friend 
    friend void showLoanDetails(const BankAccount& obj, const Loan& l);

    // Getters
    int getLoanID() const { return loanId; }
    float getAmount() const { return amount; }
    float getInterestRate() const { return interestRate; }
    int getDurationMonths() const { return durationMonths; }
};

// Friend Function implementation (Q5)
void showLoanDetails(const BankAccount& acc, const Loan& l) {
    cout << "\n****** FRIEND FUNCTION ACCESS ******\n";
    // Accessing private members directly
    cout << "Account Holder (Private Access): " << acc.holderName << "\n";
    cout << "Account Balance (Private Access): $" << acc.balance << "\n";
    cout << "Loan ID (Private Access): " << l.loanId << "\n";
    cout << "Loan Amount (Private Access): $" << l.amount << "\n";
    cout << "--------------------------------------\n";
}