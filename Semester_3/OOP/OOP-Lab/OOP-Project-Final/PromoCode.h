#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class PromoCode {
private:
    char* code;
    double discountAmount;
    bool isValid;

public:

    PromoCode(const char* c, double discount) {
        code = copyString(c);
        discountAmount = discount;
        isValid = true;
    }

    PromoCode(const PromoCode& other) {
        code = copyString(other.code);
        discountAmount = other.discountAmount;
        isValid = other.isValid;
    }

    PromoCode& operator=(const PromoCode& other) {
        if (this != &other) {
            delete[] code;
            code = copyString(other.code);
            discountAmount = other.discountAmount;
            isValid = other.isValid;
        }
        return *this;
    }

    ~PromoCode() {
        delete[] code;
    }

    bool isCodeValid(const char* inputCode) const {
        if (!isValid) return false;
        return compareString(code, inputCode);
    }


    void useCode() {
        cout << "Promo Code " << code << " applied." << endl;
    }

    double getDiscountAmount() const { return discountAmount; }
    const char* getCode() const { return code; }
    bool getStatus() const { return isValid; }

    void display() const {
        cout << "PromoCode: " << code << " | Discount: $" << discountAmount << " | Valid: " << (isValid ? "Yes" : "No") << endl;
    }
};
