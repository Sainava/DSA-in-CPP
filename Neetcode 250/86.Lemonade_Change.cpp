/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

You are given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Example 1:

Input: bills = [5,10,5,5,20]

Output: true
Explanation:
From first customer, we collect one $5 bill.
From second customer, we collect $10 bill and give back $5 bill.
From third and fourth customers, we collect two $5 bills.
From fifth customer, we collect $20 bill and give back one $10 bill and $5 bill.

Example 2:

Input: bills = [5,20,10,5]

Output: false
Constraints:

1 <= bills.length <= 100,000
bills[i] is either 5, 10, or 20.

*/
# include <iostream>    
# include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //suppose a customer pays 20 Rs then we first try to give him change by giving 10 Rs and 5 Rs  and if are unable to do then we given three 5 Rs change , in this way saving 5 Rs for future customers.
        // That is the greedy mindset 

        int five  = 0 ;
        int ten  = 0 ;
        // I do not need to keep track of how many 20 dollar notes we have as we cannot gibe that as change
        for(int bill : bills){

            if(bill == 5){
                five++ ; 
            }

            else if ( bill == 10){
                if(five >= 1){
                    five--;
                    ten++ ;
                }else {
                    return false ; 
                }
            }

            else {
                // Customer gives us 20 
                if( ten >= 1 && five>= 1){
                    ten-- ; 
                    five--;
                }
                else if( five>=3){
                    five = five - 3 ;
                }else{
                    return false ; 
                }
            }
        }

        // We completed for all customers 
        //TC:O(n) and SC:O(1)
        return true ; 
    }
};