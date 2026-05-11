/*
You are given an array of integers candidates, which may contain duplicates, and a target integer target. Your task is to return a list of all unique combinations of candidates where the chosen numbers sum to target.

Each element from candidates may be chosen at most once within a combination. The solution set must not contain duplicate combinations.

You may return the combinations in any order and the order of the numbers in each combination can be in any order.

Example 1:

Input: candidates = [9,2,2,4,6,1,5], target = 8

Output: [
  [1,2,5],
  [2,2,4],
  [2,6]
]
Example 2:

Input: candidates = [1,2,3,4,5], target = 7

Output: [
  [1,2,4],
  [2,5],
  [3,4]
]
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void solve(vector<int>& candidates, int target ,vector<vector<int>> &ans ,vector<int> &temp , int index){
        if( target == 0){
            ans.push_back(temp);
            return ;
        }

        // from this index , we can specify the range of indexes which we can take 
        // from index to the end 

        for(int i = index ; i < candidates.size() ; i++){
            // main codition 
            if( i > index && candidates[i]==candidates[i-1]) {
                // This means this same element has already been taken at this decision point so skip 
                continue ;
            }

            // Skip if greater than target , then the rest will be too
            if( candidates[i] > target ) break ;

            // Now take it
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i] , ans , temp , i+1);
            temp.pop_back();// backtrack
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort first , helps in the condition we need to check so that we do not get same combination 
        sort(candidates.begin() , candidates.end());

        vector<vector<int>> ans ;
        vector<int> temp ;
        int index = 0 ; 
        // The point of index is at every index we check from index to n-1 , which element we can take 
        // So index basically specifies the point where we need to decide an element to take
        // so if i(looping variable) is greater than index(i > index) and candidate[i] == candidate[i-1] , we skip , because we are sure this element was already taken before for this decision point
        // The value of index does not matter as much , it just decides the range of indexes we can choose from,
        // The main idea of index is it signifies a decision point  

        solve(candidates, target , ans , temp , index);

        //TC:O(2^n * k) as the total possible combinations we can have is just no of subsets so 2^n and if size of each temp is k then copying takes k 
        //SC:O(k * x) size of each answer , and x is no of answers 
        // and recursion stack SC:O(n)
        return ans ;
        
    }
};
