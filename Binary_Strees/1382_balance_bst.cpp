#include<vector>
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// approach: we are making use of fact that inorder of bst is sorted , then we can make sure that  bst is balanced by 
// dividing the inorder into half for each half recursively 
class Solution {
public:
    void findInorder(TreeNode* root , vector<int> & inorder){
        if(root==NULL){
            return ;
        }
        if(root->left)findInorder(root->left,inorder);
        inorder.push_back(root->val);
        if(root->right)findInorder(root->right,inorder);
    }

    TreeNode* createBst(int s , int e , vector<int> inorder){
        if(s>e){
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode * root = new TreeNode(inorder[mid]);
        root->left=createBst(s,mid-1,inorder);
        root->right=createBst(mid+1,e,inorder);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        findInorder(root,inorder);

        root = createBst(0,inorder.size()-1,inorder);
        return root;

    }
};