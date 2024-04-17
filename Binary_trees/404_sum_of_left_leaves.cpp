
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
    void findsol(TreeNode * root , bool flag , int & sum ){
        if(root->left == NULL and root->right == NULL and flag){
            sum += root->val;
        }
        if(root->left){
            findsol(root->left,true , sum);
        }
        if(root->right){
            findsol(root->right,false ,sum);
        }

    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root==NULL or ( root->left == NULL and root->right == NULL)){
            return 0 ;
        }
        int sum = 0 ;
        if(root->left){
            findsol(root->left,true , sum);
        }
        if(root->right){
            findsol(root->right,false ,sum);
        }
        return sum ;
    }
};