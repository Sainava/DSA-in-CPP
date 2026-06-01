/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
Example 1:

Input: ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]

Output: [null, null, null, 1, -1, null, 1, null, -1]
Explanation:
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1); // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3); // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2); // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2); // return -1 (i.e., not found), The map is now [[1,1]]

Constraints:

0 <= key, value <= 1,000,000
At most 10,000 calls will be made to put, get, and remove.
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

//SOlution 1 
class MyHashMap {
public:
    // Method 1 -> See possible values of key given (1,000,000) so if we take an array we can have key as the indices 
    vector<int> mp ; // ALL methods TC:O(1)

    MyHashMap() {
        mp.resize(1000001,-1);// -1 Means no value yet 
    }
    
    void put(int key, int value) {
        mp[key] = value ; 
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1 ; 
    }
};


class MyHashMap {
public:
    //Method 2 - > We try to implement a simple version of how it actaully works
    // We create buckets , and each pair is assigned to a bucket
    // Multiple pairs may be assigned to the same bucket so we chain ( uses linked list ) but here we use list

    vector < list < pair<int,int> > > buckets ; // Index of vector is the bucket , each bucket contains a list of key, value pair 

    // So we run loops for the bucket , but no of  elements in one bucket is <<<< total no of key-value pairs or elements 
    // With a strong hash function , one bcuket one pair 
    // So we consider it constant 

    MyHashMap() {
        buckets.resize( 1000) ; // Even for really large key values , it can be assigned a bucket 
        // In reality , hash function is a complicated fucntion so almost every key pair is assigned a unique bucket 
        // Chaining also happens 
        // And ,map also dynamically increases in size if too many key value pairs
    }

    int hash(int key){
        int bucket = key % 1000 ; // Simple hash function
        return bucket;
    }
    
    void put(int key, int value) {
        int bucket = hash(key) ;

        for( auto &p : buckets[bucket]){
            // if key already exists , update it 
            if( p.first == key){
                p.second = value ; 
                return ;
            }
        }

        // If value does not exist add it 
        buckets[bucket].push_back({key , value});
    }
    
    int get(int key) {
        int bucket = hash(key) ;
        for( auto &p : buckets[bucket]){
            // if key exists , return value  
            if( p.first == key){
                return p.second ; 
            }
        }

        // Does not exist , return -1 ; 
        return -1 ; 
        
    }
    
    void remove(int key) {
        int bucket = hash(key) ;
        
        // We need to remove so we do things a bit differently 

        for( auto it = buckets[bucket].begin() ; it != buckets[bucket].end() ; it++){

            if ( it -> first == key){
                // We need the iterator to remove the value 
                buckets[bucket].erase(it);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */