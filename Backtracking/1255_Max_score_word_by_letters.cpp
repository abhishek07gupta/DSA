#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxscore=INT_MIN;
    int n;

    void solve(vector<string>&words , vector<int>& score , int i , vector<int> freq , int curScore){
        maxscore = max(maxscore , curScore);
        if(i==n){
            return;
        }
        vector<int> tempfreq=freq;

        int j =0 ;
        int tempscore=0;
        while(j<words[i].length()){
            int  index = words[i][j]-'a';
            tempscore+=score[index];
            tempfreq[index]--;
            if(tempfreq[index]<0){
                break;
            }
            j++;
        }

        if(j==words[i].length()){
            solve(words,score,i+1,tempfreq, curScore+tempscore);
        }
        solve(words,score,i+1,freq,curScore);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n= words.size();
        vector<int>freq(26,0);
        for(int i =0 ; i < letters.size(); i++){
            int index = letters[i]-'a';
            freq[index]++;
        }
        solve(words,score,0 , freq , 0 );
        return maxscore;
    }
};