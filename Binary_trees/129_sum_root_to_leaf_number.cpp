#include <iostream>
#include<vector>
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
    void findsum(TreeNode * root , int & sum ,int sofar ){
        if(root == NULL){
            return ;
        }
        sofar = sofar*10+root->val;
        if(root->left==NULL and root->right == NULL){
            sum += sofar;
            return ;
        }
        findsum(root->left,sum, sofar);
        
        findsum(root->right , sum , sofar);
       
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0 ;
        int sofar =0 ;
        findsum(root,sum,sofar);
        return  sum;
    }
};