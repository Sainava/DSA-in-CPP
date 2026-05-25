/*
You are given an array of integers nums, where nums[i] represents the maximum length of a jump towards the right from index i. For example, if you are at nums[i], you can jump to any index i + j where:

j <= nums[i]
i + j < nums.length
You are initially positioned at nums[0].

Return the minimum number of jumps to reach the last position in the array (index nums.length - 1). You may assume there is always a valid answer.

Example 1:

Input: nums = [2,4,1,1,1,1]

Output: 2
Explanation: Jump from index 0 to index 1, then jump from index 1 to the last index.

Example 2:

Input: nums = [2,1,2,1,0]

Output: 2
Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // Question says there will always be a valid answer so we do not need to worry about reachability

        // We can solve this using 2D Dp as two things change index and jumps 
        // But Greedy provides the optimised solution 

        // We keep range 
        // Meaning index i to j can be in reached in x jumps 
        // so if I take x jumps , the minIndex I can reach is i and maxIndex I can reach is j 

        int n = nums.size() ; 
        int l = 0  ; 
        int r =  0 ;
        int jumps = 0 ; 

        while(r < n - 1 ){ // As when r reaches n-1 we stop 
            int farthest = 0 ;

            for(int i = l ; i <= r ; i++ ){
                farthest = max(farthest , i + nums[i]);
            }

            l = r + 1 ; // As nums[i] >=0 and end is reachable so we can atleast reach r + 1 , after each jump 
            r = farthest ;
            jumps++;
        }

        //TC:O(n) as l-r moves as covering the entire array 
        // Another way to see this we only process every element once 
        // SC:O(1)
        return jumps ; 
        
    }
};
