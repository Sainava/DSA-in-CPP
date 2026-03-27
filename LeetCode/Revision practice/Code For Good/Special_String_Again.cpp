/*
A string is said to be a special string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

Example

 contains the following  special substrings: .

Function Description

Complete the substrCount function in the editor below.

substrCount has the following parameter(s):

int n: the length of string s
string s: a string
Returns
- int: the number of special substrings

Input Format

The first line contains an integer, , the length of .
The second line contains the string .

Constraints


Each character of the string is a lowercase English letter, .

Sample Input 0

5
asasd
Sample Output 0

7 
Explanation 0

The special palindromic substrings of  are 

Sample Input 1

7
abcbaba
Sample Output 1

10 
Explanation 1

The special palindromic substrings of  are 

Sample Input 2

4
aaaa
Sample Output 2

10
Explanation 2

The special palindromic substrings of  are 
*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'substrCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING s
 */

long substrCount(int n, string s) {
    vector<pair<char,int>> groups;

    // Step 1: build groups
    groups.push_back({s[0], 1});

    for(int i = 1; i < n; i++){
        if(s[i] == groups.back().first){
            groups.back().second++;
        } else {
            groups.push_back({s[i], 1});
        }
    }

    long cnt = 0;

    // Step 2: Type 1
    // All elements same , this is formula for all substrings
    for(auto &g : groups){
        long len = g.second;
        cnt += (len * (len + 1)) / 2;
    }

    // Step 3: Type 2
    for(int i = 1; i < groups.size() - 1; i++){
        if(groups[i].second == 1 &&
           groups[i-1].first == groups[i+1].first){
            cnt += min(groups[i-1].second, groups[i+1].second);
        }
    }
    
    //TC :O(n) and SC:(n)
    return cnt;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(),
        s.end()
    );

    return s;
}

