/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
    // ... your code
    return encoded_string;
}
Machine 2 (receiver) has the function:

vector<string> decode(string s) {
    //... your code
    return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Example 1:

Input: dummy_input = ["Hello","World"]

Output: ["Hello","World"]

Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
Example 2:

Input: dummy_input = [""]

Output: [""]

Constraints:

0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains any possible characters out of 256 valid ASCII characters.

Follow up: Could you write a generalized algorithm to work on any possible set of characters?

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        // N = total number of characters across all strings 

        //TC:O(N)
        for(string &str : strs){
            res += to_string(str.length()) + "#" + str;
        }

        //TC:O(N) and SC:O(N)
        return res;
    }

    vector<string> decode(string s) {

        //SC:O(N)
        vector<string> ans ;

        int i = 0 ;

        //TC:O(N)
        while( i < s.length()){

            int j = i;

            while ( s[j]!= '#'){
                j++;
            }

            int len = stoi(s.substr(i,j-i));
            
            string word = s.substr(j+1,len);

            ans.push_back(word);

            i = j + 1 + len ; // The +1 takes it to the next char of the curr string which is the length of next
        }

        //TC:O(N) AND SC:O(N)
        return ans;
    }
};
