/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;


class Solution {
public:
    int numberOfSubstrings(string s) {
        
        //Number of substrings with <condition> - USE SLIDING WINDOW 

        // // Brute force
        // int count = 0 ;

        // for( int i = 0 ; i < s.size() ; i++){
        //     unordered_map<int,int> mp ;
        //     for(int j = i ; j <s.size() ; j++ ){
        //         mp[s[j]]++;
        //         if(mp.size()==3){
        //             count++;
        //         }
        //     }
        // }

        // //TC:O(n^2) and SC:O(1)
        // return count ;

        // // Brute force - A bit optimised -- will be used in optimised as well 
        // int count = 0 ;

        // for( int i = 0 ; i < s.size() ; i++){
        //     unordered_map<int,int> mp ;
        //     for(int j = i ; j <s.size() ; j++ ){
        //         mp[s[j]]++;
        //         if(mp.size()==3){
        //             count = count + s.size() - j;
        //                break;
        //         }
        //     }
        // }

        //TC:O(n^2) and SC:O(1)
        //return count ;

        // Optimised solution using sliding window 

        int i = 0 ;
        int count = 0;
        vector<int> lastSeen (3 , -1);
        // 3 size - one for each a , b and c and -1 signifying they have not been seen in the array yet 

        while ( i < s.size()){
            lastSeen [ s[i] - 'a' ] = i ;

            if( lastSeen[0]!= -1 && lastSeen[1]!= -1 && lastSeen[2]!= -1){
                count += min(lastSeen[0] , min(lastSeen[1],lastSeen[2])) + 1;
            }
            i++;
            
        }
        //TC:O(n) and SC:O(1)
        return count ;
    }
};