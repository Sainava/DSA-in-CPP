/*
You are given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k, otherwise return false.

Example 1:

Input: nums = [1,2,3,1], k = 3

Output: true
Example 2:

Input: nums = [2,1,2], k = 1

Output: false
Constraints:

1 <= nums.length <= 100,000
-1,000,000,000 <= nums[i] <= 1,000,000,000
0 <= k <= 100,000
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0 ;
        int r = 0 ; 
        int n = nums.size() ; 

        // We need to see if we have seen this number before in that range , quick search so hash set 
        unordered_set<int> st ; 

        while( r < n){
            if ( (r - l) > k){
                st.erase(nums[l]);
                l++;
            } 

            // r is not in the set yet and so when we check r with other elements in the set , the indices of r with matching element is always different 
            // This is how the distinct indices condition is fulfilled 
            if(st.count(nums[r])) return true ; 

            st.insert(nums[r]);
            
            r++;
        }

        //TC:O(n) and SC:O(k)
        return false; 
    }
};