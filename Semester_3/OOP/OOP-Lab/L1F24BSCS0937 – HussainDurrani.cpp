//NAME: Muhammad Hussain Raza Durrani
//Roll No: L1F24BSCS937
//COURSE: OOP - Lab
//Submitted To: Sir Hamza Rashed


// Task 1:
#include <iostream>
using namespace std;

void swapNumbers(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapNumbersRef(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int calculateArea(int length, int width = 1) {
	return length * width;
}

int main() {
	int a = 9, b = 11;

	cout << "Before swap--->  a = " << a << " & b = " << b << endl;
	swapNumbers(a, b);
	cout << "After swap--->  a = " << a << " & b = " << b << endl;

	cout << "Before swap by Refernce--->  a = " << a << " & b = " << b << endl;
	swapNumbersRef(a, b);
	cout << "After swap by Refernce--->  a = " << a << " & b = " << b << endl;

	cout << "Area = " << calculateArea(6, 2) << endl;

	int* p = new int;
	*p = 9;
	cout << "Before deleting pointer = " << *p << endl;
	delete p;
	//cout << "After deleting " << *p << endl;   //  This will give a dangling error
	p = new int;
	*p = 10;
	cout << "After reassigning pointer = " << *p << endl;

	return 0;
}


//// Task 2:
//#include <iostream>
//using namespace std;
//
//void swapNumbers(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main() {
//	int a, b;
//	cout << "Enter value of a: ";
//	cin >> a;
//	cout << "Enter value of b: ";
//	cin >> b;
//	cout << "Before swapping by value:\na = " << a << ", b = " << b << endl;
//	swapNumbers(a, b);  // There will be no change because it swaps the copy of a & b which is only in the function
//	cout << "After swapping by value:\na = " << a << ", b = " << b << endl;
//
//	return 0;
//}




//// Task 3:
//#include <iostream>
//using namespace std;
//
//void swapNumbersRef(int& x, int& y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//int main() {
//	int a = 9, b = 5;
//	
//	cout << "Before swap by Refernce--->  a = " << a << " & b = " << b << endl;
//	swapNumbersRef(a, b);
//	cout << "After swap by Refernce--->  a = " << a << " & b = " << b << endl;
//
//	return 0;
//}



//// Task 4:
//#include <iostream>
//using namespace std;
//
//int calculateArea(int length, int width = 5) {
//	return length * width;
//}
//
//int main() {
//	int a = 9, b = 5;
//
//	cout << "Area calculateArea(6, 2) = " << calculateArea(6, 2) << endl;
//	cout << "Area calculateArea(6) = " << calculateArea(6) << endl;
//
//	return 0;
//}



//// Task 5:
//#include <iostream>
//using namespace std;
//
//int calculateSum(int arr[], int size){
//	int sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//double calculateAverage(int arr[], int size) {
//	double average = 0;
//	double sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += arr[i];
//	}
//	average = sum / size;
//	return average;
//}
//
//int main() {
//	int N;
//	cout << "Enter the size of array: ";
//	cin >> N;
//
//	int* arr = new int[N];
//	cout << "Enter the values in the array: " << endl;
//	for (int i = 0; i < N; i++) {
//		cout << i + 1 << ") ";
//		cin >> arr[i];
//	}
//
//	cout << "Values in the array: " << endl;
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << " ";
//	}cout << endl;
//
//	cout << "The sum of the elements in the array: " << calculateSum(arr, N) << endl;
//	cout << "The sum of the elements in the array: " << calculateAverage(arr, N) << endl;
//
//	return 0;
//}




//// Task 6:
//#include <iostream>
//using namespace std;
//
//int squareValue(int* ptr) {
//    return (*ptr) * (*ptr);
//}
//
//int main() {
//    int* ptr = new int;
//
//    cout << "Enter an integer value: ";
//    cin >> *ptr;
//    cout << "You entered: " << *ptr << endl;
//
//    int squared = squareValue(ptr);
//    cout << "Square of the value: " << squared << endl;
//
//    delete ptr;
//
//    //cout << "After deletion, accessing ptr (dangling pointer): " << *ptr << " (undefined behavior!)" << endl;
//    // This is giving errors
//
//
//    ptr = nullptr;
//
//    ptr = new int;
//    cout << "Enter a new integer value: ";
//    cin >> *ptr;
//    cout << "You entered (new value): " << *ptr << endl;
//
//    delete ptr;
//    ptr = nullptr;
//
//    return 0;
//}





//// Task 7:
//#include <iostream>
//using namespace std;
//
//int squareValue(int* ptr) {
//    return (*ptr) * (*ptr);
//}
//
//int main() {
//    int* ptr = new int;
//
//    cout << "Enter an integer value: ";
//    cin >> *ptr;
//    cout << "You entered: " << *ptr << endl;
//
//    int squared = squareValue(ptr);
//    cout << "Square of the value: " << squared << endl;
//
//    // Step 2: Reassign pointer to new memory without deleting old memory first
//    ptr = new int;
//
//    // Step 3: Old memory block is now inaccessible (memory leak)
//    cout << "Pointer reassigned to new memory without deleting old memory." << endl;
//
//    cout << "Enter a new integer value: ";
//    cin >> *ptr;
//    cout << "You entered (new value): " << *ptr << endl;
//
//    // Step 5: Properly delete memory before reassigning pointer to avoid leak
//    // (For demonstration, delete current memory and then allocate new memory again)
//    delete ptr;
//
//    ptr = new int;
//    cout << "Enter another new integer value: ";
//    cin >> *ptr;
//    cout << "You entered (another new value): " << *ptr << endl;
//
//    delete ptr;
//    ptr = nullptr;
//
//    return 0;
//}
//
///*
//Explanation (Step 4):
//
//When we assign 'ptr' to a new dynamically allocated memory location without deleting the old memory,
//the original memory block becomes inaccessible. This means we lose the pointer/reference to that block,
//and thus cannot free it later. This situation causes a memory leak because the allocated memory remains
//reserved but cannot be reclaimed or used anymore.
//*/
