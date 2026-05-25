/*
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

You may return the answer in any order.

Note: Intervals are non-overlapping if they have no common point. For example, [1, 2] and [3, 4] are non-overlapping, but [1, 2] and [2, 3] are overlapping.

Example 1:

Input: intervals = [[1,3],[1,5],[6,7]]

Output: [[1,5],[6,7]]
Example 2:

Input: intervals = [[1,2],[2,3]]

Output: [[1,3]]
Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= start <= end <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size() ;

        vector<vector<int>>  ans ;

        sort(intervals.begin() , intervals.end());

        ans.push_back(intervals[0]);

        for(int i = 1 ; i < n ; i++){
            if(ans.back()[1] >= intervals[i][0]){
                // Need to merge 
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }

        //TC:O(nlogn) and SC:O(n) to return ans  
        return ans ;
    }
};
