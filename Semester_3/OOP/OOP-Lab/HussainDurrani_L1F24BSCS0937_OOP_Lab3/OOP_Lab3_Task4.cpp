// Task 4:
#include <iostream>
using namespace std;

class Car {
private:
    char* make;
    char* model;
    int year;

    void copyString(const char* source, char*& dest) {
        int length = 0;
        while (source[length] != '\0') length++;
        dest = new char[length + 1];
        for (int i = 0; i < length; i++) {
            dest[i] = source[i];
        }
        dest[length] = '\0';
    }

public:
    Car() {
        make = nullptr;
        model = nullptr;
        year = 0;
    }

    ~Car() {
        delete[] make;
        delete[] model;
    }

    void setValue(const char* mk, const char* mdl, int yr) {
        delete[] make;
        delete[] model;

        copyString(mk, make);
        copyString(mdl, model);
        year = yr;
    }

    void display() {
        cout << "Make: " << (make ? make : "N/A") << endl;
        cout << "Model: " << (model ? model : "N/A") << endl;
        cout << "Year: " << year << endl;
    }

    int calculateCarAge(int currentYear) {
        return currentYear - year;
    }

    bool isVintage(int currentYear) {
        return calculateCarAge(currentYear) > 20;
    }

    void displayCarDetails(int currentYear) {
        display();
        int age = calculateCarAge(currentYear);
        cout << "Car Age: " << age << " years" << endl;
        cout << "Vintage Status: " << (isVintage(currentYear) ? "Yes" : "No") << endl;
    }
};

int main() {
    Car car1, car2;
    char make[100], model[100];
    int year, currentYear;

    cout << "Enter details for Car 1:" << endl;
    cout << "Make: ";
    cin >> make;
    cout << "Model: ";
    cin >> model;
    cout << "Year: ";
    cin >> year;
    car1.setValue(make, model, year);

    cout << "\nEnter details for Car 2:" << endl;
    cout << "Make: ";
    cin >> make;
    cout << "Model: ";
    cin >> model;
    cout << "Year: ";
    cin >> year;
    car2.setValue(make, model, year);

    cout << "\nEnter the current year: ";
    cin >> currentYear;

    cout << "\nCar 1 details:\n";
    car1.displayCarDetails(currentYear);

    cout << "\nCar 2 details:\n";
    car2.displayCarDetails(currentYear);

    return 0;
}