#include<iostream>
#include<vector>

using namespace std;

// not optimal or required solution as sorting is done in (nlogn) but needed in (n)
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> answer; 
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         int i = 1 ;
//         while(i<n){
//             if(nums[i]==nums[i-1]){
//                 answer.push_back(nums[i]);
//             }
//             i++;
//         }
//         return answer;
//     }
// };


// optimal solution , in time complexity (n)
// as numbers are between 1-n , we can use this as index to know if index comes multiple times

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false) and cin.tie(NULL);
        vector<int> answer;

        for(auto num : nums){
            int index = abs(num)-1;
            if(nums[index]<0){
                answer.push_back(abs(num));
            }else{
                nums[index] *= -1;
            }
        }

        return answer;
    }
};