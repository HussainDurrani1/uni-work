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

    cout << "Inorder (sorted): ";
    tree.inorder(tree.root);
    cout << endl;

    int val1, val2;
    cout << "Enter two values to find their LCA: ";
    cin >> val1 >> val2;

    BNode<int>* result = tree.LCA(tree.root, val1, val2);

    if (result != nullptr)
        cout << "LCA(" << val1 << ", " << val2 << ") = " << result->data << endl;
    else
        cout << "LCA not found (one or both values may not exist in the tree)." << endl;

    return 0;
}
