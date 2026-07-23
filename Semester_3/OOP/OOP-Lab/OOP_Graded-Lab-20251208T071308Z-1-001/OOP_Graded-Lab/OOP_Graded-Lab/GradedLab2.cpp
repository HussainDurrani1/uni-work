#include "Student.h"
#include <iostream>
using namespace std;

int Book::count = 0;

int main() {

    char bookName[100];
    int pages;

    Book arr[2];

    for (int i = 0; i < 2; i++) {
        cout << "\nEnter name of book " << i + 1 << ": ";
        cin.getline(bookName, 100);
        cout << "Enter the no. of pages of book " << i + 1 << ": ";
        cin >> pages;
        arr[i].setName(bookName);
        arr[i].setPages(pages);
        cin.ignore();
    }

    for (int i = 0; i < 2; i++) {
        arr[i].display();
    }

    Book obj = arr[0];
    cout << "Copy Constructor: ";
    obj.display();

    Book combined = arr[0].combineBooks(arr[1]);
    cout << "Combined Book: ";
    combined.display();

    Book specialEdition = arr[0].createSpecialEdition();
    cout << "Special Edition: ";
    specialEdition.display();

    return 0;
}