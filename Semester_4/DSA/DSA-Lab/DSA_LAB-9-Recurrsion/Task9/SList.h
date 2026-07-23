#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class with recursive deletion
class SList {
private:
    Node* head;

    void deleteHelper(Node*& node);

public:
    SList() : head(nullptr) {}

    void insert(int val);

    void displayList();

    void deleteList();
};