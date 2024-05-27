#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row , int col , vector<vector<char>> & board ,char val){
        int n = board.size();
        for(int i = 0 ; i < n ; i ++){
            if(board[row][i]==val){
                return false;
            }
            if(board[i][col]==val){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char x = '1'; x <= '9'; x++) {
                    if (isSafe(i, j, board ,x)) {
                        board[i][j] = x;
                        bool possible = solve(board);
                        if (possible) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};