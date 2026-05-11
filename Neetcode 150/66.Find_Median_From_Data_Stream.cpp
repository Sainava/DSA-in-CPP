/*
The median is the middle value in a sorted list of integers. For lists of even length, there is no middle value, so the median is the mean of the two middle values.

For example:

For arr = [1,2,3], the median is 2.
For arr = [1,2], the median is (1 + 2) / 2 = 1.5
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far.
Example 1:

Input:
["MedianFinder", "addNum", "1", "findMedian", "addNum", "3" "findMedian", "addNum", "2", "findMedian"]

Output:
[null, null, 1.0, null, 2.0, null, 2.0]

Explanation:
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.findMedian(); // return 1.0
medianFinder.addNum(3);    // arr = [1, 3]
medianFinder.findMedian(); // return 2.0
medianFinder.addNum(2);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
Constraints:

-100,000 <= num <= 100,000
findMedian will only be called after adding at least one integer to the data structure.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap ;
    priority_queue<int , vector<int> , greater<int>> minHeap ;
    double median ;

    MedianFinder() {
        
    }

    int signum(int a , int b ){
        if ( a > b) return 1 ;
        else if( a < b) return -1 ;
        return 0 ;
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()){
            // first element , so it is the median
            median = num ;
            maxHeap.push(num);
            return ;
        }

        // If if more than one element
        // we need to understand , where we want to add the element 
        // The key idea here is 
        //all elements to the left to the median are smaller and uses max heap 
        // all elements to the right of median are bigger and uses min heap 
        // The difference between size of maxheap and minheap is <=1 at all times

        int m = maxHeap.size();
        int n = minHeap.size();

        // There are lets say N elements at all times 
        // We add to minHeap or maxHeap (atleast once ) sometimes twice 
        // So total overall 
        // TC:O(logN)  for this particular function addNum
        // But overall total complexity for this entire question
        //TC:O(NLogN) and SC:O(N)
        switch(signum(m,n)){
            case 1 :
                if(num > median){
                    // add to min heap on the right 
                    minHeap.push(num);
                    // now same elements on both sides     
                }else{
                    // if we add to maxheap it will have two numbers more than min heap ,we cannot have that 
                    // so we take one element from max heap and add to min heap first 
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();

                    // Now add to maxHeap  so both have same elements 
                    maxHeap.push(num);
                }
                median = (minHeap.top() + maxHeap.top()) / 2.0;
                break ;

            
            case -1 :
                if( num > median ){
                    // if we add to minheap , it will have two more elements than maxheap
                    maxHeap.push(minHeap.top());
                    minHeap.pop();

                    minHeap.push(num);
                }else {
                    maxHeap.push(num);
                }
                median = (minHeap.top() + maxHeap.top()) / 2.0;
                break ;

            case 0 :
                if(num>median){
                    minHeap.push(num);
                    median = minHeap.top();
                }else{
                    maxHeap.push(num);
                    median = maxHeap.top();
                }
                break ;
        }

        return ;
    }
    
    double findMedian() {
        //TC:O(1)
        return median ;
    }
};
