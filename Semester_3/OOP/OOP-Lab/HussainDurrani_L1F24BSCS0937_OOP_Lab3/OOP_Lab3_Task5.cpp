//Task 5:
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    void setValue(double l, double w) {
        length = l;
        width = w;
    }
    void display() {
        cout << "The length of rectangle is: " << length << endl;
        cout << "The width of rectangle is: " << width << endl;
    }
    double calculateArea(double length, double width) {
        return length * width;
    }
};

void testRectangle() {
    Rectangle r1;
    double length, width;
    cout << "Enter the length of rectangle (in double): ";
    cin >> length;
    cout << "Enter the width of rectangle (in double): ";
    cin >> width;
    r1.setValue(length, width);
    r1.display();

    double l, w;
    cout << "Enter length & width of rectangle to find its Area: ";
    cin >> l >> w;
    cout << "The area of rectangle is = " << r1.calculateArea(l, w) << endl;
}

class Student {
private:
    char* studentName;
    int studentID;
    double GPA;
    char* degreeName;

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
    Student() {
        studentName = nullptr;
        degreeName = nullptr;
        studentID = 0;
        GPA = 0.0;
    }
    ~Student() {
        delete[] studentName;
        delete[] degreeName;
    }
    void setValue(const char* name, int id, double gpa, const char* degree) {
        delete[] studentName;
        delete[] degreeName;
        copyString(name, studentName);
        studentID = id;
        GPA = gpa;
        copyString(degree, degreeName);
    }
    void display() {
        cout << "Student Name: " << studentName << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Degree Name: " << degreeName << endl;
    }
    double calculatePercentage(int obtained, int total) {
        if (total <= 0) return 0.0;
        return (double(obtained) / total) * 100.0;
    }
    void displayGrade(double percentage) {
        cout << "Grade: ";
        if (percentage >= 86 && percentage <= 100)
            cout << "A+";
        else if (percentage >= 82)
            cout << "A";
        else if (percentage >= 78)
            cout << "B+";
        else if (percentage >= 74)
            cout << "B";
        else if (percentage >= 70)
            cout << "B-";
        else if (percentage >= 66)
            cout << "C+";
        else if (percentage >= 62)
            cout << "C";
        else if (percentage >= 58)
            cout << "C-";
        else if (percentage >= 54)
            cout << "D+";
        else if (percentage >= 50)
            cout << "D";
        else
            cout << "F";
        cout << endl;
    }
};
void testStudent() {
    int temp;
    cout << "Enter number of students you want to input: ";
    cin >> temp;

    for (int i = 0; i < temp; i++) {
        cout << "\n--- Entering details for Student #" << i + 1 << " ---\n";

        char name[100], degree[100];
        int id, obtained, total;
        double gpa;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter GPA: ";
        cin >> gpa;

        cout << "Enter degree name: ";
        cin >> degree;

        cout << "Enter obtained marks: ";
        cin >> obtained;

        cout << "Enter total marks: ";
        cin >> total;

        Student s;
        s.setValue(name, id, gpa, degree);

        double percentage = s.calculatePercentage(obtained, total);

        cout << "\nStudent #" << i + 1 << " Info:\n";
        s.display();
        cout << "Percentage: " << percentage << "%" << endl;
        s.displayGrade(percentage);
    }
}

class Calculator {
private:
    int num1, num2, num3;

public:
    Calculator(int n1, int n2, int n3) {
        num1 = n1;
        num2 = n2;
        num3 = n3;
    }
    void display() {
        cout << "Num1 = " << num1 << endl;
        cout << "Num2 = " << num2 << endl;
        cout << "Num3 = " << num3 << endl;
    }
    int add() {
        return (num1 + num2 + num3);
    }
    int multiply() {
        return (num1 * num2 * num3);
    }
    double average() {
        double sum = num1 + num2 + num3;
        return sum / 3;
    }
    int maximum() {
        int max = num1;
        if (num2 > max) max = num2;
        if (num3 > max) max = num3;
        return max;
    }
    int minimum() {
        int min = num1;
        if (num2 < min) min = num2;
        if (num3 < min) min = num3;
        return min;
    }
};
void testCalculator() {
    int n1, n2, n3;
    cout << "Enter three numbers: " << endl;
    cin >> n1 >> n2 >> n3;

    Calculator obj1(n1, n2, n3);

    obj1.display();
    cout << "The addition of these 3 numbers is: " << obj1.add() << endl;
    cout << "The product of these 3 numbers is: " << obj1.multiply() << endl;
    cout << "The average of these 3 numbers is: " << obj1.average() << endl;
    cout << "The maximum of these 3 numbers is: " << obj1.maximum() << endl;
    cout << "The minimum of these 3 numbers is: " << obj1.minimum() << endl;
}

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
void testCar() {
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
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Test Rectangle class\n";
        cout << "2. Test Student class\n";
        cout << "3. Test Calculator class\n";
        cout << "4. Test Car class\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testRectangle();
            break;
        case 2:
            testStudent();
            break;
        case 3:
            testCalculator();
            break;
        case 4:
            testCar();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}