/*
You are given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right (1-indexed), and return the reversed list.

Example 1:



Input: head = [1,2,3,4,5], left = 1, right = 3

Output: [3,2,1,4,5]
Example 2:

Input: head = [1,1], left = 1, right = 1

Output: [1,1]
Constraints:

The number of nodes in the list is n.
1 <= n <= 500.
-500 <= Node.val <= 500
1 <= left <= right <= n
Follow up: Could you do it in one pass?

*/
#include <iostream>
using namespace std;



//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head ; 

        ListNode dummy(0);
        dummy.next = head ; 

        ListNode* prev = &dummy;

        for(int i  = 1 ; i < left && prev!=NULL ; i++){
            prev = prev->next ;
        }

        ListNode* prevSublist = prev;
        ListNode* lastNodeSubList = prev->next ; 

        ListNode* curr = prev->next ;
        ListNode * nxt = curr;
        prev = NULL;

        // Now we can treat as a spearable reverse linked list problem
        for(int i = 0 ; i < right - left +1 && curr!=NULL ; i++){
            nxt = curr ->next ; 
            curr->next = prev;
            prev = curr ; 
            curr = nxt ; 
        }   

        // Now prev (is the last of original subList) so first of reverse subList 
        prevSublist ->next = prev ;
        
        // First node in og sublist is now last node in reverse sublist 
        lastNodeSubList -> next = curr ; 

        //TC:O(n) and SC:O(1)
        return dummy.next ;

    }
};