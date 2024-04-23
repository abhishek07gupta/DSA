#include <iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void filque(unordered_set<string>&set , string & cur , queue<string>&que){
        for(int i = 0 ; i < 4 ; i ++){
            char ch = cur[i];
            char dec = ch=='0'?'9':ch-1;
            char inc = ch=='9'?'0':ch+1;
            cur[i]=dec;
            if(set.find(cur)==set.end()){
                que.push(cur);
                set.insert(cur);
            }
            cur[i]=inc;
            if(set.find(cur)==set.end()){
                que.push(cur);
                set.insert(cur);
            }
            cur[i]=ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> set(deadends.begin(),deadends.end());
        int level = 0 ;
        if(set.find(start)!=set.end()){
            return -1;
        }

        queue<string> que;
        que.push(start);
        while(!que.empty()){
            int s = que.size();
            while(s--){
                string cur = que.front();
                que.pop();

                if(cur == target){
                    return level;
                }
                filque(set,cur,que);
            }
            level++;
        }
        return -1;
    }
};