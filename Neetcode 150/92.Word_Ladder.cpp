/*
You are given two words, beginWord and endWord, and also a list of words wordList. All of the given words are of the same length, consisting of lowercase English letters, and are all distinct.

Your goal is to transform beginWord into endWord by following the rules:

You may transform beginWord to any word within wordList, provided that at exactly one position the words have a different character, and the rest of the positions have the same characters.
You may repeat the previous step with the new word that you obtain, and you may do this as many times as needed.
Return the minimum number of words within the transformation sequence needed to obtain the endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "cat", endWord = "sag", wordList = ["bat","bag","sag","dag","dot"]

Output: 4
Explanation: The transformation sequence is "cat" -> "bat" -> "bag" -> "sag".

Example 2:

Input: beginWord = "cat", endWord = "sag", wordList = ["bat","bag","sat","dag","dot"]

Output: 0
Explanation: There is no possible transformation sequence from "cat" to "sag" since the word "sag" is not in the wordList.

Constraints:

1 <= beginWord.length <= 10
1 <= wordList.length <= 100
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // This is a level wise traversal so we will do BFS ( watch Striver's video)
        // Each word is a node
        // Edge exists if: two words differ by one character
        // Then problem becomes:Shortest path in unweighted graph
        // which naturally leads to:BFS

        //SC:O(n) n being the number of words in wordlist 
        unordered_set<string> st;
        // or unordered_set<string> st(wordList.begin() , wordList.end())

        // TC:O(n) as insertion in unordered set takes O(1)
        for(string word : wordList){
            st.insert(word);
        }

        if(st.count(endWord)==false) return 0 ;

        //SC:O(1) as we remove words from set so we can only add words once 
        queue<pair<string,int>> q ;  // word and sequence length

        q.push({beginWord,1});

        // TC:O(n*wordlength*26) all words can be added and processed once as we remove from set 
        // And we take set operations as O(1) 
        while(!q.empty()){

            auto top = q.front();
            q.pop();

            string word = top.first ; 
            int seq = top.second ; 

            if(word == endWord) return seq ;

            // Now for each character , try replacing them and see if the resultant word is in set 
            // We use set because we want fast membership check and we do not want repeated insertion 

            for( int i = 0 ; i < word.length() ; i++){
                char ch = word[i];

                for(int j = 0 ; j < 26 ; j++){
                    word[i] = 'a'+ j ;

                    if(st.count(word)){
                        // it exists so push to queue and remove from set so we do not insert multiple times 

                        q.push({word , seq+1});
                        st.erase(word);
                    }

                    word[i]= ch ;
                }
            }
        }

        // end word never reached 
        //TC:O(n*wordlength*26) and SC:O(n)
        return 0 ;
    }
};
