/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std ;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // // Space optimised 
        // int i = 0 ;
        // int j = 0 ;

        // // TC:O(nlogn)
        // sort(nums1.begin() , nums1.end()) ;
        // //TC:(mlogm)
        // sort(nums2.begin() , nums2.end()) ;

        // vector<int> ans;

        // //TC:O(n + m)
        // while( i < nums1.size() && j < nums2.size()){

        //     if( nums1[i]==nums2[j]){
        //         if(ans.empty() || ans.back() != nums1[i]){
        //             // Since it should be unique 
        //             ans.push_back(nums1[i]);
        //         }
                
        //         i++;
        //         j++;
        //     } else if( nums1[i] < nums2[j]){
        //         i++;
        //     }else{
        //         j++;
        //     }
        // }

        // //TC:O(nlogn + mlogm + (n + m)) and SC:O(1)
        // return ans;


        // Time  optimised 
        // Use a set 

        //TC:O(n)
        unordered_set<int> st(nums1.begin() , nums1.end());

        vector<int> ans ;

        //TC:O(m) as unordered_set.count and erase both are O(1)
        for(int i = 0 ; i < nums2.size() ; i++){
            if(st.count(nums2[i])){
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }

        //TC:O( n + m ) and SC:O(n) for the set
        // TC can go to O(n^2) when collisions but those are rare
        return ans;
    }
};