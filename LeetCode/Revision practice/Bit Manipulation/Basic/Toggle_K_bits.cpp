/*
Problem statement
You are given a 32-bit integer ‘N’. Your task is to toggle the rightmost ‘K’ bits in the given integer and return the new integer.

For Example :
If ‘N’ = 12 and ‘K’ = 2:
The binary representation of 12 is ‘1100’, after toggling rightmost 2 bits, it becomes ‘1111’ i.e. 15. Hence, the answer is 15. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^9
1 <= K <= 31

Time Limit: 1 sec
Sample Input 1:
2
21 3
40 4
Sample Output 1:
18
39
Explanation For Sample Input 1:
In example 1, the binary representation of 21 is '10101'. After toggling rightmost 3 bits, it becomes ‘10010’ which is equal to 18.
In example 2, the binary representation of 40 is ‘101000’. After toggling rightmost 4 bits, it becomes ‘100111’ which is equal to 39.
Sample Input 2:
2 
20 2
85 5
Sample Output 2:
23
74
Explanation For Sample Input 2:
In example 1, the binary representation of 20 is '10100'. After toggling rightmost 2 bits, it becomes ‘10111’ which is equal to 23.
In example 2, the binary representation of 85 is ‘1010101’. After toggling rightmost 5 bits, it becomes ‘1001010’ which is equal to 74.
*/

#include <iostream>
using namespace std; 
int toggleKBits(int n, int k) {
    // Write your code here.

    // int i= 1;
    // int temp = 0;
    // while(i<=k){
    //     temp = (temp<<1) | 1;
    //     i++;
    // }

    // //TC:O(k) and SC:(1)
    // return n ^ temp;

    // Constant time 

    // 2^k - 1 is ( number of k bits all  ones)
    // 1<<k gives 10000 1 followed by k zeroes 
    // -1 to that gives 0 followed by k ones 
    return n ^ ((1<<k) - 1) ;
    // SO TC:O(1) and SC:O(1)
    
}