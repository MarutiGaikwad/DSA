#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void preorder(Node* root) {
    if (root == NULL) return;
      
     cout << root->data << " "; 
    preorder(root->left);
    preorder(root->right);
      
}

Node* buildTree(Node* root) {
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main() {
    Node* root = NULL;
    cout << "Build the binary tree:" << endl;
    root = buildTree(root);
    cout << "\nPreorder Traversal of Tree: ";
    preorder(root);
    cout << endl;
    return 0;
}
