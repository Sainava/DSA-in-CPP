// 07 August 2026 

// 3348. Smallest Divisible Digit Product II

/*
You are given a string num which represents a positive integer, and an integer t.

A number is called zero-free if none of its digits are 0.

Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

 

Example 1:

Input: num = "1234", t = 256

Output: "1488"

Explanation:

The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

Example 2:

Input: num = "12355", t = 50

Output: "12355"

Explanation:

12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

Example 3:

Input: num = "11111", t = 26

Output: "-1"

Explanation:

No number greater than 11111 has the product of its digits divisible by 26.

 

Constraints:

2 <= num.length <= 2 * 105
num consists only of digits in the range ['0', '9'].
num does not contain leading zeros.
1 <= t <= 1014
*/

#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
    int get_count(int val, int p) {
        int cnt = 0;
        while (val > 0 && val % p == 0) {
            cnt++;
            val /= p;
        }
        return cnt;
    }

public:
    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (t % 2 == 0) { req2++; t /= 2; }
        while (t % 3 == 0) { req3++; t /= 3; }
        while (t % 5 == 0) { req5++; t /= 5; }
        while (t % 7 == 0) { req7++; t /= 7; }
        
        if (t > 1) return "-1";

        // Local static state to avoid recomputing across test cases
        static vector<vector<string>> dp(47, vector<string>(30, string(100, '9')));
        static bool inited = false;
        
        if (!inited) {
            dp[0][0] = "";
            vector<pair<int, int>> digs = {
                {1, 0}, {0, 1}, {2, 0}, {1, 1}, {3, 0}, {0, 2} 
            };
            string chars = "234689";

            for (int i = 0; i <= 46; i++) {
                for (int j = 0; j <= 29; j++) {
                    if (i == 0 && j == 0) continue;
                    for (int k = 0; k < 6; k++) {
                        int pi = max(0, i - digs[k].first);
                        int pj = max(0, j - digs[k].second);
                        
                        if (pi == i && pj == j) continue;
                        
                        string cand = dp[pi][pj] + chars[k];
                        sort(cand.begin(), cand.end());
                        
                        if (cand.size() < dp[i][j].size() || 
                            (cand.size() == dp[i][j].size() && cand < dp[i][j])) {
                            dp[i][j] = cand;
                        }
                    }
                }
            }
            inited = true;
        }

        int n = num.size();
        vector<array<int, 4>> pref(n + 1, {0, 0, 0, 0});
        int first_zero = n;

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if (num[i] == '0') {
                if (first_zero == n) first_zero = i;
            } else {
                int d = num[i] - '0';
                pref[i + 1][0] += get_count(d, 2);
                pref[i + 1][1] += get_count(d, 3);
                pref[i + 1][2] += get_count(d, 5);
                pref[i + 1][3] += get_count(d, 7);
            }
        }

        if (first_zero == n && pref[n][0] >= req2 && pref[n][1] >= req3 && 
            pref[n][2] >= req5 && pref[n][3] >= req7) {
            return num;
        }

        for (int i = min(n - 1, first_zero); i >= 0; i--) {
            int start_d = max<int>('1', num[i] + 1);
            
            for (int d = start_d; d <= '9'; d++) {
                int c2 = max(0, req2 - pref[i][0] - get_count(d - '0', 2));
                int c3 = max(0, req3 - pref[i][1] - get_count(d - '0', 3));
                int c5 = max(0, req5 - pref[i][2] - get_count(d - '0', 5));
                int c7 = max(0, req7 - pref[i][3] - get_count(d - '0', 7));
                
                string suf = dp[c2][c3];
                suf += string(c5, '5');
                suf += string(c7, '7');
                sort(suf.begin(), suf.end());
                
                int needed = suf.size();
                int avail = n - 1 - i;
                
                if (needed <= avail) {
                    return num.substr(0, i) + (char)d + string(avail - needed, '1') + suf;
                }
            }
        }

        string suf = dp[req2][req3];
        suf += string(req5, '5');
        suf += string(req7, '7');
        sort(suf.begin(), suf.end());
        
        int len = max(n + 1, (int)suf.size());
        return string(len - suf.size(), '1') + suf;
    }
};