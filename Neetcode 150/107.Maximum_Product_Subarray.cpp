/*

Given an integer array nums, find a subarray that has the largest product within the array and return it.

A subarray is a contiguous non-empty sequence of elements within an array.

You can assume the output will fit into a 32-bit integer.

Example 1:

Input: nums = [1,2,-3,4]

Output: 4
Example 2:

Input: nums = [-2,-1]

Output: 2
Constraints:

1 <= nums.length <= 1000
-10 <= nums[i] <= 10
*/
#include <iostream>
#include <vector>
using namespace std;

//Solution with prefix and suffix product :
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Four cases:
        // 1. All positive ->just multiply all 
        // 2. Even number of negatives -> just multiply all 
        // 3. Odd negative -> Just ignore the negative number closest to zero ( basically the max negative number) 
        // And multiply the rest 
        // 4. Contains -> zero in any of the above 3 cases , ignore zeroes 
        
        // So for all cases :
        // 1.and 2.  prefix Product = suffix product = multiple all and that is the answer 
        // 3. For odd negative , the answer is the maxOf(prefixProduct , suffixProduct) prefix is to left of maxNeg and suffix is to the right of maxNeg
        // 4. Ignore zeroes in all cases 

        // In all cases :
        // Essentially the maximum (prefix ,suffix) is the answer
        int n = nums.size();
        int prefix = 1 ; 
        int suffix = 1 ; 

        int maxi = INT_MIN ; 

        for(int i = 0 ; i < n ; i++){
            if(prefix == 0 ) prefix = 1 ; 
            if(suffix == 0 ) suffix = 1 ;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];

            maxi = max( maxi , max (prefix , suffix)); // This captures the maximum prefix or suffix 
        }

        //TC:O(n) and SC:O(1)
        return maxi ;
    }   
    
};

//Solution with dp :
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Like the prefix suffix solution we track two states here 
        // Max product ending at index i 
        // Min product ending at index i 
        // We need min product because a large negative number may become positive (by multiplying with a negative)
        int n = nums.size() ; 
        vector<vector<int>> dp(n , vector<int> (2,-1));

        dp[0][0] = nums[0] ; // max product ending at index 0 ;
        dp[0][1] = nums[0] ; // min product ending at index 0 ; 
        int ans = nums[0];

        for(int i = 1 ; i < n ; i++){
            int curr = nums[i] ; // this handles the zero case as well by reinitialising values with the value next to 0 

            int prevMax = dp[i-1][0];
            int prevMin = dp[i-1][1];

            dp[i][0] = max(curr ,max(nums[i]*prevMax ,nums[i]*prevMin));
            dp[i][1] = min(curr ,min(nums[i]*prevMax ,nums[i]*prevMin));
            ans = max(ans , dp[i][0]);
        }

        //TC:O(n) and SC:O(n)
        return ans;
    }
};
