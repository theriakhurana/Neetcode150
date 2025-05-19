#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  // Time complexity: O(log n)
  // Space complexity: O(1)
  int search(vector<int>& nums, int target) {
      int s = 0, e = nums.size()-1;

      while(s <= e){
          int mid = s + (e-s)/2;

          if(nums[mid] == target) return mid;
          if(nums[mid] < target) s = mid+1;
          else e = mid-1;
      }
      return -1;
  }
};

int main(){
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 3;
  Solution sol;
  int ans = sol.search(nums, target);
  cout << "Index of " << target << " is: " << ans << endl; // 2

  nums = {-1,0,2,4,6,8};
  target = 3;
  ans = sol.search(nums, target);
  cout << "Index of " << target << " is: " << ans << endl;  // -1
}

