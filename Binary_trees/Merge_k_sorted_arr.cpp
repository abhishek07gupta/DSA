#include <iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Node{
    public:
        int i , j , val;
        Node(int val , int i , int j ){
            this->i = i ;
            this->j = j ;
            this->val = val ;
        }
};

class compare{
    public : 
        bool operator()(Node * a  , Node * b){
            return a->val > b->val;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> answer;
        priority_queue<Node * , vector<Node *> , compare> pq;
        
        for(int x = 0 ; x < K; x++){
            Node* temp = new Node(arr[x][0] , x , 0);
            pq.push(temp);
        }
        
        while(pq.size() > 0 ){
            Node* temp = pq.top();
            pq.pop();
            int i  = temp->i;
            int j = temp->j;
            answer.push_back(temp->val);
            
            if(j+1 < arr[i].size()){
                Node* newnode = new Node(arr[i][j+1] , i , j + 1);
                pq.push(newnode);
            }
        }
        return answer;
    }
};