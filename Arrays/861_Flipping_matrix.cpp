#include<vector>
#include<iostream>
#include<math.h>
using namespace std;


class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for(int i  = 0 ; i < r ; i++){
            if(grid[i][0]==0){
                // flip this row
                for(int j = 0 ; j < c; j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }

        for(int j = 1 ; j < c ; j ++){
            int countZero = 0;
            for(int i = 0 ; i < r ; i++){
                if(grid[i][j]==0){
                    countZero ++ ;
                }
            }
            int countOne = r - countZero;
            if(countZero > countOne){
                for(int i  =0 ; i < r ; i ++){
                    // flip this column
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        int answer = 0 ;
        for(int i =0 ; i< r ; i ++){
            int val =0;
            for(int j = 0 ; j < c ;j ++){
                val+=grid[i][j]*pow(2,c-j-1);
            }
            answer += val;
        }
        return answer;
    }
};