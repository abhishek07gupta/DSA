#include<vector>
#include<iostream>
using namespace std;

// approach one . brute force --> merge the arrs and then find the median 
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int a = nums1.size();
//         int b = nums2.size();
//         int i = 0 ;
//         int j = 0 ;
//         vector<int>nums3;

//         while(i < a and j < b ){
//             if(nums1[i]>nums2[j]){
//                 nums3.push_back(nums2[j]);
//                 j++;
//             }else{
//                 nums3.push_back(nums1[i]);
//                 i++;
//             }
//         }
//         if(i<a){
//             while(i<a){
//                 nums3.push_back(nums1[i]);
//                 i++;
//             }
//         }
//         if(j<b){
//             while(j<b){
//                 nums3.push_back(nums2[j]);
//                 j++;
//             }
//         }

//             int med = (a+b)/2;
//         if((a+b)%2==0){
//             return (float(nums3[med]+nums3[med-1]))/2;
//         }else{
//             return nums3[med];
//         }

//     }
// };


// --------------------------------------------------
// --------------------------------------------------

// approach 2 -> 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
    // making sure that the first array is always the smaller one and used for finding mid
        if(b<a)return findMedianSortedArrays(nums2,nums1);

        int left = (a+b+1)/2;
        int low = 0 , high = a;

        while(low<=high){
            // number of elements on the left half side from array one
            int mid1 = (low+high)>>1;
            // remaining elements from the array two
            int mid2 = left - mid1;

            // assigning the values to the ends of both halfs
            int l1=INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;
            if(mid1-1>=0)l1=nums1[mid1-1];
            if(mid2-1>=0)l2=nums2[mid2-1];
            if(mid1<a)r1=nums1[mid1];
            if(mid2<b)r2=nums2[mid2];


            // if the halfs are divided correctly 
            if(l1<=r2 && l2<=r1){
                if((a+b)%2==1){
                    return max(l2,l1);
                }
                return ((double)(max(l1,l2)+min(r2,r1)))/2.0;
            }
            else if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }
        return 0 ;
    }
};
