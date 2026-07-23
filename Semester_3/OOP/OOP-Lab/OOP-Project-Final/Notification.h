#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Notification {
private:
    char* message;
    char* timestamp; 
    bool isRead;

public:
    Notification(const char* msg, const char* time) {
        message = copyString(msg);
        timestamp = copyString(time);
        isRead = false;
    }

    Notification(const Notification& other) {
        message = copyString(other.message);
        timestamp = copyString(other.timestamp);
        isRead = other.isRead;
    }

    Notification& operator=(const Notification& other) {
        if (this != &other) {
            delete[] message;
            delete[] timestamp;

            message = copyString(other.message);
            timestamp = copyString(other.timestamp);
            isRead = other.isRead;
        }
        return *this;
    }

    ~Notification() {
        delete[] message;
        delete[] timestamp;
    }

    void markAsRead() { isRead = true; }

    void display() const {
        cout << "[" << timestamp << "] " << (isRead ? "(Read)" : "(New)") << ": " << message << endl;
    }

    bool getReadStatus() const { return isRead; }
};
