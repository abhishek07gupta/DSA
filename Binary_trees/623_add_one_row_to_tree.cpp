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

    void dfs(TreeNode * root  , int val , int depth , int curdepth){
        if(root==NULL){
            return ;
        }
        if(curdepth<depth-1){
            dfs(root->left , val , depth , curdepth+1);
            dfs(root->right , val , depth , curdepth+1);
        }
        if(curdepth== depth-1){
            TreeNode  * curleft = root->left;
            TreeNode * curright = root->right;
            TreeNode * newleft = new TreeNode(val);
            TreeNode * newright = new TreeNode(val);
            root->left=newleft;
            root->right = newright;
            newleft->left = curleft;
            newright ->right = curright;
            return ;
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * curnode = root;
            TreeNode * newnode = new TreeNode(val);
            newnode->left = curnode;
            return newnode;
        }

        dfs(root, val , depth , 1);
        return root;
    }
};