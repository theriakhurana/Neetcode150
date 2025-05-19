#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m-1;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                return search(matrix[mid], target);
            }
            if(target > matrix[mid][0]) s = mid+1;
            else e = mid-1;
        }

        return false;
    }

    bool search(vector<int>&nums, int target){
        int s = 0, e = nums.size()-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target) return true;
            if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }
        return false;
    }
};

int main(){
  Solution s;
  vector<vector<int>> matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50},
    {60, 70, 80, 90}
  };
  int target = 3;
  cout << (s.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl; // Found
  
  target = 13;
  cout << (s.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl; // Not Found
}