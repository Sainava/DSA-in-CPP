/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // // Brute 

        // // TC:O(nlogn)
        // sort(intervals.begin() , intervals.end());

        // vector<vector<int>> ans;
        
        // // This may look like n^2 but it is not 
        // // Except first element all element is seen twice 
        // // SO actual TC:O(2n)
        // for(int i = 0 ; i < n ; i++){
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];

        //     // First check if this interval is already considered in the previous ones

        //     if(!ans.empty() && end <= ans.back()[1]){
        //         continue ;
        //     }
        //     // if not , new starting point is this 
        //     // Now look ahead  and merge all intervals that can be merged 

        //     for(int j = i + 1 ; j < n ; j++){
        //         if( intervals[j][0] <= end){
        //             end = max( end , intervals[j][1]);
        //         }else{
        //             break ;
        //         }
        //     }

        //     ans.push_back({start ,end});
        // }

        // // TC : O( nlogn + 2n ) and SC : O( n ) for the answer , SC(1) extra space 
        // return ans ;

        // Optimised : We optimise the 2n pass to n 

        // TC:O(nlogn)
        sort(intervals.begin() , intervals.end());

        vector<vector<int>> ans;

        for( int i = 0 ; i < n ; i++ ) {

            // Form a new interval 
            if( ans.empty()  || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            // else it is part of the previous interval and we need to merge it 
            else{
                ans.back()[1] = max (ans.back()[1] , intervals[i][1]);
            }
        }

        //TC:O( nlogn + n ) and SC : O( n ) for the answer , SC(1) extra space 
        return ans ;
    }
};