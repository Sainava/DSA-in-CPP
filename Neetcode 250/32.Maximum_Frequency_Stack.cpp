/*
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
Example 1:

Input: ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]

Output: [null, null, null, null, null, null, null, 5, 7, 5, 4]
Explanation:
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop(); // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop(); // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].

Constraints:

0 <= val <= 1,000,000,000
At most 20,000 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.

*/
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:

    //SC:O(n)
    unordered_map<int, int> freq ; // frequency of each element 
    int maxFreq ; 

    //SC:(n) -> all elements 
    unordered_map<int, stack<int> > groups ; // Group of freq 1,freq 2 and so on 
    // Remember for the same  element , when it is first added , it is added to group 1 
    // Then when added again it is added to group 2 . 
    // Then on adding again it is pushed to group 3 and so on .
    // We use stack because if same freq , we need the last added so last in first out 

    FreqStack() {
        maxFreq = 0 ; 
    }
    
    void push(int val) {
        // First
        freq[val]++;

        groups[freq[val]].push(val);

        //TC:O(1)
        maxFreq = max( maxFreq , freq[val]);

    }
    
    int pop() {
        // Now we pop the element corresponding to group of maxFreq 

        //TC:O(1)
        int element = groups[maxFreq].top();
        groups[maxFreq].pop();
        freq[element]--;

        // Now the thing is we need to update maxFreq or not 
        if(groups[maxFreq].empty()){
            // No more elements of that size 
            maxFreq--; 
            // Just minus by one as if maxFreq was 3 and we delete the third instance of that element , the other 2 are still remaining 
        }
        return element ; 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */