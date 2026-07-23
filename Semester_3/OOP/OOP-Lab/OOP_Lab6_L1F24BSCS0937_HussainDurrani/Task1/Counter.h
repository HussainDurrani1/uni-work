#pragma once
#include <iostream>
using namespace std;
class Counter {
private:
    int count;

public:
    Counter() : count(0) {
        cout << "Counter initialized." << endl;
    }

    void increment() { count++; }

    void displayCount() const {
        cout << "Current count: " << count << endl;
    }

    ~Counter() {
        cout << "Counter destroyed." << endl;
    }
};