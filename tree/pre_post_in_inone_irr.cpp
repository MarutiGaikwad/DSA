#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
     
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;

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
void allorder(Node* root){
    stack<pair<Node*,int >> st;
    st.push({root,1});
    vector<int> pre , post, in;
    if(root==nullptr) return;
    while(!st.empty()){
        auto it= st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=nullptr){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=nullptr){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    cout << "\nPreorder: ";
    for (int x : pre) cout << x << " ";

    cout << "\nInorder: ";
    for (int x : in) cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : post) cout << x << " ";

}
int main() {
    Node* root = NULL;
    cout << "Build the binary tree:" << endl;
    root = buildTree(root);
    cout << "\nPreorder Traversal of Tree: ";
    allorder(root);
    cout << endl;
    return 0;
}