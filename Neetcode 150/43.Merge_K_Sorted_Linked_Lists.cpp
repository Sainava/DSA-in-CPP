/*
You are given an array of k linked lists lists, where each list is sorted in ascending order.

Return the sorted linked list that is the result of merging all of the individual linked lists.

Example 1:

Input: lists = [[1,2,4],[1,3,5],[3,6]]

Output: [1,1,2,3,3,4,5,6]
Example 2:

Input: lists = []

Output: []
Example 3:

Input: lists = [[]]

Output: []
Constraints:

0 <= lists.length <= 1000
0 <= lists[i].length <= 100
-1000 <= lists[i][j] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 1 : Using merge 2 sorted linked list repeatedly
class Solution {
public:
    ListNode* merge2lists(ListNode* l1 , ListNode* l2){
        if(l1 == NULL) return l2 ;
        if(l2 == NULL) return l1;

        ListNode* head = NULL;

        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }

        ListNode* tail = head;

        while(l1!=NULL && l2!=NULL){
            if( l1-> val < l2->val){
                tail->next = l1;
                tail = l1 ;
                l1 = l1->next;
            }else{
                tail->next = l2;
                tail = l2 ;
                l2 = l2->next;
            }
        }

        while(l1!=NULL){
            tail->next = l1;
            tail = l1 ;
            l1 = l1->next;
        }

        while(l2!=NULL){
            tail->next = l2;
            tail = l2 ;
            l2 = l2->next;
        }

        return head ;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;

        ListNode* head = lists[0] ;

        for(int i = 1 ; i < k; i++){
            head = merge2lists(head ,lists[i]);
        }

        // Say k no of linked list 
        // Size of each linked list goes like N1 , N2 and so on
        // So to combine  first two we have (N1 + N2)
        // Then to combine this with third we have (N1 + N2) + N3
        // so finally we have (N1 + N2) + ( (N1 + N2) + N3 ) + ((N1 + N2 + N3) + N4) and so on 
        // Say size of each is N
        // So we have 2N + 3N +4N +.... + kN
        // we can write N + 2N + 3N +4N +.... + kN ( approx)
        // N(1 + 2 + 3 + .... + k)
        // N(k(k+1)/2)
        // TC:O(N*K^2) and SC:O(1)
        return head ;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // Solution 2 : Using min heap
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Optimised 
        int k = lists.size() ; 
        if(k==0) return 0 ; 

        // min heap on value of the nodes 
        priority_queue<
            pair<int,ListNode*> ,
            vector<pair<int,ListNode*>>,
            greater<pair<int,ListNode*>>
        >pq;
        
        // lists stores the head of each 
        // TC:O(klogk) as size of k 
        // AS push in pq is logk , where k is the size of the pq
        for(int i = 0 ; i < k ; i++ ){
            pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy ;

        // TC:O(N*k)*log(k) , 
        // As total nodes as k linked list each with N nodes so total times it runs is approx (N*K)
        // and each push operation takes time log(k)
        while(!pq.empty()){
            pair<int,ListNode*> p = pq.top();
            pq.pop();

            ListNode* node = p.second;
            
            temp->next = node;
            temp = node;

            // Now add next (if it exists to pq)
            if( node->next!=NULL){
                pq.push({node->next->val , node->next});
            }

        }

        //TC:((N*k)log(k)) and SC:O(k)
        return dummy->next ;
    }
};

