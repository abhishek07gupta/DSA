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

Node * bstMin(Node * root){
    while(root!=NULL){
        root=root->left;
    }
    return root;
}
Node * bstMax(Node * root){
    while(root!=NULL){
        root=root->right;
    }
    return root;
}

Node* deleteBst(Node * &root , int delData){
    if(root==NULL){
        return root;
    }
    if(root->left == NULL && root->right== NULL){
        delete root;
        return NULL;
    }
    if(root->left!=NULL && root->right==NULL){
        Node * temp = root->left;
        delete root;
        return temp;
    }
    if(root->left==NULL && root->right!=NULL){
        Node* temp = root->right;
        delete root;
        return temp;
    }


}

int main(){
    Node * root=NULL;

    cout<<"Enter the elements of the bst"<<endl;
    root=takeInput(root);

    int delData;
    cout<<endl<<"enter the element to delete"<<endl;
    cin>>delData;
    root = deleteBst(root,delData);

    cout<<endl<<"Printing the bst"<<endl;
    printBstLevel(root);


    return 0 ;
}