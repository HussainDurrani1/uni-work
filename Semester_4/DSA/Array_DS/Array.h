#pragma once
#include<iostream>
using namespace std;


template <typename T>
class Array {
	T* array;
	const int MAX = 100;
	int size = 0;
	int currentElements = 0;

	T* doubleArray();

public:
	Array(int s);
	void fill();
	void display();
	T get(int idx);
	void addValue(T val);
	void set(int idx, T val);

	T getMaxElement();
	T getMinElement();
	T getAvg();
	int countValue(T val);
	void displayDetails();

	void setMAX(int s);
	int getCurrentElements();
	int getSize();

	void double_CopyArray();
	~Array();
};

template <typename T>
void Array<T>::setMAX(int s) { MAX = s; }

template <typename T>
int Array<T>::getSize() { return size; }

template <typename T>
int Array<T>::getCurrentElements() { return currentElements; }

template <typename T>
T* Array<T>::doubleArray() {
	size *= 2;
	T* temp = new T[size]();
	return temp;
}

template <typename T>
void Array<T>::double_CopyArray() {
	T* temp = doubleArray();
	for (int i = 0; i < size/2; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
}

template <typename T>
void Array<T>::fill() {
	currentElements = 0;
	cout << "Enter " << size << " elements: \n";
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		cin >> array[i];
		currentElements++;
	}
	cout << endl;
}

template <typename T>
void Array<T>::addValue(T val) {
	if (currentElements < MAX) {
		if (currentElements >= size) {
			double_CopyArray();
		}
		array[currentElements++] = val;
	}
	else {
		cout << "Array full...\n";
	}
}

template <typename T>
void Array<T>::set(int idx, T val) {
	if (idx < MAX) {
		if (idx < size) {
			array[idx] = val;
			if (idx >= currentElements) {
				int x = idx + 1 - currentElements;
				currentElements += x;
			}
		}
		else {
			cout << "Array is full...\n";
		}
	}
	else {
		cout << "Array has reached its limit...\n";
	}
}

template <typename T>
T Array<T>::getMaxElement() {
	T max = array[0];
	for (int i = 1; i < currentElements; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

template <typename T>
T Array<T>::getMinElement() {
	int i = 0;

	while (i < currentElements && array[i] == 0) {
		i++;
	}
	T min = array[i];

	for (int j = i + 1; j < currentElements; j++) {
		if (array[j] != 0 && array[j] < min) {
			min = array[j];
		}
	}
	return min;
}

template <typename T>
T Array<T>::getAvg() {
	T sum = 0;
	for (int i = 0; i < currentElements; i++) {
		sum += array[i];
	}
	return sum / currentElements;
}

template <typename T>
void Array<T>::displayDetails() {
	cout << "\n---------------------------------------\n";
	cout << "Max Element: " << getMaxElement() << endl;
	cout << "Min Element: " << getMinElement() << endl;
	cout << "Average of all Element: " << getAvg() << endl;
	cout << "---------------------------------------\n";
}


template <typename T>
T Array<T>::get(int idx) {
	return array[idx];
}

template <typename T>
void Array<T>::display() {
	cout << "Array Elements: ";
	if (currentElements == 0) cout << "None.\n";
	for (int i = 0; i < currentElements; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";
}

template <typename T>
Array<T>::Array(int s): size(s) {
	array = new T[size]();
}

template <typename T>
Array<T>::~Array() {
	delete[] array;
}

template <typename T>
int Array<T>::countValue(T val) {
	int count = 0;

	for (int i = 0; i < currentElements; i++) {
		if (array[i] == val) {
			count++;
		}
	}
	return count;
}