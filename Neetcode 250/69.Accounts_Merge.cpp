/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input: accounts = [
    ["neet","neet@gmail.com","neet_dsa@gmail.com"],
    ["alice","alice@gmail.com"],
    ["neet","bob@gmail.com","neet@gmail.com"],
    ["neet","neetcode@gmail.com"]
]

Output: [["neet","bob@gmail.com","neet@gmail.com","neet_dsa@gmail.com"],["alice","alice@gmail.com"],["neet","neetcode@gmail.com"]]
Example 2:

Input: accounts = [
    ["James","james@mail.com"],
    ["James","james@mail.co"]
]

Output: [["James","james@mail.com"],["James","james@mail.co"]]
Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void makeSet( vector<int> & parent , int n ){
        for(int i = 0 ; i <  n ; i++){
            parent[i] = i ; 
        }
    }

    int findParent(int u ,vector<int> & parent){
        if( parent[u] == u ) return u ; 

        return parent[u] = findParent(parent[u] , parent);
    }

    void unionSet(int u , int v ,vector<int> & parent ,vector<int> &rank ){

        u =  findParent(u , parent);
        v = findParent(v , parent);

        if(rank[u] < rank[v]){
            parent[u] = v ;
        }
        else if ( rank[v] < rank[u]){
            parent[v] = u ;
        }
        else {
            parent[u] = v;
            rank[v]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // IMPORTANT -> USES DISJOINT SET
    //SEE STRIVER'S VIDEO

    int n = accounts.size() ; 

    vector<int> parent(n , 0 ) ; 
    vector<int> rank(n , 0) ; 

    makeSet(parent , n);

    unordered_map<string,int> mapMailNode ; 

    for(int i = 0 ; i < n ; i++){

        // Now we traverse the mailids as first is name and then mailids 

        for(int j = 1 ; j < accounts[i].size() ; j++){

            string mail = accounts[i][j] ; 

            if(mapMailNode.find(mail) == mapMailNode.end()){
                // Does not exist anywhere else yet 
                mapMailNode[mail] = i ; 
            }

            else{

                // It is alredy seen that means we need to merge ( UNION SET)
                // so i needs to merge with mapMailNode[mail]

                unionSet(mapMailNode[mail] , i , parent , rank);
            }
        }
    }

    // We have made the disjoint set
    // No we need to make a list of strings

    vector<vector<string>> mergeMail( n );

    for(auto it: mapMailNode){
        // We have mailId -> accountOwner (here numbered from 0 to n-1 )
        // We want accountowner -> All of his/her mailID
        int par = findParent(it.second , parent);

        mergeMail[par].push_back(it.first);
    }


    // Finally we have 0-> it mailIDs , 1->its ,mailIds . We neeed to add the names too 
    // Same may be empty as they would have been merged
    vector<vector<string>> ans ; 

    for(int i = 0 ; i < n ; i++){

        if( mergeMail[i].size()==0) continue ; // It got merged basically 

        sort(mergeMail[i].begin() , mergeMail[i].end());

        vector<string> temp ;

        // Push name first
        temp.push_back(accounts[i][0]);

        for(auto it : mergeMail[i]){
            temp.push_back(it);
        }

        ans.push_back(temp);
    }

    return ans ; 

    // Time Complexity:
    // O(M log M)
    //
    // M = total number of email addresses.
    //
    // DSU operations are O(M * α(N))
    // Sorting merged email lists dominates:
    // O(M log M).

    // Space Complexity:
    // O(M + N)
    //
    // parent, rank -> O(N)
    // email->account map -> O(M)
    // merged emails -> O(M)

    }
};