/*
You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

Example 1:

Input: n = 3, x = 2

Output: 6
Explanation: nums can be [2,3,6].

Example 2:

Input: n = 5, x = 3

Output: 19
Explanation: nums can be [3,7,11,15,19].

Constraints:

1 <= n, x <= 100,000,000

*/
#include <iostream>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        // Two condtions 
        // We need n  numbers such that 
        // 1. They are STRICTLY INCREASING 
        // 2. When we & them all -> The answer is X 
        // We need to return the last number of the n numbers we choose 

        // Observation -> We need to build X . AND gives 1 only when all numbers in range have 1 in that position 
        // So in the position of X where it has 1 . All numbers in that range must have that bit as one 
        // Basically where X is set , all the numbers we choose must be set 

        // Now we choose X as the first number -> Why ? 
        // Suppose we get X as 4 -> 100 now any number less than 4 will have 3rd bit as 0 
        // Also and more importantly when we decrease x . One set but always disappears . That is the way binary works 
        // So X has to be the first 

        // Now for the other numbers . Lets try making the second number only for now 
        // Two conditions . One it must be larger and it must have set bits in pos where prev is set 
        
        // For condition 1 we do that number + 1 . Then we do OR with X and it satifies second condition as well 

        // We do this repeatedly and we get the answer 

        //Do not need a vector as we only need to return the last number 

        long long res = x ; //start with x 

        for(int i = 0 ; i < n -1 ; i++){
            res = ( res + 1) | x  ; // Or atleast keeps the same number of set bits or turns 0 to ones so it can increase a number but never decrease 
        }

        //TC:O(n)
        return res ; 
    }       
};


class Solution {
public:
    long long minEnd(int n, int x) {
        // Now for the optimal approach 

        // We have already concluded x is the starting number 

        // Say consider this case  say x is 101010
        // For understandinging consider thsi _1_1_1_
        // Now next number we can say that the underlined bits are 0000
        // The next number that satisfies our conditon is 101011
        // Notice something the underlines bits are 0001 .
        // Likewise next is 101110 . Notice underlined bits are 0010 
        // So we go add 0 then 1 then 2 (bit representation ) in the position where it is 0 initially 

        // Now again say x = any number but n is say 66 . If we ignore the set bits because they must remain unchanged

        // For the underlined or non set ot 0 bits (same thing )
        // We go from 0 to 1 to 2 to 3 to ...... 65 ( n - 1)

        // That is the entire idea . For any x and n = 66 . We need to put 65(1000001) in the zero postions 

        // So we can think of two pointer approach . 
        // One keeps track of the 0 bits in x and the other just traverses n - 1 normally 
        long long res = x ; 
        long long i_x = 1 ; 
        long long i_n = 1 ; // You can think of them as indexes but we actually need the bit or pos of bit . To do that we will shift by 1
        // We initialise to 1 as we can think of that as the last bit ( or last index for comparison)

        // i_n goes as 1 , 10 , 1000 , At the end it will be 10000.. where the 1 will be at the position of first set bit in n - 1 
        while ( i_n <= n - 1){
            if( (i_x & x) == 0 ){
                // Underlined bit 
                // we need to put the n-1 's bit here . But if it is zero so no change needed as x already started with 0 in these positions 
                if( (i_n & n-1)!= 0){
                    res = res | i_x ; // Remember i_x at any time is just 10000.. where the pos of the first 1 is the pos we need 
                }
                i_n = i_n << 1 ; 
            }
            i_x = i_x << 1 ;
        }

        // TC:O(64) as we basically traverse through bits 
        // SO TC:O(1) and SC:O(1)
        return res ; 
    }
};