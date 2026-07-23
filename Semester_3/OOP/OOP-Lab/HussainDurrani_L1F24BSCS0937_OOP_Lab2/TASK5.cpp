// Task 5:
#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size];

    cout << "Enter " << size << " values for array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    //Deleting the array and then try to access it (dangling pointer)
    delete[] arr;  // Memory is deallocated
    cout << "\nMemory deleted.\n";

    // Dangling pointer access (unsafe, just for demonstration)
    cout << "Trying to access deleted memory (dangling pointer):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Undefined behavior!
    }
    cout << "\n";

    //Creating a memory leak by allocating memory and not deleting it
    int* leakedArray = new int[10];  // Memory is allocated
    for (int i = 0; i < 10; i++) {
        leakedArray[i] = i * 2;  // Assign some values
    }

    // Intentionally NOT deleting leakedArray
    // This memory will not be freed before the program exits (memory leak)

    cout << "\nProgram ends. One block of memory was not deallocated (memory leak)." << endl;

    return 0;
}
