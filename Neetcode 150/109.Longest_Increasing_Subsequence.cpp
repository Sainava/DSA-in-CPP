/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the relative order of the remaining characters.

For example, "cat" is a subsequence of "crabt".
Example 1:

Input: nums = [9,1,4,2,3,3,7]

Output: 4
Explanation: The longest increasing subsequence is [1,2,3,7], which has a length of 4.

Example 2:

Input: nums = [0,3,1,3,2,3]

Output: 4
Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;


// Solution with O(n^2) time and O(n^2) space
class Solution {
public:
    int func(int index ,int prevIndex , vector<int>& nums , int n){
        // Base case 
        if(index == n ){
            // The length of LIS starting at index n(out of bounds) is ofcourse 0
            return 0 ;
        }

        // Either take or not take

        // Not take  -> index +1 and preIndex does not change and no change in length of subsequence
        int len =0 + func(index+1 , prevIndex , nums , n);

        // Take 
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            int take = 1 + func(index+1 , index , nums ,n);
            len = max(len , take);
        }

        return len ; 
        
    }

    int funcTopDown(int index ,int prevIndex , vector<int>& nums , int n ,vector<vector<int>> &dp){
        // Base case 
        if(index == n ){
            // The length of LIS starting at index n(out of bounds) is ofcourse 0
            return 0 ;
        }

        if(dp[index][prevIndex+1]!= -1) return dp[index][prevIndex+1] ;
        // Either take or not take

        // Not take  -> index +1 and preIndex does not change and no change in length of subsequence
        int len =0 + funcTopDown(index+1 , prevIndex , nums , n , dp);

        // Take 
        if((prevIndex) == -1 || nums[index] > nums[prevIndex]){
            int take = 1 + funcTopDown(index+1 , index , nums ,n ,dp);
            len = max(len , take);
        }

        return dp[index][prevIndex+1] = len ; 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int index = 0 ; 
        int prevIndex = -1 ; 

        //Recursion 
        //return func(index , prevIndex , nums , n ); // Gives the length of longest increasing subsequence starting at index with previous element = nums[prevIndex]

        // //Top Down 
        // vector<vector<int>> dp(n , vector<int> (n+1 , -1));
        // //dp[index][prevIndex] ==  Gives the length of longest increasing subsequence starting at index with previous element = nums[prevIndex]
        // // we did prevIndex = n+1 as we shifter -1 to 0 , 0 to 1 and so on , as -1 cannot be index in array
        // //TC:O(n^2) and SC:O(n^2)
        // return funcTopDown(index , prevIndex  , nums , n ,dp);

        // //Bottom - UP 
        // vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0)); 
        // // Intialise with zero 
        // // As base case is for index == n return 0 ;
        // // So all dp[n][any] == 0 

        // // Write the changing parameters in reverse fashion 
        // for(int index = n-1 ; index>=0 ; index--){
        //     for(int prevIndex = index-1 ; prevIndex >= -1 ; prevIndex--){
        //         // Not take
        //         int len =0 +dp[index+1][prevIndex+1];
        //         // Take 
        //         if((prevIndex) == -1 || nums[index] > nums[prevIndex]){
        //             int take = 1 + dp[index+1][index+1];
        //             len = max(len , take);
        //         }

        //         dp[index][prevIndex+1] = len ; 
        //     }
        // }
        
        // //TC:O(n^2) and SC:O(n^2)
        // return dp[0][-1+1];

        // Space Optimisation 
        vector<int> curr(n+1 , 0);
        vector<int> next(n+1 , 0);

        for(int index = n-1 ; index>=0 ; index--){
            for(int prevIndex = index-1 ; prevIndex >= -1 ; prevIndex--){
                // Not take
                int len =0 +next[prevIndex+1];
                // Take 
                if((prevIndex) == -1 || nums[index] > nums[prevIndex]){
                    int take = 1 + next[index+1];
                    len = max(len , take);
                }

                curr[prevIndex+1] = len ; 
            }
            next = curr;
        }

        //TC:O(n^2) and SC:O(n)
        return curr[-1+1];

    }
};

// Solution 2 : Print LIS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> dp( n , 1 );
        vector<int> hash(n);
        // dp[i] stores the length of the longest increasing subsequence ending at i 
        int maxi = INT_MIN ; // As we need the maximum value from dp 
        int lastIndex = - 1; 
        for(int index = 0 ; index < n ; index++){
            for(int prevIndex = 0 ; prevIndex < index ; prevIndex++){
                hash[index] = index ;
                if(nums[prevIndex] < nums[index] && dp[prevIndex]+1 > dp[index]){
                    dp[index] =dp[prevIndex] + 1;
                    hash[index] = prevIndex ; 
                }
            }
            if(dp[index] > maxi ){
                maxi = dp[index];
                lastIndex = index ;
            }

        }

        //Print the LIS
        vector<int> ans( maxi);
        ans.push_back(lastIndex);
        while(hash[lastIndex]!= lastIndex){
            lastIndex= hash[lastIndex];
            ans.push_back(lastIndex);
        }

        reverse(ans.begin() , ans.end());
        // Now ans contains the LIS

        //TC:O(n^2) and SC:O(n)
        // This solution is needed to print the LIS
        return maxi;
    }
};

// Solution 3 : Optimised with Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Optimised using binary search 

        vector<int> temp ; 
        temp.push_back(nums[0]);
        int len = 1 ; 
        for(int i = 1 ; i < nums.size() ; i++){
            if( nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++ ;
            }else{
                //In C++, lower_bound is a standard library function used to find the first element in a sorted range that is greater than or equal to a specified value
                auto ind = lower_bound(temp.begin() , temp.end() , nums[i]);
                int index = ind - temp.begin() ; // Because iterators behave like pointers 
                temp[index] = nums[i];
            }
        }
        // Important : temp is not the LIS , so we cant print LIS using this solution 
        // return temp.size(); // This takes a bit more space
        // TC:O(nlogn) and SC:O(n)
        return len ;
    }
};
