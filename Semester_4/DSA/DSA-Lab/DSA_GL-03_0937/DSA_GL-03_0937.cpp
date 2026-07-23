// Hussain Durrani
// L1F24BSCS0937
#include <iostream>
using namespace std;

template <typename T>
class CLNode {
public:
	T data;
	CLNode<T>* next;

	CLNode(T d) : data(d) {
		next = nullptr;
	}
};

template <typename T>
class CircularLinkedList {
public:
	CLNode<T>* first;

	CircularLinkedList() {
		first = nullptr;
	}

	void insertAtFirst(T data) {
		CLNode<T>* temp = new CLNode(data);

		if (first == nullptr) {
			first = temp;
			first->next = first;
		}
		else {
			temp->next = first;
			CLNode<T>* curr = first;
			while (curr->next != first) {
				curr = curr->next;
			}
			curr->next = temp;
			first = temp;
		}
	}

	void insertAtLast(T data) {
		CLNode<T>* temp = new CLNode<T>(data);

		if (first == nullptr) {
			first = temp;
			first->next = first;
		}
		else {
			CLNode<T>* curr = first;
			while (curr->next != first) {
				curr = curr->next;
			}
			curr->next = temp;
			temp->next = first;
		}
	}

	void displayAllTokens() {
		cout << "Tokens: ";
		CLNode<T>* curr = first;
		cout << curr->data << " -> ";
		curr = curr->next;
		while (curr != first) {
			cout << curr->data << " -> ";
			curr = curr->next;
		}
		cout << "( " << curr->data << " ...)";
		cout << "\n";
	}

	void printSequence(T currToken, int turns) {
		cout << "\nCurrent Token: " << currToken << " |  Turns: " << turns << "\n";
		cout << "Sequence: ";
		CLNode<T>* curr = first;
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
	CircularLinkedList<int> tokenNumbers;
	tokenNumbers.insertAtLast(1);
	tokenNumbers.insertAtLast(2);
	tokenNumbers.insertAtLast(3);
	tokenNumbers.insertAtLast(4);
	tokenNumbers.insertAtLast(5);
	tokenNumbers.insertAtLast(6);
	tokenNumbers.insertAtLast(7);
	tokenNumbers.insertAtLast(8);
	tokenNumbers.insertAtLast(9);
	tokenNumbers.insertAtLast(10);

	tokenNumbers.displayAllTokens();

	tokenNumbers.printSequence(8, 5);

	tokenNumbers.printSequence(9, 6);

	return 0;
}