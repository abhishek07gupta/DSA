#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int , vector<int>> mp ;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(n ==1 ){
            return true;
        }
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool>visited(n,false);

        queue<int> store;
        store.push(source);
        while(!store.empty()){
            int val = store.front();
            store.pop();

            if(val == destination){
                return true;
            }

            for(auto an : mp[val]){
                if(!visited[an]){
                    store.push(an);
                    visited[an]=true;
                }
            }
        }
        return false;
    }
};