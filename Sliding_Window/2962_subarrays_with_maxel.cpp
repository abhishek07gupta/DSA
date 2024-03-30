#include<vector>
#include<iostream>
using namespace std;


// approach 1: sliding window 

// class Solution {
// public:
//     Solution(){
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//     }
//     long long countSubarrays(vector<int>& nums, int k) {
//         int l =0 , r=0 , n = nums.size();
//         long long count = 0 ;
//         int maxi = INT_MIN;
//         long long nosub = 0;
//         for(int i = 0 ; i < n; i ++){
//             maxi = max(maxi , nums[i]);
//         }
//         while(r<n){
//             if(nums[r]==maxi){
//                 count++;
//             }
//             while(count>=k){
//                 nosub+=(n-r);
//                 if(nums[l]==maxi){
//                     count--;
//                 }
//                 l++;
//             }
//             r++;
//         }

//         return nosub;
//     }
// };


// Approach 2 : 