#include <iostream>
// NOTE: We rely on iostream for the necessary cin/cout functionality.
using namespace std;

// --- Utility Functions (Retained) ---
int findLength(const char* src){
    int len = 0;
    for (int i = 0; src[i]; i++){ len++; }
    return len;
}

const char* copyString(const char* src){
    int length = findLength(src);
    char* dest = new char[length + 1];
    for (int i = 0; i < length; i++){
        dest[i] = src[i];
    }
    dest[length] = '\0';
    return dest;
}

// --- Student Class (Retained) ---
class Student{
private:
    char* name; 
    int age;
    char grade;

public:
    Student(const Student& other){
        age = other.age;
        grade = other.grade;
        name = (char*)copyString(other.name);
    }

    Student(){
        name = (char*)copyString("Unknown");
        age = 10;
        grade = 'F';
    }

    Student(const char* sName, int sAge, char sGrade){
        age = sAge;
        grade = sGrade;
        name = (char*)copyString(sName);
    }
    
    Student& operator=(const Student& other){
        if (this == &other){
            return *this;
        }

        delete[] name;

        age = other.age;
        grade = other.grade;
        name = (char*)copyString(other.name); 

        return *this;
    }

    char getGrade() const { return grade; }
    void setGrade(char g){ grade = g; }

    int getAge() const { return age; }
    void setAge(int a){ age = a; }

    void getName(){ cout << name; }
    void setName(){
        if (name != nullptr){
            delete[] name;
            name = nullptr;
        }
        cout << "Enter the name of the Student: ";
        char temp[100];
        cin.getline(temp, 100);
        name = (char*)copyString(temp);
    }

    const char* getNameValue() const { return name; }

    void displayDetails(){
        cout << "---------------------------------------------------------------\n";
        cout << "The student's name is: " << name << "\n";
        cout << "He is " << getAge() << " years old. \n";
        cout << "His grade is: " << getGrade() << "\n";
        cout << "---------------------------------------------------------------\n";
    }

    void display(const Student& s){
        cout << "---------------------------------------------------------------\n";
        cout << "The student's name is: " << s.getNameValue() << "\n";
        cout << "He is " << s.getAge() << " years old. \n";
        cout << "His grade is: " << s.getGrade() << "\n";
        cout << "---------------------------------------------------------------\n";
    }

    ~Student(){
        delete[] name;
        name = nullptr;
    }
};

// --- Main Function with Aggressive Input Fixes ---
int main(){

    Student s1;
    s1.displayDetails();

    int age1;
    cout << "The Age of the student: ";
    cin >> age1;
    s1.setAge(age1);
    // FIX: Clear buffer after reading age1
    cin.ignore(1000, '\n'); 

    char grade1;
    cout << "The Grade of the student: ";
    cin >> grade1;
    s1.setGrade(grade1);

    // FIX: Clear buffer after reading grade1, essential before cin.getline() in setName()
    cin.ignore(1000, '\n'); 
    s1.setName();
    s1.displayDetails();

    int age2;
    cout << "The Age of the student: ";
    cin >> age2;
    // FIX: Clear buffer after reading age2
    cin.ignore(1000, '\n'); 

    char grade2;
    cout << "The Grade of the student: ";
    cin >> grade2;
    
    // FIX: Clear buffer after reading grade2
    cin.ignore(1000, '\n'); 

    Student s2("Ali", age2, grade2);
    s2.displayDetails();

    Student s3;
    s3.display(s2);

    s3 = s2;
    s3.displayDetails();

    return 0;
}