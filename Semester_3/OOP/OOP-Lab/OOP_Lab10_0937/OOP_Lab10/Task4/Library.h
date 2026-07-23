#pragma once
#include <iostream>
#include "Book.h"
using namespace std;

class Library {
private:
    Book* books[10]; 
    int bookCount;

public:
    Library() {
        bookCount = 0;
        for (int i = 0; i < 10; i++) {
            books[i] = nullptr;
        }
    }

    void addBook(Book* b) {
        if (bookCount < 10) {
            books[bookCount] = b;
            bookCount++;
        }
        else {
            cout << "Library is full (Max 10 books).\n";
        }
    }

    int getBookCount() const { return bookCount; }

    void display() const {
        cout << "Library Collection (" << bookCount << " books):\n";
        for (int i = 0; i < bookCount; i++) {
            books[i]->display();
        }
    }
};