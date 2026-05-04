/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted linked list and return the head of the new sorted linked list.

The new list should be made up of nodes from list1 and list2.

Example 1:



Input: list1 = [1,2,4], list2 = [1,3,5]

Output: [1,1,2,3,4,5]
Example 2:

Input: list1 = [], list2 = [1,2]

Output: [1,2]
Example 3:

Input: list1 = [], list2 = []

Output: []
Constraints:

0 <= The length of the each list <= 100.
-100 <= Node.val <= 100
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        if (list1==NULL) return list2;
        if (list2==NULL) return list1; 

        if(list1->val < list2->val){
            head = list1;
            list1 = list1 -> next;
        }else{
            head = list2;
            list2 = list2 -> next;
        }

        tail = head ;

        while( list1 != NULL && list2!= NULL ){
            if(list1->val <list2->val){
                tail->next =list1;
                tail =list1;
                list1 =list1->next;
            }else{
                tail->next =list2;
                tail =list2;
                list2 =list2->next;
            }
        }

        while(list1!=NULL){
            tail->next =list1;
            tail =list1;
            list1 =list1->next;
        }

        while(list2!=NULL){
            tail->next =list2;
            tail =list2;
            list2 =list2->next;
        }

        //TC :(m + n) and SC:O(1)
        return head;

        
    }
};
