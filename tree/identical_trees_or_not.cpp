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


bool same(Node* root1,Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;
     
   return  (root1->data==root2->data)&& same(root1->left,root2->left) && same(root1->right,root2->right);
     
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
    Node* root1 = NULL;
    cout << "Build the binary tree 1:" << endl;
    root1 = buildTree(root1);
    Node* root2 = NULL;
    cout << "Build the binary tree: 2" << endl;
    root2 = buildTree(root2);
   
 if (same(root1, root2))
        cout << "Trees are the same" << endl;
    else
        cout << "Trees are not the same" << endl;

    return 0;
}
