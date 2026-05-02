/*
You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.

After performing at most k replacements, return the length of the longest substring which contains only one distinct character.

Example 1:

Input: s = "XYYX", k = 2

Output: 4
Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

Example 2:

Input: s = "AAABABB", k = 1

Output: 5
Constraints:

1 <= s.length <= 1000
0 <= k <= s.length

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        // // Brute force 
        // int maxLength = 0 ;
        // for(int i = 0 ; i  <  n ; i++){
        //     vector<int> freq(26); // Since only capital letters
        //     int maxFreq = 0;

        //     for(int j = i ; j < n ; j++){

        //         freq[s[j] - 'A']++;
        //         int maxFreq = max( maxFreq , freq[s[j]-'A']);
        //         int changes = (j - i + 1) - maxFreq;

        //         if(changes <= k ){
        //             maxLength = max ( maxLength , j - i + 1);
        //         }
        //     }
        // }

        // //TC:O(n^2) and SC:O(1)
        // return maxLength ;


        // Sliding window 

        int l = 0 ;
        int r = 0 ;

        vector<int> freq(26);
        int maxFreq = 0 ;
        int maxLength  = 0 ;

        while (r < n){
            freq[s[r] - 'A']++;
            maxFreq = max( maxFreq , freq[s[r] - 'A']);
            int changes = (r - l + 1 ) - maxFreq;

            // // See if it is not a valid window  -> make it valid 
            // if( changes > k ){
            //     freq[s[l] - 'A']--;
            //     for(int i = 0 ; i < 26 ; i++){
            //         maxFreq = max(maxFreq , freq[i]);
            //     }
            //     changes = (r - l + 1 ) - maxFreq;
            //     l++;
            // }

            // Fully optimised solution -> use unupdated freq 
            // See if it is not a valid window  -> make it valid 
            if( changes > k ){
                freq[s[l] - 'A']--;
                l++;
            }

            if(changes<=k) maxLength = max (maxLength , r - l + 1);

            r++;
        }

        // Okay so why don't we update maxFreq 
        // we have the condtion length - maxFreq <=k
        // We go to update l when this becomes invalid 
        // We need to decrease the terms (length - maxFreq) so that it fits 
        // When we update maxFreq , it decrease and increase the term (length - maxFreq)
        // So not unseful for us
        // Why doesn't it break the solution 
        // When we do not update maxFreq but length increases, this term (length - maxFreq) again increases
        // So the condition is still violated and we only store answer when condtion is true so we have the best answer until now still intact

        // Hence we dont decrease maxFreq , and it still gives answer
        // Because answer can only change when maxFreq increases 

        // TC:O(n) and SC:O(1)
        return maxLength ;

    }
};
