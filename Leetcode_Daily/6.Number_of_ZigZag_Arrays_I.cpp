// 23 June 2026

//3699. Number of ZigZag Arrays I

/*
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]​​​​​​​
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 2000
1 <= l < r <= 2000
*/
#include <iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7 ;

    int zigZagArrays(int n, int l, int r) {
        // VERY VERY HARD Question 
        // See this video -> https://www.youtube.com/watch?v=jXbyP3i-dPQ

        // Step 1 -> shifting -> The answer from [l,r] is same as [0,r-l+1] as we only care about the no of ways
        int m = r - l + 1 ;

        // The recursive top-down approach is not accepted as it gives TLE -> O(n^3)
        // So we use bottom up that uses prefix Sum to pre-compute values and reduces complexity 

        vector<vector<int>> up(n + 1 , vector<int> (m , 0));
        vector<vector<int>> down(n + 1 , vector<int> (m , 0));

        // Base case -> We know the answer for length 2 

        for(int x = 0 ; x < m ; x++){
            for(int y = 0 ; y < m ; y++){

                if( x==y) continue ;

                if(x < y) up[2][y] = ( up[2][y] + 1 ) % MOD ;

                else down[2][y] = ( down[2][y] + 1 ) % MOD ;
            }
        }

        for(int i = 3 ; i <=n ; i++){
            // i is length of zigzag array 

            vector<int> prefixUp(m+1 , 0) , prefixDown(m+1 , 0);

            for(int v = 0 ; v < m ; v++){
                prefixUp[v+1] = (prefixUp[v] + up[i-1][v]) % MOD ;
                prefixDown[v+1] = (prefixDown[v] + down[i-1][v] ) % MOD ;
            }

            for(int y = 0 ; y < m ; y++){

                // up[i][y] = sum of down[i-1][y] for all x < y so from 0 to y-1
                up[i][y] = prefixDown[y] ;// Not y - 1 as we did 1 based indexing

                // down[i][y] = sum of up[i-1][y] for all x > y so y to m 
                down[i][y] = (( prefixUp[m] - prefixUp[y + 1]) % MOD + MOD) % MOD ;
            }
        }

        long long ans = 0 ; 
        if( n == 1){
            //single element arrays are always valid 
            ans = m ; 

        }else{
            for(int y = 0 ; y < m ; y++){
                ans = ( ans + up[n][y] + down[n][y]) % MOD ;
            }
        }


        //TC:O(n*m) and SC:O(n*m)
        return ans ; 
    }
};