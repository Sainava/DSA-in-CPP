/*
You are given an integer array nums, an integer array queries, and an integer x.

For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

Return an integer array answer containing the answers to all queries.

 

Example 1:

Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

Output: [0,-1,2,-1]

Explanation:

For the 1st query, the first occurrence of 1 is at index 0.
For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
For the 3rd query, the second occurrence of 1 is at index 2.
For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.
Example 2:

Input: nums = [1,2,3], queries = [10], x = 5

Output: [-1]

Explanation:

For the 1st query, 5 doesn't exist in nums, so the answer is -1.
 

Constraints:

1 <= nums.length, queries.length <= 105
1 <= queries[i] <= 105
1 <= nums[i], x <= 104
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {

        // // Keep a hash_map to keep track of all occurences of x in nums

        // unordered_map<int,int> mp ; // occurence no and index

        // int cnt = 1 ; // 

        // //TC:O(n)
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(nums[i] == x){
        //         mp[cnt++] = i;
        //     }
        // }

        // // Now process the queries 

        // vector<int> ans;

        // //TC:O(m) assuming no collisions
        // for(int i = 0 ; i < queries.size() ; i++){

        //     if(mp.find(queries[i]) != mp.end()){
        //         ans.push_back(mp[queries[i]]);
        //     }else{
        //         ans.push_back(-1);
        //     }
        // }

        // //TC:O(n + m) when no collisions and SC:O(n)
        // return ans; 

        // Can use a vector instead of map to prevent the slight chance of collisions 

        vector<int> pos;

        //TC:O(n)
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == x){
                pos.push_back(i); // 1st occurence at index 0 ; 2nd at index 1 and so on ;
            }
        }

        // Now process the queries 

        vector<int> ans;

        //TC:O(m) assuming no collisions
        for(int query : queries ){
            if( query <= pos.size()){
                ans.push_back( pos[query - 1]) ; // since 1 based indexing 
            }else{
                ans.push_back(-1);
            }
        }

        //TC:O(n + m) always and SC:O(n)
        return ans;


    }
};