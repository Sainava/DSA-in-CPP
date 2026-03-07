/*
Problem statement
You are given two numbers 'L' and 'R'.



Find the XOR of the elements in the range [L, R].



For Example:
For 'L' = 1 and ‘R’ = 5.
The answer is 1.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3 5
Sample Output 1:
2
Explanation of sample output 1:
'L' = 3 and ‘R’ = 5
Answer is 2. Value of 3^4^5 is 2.
Sample Input 2:
1 3
Sample Output 2:
0
Constraints:
1 <= ‘L’ <= ‘R’ <= 10^9
Time Limit: 1 sec
*/

#include<iostream>
using namespace std ;

// This function gives xor from 1 to n in O(1) time using patterns
int xorr(int n){

    if( n % 4 == 1) return 1;
    else if( n % 4 == 2) return n+1;
    else if (n % 4 == 3) return 0;
    else return n; // n % 4 == 0
}

int findXOR(int L, int R){
   
   //TC:O(1) and SC:O(1)
   return xorr(L-1) ^ xorr(R);
}