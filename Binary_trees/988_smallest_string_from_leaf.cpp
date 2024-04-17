#include <iostream>
#include<vector>
#include<string>
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
    string sol = "";

    void findsol(TreeNode * root , string cur){
        if(root == NULL){
            return ;
        }

        cur = char(root->val  + 'a') + cur;
        if(root->left == NULL && root->right == NULL){
            if(sol=="" || cur < sol){
                sol = cur;
            }
            return ;
        }

        findsol(root->left,cur);
        findsol(root->right,cur);
    }
    string smallestFromLeaf(TreeNode* root) {
        findsol(root,"");
        return sol;
    }
};