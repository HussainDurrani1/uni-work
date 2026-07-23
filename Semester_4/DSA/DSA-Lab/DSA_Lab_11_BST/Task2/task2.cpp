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

    cout << "Leaf nodes: " << tree.count_leaves(tree.root) << endl;

    return 0;
}
