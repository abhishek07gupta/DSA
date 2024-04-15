#include <iostream>
#include <queue>

using namespace std;

class Node
{

public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createBst(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = createBst(root->left, data);
    }
    else
    {
        root->right = createBst(root->right, data);
    }
    return root;
};

Node *takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = createBst(root, data);
        cin >> data;
    }

    return root;
};

void printBstLevel(Node *root)
{
    queue<Node *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        int q = nodes.size();
        while (q)
        {
            Node *temp = nodes.front();
            nodes.pop();
            cout << temp->data << ' ';
            if (temp->left)
                nodes.push(temp->left);
            if (temp->right)
                nodes.push(temp->right);
            q--;
        }
        cout << endl;
    }
};


Node *bstMax(Node *Root)
{
    Node *root = Root;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Node *bstMin(Node *Root)
{
    Node *root = Root;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteBst(Node *&root, int delData)
{   
    // no data found in the tree
    if (root == NULL)
    {
        return root;
    }

    // data found
    if (root->data == delData)
    {
        // no child , delete the data and return NULL
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // only one child , on left
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // only one child , on right
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // child on both sides
        if(root->left != NULL && root->right != NULL){
            int min = bstMin(root)->data;
            root->data = min ;
            root->left= deleteBst(root->left,min);
        }
    }

    if(root->data>delData){
        root->left = deleteBst(root->left,delData);
    }else{
        root->right = deleteBst(root->right,delData);
    }
    return root;
}

int main()
{
    Node *root = NULL;

    cout << "Enter the elements of the bst" << endl;
    root = takeInput(root);

    int delData;
    cout << endl
         << "enter the element to delete" << endl;
    cin >> delData;
    root = deleteBst(root, delData);

    cout << endl
         << "Printing the bst" << endl;
    printBstLevel(root);

    return 0;
}