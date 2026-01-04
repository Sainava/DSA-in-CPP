/*
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

Example 1:


Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.
Example 2:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
1 <= n <= 5000
*/
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
 

    int numOfWays(int n) {
        // No of ways to paint a row of size of 3 = 3 x 3 x3 =27
        // Horizontal constraints - consecutive cells cannot be same color so = 3 x 2 x 2= 12
        // For each row in grid , considering only row constraints , there are 12 possible values 
        // Here each row depends only on the previous row , therefore we can use dp 
        // DP is : “Same decisions repeated with the same constraints”

        // dp[i][s] = number of ways to paint rows [0..i] where row i uses state s
        // i → row index
        // s → index of one of the 12 valid row states

        int MOD = 1e9 + 7;

        // Step 1 : Generate all  12 valid states of  (R, Y, G) = {0,1,2}
        // array<int , 3 > fixes size at 3 
        // TC:O(12) = O(1) and SC:O(12) = O(1)
        vector<array<int,3>> states;
        for(int a = 0 ; a < 3 ; a++ ){
            for(int b = 0 ; b < 3 ; b++ ){
                for(int c = 0 ; c < 3 ; c++){
                    if( a!=b && b!= c){
                        states.push_back({a,b,c});
                    }
                }
            }
        }

        int m = states.size(); // Should be 12 

        // Step 2 : Check compatability  -- See which out of the 12 patterns can follow each other following column pattrn as well 
        // States follow just row constraint 
        // can Follow will take care of both row and column constraint
        //TC:O(12 x 12 x 3) =O(1)
        vector<vector<int>> canFollow(m);
        for( int i = 0 ; i < m ; i++){
            for ( int j = 0 ; j < m ; j++){

                bool ok = true ; 

                for(int k = 0 ; k < 3 ; k++){
                    if(states[i][k] == states[j][k]){
                        ok=false;
                        break;
                    }
                }

                if(ok){
                    canFollow[i].push_back(j) ; // means pattern i is compatable with pattern j 
                }
            }
        }

        // Step 3 : DP
        // For two rows prev and curr they are compatable if 
        // prev[j] != curr[j] for j = 0,1,2
        // prev is first row and hence each position 1 as it can start with any pattern out of the 12 
        //SC:O(1) as fixed size 
        vector<long long> prev(m, 1), curr(m, 0);

        //TC:O(n x 12 x 12) = O(n)
        for(int row = 1 ; row < n ; row++){
            fill(curr.begin() , curr.end() , 0 ) ;// For each row , start by making 0 

            for( int i = 0 ; i < m ; i++){
                for (int j : canFollow[i]) {
                    curr[j] = (curr[j] + prev[i]) % MOD;
                }
            }
            prev = curr;
        }

        // Step 4: sum all possibilities of last row
        long long ans = 0;
        for (long long x : prev) {
            ans = (ans + x) % MOD;
        }

        //TC:O(n) and SC:O(1)
        return ans ; 
        
    }
};