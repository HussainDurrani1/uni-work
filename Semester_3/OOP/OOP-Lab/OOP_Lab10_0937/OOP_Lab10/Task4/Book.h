#pragma once
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(string t, string a) {
        title = t;
        author = a;
    }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    void display() const {
        cout << "   - '" << title << "' by " << author << endl;
    }
};
