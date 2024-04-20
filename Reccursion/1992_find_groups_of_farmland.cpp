#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int n , m ;
    vector<vector<int>> result;
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>> & land , int i , int j  , int &r , int &c){
        land[i][j]=0;
        r = max(r,i);
        c = max(c,j);
        for(auto  dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i >=0 && new_i < m && new_j >=0 && new_j < n && land[new_i][new_j])
            dfs(land , new_i , new_j , r , c);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        for(int i = 0 ; i < m ; i ++){
            for ( int j = 0 ; j < n ; j++){
                if(land[i][j]==1){
                    int r1=i;
                    int c1=j;
                    int r2=i;
                    int c2=j;
                    dfs(land , i , j , r2,c2);
                    result.push_back({r1,c1,r2,c2});
                }
            }
        }

        return result;
    }
};