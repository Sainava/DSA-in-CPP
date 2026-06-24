// 24 June 2026

//3700. Number of ZigZag Arrays II

/*
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

​​​​​​​There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 109
1 <= l < r <= 75​​​​​​​
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    // Matrix multiplication
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();

        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    // Fast exponentiation of matrix
    Matrix power(Matrix base, long long exp) {
        int sz = base.size();

        Matrix result(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            result[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    int zigZagArrays(long long n, int l, int r) {

        int m = r - l + 1;

        // State encoding:
        //
        // 0 ... m-1      -> UP ending at value v
        // m ... 2m-1     -> DOWN ending at value v
        //
        // Total states = 2*m

        int S = 2 * m;

        if (n == 1) {
            return m;
        }

        // Build transition matrix
        Matrix T(S, vector<long long>(S, 0));

        for (int prev = 0; prev < m; prev++) {

            // -----------------------------
            // Transition from UP state
            // -----------------------------
            int fromUp = prev;

            for (int nxt = 0; nxt < prev; nxt++) {

                // UP -> DOWN
                //
                // If previous movement was increasing,
                // next movement must be decreasing.

                int toDown = m + nxt;

                T[toDown][fromUp] = 1;
            }

            // -----------------------------
            // Transition from DOWN state
            // -----------------------------
            int fromDown = m + prev;

            for (int nxt = prev + 1; nxt < m; nxt++) {

                // DOWN -> UP
                //
                // If previous movement was decreasing,
                // next movement must be increasing.

                int toUp = nxt;

                T[toUp][fromDown] = 1;
            }
        }

        // Initial vector for length = 2
        //
        // Count all valid pairs (x,y)
        //
        // x < y => UP state at y
        // x > y => DOWN state at y

        vector<long long> start(S, 0);

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < m; y++) {

                if (x == y) continue;

                if (x < y) {
                    start[y]++;
                } else {
                    start[m + y]++;
                }
            }
        }

        if (n == 2) {

            long long ans = 0;

            for (auto v : start) {
                ans = (ans + v) % MOD;
            }

            return (int)ans;
        }

        // Apply transition (n-2) times
        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {

                finalState[i] =
                    (finalState[i] + P[i][j] * start[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long v : finalState) {
            ans = (ans + v) % MOD;
        }

        return (int)ans;
    }
};