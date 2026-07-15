// 15 JUly 2026 

//3658. GCD of Odd and Even Sums

/*
You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:

sumOdd: the sum of the smallest n positive odd numbers.

sumEven: the sum of the smallest n positive even numbers.

Return the GCD of sumOdd and sumEven.

 

Example 1:

Input: n = 4

Output: 4

Explanation:

Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4.

Example 2:

Input: n = 5

Output: 5

Explanation:

Sum of the first 5 odd numbers sumOdd = 1 + 3 + 5 + 7 + 9 = 25
Sum of the first 5 even numbers sumEven = 2 + 4 + 6 + 8 + 10 = 30
Hence, GCD(sumOdd, sumEven) = GCD(25, 30) = 5.

 

Constraints:

1 <= n <= 10​​​​​​​00
*/
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n ;

        // Sum of the first n odd numbers:
        //
        // 1 + 3 + 5 + ... + (2n - 1) = n²
        //
        // Therefore:
        // sumOdd = n²

        // Sum of the first n even numbers:
        //
        // 2 + 4 + 6 + ... + 2n
        // = 2 × (1 + 2 + ... + n)
        // = 2 × (n(n + 1) / 2)
        // = n(n + 1)
        //
        // Therefore:
        // sumEven = n(n + 1)

        // We need:
        // gcd(sumOdd, sumEven)
        // = gcd(n², n(n + 1))
        //
        // Factor out n:
        // = n × gcd(n, n + 1)
        //
        // Since consecutive integers are always coprime:
        // gcd(n, n + 1) = 1
        //
        // Therefore:
        // gcd(n², n(n + 1)) = n
        //
        // So the answer is simply:
        // return n;

        // TC: O(1)
        // SC: O(1)
    }
};