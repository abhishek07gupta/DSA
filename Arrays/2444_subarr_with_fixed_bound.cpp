#include<vector>
#include<iostream>
using namespace std;

// approach 1 : brute force ->find all subarray and see whether  pass or  fail

// approach 2 : using  concept  similar to  sliding  window 
class Solution {
public:

    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        long long count = 0 ;
        int minin=-1,maxin=-1,culpritin=-1;

        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i]<mink or nums[i]>maxk)culpritin=i;
            if(nums[i]==mink)minin=i;
            if(nums[i]==maxk)maxin=i;

            int temp = min(minin,maxin)-culpritin;
            count += temp>0?temp:0;
        }
        return count;
    }
};