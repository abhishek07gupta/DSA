#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0 ;
        int count = 0 ;
        for(auto c : s){
            if(c=='('){
                count++;
            }else if(c==')'){
                count--;
            }
            maxi = max(maxi,count);
        }

        return maxi ;
    }
};