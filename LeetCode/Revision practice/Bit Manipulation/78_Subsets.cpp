/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include<iostream>
#include<vector>
using namespace std ;

// Solution 1 : Recursion 
class Solution {
public:
    void solve(vector<int>& nums ,  vector<vector<int>> &ans ,vector<int> temp , int index ){
        // Base index 

        if(index >= nums.size()){
            ans.push_back(temp);
            return ;
        }

        //exclude 
        solve(nums,ans,temp,index+1);

        // include 
        temp.push_back(nums[index]);
        solve(nums,ans,temp,index+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;

        vector<int> temp ;

        int index = 0 ;

        solve(nums , ans , temp , index);

        // Each element has 2 choices so for n elements 2^n 
        // Also copying n elements at average from temp to ans takes n time so 
        //TC:O( n*2^n)

        // Space 
        // Total subsets : 2^n
        // Size each : n ( about as we cannot say exact)
        // Recursion stack (n)
        // SC:O(n*2^n)
        return ans;
    }
};

// Solution 2 : Bit Manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Bit manipulation 
        //SC:O(2^n)
        vector<vector<int>> ans;
        int n=nums.size();

        //There are 2^n subsets -- that is 1<<n
        // So outer loop runs for 2^n , one to store each subset
        // Like for 8 subsets , we go from 0 to 7 
        // Then in the binary number of each we see how many set and unset bits 
        //TC:O(2^n)
        for(int num = 0  ; num < (1<<n) ; num++){

            vector<int> temp;

            // For each element of the nums -- we see whether in the num , is it set bet (1 meaning include) or clear ( 0 meaning do not take ) 
            for(int i = 0 ; i < n ; i++){

                // See if the ith bit is set or not in num 
                
                // if set - include
                if((num >> i) & 1){
                    temp.push_back(nums[i]);
                }
                // if not -- exclude so do nothing 
                 
            }
            //TC:(n) -- approx as we cannot exact 
            ans.push_back(temp);
        }

        //TC:O(n*2^n) and SC:O(n*2^n) but here no recursive space is needed 
        return ans;
    }
};
