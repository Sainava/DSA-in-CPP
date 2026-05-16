/*
Given a 2-D grid of characters board and a list of strings words, return all words that are present in the grid.

For a word to be present it must be possible to form the word with a path in the board with horizontally or vertically neighboring cells. The same cell may not be used more than once in a word.

Example 1:



Input:
board = [
  ["a","b","c","d"],
  ["s","a","a","t"],
  ["a","c","k","e"],
  ["a","c","d","n"]
],
words = ["bat","cat","back","backend","stack"]

Output: ["cat","back","backend"]
Example 2:



Input:
board = [
  ["x","o"],
  ["x","o"]
],
words = ["xoxo"]

Output: []
Constraints:

1 <= board.length, board[i].length <= 12
board[i] consists only of lowercase English letter.
1 <= words.length <= 30,000
1 <= words[i].length <= 10
words[i] consists only of lowercase English letters.
All strings within words are distinct.
*/
#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
    public :
        char ch ;
        vector<TrieNode*> children;
        bool isTerminal ; // this helps in checking 

        TrieNode(char ch ){
            this -> ch = ch ;
            isTerminal = false ;

            for(int i = 0 ; i < 26 ; i++){
                this->children.push_back(NULL) ;
            }
        }
};

class PrefixTree {
public:
    TrieNode* root ;

    PrefixTree() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root ,string word , int index){
        // base case -> word fully traversed 
        if(index == word.length()){
            // Entire word has been inserted 
            root->isTerminal = true ;
            return ; 
        }
        int ind = word[index] - 'a' ; // which node to check 
        TrieNode* child ; 
        // Check if this letter already exists
        if( root->children[ind]!=NULL){
            child = root->children[ind] ;
        }else{
            // Create this node 
            child = new TrieNode(word[index]);
            root->children[ind] = child ;
        }

        // call for the next letter in the word 
        insertUtil( child ,word , index + 1);
    }
    
    void insert(string word) {
        insertUtil(root,word , 0);
    }

};

void dfs( int row , int col , TrieNode* node ,vector<vector<char>>& board ,vector<string> &ans ,int m , int n,string &temp , vector<vector<bool>> &visited){
    // base case
    if( row >=m || row < 0 || col >= n || col < 0){
        return ; 
    }
    if(visited[row][col]) return ;

    char curr = board[row][col];
    TrieNode* child = node->children[curr - 'a'];


    // check if any word starts with the current node
    if(child!=NULL){
        // move forward 
        visited[row][col] = true ; 
        temp.push_back(curr);

        if( child->isTerminal){
            // add to answer but continue so that further words can be added to 
            ans.push_back(temp);
            // remove isTerminal so that no duplicate answers
            child->isTerminal = false ;
        }

        // right 
        dfs(row,col+1,child,board,ans , m , n , temp, visited);

        // down 
        dfs(row+1,col,child,board,ans , m , n , temp , visited);

        // left 
        dfs(row,col-1,child,board,ans , m , n , temp , visited);

        //up 
        dfs(row-1,col,child,board,ans , m , n , temp , visited);

        //backtrack
        temp.pop_back();
        visited[row][col] = false;

    }else{
        return ;
    }

    

}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // insert all words to trie 

        PrefixTree* trie = new PrefixTree();

        // insert all words to trie , trie will help in searching
        for(string word : words){
            trie->insert(word);
        }

        vector<string> ans ;
        // Now for searching do dfs , ask if any words start 
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n,false));
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                
                string temp = "";
                dfs(row,col,trie->root,board,ans , m , n , temp , visited);
                
            }
        }

        // Let W be total characters across all of Trie
        // Therefore TC:O(W) for building the Trie 
        // TC:O( rows * cols* 4^L) for all characters , you have 4 options to build the remianing word and lets ay average word length is L 

        // SC:O(m*n) for visited
        // SC:O(W) for the Trie
        //SC:O(L) for the recursive stack of dfs as it cannot exceed word size 
        return ans ;
        
    }
};
