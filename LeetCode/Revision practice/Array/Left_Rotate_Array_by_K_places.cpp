/*
Problem statement
Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.



Example:
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8
7 5 2 11 2 43 1 1
2
Sample Output 1:
2 11 2 43 1 1 7 5
Explanation of Sample Input 1:
Rotate 1 steps to the left: 5 2 11 2 43 1 1 7
Rotate 2 steps to the left: 2 11 2 43 1 1 7 5
Sample Input 2:
4
5 6 7 8
3
Sample Output 2:
8 5 6 7
Explanation of Sample Input 2:
Rotate 1 steps to the left: 6 7 8 5
Rotate 2 steps to the left: 7 8 5 6
Rotate 2 steps to the left: 8 5 6 7
Expected Time Complexity:
O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
Constraints:
1 <= 'n' <= 10^3
1 <= 'arr'[i] <= 10^9
1 <= 'k' < 'n'


Hints:
1. For an index ‘i’, find where it lands after k swaps.
2. When performing rotation once observe how the positions of all elements change.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int>nums, int k) {
    // //Brute Force -- Store k elements first and then just place them at the end 
    // // Rotate the rest appropriately 
    // int n = nums.size();

    // k = k % n ; 

    // //TC:O(k)
    // vector<int> temp(nums.begin() , nums.begin() + k);

    // // Shift the other elements 
    // //TC:O(n - k)
    // for(int i = k ; i < n ; i++){
    //     nums[i-k] = nums[i];
    // }

    // // Now place the elements in temp at the end 
    // //TC:(k)
    // for(int i = n - k ; i < n ; i++){
    //     nums[i] = temp[i - (n-k)];
    // }

    // //TC:O(k  + n - k + k) = TC:O(n + K)
    // //SC:(k)
    // return nums ;

    // Optimal solution 

    //TC:O(k)
    reverse(nums.begin() , nums.begin() + k);
    
    //TC:O(n-k)
    reverse( nums.begin() + k , nums.end());

    //TC:O(n)
    reverse(nums.begin() , nums.end());
    
    //TC:O(k + n-k + n) = TC:O(2n)
    //SC:O(1)
    return nums;

}
