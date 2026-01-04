/*
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 

Constraints:

1 <= nums.length <= 104
1 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
    //     Number form	              Divisors	          Count
    //     p (prime)	               1, p	               2
    //     p²	                      1, p, p²	           3
    //     p³	                    1, p, p², p³	       4 
    //     p × q (p ≠ q primes). 	1, p, q, p·q	       4 
    //     p⁴                      1, p, p², p³, p⁴.       5
    // }

    // A number has exactly 4 divisors if and only if:

    // It is of the form p³, where p is prime
    // OR it is of the form p × q, where p and q are distinct primes

    // Only two cases 
    
    int totalSum = 0 ;
    
    // TC:O(n x root(m) ) 
    for(int n : nums){

        int cnt = 0 ;
        int sum = 0 ;

        for( int i = 1 ; i*i <= n ; i++){
            if( n % i == 0 ){ // i is a divisor of n
                int d1 = i ; // p
                int d2 = n / i ; // q 

                if( d1 == d2 ){
                    cnt += 1;
                    sum += d1;
                }else{
                    cnt += 2 ;
                    sum += d1 + d2 ;
                }

                if(cnt > 4 ) break ;
            }
        }

        if(cnt == 4 ){
            totalSum+=sum;
        }
    }
    // TC:O(n x root(m) ) 
    //SC:O(1)
    return totalSum ;
    }
};