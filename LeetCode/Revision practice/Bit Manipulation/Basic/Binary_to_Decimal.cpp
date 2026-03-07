/*
Problem statement
Ninja is given a binary number as a string ‘S’ of size ‘N’, he is asked to convert it into its decimal equivalent (as an Integer) and print it.

Note:

A binary string is a string in which all characters are either ‘1’ or ‘0’.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
7
1010101
4
1011
Sample Output 1:
85
11
Explanation of Sample Input 1:
Test case 1:

The Decimal equivalent of the Binary number “1010101” is 85.

Test case 2:
The Decimal equivalent of the Binary number “1011” is 11.
Sample Input 2:
2
4
1111       
1
0
Sample Output 2:
15
0
Explanation of Sample Input 2:
Test case 1:

The Decimal equivalent of the Binary number “1111” is 15.

Test case 2:

The Decimal equivalent of the Binary number “0” is 0.
*/

#include <iostream>
#include <string>
using namespace std;

int convert(int N,string &str)
{   
    int ans = 0 ;
    int pow2=1 ; // First is 2 to the power 0 so = 1
    for(int i = N-1 ; i>=0 ; i--){
        
        // Can ignore zeroes 
        if(str[i] == '1'){
            ans += pow2;
        }
        pow2 = pow2 * 2;

    }

    //TC:O(n) and SC:O(1)
    return ans;
}