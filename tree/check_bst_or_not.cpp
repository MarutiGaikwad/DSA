#include <iostream>
#include <climits>
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

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
bool checkbst(Node* root,int mi,int ma) {
    if(root==NULL) return true;
    if((root->data >= ma)||(root->data <= mi))   return false;
     return checkbst(root->left, mi, root->data) && checkbst(root->right, root->data, ma);
}
int main() {
    Node* root = NULL;
    cout << "Build the binary tree:" << endl;
    root = buildTree(root);
    cout << "\nInorder Traversal of Tree: ";
    inorder(root);
    cout << endl;
     
int ma = INT_MAX;
int mi = INT_MIN;
    if(checkbst(root,mi,ma)){
        cout<<"Tree is BST"<<endl;
    }
    else{
         cout<<"Tree is not BST"<<endl;
    }
    return 0;
}
