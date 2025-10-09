#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& a) {
        int i=0;
      return  insert(a,i,INT_MAX);
    }
        TreeNode* insert(vector<int> &a,int & i,int b){
            if(a.size()==i|| a[i]>b) return nullptr;
            TreeNode* root= new TreeNode(a[i++]);
            root->left= insert(a,i,root->val);
            root->right=  insert(a,i,b);
        
       
    
    return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12,};
    TreeNode* root = sol.bstFromPreorder(preorder);
    
    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;
    return 0;
}
