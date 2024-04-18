#include <iostream>
#include<vector>
#include<queue>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class compare{
    public : 
        bool operator()(ListNode * a  , ListNode * b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode * , vector<ListNode *> , compare> pq;
        int k = lists.size();
        if(k==0){
            return NULL;
        }

        for(int i = 0 ; i < k ; i ++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }

        ListNode * head = NULL;
        ListNode * tail = NULL;

        while(pq.size()>0){
            ListNode * temp = pq.top();
            pq.pop();
            if(head==NULL){
                head = tail = temp;
                if(head->next!=NULL){
                pq.push(head->next);
            }
            }else{
                tail->next = temp;
                tail=tail->next;
                if(tail->next!=NULL){
                    pq.push(tail->next);
                }
            }


            
        }
        return head;

    }
};