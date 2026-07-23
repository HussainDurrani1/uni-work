#pragma once
#include <iostream>
using namespace std;

template <class T>
class Student{
private:
    string name;
    int id;
    T courses[10];
    int courseCount;

public:
    Student(string n, int i){
        name = n;
        id = i;
        courseCount = 0;
    }

    void addCourse(T c){
        if (courseCount < 10)
        {
            courses[courseCount] = c;
            courseCount++;
        }
    }

    int totalCredits(){
        int sum = 0;
        for (int i = 0; i < courseCount; i++)
        {
            sum += courses[i].credits;
        }
        return sum;
    }

    void displayCourses(){
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;

        for (int i = 0; i < courseCount; i++)
        {
            courses[i].display();
            cout << "-------------------" << endl;
        }

        cout << "Total Credits: " << totalCredits() << endl;
    }
};