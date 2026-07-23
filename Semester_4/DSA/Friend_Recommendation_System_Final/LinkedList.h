#pragma once
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
public:
    
    struct Node {
        T    data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

private:
    Node* head;
    int   count;

public:
    
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList() { clear(); }

    
    LinkedList(const LinkedList& other) : head(nullptr), count(0) {
        Node* cur = other.head;
        while (cur) {
            pushBack(cur->data);
            cur = cur->next;
        }
    }

    
    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this;
        clear();
        Node* cur = other.head;
        while (cur) {
            pushBack(cur->data);
            cur = cur->next;
        }
        return *this;
    }

    
    int  size()    const { return count; }
    bool isEmpty() const { return count == 0; }

    
    Node* getHead() const { return head; }

    
    
    void pushFront(const T& value) {
        Node* n  = new Node(value);
        n->next  = head;
        head     = n;
        count++;
    }

    
    void pushBack(const T& value) {
        Node* n = new Node(value);
        if (!head) { head = n; count++; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        count++;
    }

    
    
    bool contains(const T& value) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == value) return true;
            cur = cur->next;
        }
        return false;
    }

    
    Node* find(const T& value) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    
    
    
    bool remove(const T& value) {
        if (!head) return false;

        
        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            count--;
            return true;
        }

        
        Node* prev = head;
        Node* cur  = head->next;
        while (cur) {
            if (cur->data == value) {
                prev->next = cur->next;
                delete cur;
                count--;
                return true;
            }
            prev = cur;
            cur  = cur->next;
        }
        return false;
    }

    
    
    void clear() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        head  = nullptr;
        count = 0;
    }

    
    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
    }
};
