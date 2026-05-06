/*
You are given the head of a linked list of length n. Unlike a singly linked list, each node contains an additional pointer random, which may point to any node in the list, or null.

Create a deep copy of the list.

The deep copy should consist of exactly n new nodes, each including:

The original value val of the copied node
A next pointer to the new node corresponding to the next pointer of the original node
A random pointer to the new node corresponding to the random pointer of the original node
Note: None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

In the examples, the linked list is represented as a list of n nodes. Each node is represented as a pair of [val, random_index] where random_index is the index of the node (0-indexed) that the random pointer points to, or null if it does not point to any node.

Example 1:



Input: head = [[3,null],[7,3],[4,0],[5,1]]

Output: [[3,null],[7,3],[4,0],[5,1]]
Example 2:



Input: head = [[1,null],[2,2],[3,2]]

Output: [[1,null],[2,2],[3,2]]
Constraints:

0 <= n <= 100
-100 <= Node.val <= 100
random is null or is pointing to some node in the linked list.
*/


#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Solution 1 : Using Hash Map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Solution one using hash map 
         
        unordered_map<Node* , Node* > mp ;

        Node* temp = head ;

        
        while( temp != NULL){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode ;   
            temp = temp ->next;         
        }

        // Now since we have all the nodes we can connect the next and also the random pointers also 
        temp = head ;

        while(temp != NULL){
            Node* node = mp[temp];
            node->next = mp[temp->next];
            node->random = mp[temp->random];
            temp = temp ->next;
        }

        //TC:(2n) and SC:O(n)
        return mp[head];


    }
};

//Solution 2 : Optimised solution without using extra space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Three steps again to optimise space 

        // Step 1 . insert the new nodes in between the current nodes 
        Node* temp = head ;

        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next ;
            temp->next = newNode ;
            temp = temp->next->next ;
        }

        // Step 2 . Add the random pointers for the new Nodes 
        temp = head ;

        while(temp != NULL ){
            if(temp->random != NULL){
                temp->next->random = temp->random->next ;
            }
            
            temp = temp->next->next ;
        }

        // Step 3 .Separate the previous and the new linked list 
        Node* dummy = new Node(-1);
        Node* res = dummy ;
        temp = head ;

        while(temp != NULL){
            // Fix the new linked list 
            res->next = temp->next ;
            res = res->next ;
            
            // Fix the old linked list 
            temp->next = temp->next->next ;
            temp = temp->next ;
        }

        //TC:O(3n) and SC:O(1)
        return dummy->next ;
    }
};

