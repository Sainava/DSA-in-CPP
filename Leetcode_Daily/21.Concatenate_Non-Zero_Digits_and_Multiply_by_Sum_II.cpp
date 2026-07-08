// 8 July 2026 

// 3756. Concatenate Non-Zero Digits and Multiply by Sum II

/*
You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.

 

Example 1:

Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

Output: [12340, 4, 9]

Explanation:

s[0..7] = "10203004"
x = 1234
sum = 1 + 2 + 3 + 4 = 10
Therefore, answer is 1234 * 10 = 12340.
s[1..3] = "020"
x = 2
sum = 2
Therefore, the answer is 2 * 2 = 4.
s[4..6] = "300"
x = 3
sum = 3
Therefore, the answer is 3 * 3 = 9.
Example 2:

Input: s = "1000", queries = [[0,3],[1,1]]

Output: [1, 0]

Explanation:

s[0..3] = "1000"
x = 1
sum = 1
Therefore, the answer is 1 * 1 = 1.
s[1..1] = "0"
x = 0
sum = 0
Therefore, the answer is 0 * 0 = 0.
Example 3:

Input: s = "9876543210", queries = [[0,9]]

Output: [444444137]

Explanation:

s[0..9] = "9876543210"
x = 987654321
sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
Therefore, the answer is 987654321 * 45 = 44444444445.
We return 44444444445 modulo (109 + 7) = 444444137.
 

Constraints:

1 <= m == s.length <= 105
s consists of digits only.
1 <= queries.length <= 105
queries[i] = [li, ri]
0 <= li <= ri < m
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            int n = s.size();

            vector<int> nextNZ(n + 1, -1);
            vector<int> prevNZ(n, -1);

            // next non-zero
            int nxt = -1;
            for(int i=n-1;i>=0;i--){
                if(s[i]!='0') nxt=i;
                nextNZ[i]=nxt;
            }

            // previous non-zero
            int prv=-1;
            for(int i=0;i<n;i++){
                if(s[i]!='0') prv=i;
                prevNZ[i]=prv;
            }

            string comp;

            vector<int> pos(n,-1);

            for(int i=0;i<n;i++){
                if(s[i]!='0'){
                    pos[i]=comp.size();
                    comp.push_back(s[i]);
                }
            }

            int m=comp.size();

            vector<long long> prefNum(m+1,0);
            vector<long long> prefSum(m+1,0);
            vector<long long> pow10(m+1,1);

            for(int i=1;i<=m;i++)
                pow10[i]=pow10[i-1]*10%MOD;

            for(int i=0;i<m;i++){

                int d=comp[i]-'0';

                prefNum[i+1]=(prefNum[i]*10+d)%MOD;

                prefSum[i+1]=prefSum[i]+d;
            }

            vector<int> ans;

            for(auto &q:queries){

                int l=q[0];
                int r=q[1];

                int L=nextNZ[l];

                if(L==-1 || L>r){
                    ans.push_back(0);
                    continue;
                }

                int R=prevNZ[r];

                int a=pos[L];
                int b=pos[R];

                int len=b-a+1;

                long long number=
                    (prefNum[b+1]
                    -prefNum[a]*pow10[len])%MOD;

                if(number<0)
                    number+=MOD;

                long long sum=
                    prefSum[b+1]-prefSum[a];

                ans.push_back(number*sum%MOD);
            }

            return ans;

            // Preprocessing:
            // Build mappings          O(n)
            // Prefix arrays           O(n)
            //
            // Each query:
            // O(1)
            //
            // Total:
            // O(n + q)
            //
            // SC:
            // O(n)
    }
    
};