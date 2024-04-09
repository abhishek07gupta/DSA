#include <iostream>
#include<vector>
using namespace std;

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
