#include "Book.h"
#include <iostream>
using namespace std;

int main() {
    Book* myBookPtr = nullptr;

    char title[100];
    float price;

    cout << "Enter title of book: ";
    cin.getline(title, 100);

    cout << "Enter price of book: ";
    cin >> price;

    myBookPtr = new Book(title, price);

    myBookPtr->display();

    cout << "\nDeallocating the Book object..." << endl;
    delete myBookPtr;
    myBookPtr = nullptr;

    return 0;
}