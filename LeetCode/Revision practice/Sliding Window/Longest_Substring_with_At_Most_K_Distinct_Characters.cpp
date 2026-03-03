/*
Problem statement
You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= K <= 26
1 <= |str| <= 10^6

The string str will contain only lowercase alphabets.    

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.
Sample Input 1:
2
2
abbbbbbc
3
abcddefg
Sample Output 1:
7
4
Explanation:
For the first test case, ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

For the second test case, ‘str’ = ‘abcddefg’ and ‘K’ = 3, then the substrings that can be formed is [‘cdde’, ‘ddef’]. Hence the answer is 4.
Sample Input 2:
2
3
aaaaaaaa
1
abcefg
Sample Output 2:
8   
1   


Hints:
1. Try to think of a brute force approach.
2. Try to think of a two-pointer solution.
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int kDistinctChars(int k, string &str)
{
    // Longest Substring with <condition> - SLIDING WINDOW 

    // // Brute force 
    // int maxLength = 0;

    // for(int i = 0 ; i < str.size() ; i++){
    //     unordered_map<char , int > mp ; // < character , its count >
    //     for(int j = i ; j < str.size() ; j++){
    //         mp[str[j]]++;
            
    //         if(mp.size() <=k){
    //             maxLength = max( maxLength , j - i + 1);
    //         }else{
    //             break ;
    //         }
    //     }
    // }

    // //TC :O(n^2) and SC:O(k)
    // return maxLength;

    // Optimised using sliding window 
    int l = 0 ;
    int r = 0 ;
    int maxLength = 0 ;
    
    unordered_map<char , int > mp ;
    while( r < str.size()){
        // For the new window 
        mp[str[r]]++;

        if(mp.size()>k){
            mp[str[l]]--;
            if(mp[str[l]]==0){
                mp.erase(str[l]);
            }
            l++;
        }

        if(mp.size() <= k){
            maxLength= max(maxLength , r - l + 1);
        }

        r++;
    }

    //TC:O(n) and SC:O(k) // Since map size is k here 
    return maxLength;

}


