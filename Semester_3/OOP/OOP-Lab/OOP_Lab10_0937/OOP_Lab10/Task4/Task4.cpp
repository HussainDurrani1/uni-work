#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main() {
    int count;
    string title, author;

    Library myLibrary;
    cout << "--- Create Your Library ---\n";

    cout << "How many books to add? (Max 10): ";
    cin >> count;
    cin.ignore(); 

    if (count > 10) count = 10;

    for (int i = 0; i < count; i++) {
        cout << "\nEnter details for Book " << i + 1 << ":\n";
        cout << "Title: ";
        cin >> title;
        cout << "Author: ";
        cin >> author;

        Book* newBook = new Book(title, author);

        myLibrary.addBook(newBook);
    }

    cout << "\n----------------------------------------\n";
    cout << "FINAL LIBRARY CATALOG\n";
    cout << "----------------------------------------\n";
    myLibrary.display();

    return 0;
}