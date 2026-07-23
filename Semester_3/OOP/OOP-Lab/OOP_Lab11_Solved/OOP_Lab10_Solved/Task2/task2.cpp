#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

int main() {

	Animal a1((char*)"Animal");

	Cat c1((char*)"Cat");

	Dog d1((char*)"Dog");

	cout << "----- Display Function -----" << endl;
	a1.display();
	c1.display();
	d1.display();

	cout << "\n----- makeSound() Calls -----" << endl;
	a1.makeSound();
	c1.makeSound();
	d1.makeSound();

	cout << "\n----- Assign subclass to superclass object -----" << endl;
	Animal a2 = c1;
	a2.makeSound();

	cout << "\n----- Superclass Pointer -----" << endl;
	Animal* ptr;

	ptr = &a1;
	ptr->makeSound();

	ptr = &c1;
	ptr->makeSound();   

	ptr = &d1;
	ptr->makeSound();   

	return 0;
}