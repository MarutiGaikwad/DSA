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
int maxpath(Node* root,int & dim){
    if(root==nullptr) return 0;
    int lh= maxpath(root->left,dim);
    int rh=maxpath(root->right,dim);
    dim=max(dim,(lh+rh+root->data));
 return root->data + max(lh, rh);


}
int main(){
    Node* root=nullptr;
    root=buildTree(root);
    
 int SUM = INT32_MIN; 
    maxpath(root, SUM);
    cout<< "PATH SUM"<<" "<<SUM<<endl;
}