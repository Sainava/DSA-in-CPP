/*
Implement a time-based key-value data structure that supports:

Storing multiple values for the same key at specified time stamps
Retrieving the key's value at a specified timestamp
Implement the TimeMap class:

TimeMap() Initializes the object.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns the most recent value of key if set was previously called on it and the most recent timestamp for that key prev_timestamp is less than or equal to the given timestamp (prev_timestamp <= timestamp). If there are no values, it returns "".
Note: For all calls to set, the timestamps are in strictly increasing order.

Example 1:

Input:
["TimeMap", "set", ["alice", "happy", 1], "get", ["alice", 1], "get", ["alice", 2], "set", ["alice", "sad", 3], "get", ["alice", 3]]

Output:
[null, null, "happy", "happy", null, "sad"]

Explanation:
TimeMap timeMap = new TimeMap();
timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
timeMap.get("alice", 1);           // return "happy"
timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
timeMap.get("alice", 3);           // return "sad"
Constraints:

1 <= key.length, value.length <= 100
key and value only include lowercase English letters and digits.
1 <= timestamp <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<
        string,
        vector< pair < int, string>>
    > mp;


    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value}); // Push to vector so O(1)
        return ;
    }
    
    string get(string key, int timestamp) {
        // Timestamps are always given in increasing order so we can use Binary search here 

            if(mp.find(key)==mp.end()) return "";

            // Basically we need last occurance of timestamp 
            int start = 0 ;
            int end = mp[key].size() - 1 ;

            string ans = "";
            while( start <= end ){
                int mid = start + (end - start) / 2;

                if( mp[key][mid].first <= timestamp ){
                    ans = mp[key][mid].second;
                    start = mid + 1;
                }else {
                    end = mid - 1 ;
                }
                    
            }

            //TC:O(logn)
            return ans ;

    }
};
