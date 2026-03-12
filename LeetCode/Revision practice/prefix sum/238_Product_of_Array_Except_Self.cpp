/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

    // //Brute Force
    // vector<int> ans ;

    // int prefix = 1;
    
    // for(int i = 0 ; i< nums.size() ; i++){
        
    //     int suffix = 1;
    //     for(int j = i+1 ; j < nums.size() ; j++){
    //         suffix *= nums[j];
    //     }

    //     ans.push_back(prefix*suffix);

    //     prefix*=nums[i];
    // }

        //TC:O(n^2) and SC:O(1)
    // return ans;   
    // }

    // Better solution - Use two arrays -prefix and suffix 
      int n = nums.size();

        vector<int>prefix;
        int pre = 1 ;

        for(int i = 0 ; i < n ; i++ ){
            prefix.push_back(pre);
            pre *= nums[i];
        }

        vector<int>suffix(n);
        int suff = 1 ;

        for(int i = n - 1 ; i >=0 ; i-- ){
            suffix[i]=suff;
            suff*=nums[i];
        }

        vector<int> ans ;
        for(int  i = 0 ; i < n ; i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        //TC:O(3n) and SC:O(2n)
        return ans ;


    // // Optimal solution - best space 
    // vector<int> ans ;

    // //We will use ans as the extra space needed and the final answer
    // // Calculate prefix for every element

    // int prefix = 1;

    // //TC :O(n)
    // for(int i = 0 ; i < nums.size() ; i++){
    //     ans.push_back(prefix);
    //     prefix *= nums[i];
    // }

    // // Now from the back do suffix again 
    // int suffix = 1;
    // //TC:O(n)
    // for(int i = nums.size() - 1  ; i >=0 ; i--){
    //     prefix = ans[i];
    //     ans[i] = prefix * suffix ;

    //     suffix *= nums[i];
    // }

    // //TC:O(2n) and SC:O(1) extra space , SC:O(n) including ans 
    // return ans;
}

};