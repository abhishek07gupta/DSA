#include<iostream>
#include<queue>

using namespace std;

// defining the node of bst
class Node{
public:
    int data;
    Node * left, * right;

    Node(int data){
        this->data= data;
        this->left= NULL;
        this->right= NULL;
    }
};


// function to add the  element in the bst
Node * createBst(Node * & root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(root->data>data){
        root->left=createBst(root->left,data);
    }else{
        root->right=createBst(root->right,data);
    }
    return root;
};


// function to take input for bst
Node * takeInput(Node * & root){
    int data;
    cin>>data;
    while(data!=-1){
        root=createBst(root,data);
        cin>>data;
    }

    return root;
};


// function for the level order traversal of the bst
void printBstLevel(Node * root){
    queue<Node*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        int q = nodes.size();
        while(q){
            Node * temp = nodes.front();
            nodes.pop();
            cout<<temp->data<<' ';
            if(temp->left)nodes.push(temp->left);
            if(temp->right)nodes.push(temp->right);
            q--;
        }
        cout<<endl;
    }
};


// function for searching the data in the bst
bool searchBst(Node * root,int data){
    if(root==NULL){
        return false;
    }

    if(root->data == data){
        return true;
    }

    if(root->data>data){
        return searchBst(root->left,data);
    }else{
        return searchBst(root->right,data);
    }

}


int main(){
    Node * root=NULL;

    cout<<"Enter the elements of the bst"<<endl;
    root=takeInput(root);

    cout<<endl<<"enter the element to search"<<endl;
    int searchData ;
    cin>>searchData;
    if(searchBst(root,searchData)){
        cout<<searchData<<" is present in the Bst"<<endl;
    }

    cout<<endl<<"Printing the bst"<<endl;
    printBstLevel(root);


    return 0 ;
}