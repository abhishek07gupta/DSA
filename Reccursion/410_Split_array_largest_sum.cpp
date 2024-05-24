#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int partition(vector<int>&nums , int mid){

        int partitions = 1;
        int value = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(value+nums[i]<=mid){
                value+=nums[i];
            }else{
                partitions++;
                value = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<= high){
            int mid = low+(high-low)/2;
            int partitions = partition(nums,mid);
            if(partitions>k){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};