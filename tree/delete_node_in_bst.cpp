#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node( int val){
        data= val;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data> root->data){
       root->right=insert(root->right,data);
    }
    else if(data< root->data){
       root->left=insert(root->left,data);
    }
    return root;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
   
}


Node* findMin(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if(root == NULL) return root;

    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


int main(){
    Node* root  =nullptr;
    int n;
      cout<<"Enter no of nodes : "<<endl;
    cin>>n;
   
    for(int i=0;i<n;i++){
        cout<<"Enter Node"<<endl;
        int node;
        cin>>node;
        root=insert(root,node);
    }
    inorder(root);
    cout<<endl;
    int key;
    cout<<"Node which are delete in  BST"<<endl;
    cin>>key;
    deleteNode(root,key);
     inorder(root);
}