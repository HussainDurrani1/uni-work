#include <iostream>
#include <string>
using namespace std;

// Base Class Template
template <class T>
class Character{
protected:
    string name;
    T health;

public:
    Character(string n = "", T h = 0){
        name = n;
        health = h;
    }

    void displayCharacter() const{
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
    }
};

// Player class (virtual inheritance)
template <class T>
class Player : virtual public Character<T>{
public:
    Player(string n = "", T h = 0) : Character<T>(n, h) {}
};

// Enemy class (virtual inheritance)
template <class T>
class Enemy : virtual public Character<T>{
public:
    Enemy(string n = "", T h = 0) : Character<T>(n, h) {}
};

// Boss class (multiple inheritance)
template <class T>
class Boss : public Player<T>, public Enemy<T>{
public:
    Boss(string n, T h): Character<T>(n, h), Player<T>(n, h), Enemy<T>(n, h) {}

    void displayBoss() const{
        cout << "=== Boss Character ===" << endl;
        this->displayCharacter();
    }
};

int main(){
    Boss<int> b1("Dark Lord", 500);

    b1.displayBoss();

    return 0;
}