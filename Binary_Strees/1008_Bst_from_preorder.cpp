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

// approach 1 : using normal insert into bst approach -> O(N^2)

// approach 2 : sorting preorder to get inorder and then using inorder and preorder to create bst -> O(nlogn)

// approach 3 : using preorder only to get bst


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    TreeNode * createTree(int mini , int maxi , int & i ,vector<int>preorder){
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]> maxi or preorder[i]<mini){
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[i++]);
        root->left= createTree(mini,root->val,i,preorder);
        root->right= createTree(root->val,maxi,i,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0 ;
        return createTree(INT_MIN,INT_MAX,i,preorder);
    }
};