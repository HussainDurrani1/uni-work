#include <iostream>
#include "SList.h"
using namespace std;

void SList::insert(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { head = newNode; return; }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

void SList::displayList() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Deletes all nodes from 'node' onward
void SList::deleteHelper(Node*& node) {
    if (node == nullptr) return;

    deleteHelper(node->next);

    delete node;
    node = nullptr;
}

void SList::deleteList() {
    deleteHelper(head);
}

int main() {
    SList List;

    // Creating list: 5 -> 15 -> 25 -> 35
    List.insert(5);
    List.insert(15);
    List.insert(25);
    List.insert(35);

    cout << "Before deletion: ";
    List.displayList();

    List.deleteList();

    cout << "After deletion:  ";
    List.displayList();

    return 0;
}