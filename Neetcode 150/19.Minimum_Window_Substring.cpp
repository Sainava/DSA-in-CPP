/*
Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

You may assume that the correct output is always unique.

Example 1:

Input: s = "OUZODYXAZV", t = "XYZ"

Output: "YXAZ"
Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z" from string t.

Example 2:

Input: s = "xyz", t = "xyz"

Output: "xyz"
Example 3:

Input: s = "x", t = "xy"

Output: ""
Constraints:

1 <= s.length <= 1000
1 <= t.length <= 1000
s and t consist of uppercase and lowercase English letters.

*/
#include <iostream>
#include <vector>
using namespace std;

// Brute force solution - Check for all substrings and check if they contain all characters of t
class Solution {
public:
    string minWindow(string s, string t) {
        // Brute force 
        int m = t.size();
        int n = s.size();

        vector<int> freq(256);

        int minLength = INT_MAX ;
        int startIndex = -1 ;

        // Check for all substrings 
        for(int i = 0 ; i < n ; i++){
            int cnt = 0 ;
            vector<int> freq(256);

            for(char c:t){
                freq[c]++;
            }

            for(int j = i ; j < n ; j++){
                if( freq[s[j]] > 0){
                    // was preinserted
                    cnt++;
                    if(cnt== m ){

                        if( j - i + 1 < minLength){
                            startIndex = i ;
                            minLength = j - i + 1;
                        }
                    
                    break;
                    }
                }

                freq[s[j]]--;
            }
        }

        if(startIndex == -1 ) return "";

        //TC:O(n^2) and SC:(1)
        return s.substr(startIndex , minLength);
    }
};

// Optimised SLiding Window
class Solution {
public:
    string minWindow(string s, string t) {
        // Optimised SLiding Window 
        int m = t.size();
        int n = s.size();

        vector<int> freq(256);

        //TC:O(m)
        for(char c:t){
            freq[c]++;
        }

        int minLength = INT_MAX ;
        int startIndex = -1 ;
        int cnt = 0 ;

        int l = 0 ;
        int r = 0 ; 

        // TC:O(2n) as for each character , it can be processed twice , once by r and once by l
        while(r < n ){
            // Step 1 : Check if it was preinserted 
            if( freq[s[r]]>0){
                cnt++ ;
                
                // See if valid solution 
                while ( cnt == m){
                    
                    if(r - l + 1 < minLength ){
                        minLength = r - l + 1 ;
                        startIndex = l ;
                    }

                    freq[s[l]]++;
                    if(freq[s[l]] > 0){
                        cnt--;
                    }
                    l++;
                }
            }

            freq[s[r]]--;
            r++;
        }


        if( startIndex == -1) return "";

        //TC:O(m + 2n) and SC:O(1)
        return s.substr(startIndex , minLength);
    }
};

