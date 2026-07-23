// Task 2:
#include <iostream>
using namespace std;

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

int main() {
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

    return 0;
}