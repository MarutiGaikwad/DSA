#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }

    if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int minelement(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int node;
        cout << "Enter node " << i + 1 << ": ";
        cin >> node;
        root = insert(root, node);
    }

    cout << "\nInorder traversal: ";
    inorder(root);
    cout << endl;

    int minval = minelement(root);
    if (minval != -1)
        cout << "Minimum value in BST: " << minval << endl;

    return 0;
}
