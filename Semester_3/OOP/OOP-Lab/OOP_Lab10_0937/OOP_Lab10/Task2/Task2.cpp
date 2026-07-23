#include <iostream>
#include "Course.h"
#include "Teacher.h"
using namespace std;

int main() {
    string tName, cTitle, cCode;
    int numCourses;

    cout << "Enter Teacher's Name: ";
    cin >> tName;
    Teacher teacher1(tName);

    cout << "How many courses does " << tName << " teach? (Max 5): ";
    cin >> numCourses;

    cin.ignore();

    if (numCourses > 5) {
        cout << "Limit is 5. Setting to 5.\n";
        numCourses = 5;
    }

    for (int i = 0; i < numCourses; i++) {
        cout << "\n--- Enter Details for Course " << i + 1 << " ---\n";

        cout << "Enter Course Code: ";
        cin >> cCode;

        cout << "Enter Course Title: ";
        cin >> cTitle;

        Course* newCourse = new Course(cCode, cTitle);
        teacher1.addCourse(newCourse);
    }

    cout << "\n------------------------------------------------\n";
    cout << "FINAL TEACHER RECORD\n";
    teacher1.display();
    cout << "------------------------------------------------\n";

    cout << "\nRetrieving Course Codes manually:\n";
    for (int i = 0; i < teacher1.getCourseCount(); i++) {
        cout << "Course " << i + 1 << " Code: " << teacher1.getCourse(i)->getCourseCode() << endl;
    }

    return 0;
}