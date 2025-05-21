#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = -1;
        for(int pile : piles){
            maxB = max(pile, maxB);
        }

        int s = 1, e = maxB;
        while(s <= e){
            int m = s + (e-s)/2;

            int hours = findHours(piles, m);
            if(hours <= h){
                e = m - 1;
            }else 
                s = m + 1;
        }

        return s;
    }

    int findHours(vector<int>&piles, int limit){
        int hours = 0;
        for(int pile : piles){
            hours += ceil((double)pile/limit);
        }

        return hours;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {1,4,3,2};
    int h = 9;
    cout << sol.minEatingSpeed(piles, h) << endl; // Output: 2
    return 0;
}