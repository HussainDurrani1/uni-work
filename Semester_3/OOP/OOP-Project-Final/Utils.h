#pragma once

#include <iostream>
using namespace std;


int getStrLength(const char* str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* copyString(const char* str)
{
    if (str == nullptr) return nullptr;
    int len = getStrLength(str);
    char* temp = new char[len + 1];

    for (int i = 0; i < len; i++) {
        temp[i] = str[i];
    }

    temp[len] = '\0';
    return temp;
}

char* intToString(int num) {
    if (num == 0) return copyString("0");

    int temp = num;
    int len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }

    char* str = new char[len + 1];
    str[len] = '\0';

    temp = num;
    for (int i = len - 1; i >= 0; i--) {
        str[i] = (temp % 10) + '0';
        temp /= 10;
    }
    return str;
}

char* concatString(const char* s1, const char* s2) {
    int len1 = getStrLength(s1);
    int len2 = getStrLength(s2);

    char* result = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++) {
        result[i] = s1[i];
    }
    for (int i = 0; i < len2; i++) {
        result[len1 + i] = s2[i];
    }
    result[len1 + len2] = '\0';
    return result;
}

bool compareString(const char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) return s1 == s2;
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}
