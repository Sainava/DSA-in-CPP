/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // // Brute force -- > O(n square) --> 

        // for(int i =0 ; i < nums.size() ; i++){
            
        //     for(int j = 0 ; j < nums.size() ; j++){
        //         if(nums[i]==nums[j] && i!= j ){
        //             return true ;
        //         }
        //     }
        // }

        // return false ;

        // // Sort the array and then check 
        // // TC:O(nlogn)
        // //SC:O(logn) space used in sort function 

        // sort(nums.begin() , nums.end());

        // for( int i = 0 ; i < nums.size() - 1 ; i++ ){
        //     if(nums[i] == nums[i+1]){
        //         return true ;
        //     }
        // }

        // return false ;

        // Using hash map 
        //TC:O(n)
        //SC:O(n)
        unordered_map<int,int> mp ;

        for( int i = 0 ; i < nums.size() ; i++){
            
            // mp.find(element) returns iterator to the postion of element or pointer to the end if not found 

            // CHeck if already in map that is we've already seen it before 
            if(mp.find(nums[i]) != mp.end()){
                return true ;
            }
            mp[nums[i]] = 1; // Count does not matter here but 1 shows it is present 
        }

        return false ;

        // Using set
        // Set and map give the same complexities , but since we just need to insert elements here and do not care about the count ( the value in key value ) , set is better as key-value is not stored so less memory 

        unordered_set<int > st;
        //TC and SC:O(n)

        for(int i = 0 ; i < nums.size() ; i++){

            // if(st.find(nums[i]) != st.end()){
            //     return true;
            // }
            // st.insert(nums[i]);

            // Or 
            if(st.insert(nums[i]).second == false){
                return true;
            }
            // insert returns two values , iterator to the element if insertion sucessful and bool value 
            // returns false bool value if insertion failed that is duplicate entry tried 

        }

        return false;
    }
};