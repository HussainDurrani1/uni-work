#pragma once
#include <iostream>

using namespace std;

void clearInput() {
    cin.ignore();
}

void getStringInput(const char* prompt, char* buffer, int size = 100) {
    cout << prompt;
    char temp[100];
    cin.getline(temp, 100);

    int i = 0;
    while (temp[i] != '\0' && i < size - 1) {
        buffer[i] = temp[i];
        i++;
    }
    buffer[i] = '\0';
}
