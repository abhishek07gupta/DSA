#include<vector>
#include<iostream>
using namespace std;

// approach 1: reccursive way of solving
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode * prev = NULL;
//     void flatten(TreeNode* root) {
//         if(!root)return;
//         flatten(root->right);
//         flatten(root->left);
//         root->right= prev;
//         root->left = NULL;
//         prev=root;
//     }
// };


// approach 2 : stack 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return ;
        stack<TreeNode*>nodesval;
        nodesval.push(root);
        while(!nodesval.empty()){
            TreeNode * cur = nodesval.top();
            nodesval.pop();
            if(cur->right)nodesval.push(cur->right);
            if(cur->left)nodesval.push(cur->left);
            if(!nodesval.empty()){
                cur->right=nodesval.top();
            }
            cur->left = NULL;
        }
    }
};