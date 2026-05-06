/*
You are given an array of integers nums containing n + 1 integers. Each integer in nums is in the range [1, n] inclusive.

Every integer appears exactly once, except for one integer which appears two or more times. Return the integer that appears more than once.

Example 1:

Input: nums = [1,2,3,2,2]

Output: 2
Example 2:

Input: nums = [1,2,3,4,4]

Output: 4
Follow-up: Can you solve the problem without modifying the array nums and using 
O
(
1
)
O(1) extra space?

Constraints:

1 <= n <= 10,000
nums.length == n + 1
1 <= nums[i] <= n
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Okay there are a few hints that seem to say we need to use linked list 

        // No extra space -> SO any other data structure like mop or queue or even another vector will not work 
        // Cannot change the original vector 
        // Also n numbers but n+1 size so one repeats atleast twice \
        // Also since n numbers n+1 size , an index will point to another valid index and never go out of linked list 

        // This essentially is the same question as cycle detection of linked list where we need to find the point of entry of cycle        
        int n = nums.size();
        int slow = 0 ; 
        int fast = 0 ; 

        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]]; // move two steps 
            if(slow == fast ){
                break;
            }
        }

        // Now make one travel from same and other from the start
        slow = 0 ;

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        //TC:O(n) and SC:O(1)
        return slow;
    }
};
