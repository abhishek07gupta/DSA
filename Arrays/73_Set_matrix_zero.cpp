#include<vector>
#include<iostream>
using namespace std;

// brute force with O(n^3)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();

//         for(int i =0 ; i <rows ; i++){
//             for(int j = 0 ; j< cols ; j++){
//                 if(matrix[i][j]==0){
//                     for(int r = 0 ; r < matrix.size();r++){
//                         if(matrix[r][j]!=0)matrix[r][j]=-10;
//                     }
//                     for(int c = 0 ; c < matrix[0].size();c++){
//                         if(matrix[i][c]!=0)matrix[i][c]=-10;
//                     }
//                 }
//             }
//         }

//         for(int i  =  0 ; i<rows;i++){
//             for(int j = 0 ; j < cols ; j++){
//                 if(matrix[i][j]==-10){
//                     matrix[i][j]=0;
//                 }
//             }
//         }

//     }
// };

// --------------------------------------------------------
// --------------------------------------------------------

// better O(n^2)  using seperate row , col array to mark 


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int>r(rows,0);
        vector<int>c(cols,0);

        for(int i =0 ; i <rows ; i++){
            for(int j = 0 ; j< cols ; j++){
                if(matrix[i][j]==0){
                    r[i]=-1;
                    c[j]=-1;
                }
            }
        }

        for(int i  =  0 ; i<rows;i++){
            for(int j = 0 ; j < cols ; j++){
                if(r[i] == -1 or c[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }

    }
};
