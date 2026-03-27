/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/
#include<iostream>
#include<unordered_map>
using namespace std ;

class Node{
    public:
        int key , data;
        Node* prev ;
        Node* next ;
    
    Node(int k , int val){
        key = k;
        data = val ;
        prev = NULL ;
        next = NULL ;
    }

    Node(){
        prev = NULL ;
        next = NULL ;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*>  mp ; // Key and pointer to where the key , value is stored 
    Node * head = new Node();
    Node * tail = new Node();
    int capacity ;

    LRUCache(int capacity) {
        this->capacity = capacity ;
        mp.clear() ;


        head->next = tail;
        tail->prev = head;     
    }

    void insertAfterHead( Node* nd){
         // Now push it next to head 
        nd->next = head->next ;
        head->next->prev = nd;

        head->next = nd;
        nd->prev = head;

        return ;
    }

    void removeNode(Node* nd){
        nd->prev->next = nd->next;
        nd->next->prev = nd->prev;

        return ;

    }
    
    int get(int key) {
        // See if the value exits 
        if(mp.find(key)!=mp.end()){

            Node* nd = mp[key];
            
            // Remove the current connections and make it the MOST recently used 
            removeNode(nd) ;

            insertAfterHead(nd) ;

            return nd->data;
        
        }else{
            return -1 ;

        }
    }
    
    void put(int key, int value) {
        // Two conditions : 

        // If it already exists - Update its value and make it MOST recently used 
        if(mp.find(key)!=mp.end()){
            Node * nd = mp[key];

            nd->data = value ;
            
            // Remove the current connections and make it the MOST recently used 
            removeNode(nd ) ;

            insertAfterHead(nd ) ;

        }else{
            // Need insertion 

            // If no space 
            if(mp.size() == capacity){
                Node* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru; // IMPORTANT
            }

            Node* nd = new Node(key, value);
            insertAfterHead(nd);
            mp[key] = nd ;

            }
            return ;
        }
    ~LRUCache() {
        Node* curr = head;
        while(curr){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
        
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */