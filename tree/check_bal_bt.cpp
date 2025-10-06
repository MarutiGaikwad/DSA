#include<iostream>
#include<cmath>
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

int maxheight(Node* root) {
    if (root == nullptr)
        return 0;

    int lh = maxheight(root->left);
    int rh = maxheight(root->right);

    return 1 + max(lh, rh);
}

bool check(Node* root) {
    if (root == nullptr)
        return true;

    int lh = maxheight(root->left);
    int rh = maxheight(root->right);

    if (abs(lh - rh) > 1)
        return false;

    bool left = check(root->left);
    bool right = check(root->right);

    return left && right;
}

int main() {
    Node* root = nullptr;
    root = buildTree(root);

    int height = maxheight(root);
    cout << "\nHeight of tree = " << height << endl;

    if (check(root))
        cout << "Tree is Balanced " << endl;
    else
        cout << "Tree is NOT Balanced " << endl;

    return 0;
}
