/*
You are given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

You can return any possible rearrangement of s or return "" if not posssible.

Example 1:

Input: s = "axyy"

Output: "xyay"
Example 2:

Input: s = "abbccdd"

Output: "abcdbcd"
Example 3:

Input: s = "ccccd"

Output: ""
Constraints:

1 <= s.length <= 500.
s is made up of lowercase English characters.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26 , 0 );

        int n = s.size() ; //Total number of characters 

        //TC:O(n)
        for(int i = 0 ; i < n ; i++){
            freq[s[i] - 'a']++;

            // For n is odd > n/2 works 
            // But for n is even only >(n+1) / 2 works
            // So >(n + 1) /2 works for both 

            if( freq[s[i] - 'a'] > (n+1)/2) return "";
        }

        priority_queue< pair<int , char >> pq ; // count , char 

        for(int i = 0 ; i < 26 ; i++){
            if( freq[i] > 0){
                pq.push({freq[i] , i + 'a'});
            }
        }

        string ans = "";
 
        pair<int,char> prevUsed = {0 , '#'} ;

        //TC:O(nlogk) k is distinct characters 
        while(!pq.empty()){
            // Take the best character , use it
            auto p = pq.top() ; 
            int fr = p.first ; 
            char ch = p.second ;

            ans.push_back(ch);

            // Now pop it and put it aside 
            pq.pop();

            if( prevUsed.first > 0 ){
                //put it back 
                pq.push({prevUsed.first , prevUsed.second});
            }

            // Now put the current character aside 
            prevUsed.first = fr - 1 ; 
            prevUsed.second = ch ; 

        }
        
        // Time: O(n log k), where k is the number of distinct characters.
        // Space: O(k) auxiliary, O(n) including the output string.
        // For this specific problem with only lowercase English letters:
        // Time: O(n)
        // Space: O(1) auxiliary
        return ans ; 

    }
};