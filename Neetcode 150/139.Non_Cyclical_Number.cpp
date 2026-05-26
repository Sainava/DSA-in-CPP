/*
A non-cyclical number is an integer defined by the following algorithm:

Given a positive integer, replace it with the sum of the squares of its digits.
Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
If it stops at 1, then the number is a non-cyclical number.
Given a positive integer n, return true if it is a non-cyclical number, otherwise return false.

Example 1:

Input: n = 100

Output: true
Explanation: 1² + 0² + 0² = 1

Example 2:

Input: n = 101

Output: false
Explanation:
1² + 0² + 1² = 2
2² = 4
4² = 16
1² + 6² = 37
3² + 7² = 58
5² + 8² = 89
8² + 9² = 145
1² + 4² + 5² = 42
4² + 2² = 20
2² + 0² = 4 (This number has already been seen)

Constraints:

1 <= n <= 1000
*/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> st ; 

        while(n){
            int num = 0 ;

            while(n){
                int rem = n%10 ;
                num += rem*rem ;
                n = n/10 ;
            }

            if( num == 1) return true ;

            if(st.find(num)!= st.end()) return false ; 

            st.insert(num) ;
            
            n= num ;
        }
        
        // TC Analysis:

        // Let d = number of digits in n
        // In one iteration, we process every digit once
        // So one transformation takes O(d) = O(log n)

        // Important observation:
        // Maximum contribution of one digit = 9^2 = 81

        // Therefore for a d digit number:
        // next number <= 81 * d

        // Example:
        // n = 999999999 (9 digits)
        // next value <= 9 * 81 = 729

        // So the number shrinks very quickly and
        // eventually remains within a very small bounded range

        // After a few iterations, all values stay below ~1000
        // Therefore only constant many states are possible

        // Hence:
        // TC: O(1)  (bounded number of states)
        // SC: O(1)  (set stores only bounded many values)
        return false ; 
    }
};
