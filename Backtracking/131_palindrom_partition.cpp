#include<vector>
#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int n ;
    bool isPalindrom(string s , int l , int r ){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
    void backtrack(string& s , int idx , vector<string>& cur , vector<vector<string>>& result){
        if(idx==n){
            result.push_back(cur);
            return ;
        }

        for(int i = idx ; i<n ; i ++){
            if(isPalindrom(s,idx,i)){
                cur.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,cur,result);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> cur;

        backtrack(s,0,cur,result);
        return result;
    }
};