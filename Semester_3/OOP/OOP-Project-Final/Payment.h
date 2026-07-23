#pragma once
#include <iostream>
#include "Utils.h"
#include "RideRequest.h"
#include "Rider.h"
#include "PromoCode.h"

using namespace std;

class Payment {
private:
    char* paymentId;
    double amount;
    double discountApplied; 
    char* paymentMethod; 
    char* status;        

public:
    
    Payment() {
        paymentId = copyString("000");
        amount = 0.0;
        discountApplied = 0.0;
        paymentMethod = copyString("Cash");
        status = copyString("Pending");
    }

    Payment(const char* id, double amt, const char* method) {
        paymentId = copyString(id);
        amount = amt;
        discountApplied = 0.0;
        paymentMethod = copyString(method);
        status = copyString("Pending");
    }

    Payment(const Payment& other) {
        paymentId = copyString(other.paymentId);
        amount = other.amount;
        discountApplied = other.discountApplied;
        paymentMethod = copyString(other.paymentMethod);
        status = copyString(other.status);
    }

    Payment& operator=(const Payment& other) {
        if (this != &other) {
            delete[] paymentId;
            delete[] paymentMethod;
            delete[] status;

            paymentId = copyString(other.paymentId);
            amount = other.amount;
            discountApplied = other.discountApplied;
            paymentMethod = copyString(other.paymentMethod);
            status = copyString(other.status);
        }
        return *this;
    }

    ~Payment() {
        delete[] paymentId;
        delete[] paymentMethod;
        delete[] status;
    }

    void applyPromoCode(PromoCode* promo, const char* inputCode) {
        if (promo != nullptr && promo->isCodeValid(inputCode)) {
            discountApplied = promo->getDiscountAmount();
            promo->useCode();
            cout << "Promo Code Applied! Discount: $" << discountApplied << endl;
        }
        else {
            cout << "Invalid Promo Code." << endl;
        }
    }

    void processPayment(RideRequest* ride) {
        if (ride == nullptr) {
            cout << "Error: Invalid ride request." << endl;
            return;
        }

        Rider* rider = ride->getRider();
        if (rider == nullptr) {
            cout << "Error: No rider associated with this request." << endl;
            return;
        }

        double rideFare = (double)ride->getFare();

        amount = rideFare - discountApplied;
        if (amount < 0) amount = 0;

        cout << "Processing payment for Ride ID: " << ride->getRideId() << endl;

        cout << "Base Fare: $" << rideFare << endl;

        if (discountApplied > 0) {
            cout << "Discount: -$" << discountApplied << endl;
        }
        cout << "Total to Pay: $" << amount << endl;

        if (rider->getWalletBalance() >= amount) {
            char* rideIdStr = intToString(ride->getRideId());
            char* desc = concatString("Fare for Ride ", rideIdStr);

            rider->chargeWallet((float)amount, desc);

            delete[] rideIdStr;
            delete[] desc;

            delete[] status;
            status = copyString("Completed");

            cout << "Payment Successful! Deducted $" << amount << " from Rider: " << rider->getName() << endl;
            cout << "Remaining Balance: $" << rider->getWalletBalance() << endl;
        }
        else {
            delete[] status;
            status = copyString("Failed");
            cout << "Payment Failed! Insufficient wallet balance." << endl;
        }
    }

    void refundPayment(RideRequest* ride) {
        if (ride == nullptr) return;

        Rider* rider = ride->getRider();
        if (rider != nullptr) {
            rider->addToWallet((float)amount);

            delete[] status;
            status = copyString("Refunded");

            cout << "Refunded $" << amount << " to Rider: " << rider->getName() << endl;
        }
    }

    void setAmount(double amt) {
        amount = amt;
    }

    void setPaymentMethod(const char* method) {
        delete[] paymentMethod;
        paymentMethod = copyString(method);
    }

    void setStatus(const char* newStatus) {
        delete[] status;
        status = copyString(newStatus);
    }

    const char* getPaymentId() const { return paymentId; }
    double getAmount() const { return amount; }
    const char* getPaymentMethod() const { return paymentMethod; }
    const char* getStatus() const { return status; }

    void display() const {
        cout << "Payment Details:" << endl;
        cout << "  ID: " << paymentId << endl;
        cout << "  Amount: $" << amount << endl;
        cout << "  Method: " << paymentMethod << endl;
        cout << "  Status: " << status << endl;
    }
};
