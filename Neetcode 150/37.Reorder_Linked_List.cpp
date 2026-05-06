/*
You are given the head of a singly linked-list.

The positions of a linked list of length = 7 for example, can intially be represented as:

[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:

[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.

Example 1:

Input: head = [2,4,6,8]

Output: [2,8,4,6]
Example 2:

Input: head = [2,4,6,8,10]

Output: [2,10,4,8,6]
Constraints:

1 <= Length of the list <= 1000.
1 <= Node.val <= 1000
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
    void reorderList(ListNode* head) {
        // Three steps 

        // 1.Find middle element 
        // 2. Reverse second half
        // 3.Merge alternatively 

        // 1. Find Mid 
        ListNode* slow = head;
        ListNode* fast = head ;

        //TC:O(n)
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2.Reverse the second half of string 
        // slow now is the mid element , reverse linked list from the next node 
        // We need to reverse from the next element 
        ListNode* curr = slow->next;
        ListNode* forward = curr;
        ListNode* prev = NULL;

        // Disconnect both halves
        slow->next = NULL;

        //TC:O(n)
        while(curr!=NULL){
            forward = curr -> next ;
            curr->next = prev ;
            prev = curr ;
            curr = forward;
        }
        // Now prev is the head of the second half reversed , we can say that the two halves are not connected now 
        //3.Connect them alternatively ;

        curr = head ;
        forward = curr;

        //TC:O(n)
        while(prev!=NULL){
            forward = curr ->next ;
            curr ->next = prev;
            curr = prev ;
            prev = forward;
        }

        // // Another merge logic 
        // ListNode* first = head;
        // ListNode* second = prev; // head of reversed second half

        // while (second != NULL) {
        //     ListNode* firstNext = first->next;
        //     ListNode* secondNext = second->next;

        //     first->next = second;
        //     second->next = firstNext;

        //     first = firstNext;
        //     second = secondNext;
        // }

        //TC:O(3n) and SC:O(1)
        return ;

    }
};
