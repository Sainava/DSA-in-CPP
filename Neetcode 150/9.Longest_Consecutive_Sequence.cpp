/*
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:

Input: nums = [0,3,2,5,4,6,1,1]

Output: 7
Constraints:

0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9

*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool linearSearch(int val ,vector<int>& nums ){
        for(int num : nums){
            if( num == val){
                return true ; 
            }
        }

        return false ;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // // Brute force 
        // int maxCount = 1 ;

        // for(int i = 0 ; i < n ; i++){
        //     int curr = nums[i];
        //     int count = 1;

        //     while( linearSearch(curr+1 , nums)){
        //         curr++;
        //         count++;
        //     }

        //     maxCount = max(maxCount , count );
        // }

        // //TC:O(n^3) and SC:(1)
        // return maxCount ; 

        // // Better Solution 
        // //TC:O(nlogn)
        // sort(nums.begin() , nums.end());

        // int maxCount = 1 ;
        // int count = 1;
        // int lastSmaller = INT_MIN ;

        // //TC:O(n + logn)
        // for(int i = 0 ; i < n ; i++){
        //     if(nums[i] - 1 == lastSmaller){
        //         count++;
        //         lastSmaller = nums[i];
        //     }

             
        //     // else if (nums[i]==lastSmaller){
        //     //     do nothing ;
        //     // }

        //     else if ( nums[i]!= lastSmaller){
        //         lastSmaller = nums[i];
        //         count = 1 ;
        //     }

        //     maxCount = max(maxCount , count);

        // }

        // //TC:O(n + nlogn) and SC:(1)
        // return maxCount ;

        // Optimised solution 

        if(n==0) return 0 ;

        unordered_set<int> st;

        //TC:O(n)
        for(int num : nums){
            st.insert(num);
        }

        int maxCount = 1;

        //TC:O(2n) as each element and visited once and then second time for its sequence in worst case
        // Also insert and count are O(1) when no collisions 
        for(int num:st){

            // if its previous exists, then it has already been counted 
            if( st.count(num - 1)){
                continue;
            }

            int count = 1;

            while ( st.count( num + 1)){
                num++;
                count++;
            }

            maxCount = max(maxCount , count);

        }
        // st.insert and 


        //TC:O(3n) and SC:(n)
        return maxCount ;
    }
};
