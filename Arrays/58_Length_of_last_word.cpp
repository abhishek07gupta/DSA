#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = s.length()-1;

        while(n>=0 and s[n]==' '){
            n--;
        }
        int count=0;
        while(n>= 0 and s[n]!=' '){
            count++;
            n--;
        }
        return count;
    }
};