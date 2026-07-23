#include <iostream>
#include <string>
#include "CQueue.h"
using namespace std;

int main() {
    string searches[] = { "arrays", "queues", "stacks", "trees", "graphs", "sorting", "hashing", "recursion" };
    CQueue<string> history(3);

    for (int i = 0; i < 8; i++) {
        if (history.isFull()) {
            string dropped = history.Dequeue();
            cout << "Search: " << searches[i] << " -> Drop: " << dropped << endl;
        }
        else {
            cout << "Search: " << searches[i] << endl;
        }
        history.Enqueue(searches[i]);
    }
    return 0;
}