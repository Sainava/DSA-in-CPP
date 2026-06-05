/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
Example 1:

Input: ["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]

Output: [null, null, null, 2, 2, false]
Explanation:
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
Follow-up: Can you implement the stack using only one queue?
*/
#include <iostream>
#include <queue>       
using namespace std;


// Solution 1 : Using two queues
class MyStack {
public:
    // Use two queues 
    // Queue one will be the stack and queue will be a queue
    queue<int> stk;
    queue<int> q ; // It is temporary 

    MyStack() {
        
    }
    
    void push(int x) {
        // Push to q . It stores the value in FIFO 
        
        q.push(x) ; // This becomes the front of queue 

        //TC:O(n)
        // Now push all elements of stk to q . 
        while( !stk.empty()){
            q.push(stk.front());
            stk.pop();
        }

        // Now q has all the elements in the correct order 
        // Swap q and stk 
        //TC:O(1) as it does not copy the elements it just swaps references 
        // For swap they need to be the same datastructure 
        swap(stk, q);   
    }
    
    int pop() {
        //TC:O(1)
        // Remember stk is the queue that is actually implementing the stack 
        if( ! stk.empty()){
            int element = stk.front(); // This is like st.top()
            stk.pop();
            return element;
        }

        return -1 ; 
    }
    
    int top() {
        //TC:O(1)
        if(!stk.empty()){
            return stk.front() ; 
        }
        return -1 ;
    }
    
    bool empty() {
        //TC:O(1)
        return stk.empty();
    }
};

// Solution 2 : Using one queue
class MyStack {
public:
    // Using only one queue 
    queue<int> q ;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x) ; 
        // Now we wanted 4,3,2,1 but we have 3,2,1,4 so push the elements to the back again 

        int n = q.size() ; //we need to do it for the n-1 elements in front of the last element

        //TC:O(n)
        for(int i = 1 ; i <= n-1 ; i++){
            int element = q.front() ;
            q.pop() ; 
            q.push(element) ; 
        }

        // Now q becomes 4,3,2,1
    }
    
    int pop() {
        //TC:O(1)
        if( !q.empty()){
            int element = q.front() ; 
            q.pop() ;
            return element ; 
        }
        return -1 ; 
    }
    
    int top() {
        //TC:O(1)
        if( !q.empty()){

            return q.front() ; 
        }
        return -1 ; 
    }
    
    bool empty() {
        //TC:O(1)
        return q.empty() ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */