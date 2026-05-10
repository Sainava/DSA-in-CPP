/*
Given an unsorted array of integers nums and an integer k, return the kth largest element in the array.

By kth largest element, we mean the kth largest element in the sorted order, not the kth distinct element.

Follow-up: Can you solve it without sorting?

Example 1:

Input: nums = [2,3,1,5,4], k = 2

Output: 4
Example 2:

Input: nums = [2,3,1,1,5,5,4], k = 3

Output: 4
Constraints:

1 <= k <= nums.length <= 10000
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int> > pq ;

        for(int i = 0 ; i < nums.size() ; i++){
            pq.push(nums[i]);

            if(pq.size()>k){
                pq.pop();
            }
        }

        //TC:O(nlogk) and SC:O(k)
        return pq.top();
    }
};
