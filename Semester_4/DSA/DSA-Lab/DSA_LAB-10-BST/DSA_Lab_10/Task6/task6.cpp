#include <iostream>
using namespace std;
#include "BNode.h"
#include "Stack.h"
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

    cout << "Iterative Inorder (Left->Root->Right): ";
    tree.inorder_iter();

    cout << "Iterative Preorder (Root->Left->Right): ";
    tree.preorder_iter();

    return 0;
}
