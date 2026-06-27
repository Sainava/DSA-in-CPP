// 27 June 2026

// 3020. Find the Maximum Number of Elements in Subset

/*
You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:

You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.

 

Example 1:

Input: nums = [5,4,1,2,2]
Output: 3
Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and 22 == 4. Hence the answer is 3.
Example 2:

Input: nums = [1,3,2,4]
Output: 1
Explanation: We can select the subset {1}, which can be placed in the array as [1] which follows the pattern. Hence the answer is 1. Note that we could have also selected the subsets {2}, {3}, or {4}, there may be multiple subsets which provide the same answer. 
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= 109

*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Watch this : https://www.youtube.com/watch?v=On5UcupbF3o

        map<long long,int> freq ; // We use ordered map as starting from lowest number will increase size and since we remove after being used , we need to start from the lowest number 

        /// nlogn
        for(auto num : nums) freq[num]++;

        int ans = INT_MIN ; 

        // n in worst case 
        for( auto pair : freq){
            long long  x = pair.first ; 
            int count = 0 ; 

            while(freq.find(x) != freq.end() && freq[x]){
                if(x == 1) count += freq[x] ; // special case as we can take all the elements 
                else if ( freq[x] >= 2) count+= 2 ; // as we can only take the elements ( once while increasing and once while decreasing no matter how many occurances exist )
                else if ( freq[x] == 1) {
                    count+=1 ;
                    break ; // as we cannot check for x*x as x itself only occurs once 
                }
                freq[x] = 0 ; // Equivalent of removing this element 
                if( x > 1e5) break ;  // as constraint is 1 <= nums[i] <= 109 so 10^5 * 10^5 == 10^10 which exceeds 
                x = x * x ;
            }

            ans = max( ans , count) ; 
        }

        // Now final size can never be even as max element should occur only once so we reduce count if we counted it twice 

        //TC:O(nlogn) and SC:O(n)
        if( ans % 2 == 0 ) return ans - 1 ; 
        return ans ; 
    }
};