#pragma once
#include <iostream>
#include "Course.h" 
using namespace std;

class Teacher {
private:
    string name;
    Course* courses[5];
    int courseCount;

public:
    Teacher(string n) {
        name = n;
        courseCount = 0;
        for (int i = 0; i < 5; i++) courses[i] = nullptr;
    }

    void setName(string n) { name = n; }
    string getName() const { return name; }

    void addCourse(Course* c) {
        if (courseCount < 5) {
            courses[courseCount] = c;
            courseCount++;
        }
        else {
            cout << "Error: Limit reached.\n";
        }
    }

    int getCourseCount() const { return courseCount; }

    Course* getCourse(int index) const {
        if (index >= 0 && index < courseCount) {
            return courses[index];
        }
        return nullptr;
    }

    void display() const {
        cout << "Teacher Name: " << name << endl;
        for (int i = 0; i < courseCount; i++) {
            courses[i]->display();
        }
    }
};