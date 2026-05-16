/*
A prefix tree (also known as a trie) is a tree data structure used to efficiently store and retrieve keys in a set of strings. Some applications of this data structure include auto-complete and spell checker systems.

Implement the PrefixTree class:

PrefixTree() Initializes the prefix tree object.
void insert(String word) Inserts the string word into the prefix tree.
boolean search(String word) Returns true if the string word is in the prefix tree (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
Example 1:

Input:
["Trie", "insert", "dog", "search", "dog", "search", "do", "startsWith", "do", "insert", "do", "search", "do"]

Output:
[null, null, true, false, true, null, true]

Explanation:
PrefixTree prefixTree = new PrefixTree();
prefixTree.insert("dog");
prefixTree.search("dog");    // return true
prefixTree.search("do");     // return false
prefixTree.startsWith("do"); // return true
prefixTree.insert("do");
prefixTree.search("do");     // return true
Constraints:

1 <= word.length, prefix.length <= 1000
word and prefix are made up of lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;


class TrieNode{
    // every node in trie
    // question says it uses lower case letter 
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
    
    // All functions are TC:O(l) and SC:O(l)
    // l ->length of the word 

    //Overall Trie storage:O(total inserted characters)
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

    bool searchUtil(TrieNode* root ,string word , int index){
        // base case 
        if(index == word.length()){
            return root->isTerminal ;
        }

        int ind = word[index] - 'a' ;
        // check if the child exists , id it does ,make next call or return fase ;

        if( root->children[ind]!=NULL){
            return searchUtil(root->children[ind] ,word , index + 1);
        }else{
            return false ; 
        }
    }
    
    bool search(string word) {
        return searchUtil(root,word , 0);
    }
    
    bool startsWithUtil(TrieNode* root ,string word , int index){
        // same code as searchUtil except return true even if not terminal node
        if(index == word.length()){
            return true ;
        }

        int ind = word[index] - 'a' ;
        // check if the child exists , id it does ,make next call or return fase ;

        if( root->children[ind]!=NULL){
            return startsWithUtil(root->children[ind] ,word, index + 1);
        }else{
            return false ; 
        }
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root , prefix , 0);
    }
};
