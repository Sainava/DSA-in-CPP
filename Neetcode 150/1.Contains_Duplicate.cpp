/*
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        // SOlution 1 : Using hash map 
        // //SC:O(n)
        // unordered_map<int,int> cnt ;

        // //TC:O(n)
        // for(int num :nums){
        //     cnt[num]++;
        // }

        // //TC:O(n)
        // for(auto p : cnt ){
        //     if ( p.second >1) return true ;
        // }

        // //TC :O(n) and SC:O(n)
        // return false ;

        // Solution 2 : Using hash set since we only count about the element and not the count
        // SC:O(n)
        unordered_set<int> st;

        // For unordered_set both find( which returns iterator ) and count( which returns 1 if found and 0 if not found) have O(1) complexity 
        // TC:O(n)
        for(int num : nums ){
            if( st.find( num ) != st.end()){
                return true ;
            }

            st.insert(num);
        }
        // insert also has complexity O(1) if no clash 

        // TC:O(1) and SC:O(1)
        return false ;
    }
};