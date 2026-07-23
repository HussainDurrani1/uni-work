#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Rating {
private:
    float score; 
    char* comment;

public:
    
    Rating(float s, const char* c) {
        score = s;
        comment = copyString(c);
    }

    Rating(const Rating& other) {
        score = other.score;
        comment = copyString(other.comment);
    }

    Rating& operator=(const Rating& other) {
        if (this != &other) {
            delete[] comment;
            score = other.score;
            comment = copyString(other.comment);
        }
        return *this;
    }

    ~Rating() {
        delete[] comment;
    }

    float getScore() const { return score; }
    const char* getComment() const { return comment; }

    void display() const {
        cout << "Rating: " << score << "/5.0" << endl;
        cout << "Comment: " << comment << endl;
    }
};
