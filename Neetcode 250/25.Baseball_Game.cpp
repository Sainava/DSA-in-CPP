/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

Given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x: Record a new score of x.
'+': Record a new score that is the sum of the previous two scores.
'D': Record a new score that is the double of the previous score.
'C': Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

Note: The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

Example 1:

Input: ops = ["1","2","+","C","5","D"]

Output: 18
Explanation:

"1" - Add 1 to the record, record = [1].
"2" - Add 2 to the record, record = [1, 2].
"+" - Add 1 + 2 = 3 to the record, record = [1, 2, 3].
"C" - Invalidate and remove the previous score, record = [1, 2].
"5" - Add 5 to the record, record = [1, 2, 5].
"D" - Add 2 * 5 = 10 to the record, record = [1, 2, 5, 10].
The total sum is 1 + 2 + 5 + 10 = 18.
Example 2:

Input: ops = ["5","D","+","C"]

Output: 15
Explanation:

"5" - Add 5 to the record, record = [5].
"D" - Add 2 * 5 = 10 to the record, record = [5, 10].
"+" - Add 5 + 10 = 15 to the record, record = [5, 10, 15].
"C" - Invalidate and remove the previous score, record = [5, 10].
The total sum is 5 + 10 = 15.
Constraints:

1 <= operations.length <= 1000
operations[i] is "C", "D", +, or a string representing an integer in the range [(-30,000), (30,000)].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st ; // Score at each time 
        // The question says all operations are valid so we do not need to check for empty stack at each step 
        for(string &op : operations){

            if( op == "+"){
                
                int a = st.top();
                st.pop();
                int b = st.top();

                // Need to push the scores again as we need to record a new score
                st.push(a);

                st.push( a + b);
            }
            else if (op == "D"){
                int a = st.top();
                st.push( 2*a);
            }
            else if(op == "C"){
                st.pop();
            }
            else {
                st.push( stoi (op));
            }

        }

        int score = 0 ; 

        // Can remove this loop but keeping track of score from the get go 
        // Add to score at every push and remove from score at every pop
        while( !st.empty()){
            score += st.top();
            st.pop();
        }

        //TC:O(n) and SC:O(n)
        return score;
    }
};