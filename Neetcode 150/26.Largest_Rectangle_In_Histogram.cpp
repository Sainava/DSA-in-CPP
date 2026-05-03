/*
You are given an array of integers heights where heights[i] represents the height of a bar. The width of each bar is 1.

Return the area of the largest rectangle that can be formed among the bars.

Note: This chart is known as a histogram.

Example 1:

Input: heights = [7,1,7,2,2,4]

Output: 8
Example 2:

Input: heights = [1,3,7]

Output: 7
Constraints:

1 <= heights.length <= 1000.
0 <= heights[i] <= 1000

*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();


        vector<int> nextSmaller(n,n) ;
        stack<int> st1 ;

        vector<int> prevSmaller(n,-1);
        stack<int> st2;

        for(int i = 0 ; i < n ; i++){

            while( !st1.empty() && heights[i] < heights[st1.top()]){
                nextSmaller[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);           
        }

        for(int i = n - 1; i >= 0 ; i--){

            while( !st2.empty() && heights[i] < heights[st2.top()]){
                prevSmaller[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);           
        }

        int maxArea = 0;

        for(int i = 0 ; i < n ; i++){
            int height = heights[i];
            int maxWidth = nextSmaller[i] - prevSmaller[i] - 1;

            int area = height*maxWidth;

            maxArea = max(maxArea,area);
        }

        //TC:O(n) and SC:O(n)
        return maxArea;

    }
};
