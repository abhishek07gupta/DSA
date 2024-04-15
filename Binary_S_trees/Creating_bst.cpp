#include<iostream>
#include<queue>

using namespace std;

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

Node * takeInput(Node * & root){
    int data;
    cin>>data;
    while(data!=-1){
        root=createBst(root,data);
        cin>>data;
    }

    return root;
};

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

int main(){
    Node * root=NULL;

    cout<<"Enter the elements of the bst"<<endl;
    root=takeInput(root);

    cout<<"Printing the bst"<<endl;
    printBstLevel(root);


    return 0 ;
}