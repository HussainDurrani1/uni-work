#include <iostream>
using namespace std;

int getLength(const char* src) {
    int length = 0;
    while (src[length] != '\0') {
        length++;
    }
    return length;
}

const char* copyString(const char* src) {
    int length = getLength(src);
    char* dest = new char[length + 1];
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
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

    dest[i++] = ' ';

    for (int j = 0; j < len2; j++) {
        dest[i++] = str2[j];
    }

    dest[i] = '\0';
    return dest;
}

class Book {
    const char* name;
    int pages;
    int id;
    static int count;

public:
    // Default Constructor
    Book() : pages(0), id(++count) {
        name = copyString("Unknown");
    }

    // Parameterized Constructor
    Book(const char* name, int page) : pages(page), id(++count) {
        this->name = copyString(name);
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& obj) : pages(obj.pages), id(++count) {
        this->name = copyString(obj.name);
    }

    // Display Function
    void display() const {
        cout << "Book ID: " << id << ", Name: " << name
             << ", Pages: " << pages << endl;
    }

    // Getters and Setters
    const char* getName() const { return name; }

    void setName(const char* n) {
        delete[] name;           
        name = copyString(n); 
    }

    int getID() const { return id; }

    int getPages() const { return pages; }
    void setPages(int p) { pages = p; }

    // Special Edition creator
    Book createSpecialEdition() const {
        return Book(concatenateString(name, "Special Edition"), pages);
    }

    // Combine two books
    Book combineBooks(const Book& obj) const {
        return Book(concatenateString(name, obj.name), pages + obj.pages);
    }

    // Static Function to show current count
    static void showCount() {
        cout << "Currently alive Book objects: " << count << endl;
    }

    // Destructor
    ~Book() {
        delete[] name;
        name = nullptr;
        count--;
    }
};

// Initialize static variable
int Book::count = 0;

int main() {
    char bookName[100];
    int pages;

    Book arr[2];
    Book::showCount();

    for (int i = 0; i < 2; i++) {
        cout << "\nEnter name of book " << i + 1 << ": ";
        cin.getline(bookName, 100);
        cout << "Enter the number of pages of book " << i + 1 << ": ";
        cin >> pages;
        arr[i].setName(bookName);
        arr[i].setPages(pages);
        cin.ignore();
    }

    cout << "\n--- Book Details ---\n";
    for (int i = 0; i < 2; i++) {
        arr[i].display();
    }

    cout << "\n--- Copy Constructor Example ---\n";
    Book obj = arr[0];
    obj.display();
    Book::showCount();

    cout << "\n--- Combined Book ---\n";
    Book combined(arr[0].combineBooks(arr[1]));
    combined.display();
    Book::showCount();

    cout << "\n--- Special Edition ---\n";
    Book specialEdition(arr[0].createSpecialEdition());
    specialEdition.display();
    Book::showCount();

    cout << "\n--- Program Ending ---\n";
    Book::showCount();

    return 0;
}