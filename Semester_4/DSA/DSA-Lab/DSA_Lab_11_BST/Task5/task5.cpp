#include <iostream>
using namespace std;
#include "BNode.h"
#include "BST.h"

int main() {
    BST<int> tree;

    int n;
    cout << "How many nodes to insert? ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cout << "Before mirror - Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.mirror(tree.root);

    cout << "After mirror  - Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.mirror(tree.root);

    cout << "Restored      - Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
