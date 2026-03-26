/*
You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).

Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.

 

Example 1:

Input: a = 2, b = 4, c = 6
Output: 6
Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
- Take from 1st and 3rd piles, state is now (1, 4, 5)
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 6 points.
Example 2:

Input: a = 4, b = 4, c = 6
Output: 7
Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
- Take from 1st and 2nd piles, state is now (3, 3, 6)
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 7 points.
Example 3:

Input: a = 1, b = 8, c = 8
Output: 8
Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.
After that, there are fewer than two non-empty piles, so the game ends.
 

Constraints:

1 <= a, b, c <= 105

*/
#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // There are essentially one two cases 
        // lets assume a <= b <= c
        // If c >= a + b , just take ( a + b) basically take keep taking from a and c until a is depleted and then do the same for b 

        // if c < a + b , take from a and b until a + b = c and then do the above , the answer in this case is (a + b + c)/2 , see examples and also here all stones can be taken , as see after you take from and b to make (a + b) = c , you can take all of the remaining stones too , in the above case c was always remaining but here all stones will be take 
        // So we take (a + b + c) stones and on taking two stones we get one point 
        // so points = (a + b + c) / 2

        // The below follows the order a <= b <= c so check if  the order remains 
        // Method 1 : if - else 
        // if( c >= a + b){
        //     return a + b;
        // }else{
        //     return (a + b + c )/2;
        // }

        // Method 2 just return the minumum of the two 
        // In case one ( a + b + c) / 2 > ( a + b) , ans = ( a + b )
        // In case two ( a + b + c) / 2 < ( a + b ) , ans = ( a + b + c) 2

        //TC:O(1) and SC:(1)

        int sum =  a + b + c;
        int mx = max({a , b, c}) ; // selects the largest , say c so if we do sum - mx = a+b+c - c = a + b ; sum of two minimum 
        return min ( sum - mx , sum/2);
        }
};