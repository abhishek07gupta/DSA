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
 
// Appraoch 1 : we will traverse the bst and select one root at a time and then find the remaining part in the 
// entire bst .. O(N^2)


// --------------------------------

// Approach 2 : we find find the inorder , which is sorted and then use simple two sum appraoch.

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void findInorder(TreeNode* root , vector<int> & inorder){
        if(root==NULL){
            return ;
        }
        if(root->left)findInorder(root->left,inorder);
        inorder.push_back(root->val);
        if(root->right)findInorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inOrder;
        findInorder(root,inOrder);
        int i = 0 ;
        int j = inOrder.size()-1;
        while(i<j){
            int sum = inOrder[i]+inOrder[j];
            if(sum == k ){
                return true;
            }else if(sum < k){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};