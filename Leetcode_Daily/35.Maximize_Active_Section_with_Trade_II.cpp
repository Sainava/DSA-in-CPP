// 22 July 2026 

// 3501. Maximize Active Section with Trade II

/*
You are given a binary string s of length n, where:

'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].

For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].

Return an array answer, where answer[i] is the result for queries[i].

Note

For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
The queries are independent of each other.
 

Example 1:

Input: s = "01", queries = [[0,1]]

Output: [1]

Explanation:

Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 2:

Input: s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]

Output: [4,3,1,1]

Explanation:

Query [0, 3] → Substring "0100" → Augmented to "101001"
Choose "0100", convert "0100" → "0000" → "1111".
The final string without augmentation is "1111". The maximum number of active sections is 4.

Query [0, 2] → Substring "010" → Augmented to "10101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "1110". The maximum number of active sections is 3.

Query [1, 3] → Substring "100" → Augmented to "11001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Query [2, 3] → Substring "00" → Augmented to "1001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 3:

Input: s = "1000100", queries = [[1,5],[0,6],[0,4]]

Output: [6,7,2]

Explanation:

Query [1, 5] → Substring "00010" → Augmented to "1000101"
Choose "00010", convert "00010" → "00000" → "11111".
The final string without augmentation is "1111110". The maximum number of active sections is 6.

Query [0, 6] → Substring "1000100" → Augmented to "110001001"
Choose "000100", convert "000100" → "000000" → "111111".
The final string without augmentation is "1111111". The maximum number of active sections is 7.

Query [0, 4] → Substring "10001" → Augmented to "1100011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

Example 4:

Input: s = "01010", queries = [[0,3],[1,4],[1,3]]

Output: [4,4,2]

Explanation:

Query [0, 3] → Substring "0101" → Augmented to "101011"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "11110". The maximum number of active sections is 4.

Query [1, 4] → Substring "1010" → Augmented to "110101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "01111". The maximum number of active sections is 4.

Query [1, 3] → Substring "101" → Augmented to "11011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

 

Constraints:

1 <= n == s.length <= 105
1 <= queries.length <= 105
s[i] is either '0' or '1'.
queries[i] = [li, ri]
0 <= li <= ri < n
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        // I need to revisit this question again 

        int n = s.size();

        // Count the number of active sections initially.
        int totalOnes = 0;
        for (char ch : s) {
            if (ch == '1')
                totalOnes++;
        }

        /*
            Run Length Encoding (RLE)

            Example:
            s = "000111001"

            segmentType  = [0,1,0,1]
            segmentStart = [0,3,6,8]
            segmentEnd   = [2,5,7,8]
        */

        vector<int> segmentType;
        vector<int> segmentStart;
        vector<int> segmentEnd;

        for (int i = 0; i < n;) {

            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            segmentType.push_back(s[i] - '0');
            segmentStart.push_back(i);
            segmentEnd.push_back(j - 1);

            i = j;
        }

        int segments = segmentType.size();

        /*
            For every position in the original string,
            store which segment it belongs to.
        */

        vector<int> positionToSegment(n);

        for (int seg = 0; seg < segments; seg++) {

            for (int pos = segmentStart[seg];
                pos <= segmentEnd[seg];
                pos++) {

                positionToSegment[pos] = seg;
            }
        }

        /*
            gain[i]

            If segment i is a surrounded block of 1s,

            000111000

            then removing that 1-block merges the two
            neighbouring zero-blocks.

            Gain =
                leftZeroLength + rightZeroLength
        */

        vector<int> gain(segments, 0);

        for (int seg = 1; seg < segments - 1; seg++) {

            if (segmentType[seg] == 1) {

                int leftZero =
                    segmentEnd[seg - 1] -
                    segmentStart[seg - 1] + 1;

                int rightZero =
                    segmentEnd[seg + 1] -
                    segmentStart[seg + 1] + 1;

                gain[seg] = leftZero + rightZero;
            }
        }

        /*
            Sparse Table

            We only need Range Maximum Query on gain[].
        */

        vector<int> lg(segments + 1, 0);

        for (int i = 2; i <= segments; i++)
            lg[i] = lg[i / 2] + 1;

        int LOG = lg[segments] + 1;

        vector<vector<int>> sparse(LOG,
                                vector<int>(segments));

        for (int i = 0; i < segments; i++)
            sparse[0][i] = gain[i];

        for (int k = 1; k < LOG; k++) {

            for (int i = 0;
                i + (1 << k) <= segments;
                i++) {

                sparse[k][i] =
                    max(sparse[k - 1][i],
                        sparse[k - 1][i + (1 << (k - 1))]);
            }
        }

        /*
            Range Maximum Query on gain[]
        */

        auto queryMax = [&](int left, int right) {

            if (left > right)
                return 0;

            int k = lg[right - left + 1];

            return max(
                sparse[k][left],
                sparse[k][right - (1 << k) + 1]
            );
        };

        /*
            Computes the gain of a boundary 1-segment.

            Interior segments have their gain already stored.

            Boundary segments may be only partially inside
            the query, so we recompute them.
        */

        auto boundaryGain =
        [&](int segment,
            int leftPos,
            int rightPos,
            int leftSegment,
            int rightSegment) {

            if (segment <= leftSegment ||
                segment >= rightSegment)
                return 0;

            if (segmentType[segment] == 0)
                return 0;

            int leftZero = 0;

            if (segment - 1 == leftSegment)
                leftZero =
                    max(0,
                        segmentEnd[segment - 1] -
                        leftPos + 1);
            else
                leftZero =
                    segmentEnd[segment - 1] -
                    segmentStart[segment - 1] + 1;

            int rightZero = 0;

            if (segment + 1 == rightSegment)
                rightZero =
                    max(0,
                        rightPos -
                        segmentStart[segment + 1] + 1);
            else
                rightZero =
                    segmentEnd[segment + 1] -
                    segmentStart[segment + 1] + 1;

            return leftZero + rightZero;
        };

        vector<int> answer;

        for (auto &query : queries) {

            int L = query[0];
            int R = query[1];

            int leftSegment = positionToSegment[L];
            int rightSegment = positionToSegment[R];

            /*
                Fewer than three segments means there
                cannot exist

                    0-run
                    1-run
                    0-run

                so no trade is possible.
            */

            if (rightSegment - leftSegment < 2) {

                answer.push_back(totalOnes);
                continue;
            }

            int bestGain = 0;

            /*
                First interior 1-segment
            */
            bestGain = max(
                bestGain,
                boundaryGain(leftSegment + 1,
                            L,
                            R,
                            leftSegment,
                            rightSegment)
            );

            /*
                Last interior 1-segment
            */
            bestGain = max(
                bestGain,
                boundaryGain(rightSegment - 1,
                            L,
                            R,
                            leftSegment,
                            rightSegment)
            );

            /*
                Completely contained 1-segments.

                Their gains never change, so use RMQ.
            */

            if (leftSegment + 2 <= rightSegment - 2) {

                bestGain = max(
                    bestGain,
                    queryMax(leftSegment + 2,
                            rightSegment - 2)
                );
            }

            answer.push_back(totalOnes + bestGain);
        }

        return answer;
    }
};