/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>  
using namespace std;

class Solution {
public:
    bool linearSearch(int num ,vector<int>& nums ){
        for(int x:nums){
            if (x == num){
                return true ;
            }
        }

        return false ;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // // Brute Force 
        // if(n == 0) return 0 ;
        // int maxCount = 1 ;
        // for(int i = 0 ; i < n ; i++){

        //     int curr = nums[i];
        //     int count = 1 ;
        //     while(linearSearch(curr + 1 , nums)){
        //         curr = curr + 1 ;
        //         count++;
        //     }

        //     maxCount = max(maxCount , count);
        // }

        // //TC:O(n^3) and SC:O(1) auxillary space 
        // return maxCount ;

        // // Better Solution 

        // sort(nums.begin() , nums.end()) ;

        // int maxCount = 1;
        // int lastSmaller = INT_MIN;
        // int count= 0 ;

        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(nums[i] - 1 == lastSmaller ){
        //         count++;
        //         lastSmaller = nums[i];
        //     }
        //     //else if( nums[i] == lastSmaller){
        //         // Do not do anything 
                
        //     // }
        //     else if ( nums[i] != lastSmaller ){
        //         count = 1 ;
        //         lastSmaller = nums[i] ;
        //     }

        //     maxCount = max(maxCount , count);
            
        // }

        // //TC:O(nlogn + n) and SC:(1)
        // return maxCount ;

        // Optimal solution 

        // Unordered_Set takes time O(1) except in the case of collision where they take O(n) which is very very rare   
        if(n==0) return 0 ;

        unordered_set<int> st ;

        // SO TC:O(n)
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }

        int maxCount = 1 ;

        // For the following TC:O(2n)
        // TC:O(n) to go to every element in set 
        // But the while loop does not make it n^2 as we only mve forward when next elements exist 
        // So total TC: is approximately O(2n)
        for(int num : st){
            // Check if its previous number exists - do nothing , next iteration
            if(st.find(num -1 ) != st.end()){
                continue ;
            }

            int count = 1 ;

            //else check how far can it go 
            while(st.find( num + 1) != st.end()){
                num++;
                count++;
            }

            maxCount = max(maxCount , count );
        }

        //TC:O(3n) when no collisions 
        // SC:O(n)
        return maxCount ;
    }
};