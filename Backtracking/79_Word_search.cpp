#include<vector>
#include<iostream>
using namespace std;

// approach 1 : we first find the first char of word in the board , then we call the find function to find it whole  word is present or not

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>> &board , string word , int i , int j , int index){

    // means all the chars of word are present   
        if(index == word.length()){
            return true;
        }
        
        if(i < 0 || j < 0 || j>=board[0].size() || i>=board.size() || board[i][j]==word[index]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j]='$';
        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
// checking for each direction , return true if we find for any direction
            if(find(board,word,new_i,new_j,index+1)){
                return true;
            }
        }
        board[i][j]=temp;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0 ; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j]==word[0] && find(board,word , i , j ,0)){
                    return true;
                }
            }
        }

        return false;
    }
};

