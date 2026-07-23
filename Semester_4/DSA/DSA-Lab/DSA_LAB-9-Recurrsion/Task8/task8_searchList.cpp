#include <iostream>
#include "SList.h"
using namespace std;

// Insert a value at the end of the list
void SList::insert(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { head = newNode; return; }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

// Display the list
void SList::displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Private recursive helper: searches from given node onward
bool SList::searchHelper(Node* node, int target) {
    if (node == nullptr) return false;

    if (node->data == target) return true;

    // Search the rest of the list
    return searchHelper(node->next, target);
}

bool SList::searchList(int target) {
    return searchHelper(head, target);
}

SList::~SList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

int main() {
    SList List;

    // Creating list: 10 -> 20 -> 30 -> 40 -> 50
    List.insert(10);
    List.insert(20);
    List.insert(30);
    List.insert(40);
    List.insert(50);

    cout << "List: ";
    List.displayList();
    cout << endl;

    cout << "searchList(30) = " << List.searchList(30) << "  (Expected: 1 / Found)"     << endl;
    cout << "searchList(10) = " << List.searchList(10) << "  (Expected: 1 / Found)"     << endl;
    cout << "searchList(50) = " << List.searchList(50) << "  (Expected: 1 / Found)"     << endl;
    cout << "searchList(99) = " << List.searchList(99) << "  (Expected: 0 / Not Found)" << endl;

    return 0;
}