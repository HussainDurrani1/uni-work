// Task 1:
#include <iostream>
using namespace std;

template <typename T>
double average(T arr[], int size){
    double sum = 0;

    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    int intArr[] = { 1, 2, 3, 4, 5 };
    long longArr[] = { 10, 20, 30, 40, 50 };
    double doubleArr[] = { 2.5, 3.5, 4.5, 5.5, 6.9 };
    char charArr[] = { 'A', 'B', 'C', 'D', 'E'};   // ASCII values used

    cout << "Average of int array: " << average(intArr, 5) << endl;
    cout << "Average of long array: " << average(longArr, 5) << endl;
    cout << "Average of double array: " << average(doubleArr, 5) << endl;
    cout << "Average of char array: " << average(charArr, 5) << endl;

    return 0;
}