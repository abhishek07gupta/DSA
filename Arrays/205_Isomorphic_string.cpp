#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smp;
        unordered_map<char,char> tmp;

        for(int i = 0  ; i < s.length(); i ++){
            char c1 = s[i];
            char c2 = t[i];
            if(smp.find(c1) != smp.end() && smp[c1]!=c2  || (tmp.find(c2) != tmp.end() && tmp[c2] != c1)){
                return false;
            }
            smp[c1]=c2;
            tmp[c2]=c1;

        }
        return true;
    }
};