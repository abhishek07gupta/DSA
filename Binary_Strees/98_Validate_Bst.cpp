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
 

// approach  1 : we know inorder traversal of bst in sorted in asc order. 
// class Solution {
// public:
//     void inOrder(TreeNode * root , vector<int>& ans){
//         if(root==NULL){
//             return ;
//         }
//         inOrder(root->left,ans);
//         ans.push_back(root->val);
//         inOrder(root->right,ans);
//     }
//     bool isValidBST(TreeNode* root) {
//       vector<int>sorted;
//       inOrder(root,sorted);
//       for(int i =1 ; i < sorted.size();i++){
//         if(sorted[i]<=sorted[i-1]){
//             return false;
//         }
//       }  
//       return true;
//     }
// };

// ---------------------------------------------------------------
// ---------------------------------------------------------------

// Approach 2 : 
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
    bool isTrue(TreeNode * root , long long min , long max){
        if(root==NULL){
            return true;
        }
        if(root->val > min && root->val < max){
            bool left = isTrue(root->left,min , root->val);
            bool right = isTrue(root->right , root->val , max);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        return isTrue(root, LLONG_MIN , LLONG_MAX);
    }
};
