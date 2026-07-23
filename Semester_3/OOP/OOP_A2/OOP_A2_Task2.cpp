#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

void addStudent(Student**& registry, int& count, int& capacity);
void displayAll(Student** registry, int count);
void saveToCSV(Student** registry, int count);
void loadFromCSV(Student**& registry, int& count, int& capacity);
void saveToBinary(Student** registry, int count);
void loadFromBinary(Student**& registry, int& count, int& capacity);
void searchStudent(Student** registry, int count);
void updateStudent(Student** registry, int count);
void deleteStudent(Student**& registry, int& count);
void printSummary(int count);

static int stringToInt_local(const char* str) {
    int res = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - '0');
        }
        else {
            break;
        }
        i++;
    }
    return res;
}

static int getIntLength(int num) {
    if (num == 0) return 1;
    int count = 0;
    if (num < 0) { count++; num = -num; }
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}


int Student::totalStudents = 0;

int main() {
    int count = 0;
    int capacity = 10;
    Student** registry = new Student * [capacity];

    cout << "--- Student Registry System Initialized ---\n";
    cout << "Initial capacity: " << capacity << " students.\n";

    int choice = 0;
    do {
        cout << "\n========================================\n";
        cout << "STUDENT REGISTRY MENU\n";
        cout << "1. Add Student (Q1)\n";
        cout << "2. Display All (Q1)\n";
        cout << "3. Save to CSV (Q2)\n";
        cout << "4. Load from CSV (Q2)\n";
        cout << "5. Save to Binary (Q3)\n";
        cout << "6. Load from Binary (Q3)\n";
        cout << "7. Search (by ID / Name) (Q4)\n";
        cout << "8. Update (by ID) (Q4)\n";
        cout << "9. Delete (by ID) (Q4)\n";
        cout << "10. Exit\n";
        printSummary(count);
        cout << "Enter your Choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: addStudent(registry, count, capacity); break;
        case 2: displayAll(registry, count); break;
        case 3: saveToCSV(registry, count); break;
        case 4: loadFromCSV(registry, count, capacity); break;
        case 5: saveToBinary(registry, count); break;
        case 6: loadFromBinary(registry, count, capacity); break;
        case 7: searchStudent(registry, count); break;
        case 8: updateStudent(registry, count); break;
        case 9: deleteStudent(registry, count); break;
        case 10: cout << "Exiting system. Goodbye!\n"; break;
        default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    cout << "\n--- Memory Cleanup ---\n";
    for (int i = 0; i < count; i++) {
        if (registry[i] != nullptr) {
            delete registry[i];
        }
    }
    delete[] registry;
    cout << "Registry cleared. Program terminated.\n";

    return 0;
}

void printSummary(int count) {
    cout << "Total Students Registered: " << count << " (Total Objects: " << Student::getTotalStudents() << ")\n";
}

void addStudent(Student**& registry, int& count, int& capacity) {
    int id, age;
    float gpa;
    char name_buffer[100];

    cout << "\n--- ADD NEW STUDENT ---\n";

    if (count == capacity) {
        int new_capacity = capacity * 2;
        Student** new_registry = new Student * [new_capacity];

        for (int i = 0; i < count; i++) {
            new_registry[i] = registry[i];
        }
        for (int i = count; i < new_capacity; i++) {
            new_registry[i] = nullptr;
        }

        delete[] registry;
        registry = new_registry;
        capacity = new_capacity;
        cout << "Registry resized. New capacity: " << capacity << ".\n";
    }

    bool valid = false;
    do {
        cout << "Enter Student ID (> 0, non-zero): ";
        if (!(cin >> id)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid ID format.\n"; continue; }

        bool id_exists = false;
        for (int i = 0; i < count; i++) {
            if (registry[i] && registry[i]->getID() == id) {
                id_exists = true;
                break;
            }
        }
        if (id_exists) { cout << "ID already exists. Please enter a unique ID.\n"; continue; }

        cout << "Enter Name (non-empty): ";
        cin.ignore(1000, '\n');
        cin.getline(name_buffer, 100);

        cout << "Enter Age (>= 16): ";
        if (!(cin >> age)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Age format.\n"; continue; }

        cout << "Enter GPA (0.0 to 4.0): ";
        if (!(cin >> gpa)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid GPA format.\n"; continue; }

        Student temp(id, name_buffer, age, gpa);
        if (temp.getID() == id && temp.getName()[0] != '\0' && temp.getAge() == age && temp.getGPA() == gpa) {
            registry[count] = new Student(id, name_buffer, age, gpa);
            count++;
            cout << "Student added successfully.\n";
            valid = true;
        }
        else {
            cout << "Invalid input detected (ID, Name, Age, or GPA validation failed). Try again.\n";
        }

    } while (!valid);
}

void displayAll(Student** registry, int count) {
    cout << "\n--- DISPLAY ALL STUDENTS ---\n";
    if (count == 0) {
        cout << "Registry is empty.\n";
        return;
    }

    cout << "ID   " << " | "
        << "NAME                          " << " | "
        << "AGE " << " | "
        << "GPA " << endl;
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        if (registry[i] != nullptr) {
            registry[i]->display();
        }
    }
    cout << "------------------------------------------------------\n";
}

void saveToCSV(Student** registry, int count) {
    const char* filename = "registry_data.csv";
    char confirmation;

    cout << "\n[Q2: CSV I/O]\n";
    cout << "WARNING: This will overwrite " << filename << ". Continue? (y/n): ";
    cin >> confirmation;
    if (myToLower(confirmation) != 'y') {
        cout << "Save cancelled.\n";
        return;
    }

    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }

    ofs << "ID,Name,Age,GPA\n";

    for (int i = 0; i < count; i++) {
        if (registry[i] != nullptr) {
            registry[i]->toCSV(ofs);
        }
    }

    ofs.close();
    cout << "Successfully saved " << count << " records to " << filename << endl;
}

void loadFromCSV(Student**& registry, int& count, int& capacity) {
    const char* filename = "registry_data.csv";
    char confirmation;

    cout << "\n[Q2: CSV I/O]\n";
    cout << "WARNING: Loading will **REPLACE** all current data. Continue? (y/n): ";
    cin >> confirmation;
    if (myToLower(confirmation) != 'y') {
        cout << "Load cancelled.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        delete registry[i];
    }
    count = 0;

    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Error opening file for reading: " << filename << endl;
        return;
    }

    char line[256];
    ifs.getline(line, 256);

    int loaded_count = 0;
    int invalid_count = 0;

    while (ifs.getline(line, 256)) {
        Student* temp_student = new Student();

        if (temp_student->fromCSV(line)) {
            if (count == capacity) {
                Student** new_registry = new Student * [capacity * 2];
                for (int i = 0; i < count; i++) {
                    new_registry[i] = registry[i];
                }
                delete[] registry;
                registry = new_registry;
                capacity *= 2;
            }

            registry[count] = temp_student;
            count++;
            loaded_count++;
        }
        else {
            delete temp_student;
            invalid_count++;
        }
    }

    ifs.close();
    cout << "Load Summary:\n";
    cout << "  - Successfully loaded: " << loaded_count << " records.\n";
    cout << "  - Skipped invalid lines: " << invalid_count << ".\n";
    cout << "New total students: " << count << endl;
}

void saveToBinary(Student** registry, int count) {
    const char* filename = "registry_data.bin";
    char confirmation;

    cout << "\n[Q3: Binary I/O] ";
    cout << "WARNING: This will overwrite " << filename << ". Continue? (y/n): ";
    cin >> confirmation;
    if (myToLower(confirmation) != 'y') {
        cout << "Save cancelled.\n";
        return;
    }

    ofstream ofs(filename, ios::binary | ios::trunc);
    if (!ofs.is_open()) {
        cout << "Error opening binary file for writing: " << filename << endl;
        return;
    }

    char count_buffer[10];
    int temp = count;
    int i = 0;

    if (temp == 0) { count_buffer[i++] = '0'; }
    else {
        while (temp > 0) {
            count_buffer[i++] = (char)(temp % 10 + '0');
            temp /= 10;
        }
        for (int j = 0; j < i / 2; j++) { char t = count_buffer[j]; count_buffer[j] = count_buffer[i - 1 - j]; count_buffer[i - 1 - j] = t; }
    }
    count_buffer[i] = '\0';

    ofs << count_buffer << "\n";

    for (int i = 0; i < count; i++) {
        if (registry[i] != nullptr) {
            registry[i]->writeBinary(ofs);
        }
    }

    if (ofs.fail()) {
        cout << "Error writing to binary file.\n";
    }
    else {
        cout << "Successfully saved " << count << " records to " << filename << " (Binary format).\n";
    }
    ofs.close();
}

void loadFromBinary(Student**& registry, int& count, int& capacity) {
    const char* filename = "registry_data.bin";
    char confirmation;

    cout << "\n[Q3: Binary I/O]\n";
    cout << "WARNING: Loading will **REPLACE** all current data. Continue? (y/n): ";
    cin >> confirmation;
    if (myToLower(confirmation) != 'y') {
        cout << "Load cancelled.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        delete registry[i];
    }
    count = 0;

    ifstream ifs(filename, ios::binary);
    if (!ifs.is_open()) {
        cout << "Error opening binary file for reading: " << filename << endl;
        return;
    }

    char count_line[10];
    ifs.getline(count_line, 10);
    int expected_count = stringToInt_local(count_line);

    if (expected_count == 0 && ifs.fail()) {
        cout << "Error reading file header or file is empty.\n";
        ifs.close();
        return;
    }

    int loaded_count = 0;
    while (loaded_count < expected_count && ifs.peek() != EOF) {
        if (count == capacity) {
            Student** new_registry = new Student * [capacity * 2];
            for (int i = 0; i < count; i++) {
                new_registry[i] = registry[i];
            }
            delete[] registry;
            registry = new_registry;
            capacity *= 2;
        }

        Student* temp_student = new Student();
        if (temp_student->readBinary(ifs)) {
            registry[count] = temp_student;
            count++;
            loaded_count++;
        }
        else {
            cout << "Error reading binary record (may be EOF or corrupted data).\n";
            delete temp_student;
            break;
        }
    }

    ifs.close();
    cout << "Successfully loaded " << loaded_count << " records from binary file.\n";
    cout << "New total students: " << count << endl;
}

void searchStudent(Student** registry, int count) {
    if (count == 0) {
        cout << "Registry is empty.\n";
        return;
    }

    int search_type;
    cout << "\n--- SEARCH ---\n";
    cout << "Search by:\n1. ID\n2. Partial Name\nChoice: ";
    if (!(cin >> search_type)) { cin.clear(); cin.ignore(1000, '\n'); return; }

    cout << "Search Results:\n";
    bool found = false;

    if (search_type == 1) {
        int id;
        cout << "Enter ID to search: ";
        if (!(cin >> id)) { cin.clear(); cin.ignore(1000, '\n'); return; }

        for (int i = 0; i < count; i++) {
            if (registry[i] != nullptr && registry[i]->getID() == id) {
                registry[i]->display();
                found = true;
                break;
            }
        }
    }
    else if (search_type == 2) {
        char name_query[100];
        cout << "Enter partial name to search (case-insensitive): ";
        cin.ignore(1000, '\n');
        cin.getline(name_query, 100);

        cout << "ID   " << " | "
            << "NAME                          " << " | "
            << "AGE " << " | "
            << "GPA " << endl;
        cout << "------------------------------------------------------\n";

        for (int i = 0; i < count; i++) {
            if (registry[i] != nullptr && registry[i]->matchName(name_query)) {
                registry[i]->display();
                found = true;
            }
        }
    }
    else {
        cout << "Invalid search type.\n";
        return;
    }

    if (!found) {
        cout << "No matching student found.\n";
    }
}

void updateStudent(Student** registry, int count) {
    if (count == 0) {
        cout << "Registry is empty.\n";
        return;
    }

    int id;
    cout << "\n--- UPDATE STUDENT ---\n";
    cout << "Enter ID of student to update: ";
    if (!(cin >> id)) { cin.clear(); cin.ignore(1000, '\n'); return; }

    Student* target = nullptr;
    for (int i = 0; i < count; i++) {
        if (registry[i] != nullptr && registry[i]->getID() == id) {
            target = registry[i];
            break;
        }
    }

    if (!target) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    cout << "Found student:\n";
    target->display();

    int field_choice;
    cout << "\nWhich field to update?\n1. Name\n2. Age\n3. GPA\nChoice: ";
    if (!(cin >> field_choice)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid choice.\n"; return; }

    bool updated = false;
    if (field_choice == 1) {
        char new_name[100];
        cout << "Enter new Name: ";
        cin.ignore(1000, '\n');
        cin.getline(new_name, 100);

        char* original_name = copyString(target->getName());
        target->setName(new_name);

        if (getStrLength(target->getName()) > 0 && target->getName() != original_name) {
            updated = true;
        }
        else {
            cout << "Update failed: Invalid name (must be non-empty).\n";
        }
        delete[] original_name;

    }
    else if (field_choice == 2) {
        int new_age;
        cout << "Enter new Age (>= 16): ";
        if (cin >> new_age && new_age >= 16) {
            target->setAge(new_age);
            updated = true;
        }
        else {
            cout << "Update failed: Invalid age (must be >= 16).\n";
        }
    }
    else if (field_choice == 3) {
        float new_gpa;
        cout << "Enter new GPA (0.0 to 4.0): ";
        if (cin >> new_gpa && new_gpa >= 0.0f && new_gpa <= 4.0f) {
            target->setGPA(new_gpa);
            updated = true;
        }
        else {
            cout << "Update failed: Invalid GPA (must be 0.0-4.0).\n";
        }
    }

    if (updated) {
        cout << "Update successful. New details:\n";
        target->display();
    }
}

void deleteStudent(Student**& registry, int& count) {
    if (count == 0) {
        cout << "Registry is empty.\n";
        return;
    }

    int id;
    cout << "\n--- DELETE STUDENT ---\n";
    cout << "Enter ID of student to delete: ";
    if (!(cin >> id)) { cin.clear(); cin.ignore(1000, '\n'); return; }

    int delete_index = -1;
    for (int i = 0; i < count; i++) {
        if (registry[i] != nullptr && registry[i]->getID() == id) {
            delete_index = i;
            break;
        }
    }

    if (delete_index == -1) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    char confirmation;
    cout << "Confirm deletion of student ID " << id << "? (y/n): ";
    cin >> confirmation;

    if (myToLower(confirmation) == 'y') {
        delete registry[delete_index];

        for (int i = delete_index; i < count - 1; i++) {
            registry[i] = registry[i + 1];
        }

        count--;
        registry[count] = nullptr;

        cout << "Student ID " << id << " deleted and registry compacted.\n";
    }
    else {
        cout << "Deletion cancelled.\n";
    }
}