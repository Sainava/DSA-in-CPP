/*
You are given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:

Input: n = 4

Output: 4
Explanation: 4 = 2 + 2, 2 x 2 = 4.

Example 2:

Input: n = 12

Output: 81
Explanation: 12 = 3 + 3 + 3 + 3, 3 x 3 x 3 x 3 = 81.

Constraints:

2 <= n <= 58

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n , int original ,vector<int> &dp){
        if( n == 1) return 1 ; 

        if (dp[n]!= -1) return dp[n] ;

        int prod = 0 ; // It is compulsory to break down the original number given to us 

        if( n != original){
            prod = n ; // But subproblems need not be broken down 
        }  
        
        // Say we divide 4 to 3 and 1 , we needed to break 4 as that was the question 
        // But breaking 3 down to 2 and 1 does not give us our max number that we need 

        for(int i = 1 ; i < n ; i++){ // Important < n and <= n as 0 + n will give 0 we do not have base case for n == 0  
            int left = i ; 
            int right = n - i ; 

            int value = solve(left , original ,dp) * solve(right , original ,dp);
            prod = max( prod , value);
        }

        return dp[n] = prod ;
    }

    int integerBreak(int n) {
        int original = n ;

        vector<int> dp( n + 1 , -1 );

        // Time Complexity: O(n²)
        //
        // There are n states:
        //   solve(1)...solve(n)
        //
        // Each state tries all splits:
        //
        //   1 + (n-1)
        //   2 + (n-2)
        //   ...
        //
        // Therefore:
        //
        // O(n²)
        return solve(n , original , dp);
    }
};


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp( n + 1 , 0 );

        dp[1] = 1 ; 

        for(int i = 2 ; i<=n ; i++){
            int prod = 0 ; // It is compulsory to break down the original number given to us 

            if( i !=n){
                prod = i ; // But subproblems need not be broken down 
            }  

            for(int j = 1 ; j < i ; j++){ // Important < n and <= n as 0 + n will give 0 we do not have base case for n == 0  
                int left = j ; 
                int right = i - j ; 

                int value = dp[left] * dp[right];
                prod = max( prod , value);
            }

            dp[i] = prod ; 
        }

        // Time Complexity: O(n²)
        //
        // Outer loop:
        //   i = 2 -> n
        //
        // Inner loop:
        //   j = 1 -> i-1
        //
        // Total:
        //   1 + 2 + 3 + ... + (n-1)
        // = O(n²)
        //
        // Space Complexity: O(n)
        //
        // Only the dp array is stored.
        return dp[n] ; 
        
    }
};

class Solution {
public:
    int integerBreak(int n) {
        
        if(n <= 3) return n - 1;

        int ans = 1;

        while(n > 4){
            ans *= 3;
            n -= 3;
        }

        // Time Complexity: O(n/3)
        // Space Complexity: O(1)
        return ans * n;

// Why stop at 4 ?
// Keep extracting 3's while the remaining value is > 4.
//
// We stop at 4 (not 3) because:
//
// 4 = 2 + 2
// Product = 4
//
// whereas:
//
// 3 + 1
// Product = 3
//
// So whenever we would be left with a remainder of 1,
// we keep the final 4 intact instead of extracting
// one more 3.
//
// Example:
// n = 10
//
// Good:
// 3 + 3 + 4 = 36
//
// Bad:
// 3 + 3 + 3 + 1 = 27

// MATH SOLUTION
//
// ------------------------------------------------------------
// KEY OBSERVATION #1
// ------------------------------------------------------------
//
// We are asked to:
//
// Break n into at least TWO positive integers
//
// and maximize:
//
// product = a * b * c * ...
//
// Example:
//
// n = 10
//
// Possible breaks:
//
// 5 + 5       => 25
// 4 + 6       => 24
// 3 + 3 + 4   => 36   <-- best
//
// ------------------------------------------------------------
// KEY OBSERVATION #2
// ------------------------------------------------------------
//
// For any piece x >= 5, it is ALWAYS beneficial
// to break off a 3.
//
// Why?
//
// Compare:
//
// Keep x as-is:
// Product contribution = x
//
// Break it into:
// 3 + (x-3)
//
// Product contribution becomes:
//
// 3 * (x-3)
//
// We want to know when:
//
// 3*(x-3) > x
//
// 3x - 9 > x
//
// 2x > 9
//
// x > 4.5
//
// Therefore:
//
// For every x >= 5:
//
// 3*(x-3) > x
//
// Meaning:
//
// Any number >= 5 should be broken further.
//
// Example:
//
// 5
// Keep: 5
// Break: 3 * 2 = 6
//
// 6 > 5
//
// ------------------------------------------------------------
// EXAMPLE
// ------------------------------------------------------------
//
// n = 8
//
// Keep as:
//
// 8
//
// Product = 8
//
// Break:
//
// 3 + 5
//
// Product = 15
//
// But 5 can be broken again:
//
// 3 + 3 + 2
//
// Product:
//
// 3 * 3 * 2 = 18
//
// Better than 15 and better than 8.
//
// ------------------------------------------------------------
// KEY OBSERVATION #3
// ------------------------------------------------------------
//
// Since every number >= 5 should be broken,
// we keep extracting 3's.
//
// Why 3 specifically?
//
// Compare:
//
// 4 = 2 + 2
//
// Product:
//
// 2 * 2 = 4
//
// No gain.
//
// ------------------------------------------------------------
//
// 5 = 2 + 3
//
// Product:
//
// 2 * 3 = 6
//
// Gain.
//
// ------------------------------------------------------------
//
// 6:
//
// 3 + 3
//
// Product:
//
// 3 * 3 = 9
//
// Better than:
//
// 2 + 2 + 2
//
// Product:
//
// 8
//
// Therefore:
//
// 3 is the most profitable piece to repeatedly use.
//
// ------------------------------------------------------------
// REMAINDER CASES
// ------------------------------------------------------------
//
// After repeatedly removing 3's,
// only three remainders are possible:
//
// n % 3 == 0
// n % 3 == 1
// n % 3 == 2
//
// ------------------------------------------------------------
// CASE 1
// ------------------------------------------------------------
//
// n % 3 == 0
//
// Perfect.
//
// Use only 3's.
//
// Example:
//
// n = 9
//
// 9 = 3 + 3 + 3
//
// Product:
//
// 3 * 3 * 3 = 27
//
// Formula:
//
// 3^(n/3)
//
// ------------------------------------------------------------
// CASE 2
// ------------------------------------------------------------
//
// n % 3 == 2
//
// Use all possible 3's and one final 2.
//
// Example:
//
// n = 8
//
// 8 = 3 + 3 + 2
//
// Product:
//
// 3 * 3 * 2 = 18
//
// Formula:
//
// 3^(n/3) * 2
//
// Example:
//
// n = 11
//
// 11 = 3 + 3 + 3 + 2
//
// Product:
//
// 3 * 3 * 3 * 2 = 54
//
// ------------------------------------------------------------
// CASE 3
// ------------------------------------------------------------
//
// n % 3 == 1
//
// This is the tricky case.
//
// Example:
//
// n = 10
//
// Greedy 3's:
//
// 10 = 3 + 3 + 3 + 1
//
// Product:
//
// 3 * 3 * 3 * 1 = 27
//
// BAD.
//
// Why?
//
// Multiplying by 1 contributes nothing.
//
// Instead:
//
// Take one 3 back:
//
// 3 + 3 + 4
//
// Product:
//
// 3 * 3 * 4 = 36
//
// Better.
//
// Since:
//
// 3 * 1 = 3
//
// but
//
// 2 * 2 = 4
//
// Therefore:
//
// Whenever remainder is 1,
// replace:
//
// 3 + 1
//
// with
//
// 2 + 2
//
// Formula:
//
// 3^(k-1) * 4
//
// Example:
//
// n = 13
//
// 13 = 3 + 3 + 3 + 4
//
// Product:
//
// 3 * 3 * 3 * 4 = 108
//
// ------------------------------------------------------------
// SMALL NUMBERS
// ------------------------------------------------------------
//
// n = 2
//
// Must break:
//
// 1 + 1
//
// Product = 1
//
// ------------------------------------------------------------
//
// n = 3
//
// Must break:
//
// 1 + 2
//
// Product = 2
//
// ------------------------------------------------------------
//
// Therefore:
//
// if(n <= 3)
//     return n - 1;
//
// ------------------------------------------------------------
// FINAL ALGORITHM
// ------------------------------------------------------------
//
// 1. Handle n <= 3 separately.
// 2. Repeatedly remove 3 while n > 4.
// 3. Multiply answer by each removed 3.
// 4. Multiply the remaining n (which will be 2,3 or 4).
//
// Example:
//
// n = 10
//
// ans = 1
//
// Remove 3:
//
// ans = 3
// n = 7
//
// Remove another 3:
//
// ans = 9
// n = 4
//
// Stop because n <= 4.
//
// Final:
//
// ans * n
//
// = 9 * 4
//
// = 36
//
// Correct.


    }
};