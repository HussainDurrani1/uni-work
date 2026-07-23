#include <iostream>
using namespace std;

class CLNode {
public:
	int data;
	CLNode* next;

	CLNode(int d) : data(d) {
		next = nullptr;
	}
};

class CircularLinkedList {
public:
	CLNode* first;

	CircularLinkedList() {
		first = nullptr;
	}

	void insertAtFirst() {
		int data;
		cout << "Enter a value: "; cin >> data;
		CLNode* temp = new CLNode(data);

		if (first == nullptr) {
			first = temp;
			first->next = first;
		}
		else {
			temp->next = first;
			CLNode* curr = first;
			while (curr->next != first) {
				curr = curr->next;
			}
			curr->next = temp;
			first = temp;
		}
	}

	void insertAtLast() {
		int data;
		cout << "Enter a value: "; cin >> data;
		CLNode* temp = new CLNode(data);

		if (first == nullptr) {
			first = temp;
			first->next = first;
		}
		else {
			CLNode* curr = first;
			while (curr->next != first) {
				curr = curr->next;
			}
			curr->next = temp;
			temp->next = first;
		}
	}

	void displayAllTokens() {
		cout << "Tokens: ";
		CLNode* curr = first;
		cout << curr->data << " -> ";
		curr = curr->next;
		while (curr != first) {
			cout << curr->data << " -> ";
			curr = curr->next;
		}
		cout << "( " << curr->data << " ...)";
		cout << "\n";
	}

	void printSequence() {
		int currToken = 0;
		int turns = 0;
		cout << "Enter Current Token: "; cin >> currToken;
		cout << "Enter Turns: "; cin >> turns;
		cout << "\n\nCurrent Token: " << currToken << " |  Turns: " << turns << "\n";
		cout << "Sequence: ";
		CLNode* curr = first;
		while (curr->data != currToken) {
			curr = curr->next;
		}
		while (turns > 0) {
			cout << curr->data << " -> ";
			curr = curr->next;
			turns--;
		}
		cout << curr->data << " ";
		cout << "\n";
		cout << "Final Token: " << curr->data << "\n";
	}

};



int main() {
	CircularLinkedList tokenNumbers;
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();
	tokenNumbers.insertAtLast();

	tokenNumbers.displayAllTokens();

	tokenNumbers.printSequence();

	tokenNumbers.printSequence();

	return 0;
}