void saveToCSV(Student* students[], int size, const char* filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr) {
            file << students[i]->getName() << ","
                 << students[i]->getRollNo() << ","
                 << students[i]->getMarks() << ","
                 << students[i]->getGrade() << "\n";
        }
    }
    file.close();
    cout << "Data saved to CSV successfully.\n";
}
else if (choice == 3) {
    saveToCSV(students, Student::getStudentCount(), "students.csv");
}

//----------------------------------------------------------------------

void loadFromCSV(Student* students[], int &size, const char* filename, int maxCapacity) {
    ifstream file(filename);
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    char line[300];
    int loadedCount = 0;
    
    char name[100], roll[100], gradeChar;
    int marks;

    while (file.getline(line, 300)) {

        // parse CSV line
        if (sscanf(line, "%99[^,],%99[^,],%d,%c", name, roll, &marks, &gradeChar) == 4) { // WTF is this
            if (size < maxCapacity) {
                students[size++] = new Student(name, roll, marks, gradeChar);
                loadedCount++;
            }
        }
    }
    file.close();
    cout << loadedCount << " students loaded from CSV.\n";
}

else if (choice == 4) {
    loadFromCSV(students, Student::getStudentCount(), "students.csv", MAX_STUDENT_CAPACITY);
}

// -------------------------------------------------------------------------------------------

void saveToBinary(Student* students[], int size, const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening binary file.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr) {
            int nameLen = strlen(students[i]->getName()) + 1;
            int rollLen = strlen(students[i]->getRollNo()) + 1;
            file.write((char*)&nameLen, sizeof(int));
            file.write(students[i]->getName(), nameLen);
            file.write((char*)&rollLen, sizeof(int));
            file.write(students[i]->getRollNo(), rollLen);
            file.write((char*)&students[i]->getMarks(), sizeof(int));
            file.write((char*)&students[i]->getGrade(), sizeof(char));
        }
    }

    file.close();
    cout << "Data saved to binary successfully.\n";
}

else if (choice == 5) {
    saveToBinary(students, Student::getStudentCount(), "students.bin");
}

//----------------------------------------------------------------------------------------

void loadFromBinary(Student* students[], int &size, const char* filename, int maxCapacity) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Binary file not found.\n";
        return;
    }

    while (file && size < maxCapacity) {
        int nameLen, rollLen;
        if (!file.read((char*)&nameLen, sizeof(int))) break;
        char* name = new char[nameLen];
        file.read(name, nameLen);

        file.read((char*)&rollLen, sizeof(int));
        char* roll = new char[rollLen];
        file.read(roll, rollLen);

        int marks;
        char grade;
        file.read((char*)&marks, sizeof(int));
        file.read((char*)&grade, sizeof(char));

        students[size++] = new Student(name, roll, marks, grade);

        delete[] name;
        delete[] roll;
    }

    file.close();
    cout << "Binary data loaded. Total students: " << size << "\n";
}
else if (choice == 6) {
    loadFromBinary(students, Student::getStudentCount(), "students.bin", MAX_STUDENT_CAPACITY);
}

//--------------------------------------------------------------------------------------------------

void searchStudent(Student* students[], int size) {
    cout << "Enter Roll No or Partial Name to search: ";
    char query[100];
    cin.getline(query, 100);

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr) {
            if (strstr(students[i]->getName(), query) != nullptr || 
                strcmp(students[i]->getRollNo(), query) == 0) {
                students[i]->display();
                found = true;
            }
        }
    }
    if (!found) cout << "No matching student found.\n";
}

else if (choice == 7) {
    searchStudent(students, Student::getStudentCount());
}


//-----------------------------------------------------------------------------------------------------

void updateStudent(Student* students[], int size) {
    cout << "Enter Roll No of student to update: ";
    char roll[100];
    cin.getline(roll, 100);

    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr && strcmp(students[i]->getRollNo(), roll) == 0) {
            cout << "Updating Student: \n";
            students[i]->setName();
            students[i]->setMarks();
            students[i]->setGrade();
            cout << "Student updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

else if (choice == 8) {
    updateStudent(students, Student::getStudentCount());
}


//-----------------------------------------------------------------------------------------------------

void deleteStudent(Student* students[], int &size) {
    cout << "Enter Roll No of student to delete: ";
    char roll[100];
    cin.getline(roll, 100);

    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr && strcmp(students[i]->getRollNo(), roll) == 0) {
            delete students[i];
            // shift remaining left
            for (int j = i; j < size - 1; j++) {
                students[j] = students[j + 1];
            }
            students[size - 1] = nullptr;
            size--;
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

else if (choice == 9) {
    deleteStudent(students, Student::getStudentCount());
}

//----------------------------------------------------------------------------------------------------