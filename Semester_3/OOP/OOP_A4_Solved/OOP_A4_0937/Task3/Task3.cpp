// Task 3:
#include "Student.h"
#include "Course.h"

int main()
{
    Course c1("Programming Fundamentals", "CS101", 3);
    Course c2("Object Oriented Programming", "CS201", 4);
    Course c3("Data Structures", "CS301", 3);

    Student<Course> s1("Ali", 101);

    s1.addCourse(c1);
    s1.addCourse(c2);
    s1.addCourse(c3);

    s1.displayCourses();

    return 0;
}