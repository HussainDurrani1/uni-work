#include "Counter.h"
#include <iostream>
using namespace std;

void performTask() {
    static Counter c;

    c.increment();
    c.displayCount();
}

int main() {
    cout << "First call to performTask():" << endl;
    performTask();

    cout << "\nSecond call to performTask():" << endl;
    performTask();

    cout << "\nThird call to performTask():" << endl;
    performTask();

    cout << "\nProgram ending..." << endl;

    return 0;
}