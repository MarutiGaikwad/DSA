#include<iostream> 
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        right=nullptr;
        left=nullptr;

    }
};
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
bool search(Node* root, int key){
    if(root==NULL)
    return false;
    if(root->data==key)
    return 1;
    int LS=search(root->left, key);
      int RS=search(root->right, key);
      return LS||RS;
}
int main(){
    Node* root=nullptr;
    root=buildTree(root);
    int key;
    cout<<"enter the key"<<endl;
    cin>>key;
    if(search(root,key)){
        cout<<"key is found"<<endl;
    }
    else{
        cout<<"key is not found"<<endl;
    }
}