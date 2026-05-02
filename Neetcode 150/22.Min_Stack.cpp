/*
Design a stack class that supports the push, pop, top, and getMin operations.

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Each function should run in 
O
(
1
)
O(1) time.

Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1
Constraints:

-2^31 <= val <= 2^31 - 1.
pop, top and getMin will always be called on non-empty stacks.
*/
#include <iostream>
#include <stack>
using namespace std;

// Solution 1 : Constant time but not constant space
class MinStack {
public:
    //THis solves this question of getting min in constant time but not constant space
    //TC:O(1) and SC:O(n) for this implementation
    stack<int> primary ;
    stack<int> mini;

    MinStack() {
    }
    
    void push(int val) {
        if(primary.empty()) {
            primary.push(val);
            mini.push(val);
            return ;
        }
        int currMini = mini.top();
        int newMini = min(currMini , val);

        // Now push to both stacks
        primary.push(val);
        mini.push(newMini);
        return ;
    }
    
    void pop() {
        // POp from both 
        if(!primary.empty()){
            primary.pop();
            mini.pop();
        }
        
    }
    
    int top() {
        if(!primary.empty()) return primary.top();
        return -1 ;
    }
    
    int getMin() {
        if(!mini.empty()) return mini.top();
        return -1 ;
    }
};

// Solution 2 : Constant time and constant space
class MinStack {
public:
    //TC:O(1) and SC:O(1) for this implementation
    stack<long long > st;
    long long mini ; 

    MinStack() {
        
    }
    
    void push(int val) {
        // if empty
        if(st.empty()){
            st.push(val);
            mini = val;
            return ;
        }

        // Two conditions 

        // If current is less than mini , then mini needs to be updated
        if(val < mini){
            long long newVal = 2LL*val - mini;// This new value can be used to get previous mini and since it is less than mini it shows that this value is not the actual value which was received
            st.push(newVal);
            mini = val;
        }else{
            // Just push 
            st.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()){

            // If curr is less then the mini then it is not real value 
            long long curr = st.top();
            if(curr < mini){
                mini= 2LL*mini - curr;// The mini after this element has been deleted because the original number correspinding was the mini till now 
            }
            // Now pop
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()) {
           long long curr = st.top();

           if(curr < mini ){
            return mini ;
           }else{
            return curr;
           }
            
        }

        return -1;
    } 
    
    int getMin() {
        if(!st.empty()) return mini;
        return -1;
    }
};

