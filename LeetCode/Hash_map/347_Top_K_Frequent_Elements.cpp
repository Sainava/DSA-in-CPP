/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // The maximum count can be n and minimum count can be 1 for any element in nums 
        // Hence we can create bucket of size n + 1 (where index 1 till n tell us the count and the element that appears that number of times )

        int n = nums.size();
        // SC:O(n)
        unordered_map<int,int> freq;

        //TC:O(n)
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1 );

        for(auto &p:freq){
            buckets[p.second].push_back(p.first);
        }

        vector<int> result ;

        //TC:O(n)
        for(int i = n ; i >=1 && result.size() < k;  i--){
            for(int num:buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    break;
                }
            }
        }

        //TC:O(n) and SC:O(n)
        return result ;


    }
};