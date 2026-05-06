/*
You are given the beginning of a linked list head, and an integer n.

Remove the nth node from the end of the list and return the beginning of the list.

Example 1:

Input: head = [1,2,3,4], n = 2

Output: [1,2,4]
Example 2:

Input: head = [5], n = 1

Output: []
Example 3:

Input: head = [1,2], n = 2

Output: [2]
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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

// Solution 1 : Two pass solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Solution 1 : Two traversals 

        int N = 0 ; // Total number of nodes ;

        ListNode* curr = head ;
        
        while( curr!= NULL){
            N++;
            curr = curr -> next;
        }

        if(N == 1) return NULL;

        // n from the back is (N-n)th from the front;
        int k = N - n ;

        // special case : If head is to be deleted 
        if(k == 0 ) {
            head=head->next;
            return head ;
        }

        int cnt = 0 ;
        curr = head ;

        while(cnt!= k-1){
            cnt++;
            curr = curr->next;
        }

        // curr is at k-1 element ;

        curr->next = curr->next->next ;

        //TC:O(2n) and SC:(1)
        return head ;
    }
};



// Solution 2 : Single pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // For a single pass we will use a very subtle idea 

        // We need nth node from the end 
        // Say fast starts n nodes ahead of slow 
        // Then they MOVE AT THE SAME SPEED 
        // Then when fast finishes its trversal , SLOW WILL BE AT NTH NODE FROM THE END 
        // But here for deletion we need the node before nth so we stop when fast reaches last node 

        // Edge case 1 : if list only has element 
        if( head->next == NULL) return NULL;

        ListNode* slow = head ;
        ListNode* fast = head ;


        int cnt = 0 ;

        while(cnt!= n){
            cnt++;
            fast = fast -> next ;
        }
        
        // Edge case 2 : when we need to delete head 
        // That happens when n is equal to the length of the linked list 
        if(fast== NULL) {
            head = head->next ;
            return head ;
        }

        // Now we move both at same speed 
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow is one behind the needed node 
        slow ->next = slow -> next ->next ;

        //TC:O(n) single pass as fast moves from start to the end of the list in the code 
        //SC:O(1)
        return head ;

    }
};
