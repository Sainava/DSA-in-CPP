/*
Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times. Given a string , determine if it is valid. If so, return YES, otherwise return NO.

Example

This is a valid string because frequencies are .


This is a valid string because we can remove one  and have  of each character in the remaining string.


This string is not valid as we can only remove  occurrence of . That leaves character frequencies of .

Function Description

Complete the isValid function in the editor below.

isValid has the following parameter(s):

string s: a string
Returns

string: either YES or NO
Input Format

A single string .

Constraints

Each character 
Sample Input 0

aabbcd
Sample Output 0

NO
Explanation 0

Given , we would need to remove two characters, both c and d  aabb or a and b  abcd, to make it valid. We are limited to removing only one character, so  is invalid.

Sample Input 1

aabbccddeefghi
Sample Output 1

NO
Explanation 1

Frequency counts for the letters are as follows:

{'a': 2, 'b': 2, 'c': 2, 'd': 2, 'e': 2, 'f': 1, 'g': 1, 'h': 1, 'i': 1}

There are two ways to make the valid string:

Remove  characters with a frequency of : .
Remove  characters of frequency : .
Neither of these is an option.

Sample Input 2

abcdefghhgfedecba
Sample Output 2

YES
Explanation 2

All characters occur twice except for  which occurs  times. We can delete one instance of  to have a valid string.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <fstream>
using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    
    //SC:(1)
    vector<int> cnt(26,0);
    
    //TC:O(n)
    for(char c:s){
        cnt[c-'a']++;
    }
    
    // Now frequency of frequency 
    //SC:O(1) as atmost 26 characters and at most 26 different counts
    unordered_map<int, int> mp;
    
    //TC:(1)
    for(int i = 0 ; i < 26 ; i++){
        if(cnt[i]){
            mp[cnt[i]]++;
        }
    }
    
    
    if(mp.size()  == 1){
        return "YES" ;
    } 
    else if (mp.size() == 2){
        auto it = mp.begin() ;
        int f1 = it->first  , c1= it->second;
        it++;
        int f2 = it->first  , c2= it->second;
        
        // Case: one char with freq 1
        if((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)){
            return "YES";
        }
        // Case: one freq higher by 1 and appears once
        if(abs(f1 - f2) == 1){
            if((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))
                return "YES";
        }
        
        return "NO" ;
    }
    else{
        return "NO" ;
    }
    
    //TC:O(n) and SC:O(1)
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
