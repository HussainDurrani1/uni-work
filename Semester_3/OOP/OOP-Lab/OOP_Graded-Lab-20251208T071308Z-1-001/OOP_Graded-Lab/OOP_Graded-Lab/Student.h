#pragma once
#include <iostream>
using namespace std;

int getLength(const char* src) {
    int length = 0;
    while (src[length] != '\0') { length++; }
    return length;
}

const char* copyString(const char* src) {
    int length = getLength(src);
    char* dest = new char[length + 1];
    for (int i = 0; i < length; i++) { dest[i] = src[i]; }
    dest[length] = '\0';
    return dest;
}

const char* concatenateString(const char* str1, const char* str2) {
    int len1 = getLength(str1);
    int len2 = getLength(str2);
    char* dest = new char[len1 + len2 + 2];

    int i = 0;
    for (; i < len1; i++) {
        dest[i] = str1[i];
    }
    char temp = ' ';
    dest[i++] = temp;
    for (int j = 0; j < len2; j++) {
        dest[i++] = str2[j];
    }
    dest[i] = '\0';
    return dest;
}

class Book{
    const char* name;
    int pages;
    int id;
    static int count;

public:
    Book(): pages(0), id(++count), name(nullptr) {}

    Book(const Book& obj) : pages(obj.getPages()), id(++count){
        this->name = obj.getName();
    }

    Book(const char* name, int page): pages(page), id(++count){
        this->name = copyString(name);
    }

    void display() const{
        cout << "Book ID: " << id << ", Name: " << name << ", Pages: " << pages << endl;
    }

    const char* getName() const{
        return copyString(name);
    }

    int getID() const{
        return id;
    }

    int getPages() const{
        return pages;
    }

    void setPages(int p){
        pages = p;
    }

    void setName(const char* n){
        name = copyString(n);
    }

    Book createSpecialEdition() const {
        return Book((concatenateString(name, "Special Edition")), this->getPages());
    }

    Book combineBooks(const Book& obj) const {
        return Book((concatenateString(name, obj.getName())), obj.getPages() + this->getPages());
    }

    ~Book(){
        delete[] name;
        name = nullptr;
        count--;
    }
};