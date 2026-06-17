/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

You are given two strings str1 and str2, return the largest string x such that x divides both str1 and str2. If there is no such string, return "".

Example 1:

Input: str1 = "ABAB", str2 = "AB"

Output: "AB"
Example 2:

Input: str1 = "NANANA", str2 = "NANA"

Output: "NA"
Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

*/
#include <iostream>
#include <string>
#include <numeric> // Required header for std::gcd
using namespace std;

class Solution {
public:
    bool isDivisor(string& str1, string& str2, string& substr) {
        int l = substr.size();

        if (str1.size() % l != 0 || str2.size() % l != 0)
            return false;

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != substr[i % l])
                return false;
        }

        for (int i = 0; i < str2.size(); i++) {
            if (str2[i] != substr[i % l])
                return false;
        }

        //TC:O(m + n) and SC:O(1)
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int m = str1.size() ; 
        int n = str2.size() ;

        if (m > n) return gcdOfStrings(str2, str1);  // This way we know str1 is the shorter string 

        // We try making from the shorter one as we need a substring that can make both 
        // If len of substr is greater than either one , it is simply not possible 
        // We start from the end , as weed to return the largest , so first time we get it we can return 
        for(int l = m  ; l >= 1 ; l--){ 
            string substr = str1.substr( 0 , l ) ; // pos and size or length (l)

            if( isDivisor(str1 , str2 , substr)){
                return substr ; 
            }
        }

        //TC: O(min(m,n) * (m + n))
        return "" ;
    }
};


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1)
            return "";

        int len = gcd(str1.size(), str2.size());

        // Let:
        // m = str1.size()
        // n = str2.size()

        // str1 + str2 and str2 + str1 each require O(m+n)

        // gcd(m,n) = O(log(min(m,n)))

        // substr = O(gcd(m,n))

        // Time Complexity: O(m + n)

        // Space Complexity: O(m + n)
        // (temporary concatenated strings)
        return str1.substr(0, len);


        // INTUITION:
//
// We need to find the largest string x such that:
//
// str1 = x repeated some number of times
// str2 = x repeated some number of times
//
// Example:
//
// str1 = "ABCABCABC"
// str2 = "ABCABC"
//
// Both strings are formed by repeating:
//
// x = "ABC"
//
// Therefore:
//
// "ABCABCABC" = "ABC" × 3
// "ABCABC"    = "ABC" × 2
//
// ------------------------------------------------------------
// OBSERVATION 1
// ------------------------------------------------------------
//
// If a common divisor string exists, then:
//
// str1 + str2 == str2 + str1
//
// Why?
//
// Suppose:
//
// str1 = x repeated a times
// str2 = x repeated b times
//
// Then:
//
// str1 + str2
// = x repeated (a+b) times
//
// str2 + str1
// = x repeated (b+a) times
//
// Since addition is commutative:
//
// a+b = b+a
//
// Therefore:
//
// str1 + str2 == str2 + str1
//
// ------------------------------------------------------------
// EXAMPLE
// ------------------------------------------------------------
//
// str1 = "ABCABC"
// str2 = "ABC"
//
// str1 + str2
// = "ABCABCABC"
//
// str2 + str1
// = "ABCABCABC"
//
// Equal -> possible to have a common divisor string.
//
// ------------------------------------------------------------
// COUNTER EXAMPLE
// ------------------------------------------------------------
//
// str1 = "ABAB"
// str2 = "ABBA"
//
// str1 + str2
// = "ABABABBA"
//
// str2 + str1
// = "ABBAABAB"
//
// Not equal.
//
// Therefore there is NO common divisor string.
//
// Hence:
//
// if(str1 + str2 != str2 + str1)
//     return "";
//
// ------------------------------------------------------------
// OBSERVATION 2
// ------------------------------------------------------------
//
// If a divisor string exists, its length must divide
// both string lengths.
//
// Example:
//
// str1 = "ABCABCABC"  -> length = 9
// str2 = "ABCABC"     -> length = 6
//
// divisor string = "ABC"
//
// length("ABC") = 3
//
// Notice:
//
// 3 divides 9
// 3 divides 6
//
// Therefore the answer length must be a COMMON DIVISOR
// of both lengths.
//
// The largest possible such length is:
//
// gcd(str1.length(), str2.length())
//
// ------------------------------------------------------------
// WHY DOES TAKING THE FIRST gcd LENGTH WORK?
// ------------------------------------------------------------
//
// Observation 1 already guarantees that both strings
// are generated from the same repeating pattern.
//
// Therefore the largest valid pattern must have length:
//
// gcd(m,n)
//
// where:
//
// m = str1.size()
// n = str2.size()
//
// So we simply take:
//
// str1.substr(0, gcd(m,n))
//
// ------------------------------------------------------------
// DRY RUN
// ------------------------------------------------------------
//
// str1 = "ABABAB"
// str2 = "ABAB"
//
// Step 1:
//
// str1 + str2
// = "ABABABABAB"
//
// str2 + str1
// = "ABABABABAB"
//
// Equal -> continue.
//
// Step 2:
//
// lengths:
//
// 6 and 4
//
// gcd(6,4) = 2
//
// Step 3:
//
// Take first 2 characters:
//
// "AB"
//
// Return "AB".
//
// ------------------------------------------------------------
// MATHEMATICAL ANALOGY
// ------------------------------------------------------------
//
// Numbers:
//
// 12 = 6 × 2
// 18 = 6 × 3
//
// gcd(12,18) = 6
//
// Strings:
//
// "ABCABCABC" = "ABC" × 3
// "ABCABC"    = "ABC" × 2
//
// gcd string = "ABC"
//
// We are essentially finding the largest repeating
// pattern that divides both strings.
//
// ------------------------------------------------------------
// TIME COMPLEXITY
// ------------------------------------------------------------
//
// Let:
//
// m = str1.size()
// n = str2.size()
//
// Comparing:
//
// str1 + str2
// str2 + str1
//
// takes O(m+n)
//
// gcd(m,n) takes O(log(min(m,n)))
//
// substr(...) takes O(gcd(m,n))
//
// Overall:
//
// Time Complexity: O(m+n)
//
// Space Complexity: O(m+n)
// (because of the temporary concatenated strings)
//
    }
};