//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//	int empID;
//	Node* left;
//	Node* right;
//	Node(int id) : empID(id) {
//		right = left = nullptr;
//	}
//};
//
//Node* insertEmp(Node* root, int id) {
//	if (root == nullptr) return new Node(id);
//	if (id < root->empID) root->left = insertEmp(root->left, id);
//	else if (id > root->empID)	root->right = insertEmp(root->right, id);
//	return root;
//}
//
//bool findNode(Node* root, int id) {
//
//	if (root == nullptr) return false;
//	if (root->left == nullptr && root->right == nullptr) return false;
//
//	if (root->empID = id) {
//		return true;
//	}
//
//	findNode(root->left, id);
//	findNode(root->right, id);
//	return false;
//}
//
//Node* findLCA(Node* root, int n1, int n2) { 
//    Node* LCA = root;
//
//    while (true) {
//        if (LCA->empID > n1 && LCA->empID > n2) {
//            LCA = LCA->left;
//        }
//        else if (LCA->empID < n1 && LCA->empID < n2) {
//            LCA = LCA->right;
//        }
//        else break;
//    }
//
//    return LCA;
//} 
//
//int main() {
//
//	Node* root = nullptr;
//	root = insertEmp(root, 50);
//	root = insertEmp(root, 30);
//	root = insertEmp(root, 70);
//	root = insertEmp(root, 20);
//	root = insertEmp(root, 40);
//	root = insertEmp(root, 60);
//	root = insertEmp(root, 80);
//	
//	int id1 = 30, id2 = 70;
//	Node* lca = findLCA(root, id1, id2);
//
//	if (lca != nullptr) {
//		cout << "LCA of " << id1 << " and " << id2 << " is: " << lca->empID << endl;
//	}
//
//	else {
//		cout << "LCA not found.\n";
//	}
//
//	return 0;
//}