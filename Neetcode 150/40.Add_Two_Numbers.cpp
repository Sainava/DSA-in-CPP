/*
You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.

The digits are stored in reverse order, e.g. the number 321 is represented as 1 -> 2 -> 3 -> in the linked list.

Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Return the sum of the two numbers as a linked list.

Example 1:



Input: l1 = [1,2,3], l2 = [4,5,6]

Output: [5,7,9]

Explanation: 321 + 654 = 975.
Example 2:

Input: l1 = [9], l2 = [9]

Output: [8,1]
Constraints:

1 <= l1.length, l2.length <= 100.
0 <= Node.val <= 9
*/



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val == 0) return l2;
        if(l2->val == 0) return l1;

        ListNode* first = l1 ;
        ListNode* second = l2 ;

        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy ;

        int carry = 0 ;
        while ( first!=NULL || second!= NULL || carry ){
            int x = (first==NULL)? 0 : first->val;
            int y = (second==NULL)? 0 : second->val;
            int sum = x + y + carry ;

            carry = sum / 10 ;
            sum = sum % 10 ;

            ListNode* newNode = new ListNode(sum);
            res->next = newNode ;
            res = res->next;

            if(first!= NULL) first = first->next;
            if(second!= NULL) second = second->next;
        }


        //TC:O(m + n ) and SC:O(m + n) for the answer 
        return dummy->next; ;
    }
};
