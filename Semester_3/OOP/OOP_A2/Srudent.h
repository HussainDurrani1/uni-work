#pragma once

#include <iostream>
#include <fstream> 
using namespace std;

static char myToLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

static int getStrLength(const char* str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

static char* copyString(const char* str) {
    if (!str) return nullptr;
    int len = getStrLength(str);
    char* dest = new char[len + 1];
    for (int i = 0; i < len; i++) {
        dest[i] = str[i];
    }
    dest[len] = '\0';
    return dest;
}

static char* trim(const char* str) {
    if (!str) return copyString("");
    int start = 0;
    int end = getStrLength(str) - 1;

    while (start <= end && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }

    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\r')) {
        end--;
    }

    int new_len = end - start + 1;
    if (new_len <= 0) return copyString("");

    char* trimmed = new char[new_len + 1];
    for (int i = 0; i < new_len; i++) {
        trimmed[i] = str[start + i];
    }
    trimmed[new_len] = '\0';
    return trimmed;
}

static int stringToInt(const char* str) {
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

static float stringToFloat(const char* str) {
    float integer_part = 0.0f;
    float fractional_part = 0.0f;
    float divisor = 1.0f;
    bool found_dot = false;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '.') {
            found_dot = true;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            if (!found_dot) {
                integer_part = integer_part * 10.0f + (float)(str[i] - '0');
            }
            else {
                divisor *= 10.0f;
                fractional_part = fractional_part + (float)(str[i] - '0') / divisor;
            }
        }
        i++;
    }
    return integer_part + fractional_part;
}


class Student {
private:
    int id;
    char* name;
    int age;
    float gpa;

    static int totalStudents;

    void printFormattedGPA() const {
        float rounded_gpa = gpa + 0.005f;
        int int_part = (int)rounded_gpa;
        int frac_part = (int)((rounded_gpa - (float)int_part) * 100.0f);

        cout << int_part << ".";
        if (frac_part < 10) cout << "0";
        cout << frac_part;
    }

public:

    Student() {
        id = 0;
        name = copyString("Unknown");
        age = 16;
        gpa = 0;
        totalStudents++;
    }

    Student(int _id, const char* _name, int _age, float _gpa) {
        setID(_id);
        setName(_name);
        setAge(_age);
        setGPA(_gpa);
        totalStudents++;
    }

    Student(const Student& s) {
        id = s.id;
        age = s.age;
        gpa = s.gpa;
        name = copyString(s.name);
        totalStudents++;
    }

    ~Student() {
        delete[] name;
        name = nullptr;
        totalStudents--;
    }

    void display() const {
        cout.width(5); cout << id; cout << " | ";
        cout.width(30); cout << name; cout << " | ";
        cout.width(4); cout << age; cout << " | ";
        printFormattedGPA(); cout << endl;
    }

    int getID() const { return id; }
    const char* getName() const { return name; }
    int getAge() const { return age; }
    float getGPA() const { return gpa; }
    static int getTotalStudents() { return totalStudents; }

    void setID(int _id) {
        if (_id > 0) {
            id = _id;
        }
    }

    void setName(const char* _name) {
        char* trimmed_name = trim(_name);
        if (trimmed_name[0] != '\0') {
            delete[] name;
            name = trimmed_name;
        }
        else {
            delete[] trimmed_name;
        }
    }

    void setAge(int _age) {
        if (_age >= 16) {
            age = _age;
        }
    }

    void setGPA(float _gpa) {
        if (_gpa >= 0 && _gpa <= 4) {
            gpa = _gpa;
        }
    }

    void toCSV(ofstream& fout) const {

        float rounded_gpa = gpa + 0.005f;
        int int_part = (int)rounded_gpa;
        int frac_part = (int)((rounded_gpa - (float)int_part) * 100.0f);

        fout << id << "," << name << "," << age << ",";
        fout << int_part << ".";
        if (frac_part < 10) fout << "0";
        fout << frac_part << "\n";
    }

    bool fromCSV(const char* line) {
        if (!line) return false;

        char field_buffer[100];
        int line_index = 0;
        int current_field = 0;

        int tmpId = 0, tmpAge = 0;
        float tmpGPA = 0.0f;
        char tmpName[100] = "";

        while (line[line_index] != '\0' && current_field < 4) {
            int field_index = 0;
            while (line[line_index] != ',' && line[line_index] != '\0' && line[line_index] != '\r') {
                if (field_index < 99) {
                    field_buffer[field_index++] = line[line_index];
                }
                line_index++;
            }
            field_buffer[field_index] = '\0';

            char* trimmed_field = trim(field_buffer);

            if (current_field == 0) { // ID
                tmpId = stringToInt(trimmed_field);
            }
            else if (current_field == 1) { // Name
                for (int k = 0; k < field_index + 1; ++k) tmpName[k] = trimmed_field[k];
            }
            else if (current_field == 2) { // Age
                tmpAge = stringToInt(trimmed_field);
            }
            else if (current_field == 3) { // GPA
                tmpGPA = stringToFloat(trimmed_field);
            }
            delete[] trimmed_field;

            if (line[line_index] == ',') {
                line_index++;
            }
            current_field++;
        }

        if (current_field == 4 && tmpId > 0 && tmpName[0] != '\0' && tmpAge >= 16 && tmpGPA >= 0 && tmpGPA <= 4) {
            id = tmpId;
            delete[] name;
            name = copyString(tmpName);
            age = tmpAge;
            gpa = tmpGPA;
            return true;
        }
        return false;
    }

    void writeBinary(ofstream& fout) const {
        fout.write(reinterpret_cast<const char*>(&id), sizeof(id));
        fout.write(reinterpret_cast<const char*>(&age), sizeof(age));
        fout.write(reinterpret_cast<const char*>(&gpa), sizeof(gpa));

        int len = getStrLength(name);
        fout.write(reinterpret_cast<const char*>(&len), sizeof(len));
        fout.write(name, len + 1);
    }

    bool readBinary(ifstream& fin) {
        int len;

        if (!fin.read(reinterpret_cast<char*>(&id), sizeof(id))) return false;
        if (!fin.read(reinterpret_cast<char*>(&age), sizeof(age))) return false;
        if (!fin.read(reinterpret_cast<char*>(&gpa), sizeof(gpa))) return false;

        if (!fin.read(reinterpret_cast<char*>(&len), sizeof(len))) return false;

        if (len < 0 || len >= 100) return false;

        char* buffer = new char[len + 1];

        if (!fin.read(buffer, len + 1)) {
            delete[] buffer;
            return false;
        }

        delete[] name;
        name = buffer;

        if (id > 0 && name[0] != '\0' && age >= 16 && gpa >= 0 && gpa <= 4) {
            return true;
        }
        return false;
    }

    bool matchName(const char* partial) const {
        int lenPartial = getStrLength(partial);
        int lenName = getStrLength(name);
        for (int i = 0; i <= lenName - lenPartial; i++) {
            bool match = true;
            for (int j = 0; j < lenPartial; j++) {
                if (myToLower(name[i + j]) != myToLower(partial[j])) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};