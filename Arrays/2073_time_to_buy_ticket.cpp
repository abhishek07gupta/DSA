#include <iostream>
#include<vector>
using namespace std;


// Approach 1 : brute force -> O(n*m)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count =0 ; 
        int i = 0 ;
        while(i%(tickets.size()) < tickets.size() && tickets[k]!=0){
           
            if(tickets[i%(tickets.size())]>0){
                count++;
                tickets[i%(tickets.size())]--;
            }
            i++;
        }
        return count;
    }
};

// Approach 2 : Optimal -> O(n);

class Solution {
public:
    int timeRequiredToBuy(vector<int>& ticket, int k) {
        int count=0;
        for(int i =0 ; i < ticket.size() ; i ++){
            if(i <= k ){
                count += min(ticket[i],ticket[k]);
            }else{
                count += min(ticket[k]-1,ticket[i]);
            }
        }
        return count;
    }
};
