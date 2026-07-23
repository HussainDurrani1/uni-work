#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <iomanip>

using namespace std;

class User {
public:
    int id;
    string name;
    vector<string> interests;

    User() : id(0), name("") {}

    User(int id, string name, vector<string> interests)
        : id(id), name(name), interests(interests) {}

    unordered_set<string> interestSet() const {
        return unordered_set<string>(interests.begin(), interests.end());
    }

    void display() const {
        cout << "+----------------------------------+\n";
        cout << "| " << left << setw(32) << ("User ID: " + to_string(id)) << " |\n";
        cout << "| " << left << setw(32) << ("Name   : " + name) << " |\n";

        string text = "Interests: ";
        for (int i = 0; i < (int)interests.size(); i++) {
            text += interests[i];
            if (i + 1 < (int)interests.size()) text += ", ";
        }

        cout << "| " << left << setw(32) << text << " |\n";
        cout << "+----------------------------------+\n";
    }
};
