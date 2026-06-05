/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
Example 1:

Input: ["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]

Output: [null, null, null, 1, 1, false]
Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/
#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:

    stack<int> in ; // new arrivals
    stack<int> out ; // Our real queue  // Ready to leave

    // TC : O(1) for all functions -> EVEN FOR POP AND PEEP

    // AS all elements pushed to out and in once and pushed also once
    // SO amortized -> TC:O(1)

    // Each element:
    //
    // 1. Is pushed into 'in' once
    // 2. Is moved from 'in' to 'out' at most once
    // 3. Is popped from 'out' once
    //
    // Therefore total work is linear in the number of elements,
    // giving amortized O(1) push, pop and peek.

    // push  : O(1)
    // pop   : Amortized O(1)
    // peek  : Amortized O(1)
    // empty : O(1)
    MyQueue() {
        
    }
    
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        // If out is empty 
        if( out.empty()){
            // Take all elements from in and push to out 

            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int element = out.top() ; 
        out.pop() ;
        return element;
    }
    
    int peek() {
        // If out is empty 
        if( out.empty()){
            // Take all elements from in and push to out 

            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */