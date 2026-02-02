/*
You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.

Return the minimum possible sum of the cost of these subarrays.

 

Example 1:

Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
Output: 5
Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
Example 2:

Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
Output: 15
Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
The division [10], [1], [2,2,2], and [1] is not valid, because the difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.
Example 3:

Input: nums = [10,8,18,9], k = 3, dist = 1
Output: 36
Explanation: The best possible way to divide nums into 4 subarrays is: [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
The division [10], [8,18], and [9] is not valid, because the difference between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.
 

Constraints:

3 <= n <= 105
1 <= nums[i] <= 109
3 <= k <= n
k - 2 <= dist <= n - 2
 
*/
#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // Base cost is always the first element
        long long current_sum = nums[0];
        
        // We need to pick k-1 additional elements from a window of size dist+1
        int needed = k - 1;
        
        // Two multisets to maintain the smallest 'needed' elements
        // top: stores the smallest 'needed' elements
        // rest: stores the remaining elements in the current window
        multiset<int> top; 
        multiset<int> rest;
        
        long long window_sum = 0;
        
        // Helper lambda to add an element
        auto add = [&](int val) {
            top.insert(val);
            window_sum += val;
            
            // If top has too many elements, move the largest to rest
            if (top.size() > needed) {
                auto it = prev(top.end()); // Largest in top
                window_sum -= *it;
                rest.insert(*it);
                top.erase(it);
            }
        };
        
        // Helper lambda to remove an element
        auto remove = [&](int val) {
            // Check if val is in top or rest
            // Note: We must locate the element carefully to remove only one instance
            if (rest.find(val) != rest.end()) {
                rest.erase(rest.find(val));
            } else {
                auto it = top.find(val);
                if (it != top.end()) {
                    window_sum -= *it;
                    top.erase(it);
                    
                    // Refill top from rest if possible
                    if (!rest.empty()) {
                        auto smallest_rest = rest.begin();
                        top.insert(*smallest_rest);
                        window_sum += *smallest_rest;
                        rest.erase(smallest_rest);
                    }
                }
            }
        };
        
        int n = nums.size();
        // Initialize the first window: nums[1] to nums[dist+1]
        // Note: The window size is effectively dist+1 elements
        for (int i = 1; i <= min(n - 1, dist + 1); i++) {
            add(nums[i]);
        }
        
        long long min_cost = current_sum + window_sum;
        
        // Slide the window
        // i is the index of the element LEAVING the window
        // i + dist + 1 is the index of the element ENTERING the window
        for (int i = 1; i + dist + 1 < n; i++) {
            int out_val = nums[i];
            int in_val = nums[i + dist + 1];
            
            remove(out_val);
            add(in_val);
            
            min_cost = min(min_cost, current_sum + window_sum);
        }
        
        return min_cost;
    }
};