// Task 2:
#include <iostream>
using namespace std;

template <class T>
class Rectangle{
private:
    T length, breadth, height;

public:
    Rectangle(T l, T b, T h){
        length = l;
        breadth = b;
        height = h;
    }

    T Cal_Volume(){
        return length * breadth * height;
    }

    void Compare(Rectangle obj){
        if (this->Cal_Volume() > obj.Cal_Volume())
            cout << "Current object has greater volume." << endl;
        else if (this->Cal_Volume() < obj.Cal_Volume())
            cout << "Other object has greater volume." << endl;
        else
            cout << "Both objects have equal volume." << endl;
    }
};

int main(){
    Rectangle<int> r1(2, 3, 4);
    Rectangle<int> r2(3, 3, 3);

    r1.Compare(r2);

    return 0;
}