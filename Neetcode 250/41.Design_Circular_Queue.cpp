/*
Design and implement circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.
Example 1:

Input: ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]

Output: [null, true, true, true, false, 3, true, true, true, 4]
Explanation:
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear(); // return 3
myCircularQueue.isFull(); // return True
myCircularQueue.deQueue(); // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear(); // return 4

Constraints:

1 <= k <= 1000.
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
*/
#include <iostream>
#include <vector>
using namespace std;


class MyCircularQueue {
public:
    vector<int> q ;
    int front ; // Handles deletion  , shows the index of first element 
    int rear ; // Handles insertion , shows the index of the position where element may be added
    int cnt ; // To handle one problem state as front == rear can mean empty or full
    int capacity ; 
    // All functions have TC:O(1)
    // And total SC:O(k)

    MyCircularQueue(int k) {
        q.resize(k);
        front = 0 ; 
        rear = 0 ;
        cnt = 0 ; 
        capacity = k ;
    }
    
    bool enQueue(int value) {
        if(cnt == capacity){
            //queue is full 
            return false ; 
        }
        // Can add just need to find where to add 
        q[rear] = value ; 
        rear = (rear + 1) % capacity;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0){
            //queue is empty
            return false ; 
        }
        // Just need to move front
        front =(front + 1 ) % capacity ; 
        cnt--;
        return true ;

    }
    
    int Front() {
        if(cnt == 0){
            return -1 ; 
        }
        return q[front];
    }
    
    int Rear() {
        if(cnt == 0){
            return -1 ; 
        }
        // rear shows the index that is empty 
        // We need the index before rear 
        // rear - 1 may give out of index 
        int index = (rear + capacity - 1) % capacity;
        return q[index];
    }
    
    bool isEmpty() {
        return cnt == 0 ;
    }
    
    bool isFull() {
        return cnt == capacity ; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */