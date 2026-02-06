/*
You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element is at most k times the minimum element.

You may remove any number of elements from nums​​​​​​​ without making it empty.

Return the minimum number of elements to remove so that the remaining array is balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

 

Example 1:

Input: nums = [2,1,5], k = 2

Output: 1

Explanation:

Remove nums[2] = 5 to get nums = [2, 1].
Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.
Example 2:

Input: nums = [1,6,2,9], k = 3

Output: 2

Explanation:

Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.
Example 3:

Input: nums = [4,6], k = 2

Output: 0

Explanation:

Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 105
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // Step 1: Sort the array to easily identify min and max in a range
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int max_kept = 0;
        
        // Step 2: Sliding window
        for (int right = 0; right < n; ++right) {
            // While the condition is violated, shrink the window from the left
            // We use long long to prevent integer overflow for nums[left] * k
            while ((long long)nums[right] > (long long)nums[left] * k) {
                left++;
            }
            
            // Update the maximum number of elements we can keep
            max_kept = max(max_kept, right - left + 1);
        }
        
        // Step 3: Result is Total - MaxKept
        return n - max_kept;
    }
    
};