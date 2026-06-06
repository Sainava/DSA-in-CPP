/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
Example 1:

Input: ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]

Output: [null, 1, 1, 1, 2, 1, 4, 6]
Explanation:
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80); // return 1
stockSpanner.next(60); // return 1
stockSpanner.next(70); // return 2
stockSpanner.next(60); // return 1
stockSpanner.next(75); // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85); // return 6

Constraints:

1 <= price <= 100,000
At most 10,000 calls will be made to next.
*/
#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
    // Rephrase 
    //For todays price: say (price = 75)
    // we want to know:
    // How far back can I go before I encounter a price strictly greater than 75?
    // Basically in terms of indices 
    // Span = curr index - index of last greater element
    

    // We will use a monotic stack -> Store decreasing only 
    stack<pair<int , int>> st ;  // price , span
    // This way for first element -> index = 0 and span = 0 - (-1) = 1 which is correct 
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1 ; 
        
        //TC:O(n)
        while( !st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop() ;
        }

        st.push( {price , span});

        //TC:O(n) and SC:O(n) for overall question to use Stack 
        return span ; 

    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */