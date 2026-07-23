#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class
class SList {
private:
    Node* head;

    bool searchHelper(Node* head, int target);

public:
    SList() : head(nullptr) {}

    void insert(int val);

    bool searchList(int target);

    void displayList();

    ~SList();
};