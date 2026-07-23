
// Task 6:
#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int average(int a, int b) {
    int sum = a + b;
    return sum / 2;
}

double average(double a, double b) {
    double sum = a + b;
    double avg = sum / 2;
    return avg;
}

int Area(int length) {
    return length * length;
}

int Area(int length, int width) {
    return length * width;
}

double Area(double radius) {
    return 3.14 * radius * radius;
}

int calculate(int length, int width = 5) {
    return length * width;
}

void memoryTest() {
    int size = 5;
    int* arr = new int[size];

    cout << "Enter " << size << " values for array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    delete[] arr;  // Deallocate memory
    cout << "\nMemory deleted.\n";

    cout << "Trying to access deleted memory (dangling pointer):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Undefined behavior
    }
    cout << "\n";

    // Memory leak
    int* leakedArray = new int[10];
    for (int i = 0; i < 10; i++) {
        leakedArray[i] = i * 2;
    }

    cout << "\nProgram ends. One block of memory was not deallocated (memory leak)." << endl;
}

int main() {
    int choice;

    do {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. PassByValue and PassByRef Function" << endl;
        cout << "2. Overloaded Average Function" << endl;
        cout << "3. Overloaded Area Function" << endl;
        cout << "4. Default Argument Calculate Function" << endl;
        cout << "5. Test Dynamic Memory, Dangling Pointers, Memory Leak" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            swapByValue(a, b);
            cout << "After Swapping by Value: a = " << a << ", b = " << b << endl;
            swapByReference(a, b);
            cout << "After Swapping by Reference: a = " << a << ", b = " << b << endl;
            break;
        }
        case 2: {
            double a, b;
            cout << "Enter two floating point numbers: ";
            cin >> a >> b;
            cout << "Average (double): " << average(a, b) << endl;

            int c, d;
            cout << "Enter two integers: ";
            cin >> c >> d;
            cout << "Average (int): " << average(c, d) << endl;
            break;
        }
        case 3: {
            int length, width;
            double radius;
            cout << "Enter length for square: ";
            cin >> length;
            cout << "Area of square = " << Area(length) << endl;

            cout << "Enter length and width for rectangle: ";
            cin >> length >> width;
            cout << "Area of rectangle = " << Area(length, width) << endl;

            cout << "Enter radius for circle: ";
            cin >> radius;
            cout << "Area of circle = " << Area(radius) << endl;
            break;
        }
        case 4: {
            int length, width;
            cout << "Enter length (and optionally width): ";
            cin >> length;

            cout << "Area using default width (5): " << calculate(length) << endl;

            cout << "Now enter width: ";
            cin >> width;
            cout << "Area with user width: " << calculate(length, width) << endl;
            break;
        }
        case 5:
            memoryTest();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
