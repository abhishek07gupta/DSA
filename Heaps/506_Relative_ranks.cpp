#include<vector>
#include<iostream>
#include<queue>
#include<string>
using namespace std;


class Node{
    public:
    int data , position;
    Node(int data , int position){
        this->data = data ;
        this->position = position;
    }
    bool operator<(const Node& other) const {
        return data < other.data;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<Node> pq;
        vector<string> answer(score.size());

        for(int i = 0 ; i < score.size();i++){
            pq.push(Node(score[i],i));
        }

        int rank = 1;
        
        while(!pq.empty()){
            Node temp = pq.top();
            pq.pop();
            int pos = temp.position;
            if(rank==1){
                answer[pos]="Gold Medal";
            }else if(rank == 2 ){
                answer[pos]="Silver Medal";
            }else if(rank == 3){
                answer[pos]="Bronze Medal";
            }else{
                answer[pos]=to_string(rank);
            }
            rank++;
        }

        return answer;
    }
};