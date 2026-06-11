/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
You are given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: a = 3, b = 4, c = 2

Output: "bababcabc"
Example 2:

Input: a = 0, b = 1, c = 5

Output: "ccbcc"
Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n = a + b + c ;

        priority_queue< pair<int , char >> pq ; 

        if( a> 0 ) pq.push({a , 'a'});
        if( b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        int i = 0 ; 
        
        string ans = "" ; 

        //TC:O(nlog3)
        while(!pq.empty() ){
            auto p1 = pq.top();
            pq.pop();

            int freq1 = p1.first;
            char ch1 = p1.second;

            if(ans.size() >= 2 && ans.back() == ch1 && ans[ans.size()-2] == ch1){

                // No alternative character exists
                if( pq.empty()) break ;

                auto p2 = pq.top();
                pq.pop();

                int freq2 = p2.first;
                char ch2 = p2.second;

                ans.push_back(ch2);
                freq2--;

                if(freq2 > 0)
                pq.push({freq2, ch2});

                // Put the blocked character back
                pq.push({freq1, ch1});
            }
            else{
                ans.push_back(ch1);
                freq1--;

                if(freq1 > 0)
                    pq.push({freq1, ch1});
            }
        }

        //TC:O(nlog3) and SC:O(3)
        // Simplified TC:O(n) and SC:O(1)
        return ans ; 

    }
};