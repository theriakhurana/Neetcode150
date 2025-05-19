#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = nums1.size();
        int n = (nums1.size()+nums2.size());
        int numsOnLeft = (n+1)/2;

        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = numsOnLeft - mid1;

            int l1 = (mid1 >= 1) ? nums1[mid1-1] : INT_MIN;
            int r1 = (mid1 < nums1.size()) ? nums1[mid1] : INT_MAX;
            int l2 = (mid2 >= 1) ? nums2[mid2-1] : INT_MIN;
            int r2 = (mid2 < nums2.size()) ? nums2[mid2] : INT_MAX;

            if(l1 > r2){
                high = mid1-1;
            }
            else if(l2 > r1){
                low = mid1+1;
            }
            else{
                if(n & 1){ // odd length array
                    return max(l1,l2);
                }else{
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
            }
        }

        return 0;
    }


    int main(){
        Solution s;
        vector<int> nums1 = {1,3};
        vector<int> nums2 = {2};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

        nums1 = {1,2};
        nums2 = {3,4};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.5

        return 0;
    }
};
