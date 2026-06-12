/*
You are given an array nums, that might contain duplicates , return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]

Output: [
    [1,1,2],
    [1,2,1],
    [2,1,1]
]
Example 2:

Input: nums= [2,2]

Output: [[2,2]]
Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void func(unordered_map<int,int> &freq ,int n ,vector<int> &temp ,vector<vector<int>> &ans , vector<int>& nums){
        if( temp.size() == n){
            ans.push_back(temp);
            return ; 
        }

        // IMPORTANT -> DO &p : freq and NOT p:freq
        for( auto &p : freq ){
            if( p.second > 0 ){
                temp.push_back( p.first);
                p.second--;

                func( freq , n , temp , ans , nums);

                temp.pop_back();
                p.second++;
            }
           
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size() ; 

       unordered_map<int,int> freq ; 

       for(int num : nums){
        freq[num]++;
       }
        
        vector<vector<int>> ans ;  

        vector<int> temp ; 
        
        func( freq , n ,temp , ans , nums); 

        
        return ans ;

        // Let m = number of unique permutations
        // m = n! / (f1! * f2! * ... * fk!)
        // where fi are the frequencies of duplicate elements

        // Time Complexity:
        // O(m * n)
        // Reason:
        // - There are m unique permutations generated.
        // - Each permutation of length n is copied into ans via ans.push_back(temp),
        //   which costs O(n).
        //
        // Worst case (all elements distinct):
        // O(n * n!)

        // Auxiliary Space Complexity:
        // O(n)
        // Reason:
        // - Recursion depth is at most n.
        // - temp stores at most n elements.
        // - freq map stores at most n distinct values.

        // Output Space Complexity:
        // O(m * n)
        // Reason:
        // - ans stores m permutations, each of length n.
        //
        // Worst case:
        // O(n * n!)
    }
};