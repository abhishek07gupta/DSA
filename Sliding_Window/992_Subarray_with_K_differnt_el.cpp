#include<vector>
#include<iostream>
using namespace std;


// approach 1: sliding window 2 times. we find the subarray where K and less than K elements are presnt 
// then we subtract the subarrays where k-1 and less thank-1 elements to get the subarray with k elements
// class Solution {
// public:
//     Solution(){
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//     }
//     int slidingWindow(vector<int>nums , int k){
//         unordered_map<int , int > mp;
//         int count = 0 , i = 0 , j =0 , n = nums.size();
        
//         while(j<n){
//             mp[nums[j]]++;
//             while(mp.size()>k){
//                 mp[nums[i]]--;
//                 if(mp[nums[i]]==0){
//                     mp.erase(nums[i]);
//                 }
//                 i++;
//             }
//             count+=(j-i+1);
//             j++;
//         }
//         return count;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return slidingWindow(nums,k)-slidingWindow(nums,k-1);
//     }
// };
