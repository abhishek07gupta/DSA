#include<vector>
#include<iostream>
#include<stack>
using namespace std;

// we are doing in order traversal as it gives result in ascedning order , we can keep the record of the current position to know the rank of the element

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// class Solution {
// public:
// i represents the rank of element 
//     int findval(TreeNode * root , int k  , int & i ){
//         if(root== NULL){
//             return -1;
//         }

//         //  we will get the value from the left subtree, if we get  
//         int left = findval(root->left,k,i);
//         if(left!=-1){
//             return left;
//         }
//         i++;
//         if(i==k){
//             return root->val;
//         }
//         return  findval(root->right,k,i);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);
//         int i = 0 ;
//         return findval(root, k,i);
//     }
// };


// -----------------------------------------------
// -----------------------------------------------

// approach two : maintaing a stack of elements
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
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stack<TreeNode * > nodes;
        TreeNode * pointer=root;
        int count=0;
        while(pointer!= NULL || !nodes.empty()){
            while(pointer!=NULL){
                nodes.push(pointer);
                pointer = pointer->left;
            }
            count++;
            pointer = nodes.top();
            nodes.pop();
            if(count==k)return pointer->val;
            pointer=pointer->right;

        }
        return -1;
    }
};