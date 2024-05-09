#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     sort(happiness.begin(),happiness.end(),greater<int>());
     long long happyness=0;

     for(int i =0 ; i < k ; i ++){
    
        if(happiness[i]-i>0){
            happyness+=happiness[i]-i;
        }else{
            break;
        }

     }   
     return happyness;
    }
};