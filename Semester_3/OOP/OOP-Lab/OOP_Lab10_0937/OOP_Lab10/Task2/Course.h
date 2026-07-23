#pragma once
#include <iostream>
using namespace std;

class Course {
private:
    string courseCode;
    string title;

public:
    Course(string code, string t) {
        courseCode = code;
        title = t;
    }

    void setCourseCode(string code) { courseCode = code; }
    void setTitle(string t) { title = t; }

    string getCourseCode() const { return courseCode; }
    string getTitle() const { return title; }

    void display() const {
        cout << "   [Course] " << title << " (" << courseCode << ")" << endl;
    }
};