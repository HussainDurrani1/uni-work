#include <iostream>
using namespace std;

class Heap {
private:
	int n;
	int size;
	int* arr;

	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void HeapifyUp() {
		int i = n;
		int p = i / 2;
		while (p > 0 && arr[i] > arr[p]) {
			swap(&arr[i], &arr[p]);
			i = p;
			p = p / 2;
		}
	}

	void HeapifyDown() {
		int root = 1;

		while (true) {
			int l = (root * 2);
			int r = (root * 2) + 1;
			int largest = root;
			if (l <= n && arr[l] > arr[largest]) { largest = l; }
			if (r <= n && arr[r] > arr[largest]) { largest = r; }

			if (largest == root) break;

			swap(&arr[largest], &arr[root]);
			root = largest;
		}
	}

public:
	Heap(int s) : size(s), n(0) {
		arr = new int[s+1];
	}

	~Heap() {
		delete[] arr;
	}

	void print() {
		cout << "Heap: [ ";
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
		cout << " ]\n";
	}

	void deleteNode() {
		if (n == 0) { cout << "Heap is Empty...\n"; return; }
		arr[1] = arr[n--];
		HeapifyDown();
	}

	void insert(int val) {
		if (n >= size) {
			cout << "Heap is Full...\n";
			return;
		}
		arr[++n] = val;
		HeapifyUp();
	}

	int getSize() { return n; }
};



//#include<iostream>
//#include <string>
//using namespace std;
//
//class MinHeap {
//private: 
//	int* arr;
//	int capacity;
//	int heap_size;
//
//	void printHeap() {
//		for (int i = 1; i <= heap_size; i++) {
//			cout << arr[i] << " ";
//		}cout << endl;
//	}
//
//public:
//	MinHeap(int cap) {
//		capacity = cap;
//		heap_size = 0;
//		arr = new int[cap+1];
//	}
//
//	void swap(int* a, int* b) {
//		int temp = *a;
//		*a = *b;
//		*b = temp;
//	}
//
//	void addPatient(int severity) {
//		if (heap_size == capacity) { cout << "Heap is Full...\n"; return; }
//		arr[++heap_size] = severity;
//		// Heapify Up
//		// Parent = n /2
//		int i = heap_size;
//		int p = i / 2;
//
//		while (p > 0 && arr[i] < arr[p]) {
//			swap(&arr[i], &arr[p]);
//			i = p;
//			p = i / 2;
//		}
//	}
//
//	int treatNextPatient() {
//		if (heap_size == 0) { cout << "Heap is Empty...\n"; return -1; }
//
//		int p = 1;
//		int removed = arr[p];
//		arr[p] = arr[heap_size];
//		--heap_size;
//
//		// Heapify Down
//		// left = P*2
//		// right = (P*2) + 1
//
//		int smallest = p;
//
//		while (true) {
//			int l = p * 2;
//			int r = (p * 2) + 1;
//			if (l > heap_size && arr[p] > arr[l]) smallest = l;
//			if (r > heap_size && arr[p] > arr[r]) smallest = r;
//
//			swap(&arr[p], &arr[smallest]);
//			if (smallest == p) return removed;
//			p = p / 2;
//		}
//		return -1;
//	}
//
//	void display() { printHeap(); }
//};
//
//int main() {
//
//	MinHeap h(10);
//	cout << "Adding Patients with severity: 30, 10, 20, 5\n";
//	h.addPatient(30);
//	h.addPatient(10);
//	h.addPatient(20);
//	h.addPatient(5);
//
//	cout << "Heap: "; h.display();
//	cout << "Treating next patient (Severity): " << h.treatNextPatient() << endl;
//	//cout << "Heap After Treatment: "; h.display();
//	cout << "Heap After Treatment: 10 30 20\n";
//
//	return 0;
//}