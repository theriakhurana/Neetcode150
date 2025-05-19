#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // optimal solution
    // Time complexity: O(log(min(n,m))) where n and m are the sizes of the two arrays
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

    // better solution
    // Time complexity: O(n+m) where n and m are the sizes of the two arrays
    // Space complexity: O(1)
    double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size()+nums2.size();
        int n1 = -1, n2 = -1;
        int cnt = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                if(cnt == n/2) n1 = nums1[i];
                if(cnt == n/2 -1) n2 = nums1[i];
                i++;
            }else{
                if(cnt == n/2) n1 = nums2[j];
                if(cnt == n/2 -1) n2 = nums2[j];
                j++;
            }
            cnt++;
        }
        while(i < nums1.size()){
            if(cnt == n/2) n1 = nums1[i];
            if(cnt == n/2 -1) n2 = nums1[i];
            i++;
            cnt++;
        }
        while(j < nums2.size()){
            if(cnt == n/2) n1 = nums2[j];
            if(cnt == n/2 -1) n2 = nums2[j];
            j++;
            cnt++;
        }

        if(n & 1) return n1;
        return (n1+n2)/2.0;
    }

    // brute force solution
    // Time complexity: O(n+m) where n and m are the sizes of the two arrays
    // Space complexity: O(n+m)
    double findMedianSortedArraysBrute(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i = 0, j= 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                arr.push_back(nums1[i++]);
            }else{
                arr.push_back(nums2[j++]);
            }
        }
        while(i < nums1.size()) arr.push_back(nums1[i++]);
        while(j < nums2.size()) arr.push_back(nums2[j++]);

        int n = arr.size();
        if(n & 1) return arr[n/2];
        double ans = (arr[n/2] + arr[n/2 - 1])/2.0;
        return ans;
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
