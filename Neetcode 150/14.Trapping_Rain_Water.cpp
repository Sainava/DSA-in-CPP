/*
You are given an array of non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.

Example 1:



Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9
Constraints:

1 <= height.length <= 1000
0 <= height[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;


// Solution 1 : Prefix and Suffix Max  - Separate arrays for prefix and suffix max
class Solution { 
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //SC:O(2n)
        vector<int> prefixMax(n,0);// Max from 0 to that index
        vector<int> suffixMax(n,0); // Max from n -1 to that index 

        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n-1];

        for(int i = 1 ; i < n ; i++){
            prefixMax[i] = max(prefixMax[i-1],height[i]);
        }

        for( int i = n - 2 ; i >=0 ; i--){
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }

        int total = 0;

        for(int i = 0 ; i < n ; i++){
            int water = min(prefixMax[i],suffixMax[i]) - height[i]; // water above just this bar

            total += water;
        }

        //TC:O(3n) and SC:O(2n)
        return total ;
    }
};

// Solution 2 : Prefix and Suffix Max - Optimised space by using variables instead of arrays
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //SC:O(n)
        int prefixMax = 0;// Max from 0 to that index
        vector<int> suffixMax(n,0); // Max from n -1 to that index 

        suffixMax[n-1] = height[n-1];

        for( int i = n - 2 ; i >=0 ; i--){
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }

        int total = 0;

        for(int i = 0 ; i < n ; i++){
            prefixMax = max(prefixMax , height[i]);
            
            int water = min(prefixMax,suffixMax[i]) - height[i]; // water above just this bar

            total += water;
        }

        //TC:O(2n) and SC:O(n)
        return total ;
    }
};

// Solution 3 : Two Pointers - Optimised space by using two pointers and variables instead of arrays
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // We need to optimise space 
        // We needed extra space because we needed leftMax and rightMax for each i 
        // But in actuality we only need the minimum of the two , so if we can find that wihtout extra space , space is optimised 


        // Cannot traverse from left to right ,as then everything to the right of i is unseen 
        // Cannot traverse from right to left ,as then everything to the left of i is unseen 

        // Think of two pointers
        int l = 0 ; 
        int r = n - 1 ;


        // Core Idea ** -> Move the smaller one first , this means that all times 
        // The limiting height is obvious 

        int total = 0 ; 
        int leftMax = 0 ;
        int rightMax = 0 ;

        while(l < r){
            if( height[l] <= height[r]){
                // LeftMax will be limiting factor 
                if( leftMax > height[l]){
                    total+= leftMax - height[l];
                }else{
                    leftMax = height[l];
                }
                l++;
            }
            else {
                // RightMax will be limiting factor 
                if( rightMax > height[r]){
                    total+= rightMax - height[r];
                }else{
                    rightMax = height[r];
                }
                r--;
            }
        }
        // Okay now the main at all times , the only unseen to us are the heights between l and r

        // But since l only moves when it is smaller than r , we can say that 
        // rightMax >= height[r] >= height[l]
        // So leftMax now becomes the limiting factor 

        // Also consider this case :
        // Also say leftMax = 4 ;
        // height[l] = 1;
        // height[r] = 2 ;
        // rightMax = 2;
        // So we might think wait leftMax - height[l] will give wrong answer as rightMax is the limitng factor here 
        // But the above case will never arrive as 
        // when heigh[l] reaches 4 it will not move further until it is equal to or less than height[r]
        // so height[l] can never be 1 in this case as it stops for r to move as it reaches this case
        // In this way we can always be sure what is the limitng height 

        //TC:O(n) and SC:(1)
        return total ;
    }
};
