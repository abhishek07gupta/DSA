#include<vector>
#include<iostream>
using namespace std;


	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

void findinorder(BinaryTreeNode * root , vector<int> & inorder){
	if(root==NULL){
		return ;
	}
	findinorder(root->left, inorder);
	inorder.push_back(root->data);
	findinorder(root->right, inorder);
}

void createminheap(BinaryTreeNode *  root , vector<int> & inorder , int & index){
	if(index>=inorder.size()){
		return ;
	}
	if(root==NULL){
		return ;
	}
	root->data = inorder[index++];
	createminheap(root->left, inorder, index);
	createminheap(root->right,inorder, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int > inorder;
	findinorder(root,inorder);
	int index = 0 ;
	createminheap(root,inorder,index);
	return root;
}