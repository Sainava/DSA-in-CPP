/*
Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 50
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 104 calls in total will be made to reset and shuffle.
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<int> original ;

    Solution(vector<int>& nums) {
        //TC:O(n) and SC:O(n)
        original = nums ;
        srand(time(0)); // seed
    }
    
    vector<int> reset() {
        // TC:O(n) and SC:O(n), a copy is made when we  returned so O(n)
        return original;
    }
    
    vector<int> shuffle() {
        //TC:(n) and SC:O(n) since the rand is independent of n and swap takes constant time 

        vector<int> temp = original;
        int n = temp.size();

        for(int i = 0 ; i < n ; i++){
            int j = i + rand() % ( n - i );

            // rand() generates  a random integer , may be very large too so 
            // % ( n - i) bring that number to max (n - i - 1 )
            // so j can be i + 0 to ( n - i - 1 )

            swap( temp[i] , temp[j]);
            
        }
        return temp ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */