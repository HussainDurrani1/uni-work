#include<iostream>
#include <string>
using namespace std;

class Node {
public:
	int candID;
	string name;
	Node* next;
	Node* prev;

	Node(int id, string n) : candID(id), name(n) {
		next = prev = nullptr;
	}
};

void addCandidate(Node*& head, int id, string n) {
	Node* newNode = new Node(id, n);
	if (head == nullptr) { head = newNode; return; }
	Node* temp = head;
	while (temp->next != nullptr) temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

void display(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << "[" << temp->candID << ":" << temp->name << "] <-> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int findLength(Node*& head) {
	int count = 0;
	Node* temp = head->next;
	count++;
	while (temp->next != nullptr){ temp = temp->next; count++; }
	return count;
}

//void ReversePairsOf2(LinkedList &l) {
//    Node* first = l.getFirst();
//    Node* prev = nullptr;
//    Node* c1 = first;
//    Node* c2 = first->next;
//    Node* c3 = first->next->next;
//    
//    while (true) {
//
//        c2->next = c1;
//        c1->next = c3;
//        
//        if (prev == nullptr) { l.setFirst(c2); }
//        else { prev->next = c2; }
//        
//        if (c3 != nullptr) {
//            prev = c1;
//            c1 = prev->next;
//            c2 = c1->next;
//            if (c2 == nullptr) { break; }
//            c3 = c2->next;
//        }
//        else { break; }
//    }
//}


// change it a little (accept head node in the parameters) and make the function as per the Class
void PairWiseSwap(Doubly_LinkedList &l) {
    Node* first = l.getFirst();
    Node* prev = nullptr;
    Node* c1 = first;
    Node* c2 = first->next;
    Node* c3 = first->next->next;
    
    while (true) {

        c2->next = c1;
        c2->prev = prev;
        c1->next = c3;
        if (c3 == nullptr) { l.setLast(c1); }
        else if (c3->next == nullptr) { l.setLast(c3); c3->prev = c1; }
        else { c3->prev = c1; }
        //c2->prev = c2;
        
        if (prev == nullptr) { l.setFirst(c2); }
        else { prev->next = c2; }

        if (c1 != nullptr) {
            prev = c1;
            c1 = prev->next;
            if (c1 != nullptr) { c2 = c1->next; }
            if (c1 == nullptr || c1->next == nullptr) { break; }
            c3 = c2->next;
        }
        else if (c1 == nullptr) { break; }
    }
}

int main() {
	Node* head = nullptr;
	addCandidate(head, 1, "Ali");
	addCandidate(head, 2, "Bob");
	addCandidate(head, 3, "Cat");
	addCandidate(head, 4, "Dan");

	cout << "--- Before Pairwise Swap ---\n";
	display(head);

	pairwiseSwap(head);

	cout << "--- After Pairwise Swap ---\n";
	display(head);


	return 0;
}