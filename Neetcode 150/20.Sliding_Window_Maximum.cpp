/*
You are given an array of integers nums and an integer k. There is a sliding window of size k that starts at the left edge of the array. The window slides one position to the right until it reaches the right edge of the array.

Return a list that contains the maximum element in the window at each step.

Example 1:

Input: nums = [1,2,1,0,4,2,6], k = 3

Output: [2,2,4,4,6]

Explanation:
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6
Constraints:

1 <= nums.length <= 100,000
-10,000 <= nums[i] <= 10,000
1 <= k <= nums.length

*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Here we use deque to store the index of the largest element in that window
        // Index because it helps us see when the largest element is no longer in that window 
        // Here say an element is largest in a window , only the elements to the right of it can be needed when the window chnages so we can discard element to its left 
        // One end of the deque(the back ) acts as a monotonic stack , same end for pop and push , and monotic stack is used to find largest and smallest in constant time 

        int n = nums.size();
        vector<int> ans;

        // // Solution 1 : Brute Force 
        // //TC:O(n-k)
        // for(int i = 0 ; i <= n - k ; i++){
        //     int maxElement = INT_MIN;
        //     //TC:O(k)
        //     for(int j = i ; j <= i + k - 1; j++){
        //         maxElement = max( maxElement , nums[j]);
        //     }
        //     ans.push_back(maxElement);

        // }

        // //TC:O(n*k) and SC:(1)
        // return ans;

        //Optimised Solution
        deque<int> dq;

        // Outer loop TC:O(n)
        // Inner loop combined across all can be TC:O(n)
        // SO total TC:O(2n)
        // Basically all elements can enter the queue once and be deleted once so in this way 2n 
        for(int i = 0 ; i < n ; i++ ){
            // Two things to take care of 
            
            // First if the max element is not in the window 
            if(!dq.empty() and dq.front()<= i - k){
                dq.pop_front();
            }

            // Now the window is valid 

            // Second : now if the element is the larger then the queue's front , that means it is largest element and will be till it is out of the window 
            while( !dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            // Now push the element to queue
            dq.push_back(i);

            // Start storing answer when the window actually starts
            if( i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }

        //TC:O(n) and SC:O(n)
        return ans;
    }
};
