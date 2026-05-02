/*
You are given an integer array heights where heights[i] represents the height of the 
i
t
h
i 
th
  bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:



Input: height = [1,7,2,5,4,7,3,6]

Output: 36
Example 2:

Input: height = [2,2,2]

Output: 4
Constraints:

2 <= height.length <= 1000
0 <= height[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0 ;
        int j = n - 1;

        int maxArea = 0;

        while(i<j){
            int area = min(heights[i] , heights[j]) * (j - i) ;

            if( heights[i] < heights[j]) i++;
            else j--;

            maxArea = max(maxArea , area);
        }

        //TC:O(n) and SC:O(1)
        return maxArea;
    }
};
