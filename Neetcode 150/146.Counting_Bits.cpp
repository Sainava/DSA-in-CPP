/*
Given an integer n, count the number of 1's in the binary representation of every number in the range [0, n].

Return an array output where output[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 4

Output: [0,1,1,2,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100

Constraints:

0 <= n <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // Brute force -> call count set bits for each number in range

        // For any number 
        // If we remove the last bit we get thay number divided by 2 
        // Because n >> 1 = n / 2 
        // NO of set bits in n = no of set bits in (n / 2) + (n&1)
        // dp[i] = dp[i >> 1] + (i & 1)

        vector<int> dp( n + 1 , 0) ; 

        //dp[0] = 0 ; // Base case 

        for(int i = 0 ; i <= n ; i++){
            dp[i] = dp[i>>1] + (i & 1) ;
        } 

        // TC :O(n) and SC:O(1)
        return dp ;
    }
};
