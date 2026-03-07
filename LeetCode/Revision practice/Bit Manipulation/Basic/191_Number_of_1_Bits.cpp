/*
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

Constraints:

1 <= n <= 231 - 1
 

Follow up: If this function is called many times, how would you optimize it?
 
*/
#include<iostream>
using namespace std ;

class Solution {
public:
    int hammingWeight(int n) {
        // convert to binary and while doing it count one 

        // int count = 0 ;

        // while ( n != 0){
        //     if(n%2==1){
        //         count++;
        //     }
    
        //     n=n/2;
        // }

        // while ( n != 0){
        //     // Or since last bit of an odd number is always one 
        //     if( n & 1 == 1){
        //         count++;
        //     }
    
        //     n=n>>1;
        // }

        // //TC:Ologn and SC:O(1)
        // return count ;

        // The TC is actually TC:O(no of set bits) which in the worst case will be TC:O(31) as TC:O(logn) and n max will be 2^31

        // See the next solution to understand better 
        int count = 0 ;

        while (n!=0){
            n = n& n-1;
            count++;
        }

        // For the above -- at each iteration the rightmost bit is set to 1
        // SO TC:O(no of set bits ) which in worst case is TC(1)
        // But since this is very unlikely it is better than the above solutions 

        //TC:O(1)
        return count ;
            
    }
}; 