/*
Implement the Least Recently Used (LRU) cache class LRUCache. The class should support the following operations

LRUCache(int capacity) Initialize the LRU cache of size capacity.
int get(int key) Return the value corresponding to the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the introduction of the new pair causes the cache to exceed its capacity, remove the least recently used key.
A key is considered used if a get or a put operation is called on it.

Ensure that get and put each run in 
O
(
1
)
O(1) average time complexity.

Example 1:

Input:
["LRUCache", [2], "put", [1, 10],  "get", [1], "put", [2, 20], "put", [3, 30], "get", [2], "get", [1]]

Output:
[null, null, 10, null, null, 20, -1]

Explanation:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 10);  // cache: {1=10}
lRUCache.get(1);      // return 10
lRUCache.put(2, 20);  // cache: {1=10, 2=20}
lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
lRUCache.get(2);      // returns 20 
lRUCache.get(1);      // return -1 (not found)
Constraints:

1 <= capacity <= 100
0 <= key <= 1000
0 <= value <= 1000
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int key , value;
        Node * next ;
        Node * prev ;

    Node(int k , int v){
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }

    Node(){
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    // SC:O(2capacity) for linked list and map 
    unordered_map<int,Node*> mp;
    int capacity ;
    Node * head = new Node();
    Node * tail = new Node();

    LRUCache(int capacity) {
        this->capacity = capacity ;
        mp.clear();
        
        // All nodes will be in between head and tail
        // head and tail are dummy nodes
        head->next = tail;
        tail->prev = head;
    }

    //TC:O(1)
    void insertAfterHead(Node* node){
        // make connections with this node 
        node->next = head->next;
        node->prev = head;


        head->next = node;
        node->next->prev = node;

        return ;
    }
    
    //TC:O(1)
    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;

        return ;
    }
    
    //TC:O(1)
    int get(int key) {
        // If it exists 
        if(mp.find(key)!=mp.end()){
            // Make it most recently used 

            Node* node = mp[key];

            removeNode(node);
            insertAfterHead(node);

            return node->value;

        }

        return -1;
    }
    
    //TC:O(1)
    void put(int key, int value) {
        // Two conditions :

        // IF it exists , update and make it most recenty used 
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];

            // Update key 
            node->value = value ;

            // Make mru
            removeNode(node);
            insertAfterHead(node);
        }
        else{
            //Need to insert
            if(mp.size() == capacity){
                // remove the lru , the node before the tail 
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            // insert at head 
            Node* node = new Node(key,value);

            mp[key] = node;

            insertAfterHead(node);
        }

        return ;


    }

    ~LRUCache(){
        Node * curr = head;
        while(curr!=NULL){
            Node* temp = curr;
            curr = curr->next;
            delete temp ;
        }
    }
};
