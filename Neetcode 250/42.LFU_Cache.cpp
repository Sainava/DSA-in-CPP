/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input: ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]

Output: [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
Explanation:
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1); // cache=[1,_], cnt(1)=1
lfu.put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1); // return 1
// cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3); // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
// cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2); // return -1 (not found)
lfu.get(3); // return 3
// cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4); // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
// cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1); // return -1 (not found)
lfu.get(3); // return 3
// cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4); // return 4
// cache=[4,3], cnt(4)=2, cnt(3)=3

Constraints:

1 <= capacity <= 10,000.
0 <= key <= 100,000
0 <= value <= 1,000,000,000
At most 200,000 calls will be made to get and put.

*/

// Quite tricky so go step by step 
// Similar to maximum frequency stack 
//TC:O(1) average for all 
//SC:O(capacity) or SC:O(capacity + number_of_frequency_buckets)
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public : 
        int key ; 
        int value ; 
        int freq ; 
        Node* next ;
        Node* prev ;

        Node(){
            next = NULL;
            prev = NULL ;
        }

        Node(int k , int v){
            key = k ;
            value = v ;
            freq = 1 ;
            next = NULL;
            prev = NULL ;
        }
};

class DoublyList{
    public :
        Node* head = new Node(); 
        Node* tail = new Node();
        int size = 0 ; 

        DoublyList(){
            head -> next = tail ; 
            tail -> prev = head ; 
        }

        void insertAtHead(Node* node){
            node -> next = head -> next ;
            node -> prev = head ; 

            head->next->prev = node ; 
            head -> next = node ; 

            size++;
        }

        void removeNode(Node* node){
            node -> next -> prev = node -> prev ; 
            node -> prev -> next =  node -> next ; 

            size--; 
        }
};

class LFUCache {
public:
    unordered_map<int , Node*> mp ; // This makes search easier 
    unordered_map< int , DoublyList* > groups ; // frequency -> no of nodes accessed at that time 
    int capacity ; 
    int minFreq ; 

    LFUCache(int capacity) {
        this->capacity = capacity ;
        mp.clear();
        groups.clear() ;
        minFreq = 1 ;
    }

    void updateFreq(Node * node){
        int cnt = node-> freq ; 

        // Remove from its current group and add to group + 1 ; 
        groups[cnt]->removeNode(node);

        if(groups.find(cnt + 1) == groups.end()){
            groups[cnt + 1] = new DoublyList();
        }

        groups[cnt + 1]->insertAtHead(node);

        node->freq = cnt + 1 ; 

        if(cnt == minFreq && groups[minFreq]->size == 0) minFreq++;
    }
    
    int get(int key) {
        // Two cases it exists or it does not 
        if(mp.find(key) != mp.end()){
            // Increase its frequency 
            Node* node = mp[key];

            updateFreq(node);

            return node->value ; 
        }

        return -1 ; 
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;

        // Two cases -> Maybe it already exists 
         if(mp.find(key) != mp.end()){
            // Increase its frequency and update the value ;

            Node* node = mp[key];

            updateFreq(node);

            node->value = value ; 

        }
        else {
            // Need to check if it is above capacity 
            if(mp.size() >= capacity){
                // Need to delete the last element from minFrequency 
                Node* node = groups[minFreq]->tail-> prev ;

                groups[minFreq]->removeNode(node);

                mp.erase(node->key);
                delete node;

            }

            Node * node = new Node(key , value);


           if(groups.find(1) == groups.end()){
                groups[1] = new DoublyList();
            }

            groups[1]->insertAtHead(node);


            mp[key] = node;
            minFreq = 1 ; 

        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */