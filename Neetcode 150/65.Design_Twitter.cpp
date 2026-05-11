/*
Implement a simplified version of Twitter which allows users to post tweets, follow/unfollow each other, and view the 10 most recent tweets within their own news feed.

Users and tweets are uniquely identified by their IDs (integers).

Implement the following methods:

Twitter() Initializes the twitter object.
void postTweet(int userId, int tweetId) Publish a new tweet with ID tweetId by the user userId. You may assume that each tweetId is unique.
List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent tweet IDs in the user's news feed. Each item must be posted by users who the user is following or by the user themself. Tweets IDs should be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId follows the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId unfollows the user with ID followeeId.
Example 1:

Input:
["Twitter", "postTweet", [1, 10], "postTweet", [2, 20], "getNewsFeed", [1], "getNewsFeed", [2], "follow", [1, 2], "getNewsFeed", [1], "getNewsFeed", [2], "unfollow", [1, 2], "getNewsFeed", [1]]

Output:
[null, null, null, [10], [20], null, [20, 10], [20], null, [10]]

Explanation:
Twitter twitter = new Twitter();
twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
twitter.getNewsFeed(2);   // User 2's news feed should only contain their own tweets -> [20].
twitter.follow(1, 2);     // User 1 follows user 2.
twitter.getNewsFeed(1);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
twitter.getNewsFeed(2);   // User 2's news feed should still only contain their own tweets -> [20].
twitter.unfollow(1, 2);   // User 1 unfollows user 2.
twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
Constraints:

1 <= userId, followerId, followeeId <= 100
0 <= tweetId <= 1000
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
public:
    // We need a global timer to get the feed of most recent tweets 
    int time ;
    // For following , we need effective 
    // insertion 
    // deletion - to implement unfollow 
    // search - to implement the news feed 
    // SO we use unordered_set because it has insertion , deletion and search of O(1)
    //SC:O(total follows )
    unordered_map<int, unordered_set<int>> following ;// user-> following (followingId)

    // Next we need to keep track of all tweets a user has posted 
    // Since for a single user we can just store it contigously , since the second post will be after the first and so on 
    // We can use a simple vector of tweets 
    // But for the newsfeed logic we need to merge based on time so time plays a role 
    //SC:O(total tweets )
    unordered_map<int,vector<pair<int,int>>> tweets ; // {timestamp , tweetid}
    Twitter() {
        time = 0 ; 
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        // TC:O(1)  and SC:O(1)
        tweets[userId].push_back({time , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Similar logic to merge k sorted list 
        // Make a max heap based on time 
        priority_queue<vector<int>> pq;//(timestamp, tweetId, userId, indexInUserTweetList)

        // Get all the users id and push their latest tweet into the pq
        // Add latest user tweet

        // Say current user follows u people , so heap size u+1 , following + itself
        // So initial pushes take :TC:O(ulogu)
        if(tweets[userId].size()!=0){
            pq.push({
                tweets[userId].back().first,
                tweets[userId].back().second, 
                userId, 
                (int)tweets[userId].size() - 1
            });
        }
        

        for(auto followingId:following[userId]){
            if(followingId == userId) continue ; // skips double addition of self 
            if(tweets[followingId].size()!=0){
                pq.push({
                    tweets[followingId].back().first,
                    tweets[followingId].back().second, 
                    followingId, 
                    (int)tweets[followingId].size() - 1
                });
            }
            
        }

        // Now same logic as merge k sorted list 
        int cnt = 0 ;
        vector<int> ans ; 

        // TC:O(10logu)
        while(!pq.empty() && cnt <10){
            ans.push_back(pq.top()[1]);
            
            int index = pq.top()[3];
            int userId = pq.top()[2];
            // insert its previous if it exist 
            if( index > 0 ){
                pq.push({
                    tweets[userId][index -1 ].first,
                    tweets[userId][index -1 ].second, 
                    userId, 
                    index  - 1  
                 });
            }
            

            pq.pop();
            cnt++;
        }

        //TC:O(ulogu) + SC:O(u)
        return ans ;

    }
    
    void follow(int followerId, int followeeId) {
        //TC:O(1) and SC:O(1)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        //TC:O(1) and SC:O(1)
        following[followerId].erase(followeeId);
    }
};
