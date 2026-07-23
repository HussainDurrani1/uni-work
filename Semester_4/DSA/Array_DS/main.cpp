#include "Array.h"

int main(){

	// -------- INT ARRAY --------
	Array<int> arr(5);
	arr.display();
	
	arr.addValue(12);
	arr.addValue(22);
	arr.addValue(32);
	arr.addValue(42);
	arr.addValue(52);
	arr.addValue(69);
	arr.display();

	cout << "The value at index 5: " << arr.get(5) << endl;

	arr.fill();
	arr.display();

	arr.set(10, 69);
	arr.display();
	cout << "Size = " << arr.getSize() << endl;

	arr.addValue(11);
	arr.addValue(21);
	arr.addValue(31);
	arr.addValue(41);
	arr.addValue(51);
	arr.display();

	cout << "Current number of elements: " << arr.getCurrentElements() << endl;
	cout << "Size = " << arr.getSize() << endl;

	arr.set(29, 69);
	arr.display();

	arr.double_CopyArray();
	arr.set(29, 69);
	arr.display();

	cout << "Current number of elements: " << arr.getCurrentElements() << endl;
	cout << "Size = " << arr.getSize() << endl;

	cout << "Count of 11 is = " << arr.countValue(11) << endl;

	arr.displayDetails();

	arr.fill();
	arr.display();

	cout << "Current number of elements: " << arr.getCurrentElements() << endl;
	cout << "Size = " << arr.getSize() << endl;

	arr.displayDetails();


	// -------- DOUBLE ARRAY --------
	cout << "\n\n===== DOUBLE ARRAY =====\n";

	Array<double> darr(5);
	darr.display();

	darr.addValue(1.1);
	darr.addValue(2.2);
	darr.addValue(3.3);
	darr.addValue(4.4);
	darr.addValue(5.5);
	darr.addValue(6.6);
	darr.display();

	cout << "The value at index 3: " << darr.get(3) << endl;

	darr.fill();
	darr.display();

	darr.set(8, 9.9);
	darr.display();

	cout << "Count of 2.2 is = " << darr.countValue(2.2) << endl;

	darr.displayDetails();


	// -------- CHAR ARRAY --------
	cout << "\n\n===== CHAR ARRAY =====\n";

	Array<char> carr(5);
	carr.display();

	carr.addValue('A');
	carr.addValue('B');
	carr.addValue('C');
	carr.addValue('D');
	carr.addValue('E');
	carr.addValue('F');
	carr.display();

	cout << "The value at index 2: " << carr.get(2) << endl;

	carr.fill();
	carr.display();

	carr.set(7, 'Z');
	carr.display();

	cout << "Count of A is = " << carr.countValue('A') << endl;

	carr.displayDetails();

	return 0;
}
