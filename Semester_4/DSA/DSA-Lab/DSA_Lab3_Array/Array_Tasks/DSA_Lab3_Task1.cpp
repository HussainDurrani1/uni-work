// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

template <class T>
class Array
{
    T* arr;
    int size;
    int n;

public:
    Array(int ssize): n(0), size(ssize) {
        arr = new T[ssize];
    }

    void insert(T v) {
        if (n < size) {
            arr[n++] = v;
            cout << v << " added.\n";
        }
        else {
            cout << "Array is Full. Can't add more elements...\n";
        }
    }

    int search(T v) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == v) { return i; }
        }
        return -1;
    }

    void display() {
        cout << "\n-----------------------------------\n";
        cout << "Elements of ARRAY: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " | ";
        }
        cout << "\n-----------------------------------\n\n";
    }

    int getCurrentElements() { return n; }

    void remove(T v) {
        int index = this->search(v);
        for (int i = index; i < n-1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << v << " is removed from the array...\n";
    }
 
 	~Array() {
		delete[] arr;
	}

};


int main() {
	
    //========== INT ARRAY ==========
    cout << "Integer Array: \n";
    Array<int> a2(5);
    a2.insert(10);
    a2.insert(20);
    a2.insert(30);
    a2.insert(40);
    a2.insert(50);
    a2.insert(60);

    a2.display();
    
    if (a2.search(50) != -1) cout << "Element 50 is at index: " << a2.search(50) << "\n";
    else cout << "Element is not present in the array\n";

    a2.remove(30);

    a2.display();

    if (a2.search(50) != -1) cout << "Element 50 is at index: " << a2.search(50) << "\n";
    else cout << "Element is not present in the array\n";
    cout << "Current Number of Elements are: " << a2.getCurrentElements() << "\n";


    //========== Float ARRAY ==========
    cout << "\nFloat Array: \n";
    Array<float> a3(5);
    a3.insert(10.11);
    a3.insert(20.22);
    a3.insert(30.33);
    a3.insert(40.44);
    a3.insert(50.55);
    a3.insert(60.66);

    a3.display();

    if (a3.search(50.55) != -1) cout << "Element 50.55 is at index: " << a3.search(50.55) << "\n";
    else cout << "Element is not present in the array\n";

    a3.remove(30.33);

    a3.display();

    if (a2.search(50.55) != -1) cout << "Element 50.55 is at index: " << a2.search(50.55) << "\n";
    else cout << "Element is not present in the array\n";
    cout << "Current Number of Elements are: " << a3.getCurrentElements() << "\n";


    //========== String ARRAY ==========
    cout << "\nString Array: \n";
    Array<string> a1(5);
    a1.insert("Hussain");
    a1.insert("Durrani");
    a1.insert("Ali");
    a1.insert("Talha");
    a1.insert("Ahmad");
    a1.insert("Donald");


    a1.display();

    if (a1.search("Talha") != -1) cout << "Element Talha is at index: " << a1.search("Talha") << "\n";
    else cout << "Element is not present in the array\n";

    a1.remove("Ali");

    a1.display();

    if (a1.search("Talha") != -1) cout << "Element Talha is at index: " << a1.search("Talha") << "\n";
    else cout << "Element is not present in the array\n";
    cout << "Current Number of Elements are: " << a1.getCurrentElements() << "\n";


	return 0;
}