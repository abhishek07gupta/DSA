#include<vector>
#include<iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// approach 1 : recursive way
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        if(root->val < p->val and root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }else if(root->val>p->val and root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};

// approach 2 : iterative way
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(root->val>p->val and root->val >q->val){
                root=root->left;
            }else if(root->val < p->val and root->val < q->val ){
                root=root->right;
            }
            else{
                return root;
            }
        }
    }
};