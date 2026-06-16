/*
You are given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
Example 1:

Input: arr = [2,4,3,2,2,5,1,4]

Output: 4
Explanation: The longest turbulent subarray is [2,5,1,4].

Example 2:

Input: arr = [1,1,2]

Output: 2
Constraints:

1 <= arr.length <= 40,000
0 <= arr[i] <= 1,000,000,000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0 ; 
        int r = 1 ; 

        int maxLen = 1 ; // We are given that the array will atleast have 1 element
        string prev = "" ;

        int n = arr.size() ; 

        while( r < n){
            if( arr[r-1] > arr[r] && prev != ">"){
                maxLen = max(maxLen , r - l + 1);
                r++ ; 
                prev = ">" ;
            }

            else if( arr[r-1] < arr[r] && prev != "<"){
                maxLen = max(maxLen , r - l + 1);
                r++ ; 
                prev = "<" ;
            }
            else {
                // We had consecutive same signs or we encountered a equal to 

                if( arr[r - 1] == arr[r]){
                    // We need to update r as we ignore = 
                    r++ ; 
                }
                l = r - 1 ; 
                prev = "" ;
            }
        }

        //TC:O(n) and SC:O(1)
        return maxLen ;

        // For the else case here is how to understand it 
        // { 9 > 4 > 2 < 10 > 7 < 8 = 8 > 1 < 9}

        // for when right 8 = 8( R HERE )  this 8 = 8 cannot contribute to answer so we increment
        // and it becomes ( l here)8 > 1( r here)

        // But if it was < instead of = 
        // { 9 > 4 > 2 < 10 > 7 < 8 < 9 > 1 < 9}
        // When 8 < 9( r here ) the turbulence break as < is repeated but this (8 < 9) can contribute to other answer so we do not move r 


    }
};