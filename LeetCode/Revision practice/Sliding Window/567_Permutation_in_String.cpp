/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:

    bool checkequal(vector<int> &freq1,vector<int> &freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }

        return true;
    }


    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        //Find count of S1
        vector<int> freq1(26,0);

        for(int i=0;i<s1.length();i++){
            int idx=s1[i]-'a';
            freq1[idx]++;
        }

        //Create a new frequency count for the window 
        vector<int> freq2(26,0);

        //Start the first window 
        int windowsize=s1.length();
        int i=0;
        while(i<windowsize)
        {
            int idx=s2[i++]-'a';
            freq2[idx]++;
        }

        //check if present in first window 
        if(checkequal(freq1,freq2)){
            return true ;
        }


        //Then try the same windowszie until the s2 is full traversed
        while(i<s2.length()){
            int excIdx=s2[i-windowsize]-'a';
            int incIdx=s2[i] -'a';

            freq2[incIdx]++;
            freq2[excIdx]--;

            //Now check again
            if(checkequal(freq1,freq2)){
                return true ;
            }

            i++;

        }

        return false;

    }
};