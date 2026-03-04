/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Longest Repeating Character with <condition>
        // We need longest substring , so this means LOngest substring with <condition> 
        // USE SLIDING WINDOW 

        // // Brute Force - CHECK all substrings 

        // int maxLength = 0;
        // for(int i = 0 ; i < s.size() ; i++){
        //     int maxFrequency = 0;
        //     vector<int> count(26);
        //     for(int j = i ; j < s.size() ; j++){
        //         count[ s[j] - 'A' ]++;

        //         // Calculate number of changes needed for each substring 
        //         // Changes = Total length of subtring - maxFrequecy

        //         maxFrequency = max(maxFrequency , count[ s[j] - 'A' ] );

        //         int changes = (j - i + 1) - maxFrequency ;

        //         if(changes <= k){
        //             // May Update max length -> Can be an answer
        //             maxLength = max(maxLength , j - i + 1);
        //         }
        //     }
        // }
        // //TC : O(n^2) and SC:O(1)
        // return maxLength;

        // Optimised using Sliding Window 

        int l = 0 ;
        int r = 0 ;
        int maxLength = 0 ;
        int maxFrequency = 0;
        vector<int> count(26);
        
        // while(r < s.size()){

        //     // For the new window 
        //     count[ s[r] - 'A' ]++;

        //     // See if window valid 
        //     // Calculate number of changes needed for each substring 
        //     // Changes = Total length of subtring - maxFrequecy

        //     maxFrequency = max(maxFrequency , count[ s[r] - 'A' ] );

        //     int changes = (r - l + 1) - maxFrequency ;

        //     // MAke the window valid 
        //     while(changes > k){
        //         count[ s[l] - 'A' ]--;
        //         maxFrequency= 0;
        //         for(int i= 0; i < 26 ; i++){
        //             maxFrequency = max(maxFrequency , count[i]);                  
        //         }
        //         changes = (r - l + 1) - maxFrequency ;
        //         l++;
        //     }

        //     if(changes <= k){
        //         maxLength = max(maxLength , r - l + 1);
        //     }

        //     r++;

        // }

        // The above is TC:O( 26 x (n + n))

        // // More optimised 
        // while(r < s.size()){

        //     // For the new window 
        //     count[ s[r] - 'A' ]++;

        //     // See if window valid 
        //     // Calculate number of changes needed for each substring 
        //     // Changes = Total length of subtring - maxFrequecy

        //     maxFrequency = max(maxFrequency , count[ s[r] - 'A' ] );

        //     int changes = (r - l + 1) - maxFrequency ;

        //     // MAke the window valid 
        //     if(changes > k){
        //         count[ s[l] - 'A' ]--;
        //         maxFrequency= 0;
        //         for(int i= 0; i < 26 ; i++){
        //             maxFrequency = max(maxFrequency , count[i]);                  
        //         }
        //         changes = (r - l + 1) - maxFrequency ;
        //         l++;
        //     }

        //     if(changes <= k){
        //         maxLength = max(maxLength , r - l + 1);
        //     }

        //     r++;

        // }

        // //TC:O(26 n) and SC:O(1) // Since count is a constant 
        // return maxLength;



        // Most optimised solution 
        // Do not change maxFrequency , keep the outdated one . 
        // This will not break the algo and work as reducing maxFrequency does not give us a better solution than what we already have 

         while(r < s.size()){

            // For the new window 
            count[ s[r] - 'A' ]++;

            // See if window valid 
            // Calculate number of changes needed for each substring 
            // Changes = Total length of subtring - maxFrequecy

            maxFrequency = max(maxFrequency , count[ s[r] - 'A' ] );

            int changes = (r - l + 1) - maxFrequency ;

            // MAke the window valid 
            if(changes > k){
                count[ s[l] - 'A' ]--;
                
                changes = (r - l + 1) - maxFrequency ;
                l++;
            }

            if(changes <= k){
                maxLength = max(maxLength , r - l + 1);
            }

            r++;

        }

        //TC:O(n) and SC:O(1)
        return maxLength;



    }
};