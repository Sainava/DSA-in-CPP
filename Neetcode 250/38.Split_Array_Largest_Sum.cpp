/*
You are given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [2,4,10,1,5], k = 2

Output: 16
Explanation: The best way is to split into [2,4,10] and [1,5], where the largest sum among the two subarrays is only 16.

Example 2:

Input: nums = [1,0,2,3,5], k = 4

Output: 5
Explanation: The best way is to split into [1], [0,2], [3] and [5], where the largest sum among the two subarrays is only 5.

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1,000,000
1 <= k <= min(50, nums.length)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPossible(int maxSum ,vector<int>& nums, int k){
        int sum = 0 ; // Sum of that subarray at that time 
        int cnt = 1 ; // No of subarrays 


        //TC:O(n)
        for(int i = 0 ; i < nums.size() ; i++ ){
            if( sum + nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                sum = nums[i]; ; 
                cnt++;

                if(cnt > k){
                    return false ; 
                }

            }
        }

        return true ; 
    }

    int splitArray(vector<int>& nums, int k) {
        
        int maxi = INT_MIN ;
        int sum = 0 ;

        for(int num : nums){
            maxi = max(maxi , num);
            sum += num ;
        }

        int start = maxi ; 
        int end = sum ; 

        // Basically the mini sum of an subarry and maximum sum can be this 
        // We now do binary search on this and see what values are possible 

        // We need to find he minimum largest sum of subarray 

        // If one max sum is possible , we know anything more will also be possible 
        // SO we see if anything less is possibe ;

        int ans = end ; 
        
        //TC :O(n log( sum - maxi ))
        while(start <= end ){
            int mid = start + ( end - start) / 2 ;

            if(isPossible(mid , nums , k)){
                ans = mid ; 
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ; 
            }
        }


        //TC :O(n log( sum - maxi )) and SC:O(1)
        // Approx TC:O(nlog(sum(n)))
        return ans ; 
    }
};