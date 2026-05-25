/*
You are given a string s consisting of lowercase english letters.

We want to split the string into as many substrings as possible, while ensuring that each letter appears in at most one substring.

Return a list of integers representing the size of these substrings in the order they appear in the string.

Example 1:

Input: s = "xyxxyzbzbbisl"

Output: [5, 5, 1, 1, 1]
Explanation: The string can be split into ["xyxxy", "zbzbb", "i", "s", "l"].

Example 2:

Input: s = "abcabc"

Output: [6]
Constraints:

1 <= s.length <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size() ; 
        
        vector<int> lastIndex(26); // char and lastIndex at which char appeared 

        for(int i = 0 ; i < s.size() ; i++){
            lastIndex[s[i] - 'a'] = i ; 
        }

        vector<int> ans ; 
        int start = 0 ; 

        while(start < n){
            // We traverse from s to end , to see if every number inside ends at this 

            int end = lastIndex[s[start] - 'a'] ;
            int i = start + 1 ; 
            while( i <= end){
                // It has to be i<= end and not i!=end as when start == end -> then too i != end , so we may run wrongly
                if( lastIndex[s[i] - 'a'] > end) end = lastIndex[s[i] - 'a'] ;
                i++ ;
            }
            
            // One partition , push to answer 
            ans.push_back(end - start + 1) ;
            start = end + 1 ;

        }

        // TC:O(n) as each element is second loop is only processed once
        // SC:O(1)
        return ans ;
        
    }
};
