/*
You are given the head of a singly linked list head and a positive integer k.

You must reverse the first k nodes in the linked list, and then reverse the next k nodes, and so on. If there are fewer than k nodes left, leave the nodes as they are.

Return the modified list after reversing the nodes in each group of k.

You are only allowed to modify the nodes' next pointers, not the values of the nodes.

Example 1:



Input: head = [1,2,3,4,5,6], k = 3

Output: [3,2,1,6,5,4]
Example 2:



Input: head = [1,2,3,4,5], k = 3

Output: [3,2,1,4,5]
Constraints:

The length of the linked list is n.
1 <= k <= n <= 100
0 <= Node.val <= 100
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base Case :
        if( head == NULL){
            return NULL;
        }

        // Check if k nodes exist 
        ListNode*temp = head;
        int cnt = 0;

        //TC:O(k) runs k times max ( can stop when less than k nodes and temp = NULL)
        while(temp!=NULL and cnt < k){
            cnt++;
            temp = temp ->next ;
        }

        if(cnt < k ) return head ;

        // Reverse the first k nodes
        ListNode * curr = head ;
        ListNode * next = head ;
        ListNode * prev = NULL ;
        cnt = 0 ;

        while( curr!= NULL && cnt<k){
            next = curr -> next;
            curr->next = prev;
            prev = curr ;
            curr = next ;
            cnt++;
        }


        // Now let recursion revere the rest of the linked list 
        if(next!=NULL){
            // head is now the last node in this list 
            head->next = reverseKGroup(next,k);
        }

        // Returnt the new first node ; which is previous 
        //TC:O(2n) since each node is visited twice ,once to check and once to reverse 
        //SC:O(n/k) number of calls in recursion stack 
        return prev;
    }
};
