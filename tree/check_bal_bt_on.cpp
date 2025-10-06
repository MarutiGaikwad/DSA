 #include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int checkBalance(Node* root, bool &isBalanced) {
    if (root == nullptr)
        return 0;

    int leftHeight = checkBalance(root->left, isBalanced);
    int rightHeight = checkBalance(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = nullptr;
    root = buildTree(root);

    bool isBalanced = true;
    int height = checkBalance(root, isBalanced);

    cout << "\nHeight of tree = " << height << endl;
    
    if (isBalanced) {
        cout << "Tree is Balanced" << endl;
    } else {
        cout << "Tree is Not Balanced" << endl;
    }

    return 0;
}
