/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 105
-106 <= arr[i] <= 106
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin() , arr.end());

        // Now the minimum difference is difference between any two consecutive elements 

        vector<vector<int>> ans ; 
        int minDiff = INT_MAX;

        for(int i = 1 ; i< arr.size() ; i++){
            

            // Three cases 
            
            // Case 1 :  New smaller difference so clear the previous answers 
            if(abs(arr[i] - arr[i-1]) < minDiff){
                minDiff = abs(arr[i] - arr[i-1]);

                ans.clear();

                ans.push_back({arr[i-1]  , arr[i]});
            }

            // Case 2 : Same difference 
            else if ( abs(arr[i] - arr[i-1]) == minDiff ){
                ans.push_back({arr[i-1]  , arr[i]});
            }

            // Case 3 : Greater difference ignore 
        }
        
        //TC:O(nlogn) and SC:O(logn) (for the sorting )
        return ans ;
    }
};