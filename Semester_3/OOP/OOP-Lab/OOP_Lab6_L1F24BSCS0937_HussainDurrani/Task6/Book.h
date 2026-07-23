#pragma once
#include <iostream>
using namespace std;
class Book {
private:
	char* title;
	float price;

	int getLength(const char* src) {
		int len = 0;
		while (src[len] != '\0') { len++; }
		return len;
	}

	char* copyString(const char* src) {
		int length = getLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}

public:
    Book() : price(0.0f) {
        title = copyString("Unknown");
        cout << "Default Book object created." << endl;
    }

    Book(const char* t, float p) : price(p) {
        if (t != nullptr) {
            title = copyString(t);
        }
        else {
            title = new char[1];
            title[0] = '\0';
        }
    }

    ~Book() {
        delete[] title;
    }

    void setTitle(const char* t) {
        delete[] title;

        if (t != nullptr) {
            title = copyString(t);
        }
        else {
            title = new char[1];
            title[0] = '\0';
        }
    }

    void setPrice(float p) {
        price = p;
    }

    void display() const {
        cout << "\nBook Details:" << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

};