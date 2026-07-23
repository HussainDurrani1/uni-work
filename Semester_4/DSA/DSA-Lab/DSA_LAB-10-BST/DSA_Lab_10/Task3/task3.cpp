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

    cout << "Recursive Insert Test:" << endl;
    cout << "Root: " << tree.root->data << endl;
    cout << "Root->Left: " << tree.root->left->data << endl;
    cout << "Root->Right: " << tree.root->right->data << endl;
    cout << "Root->Left->Left: " << tree.root->left->left->data << endl;
    cout << "Root->Left->Right: " << tree.root->left->right->data << endl;
    cout << "Root->Right->Left: " << tree.root->right->left->data << endl;
    cout << "Root->Right->Right: " << tree.root->right->right->data << endl;

    return 0;
}
