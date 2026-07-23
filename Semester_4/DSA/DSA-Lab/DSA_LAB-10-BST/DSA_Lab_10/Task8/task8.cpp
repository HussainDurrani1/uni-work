#include <iostream>
using namespace std;
#include "BNode.h"
#include "BST.h"

int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "=== Iterative Search ===" << endl;
    cout << "Search 40: " << (tree.search_iter(40) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (tree.search_iter(99) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (tree.search_iter(50) ? "Found" : "Not Found") << endl;
    cout << "Search 1:  " << (tree.search_iter(1)  ? "Found" : "Not Found") << endl;

    cout << "\n=== Recursive Search ===" << endl;
    cout << "Search 60: " << (tree.search_rec(tree.root, 60) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search_rec(tree.root, 25) ? "Found" : "Not Found") << endl;
    cout << "Search 80: " << (tree.search_rec(tree.root, 80) ? "Found" : "Not Found") << endl;
    cout << "Search 55: " << (tree.search_rec(tree.root, 55) ? "Found" : "Not Found") << endl;

    return 0;
}
