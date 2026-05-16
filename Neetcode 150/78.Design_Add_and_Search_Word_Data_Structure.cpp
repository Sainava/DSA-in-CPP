/*
Design a data structure that supports adding new words and searching for existing words.

Implement the WordDictionary class:

void addWord(word) Adds word to the data structure.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
Example 1:

Input:
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["day"],["bay"],["may"],["say"],["day"],[".ay"],["b.."]]

Output:
[null, null, null, null, false, true, true, true]

Explanation:
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("day");
wordDictionary.addWord("bay");
wordDictionary.addWord("may");
wordDictionary.search("say"); // return false
wordDictionary.search("day"); // return true
wordDictionary.search(".ay"); // return true
wordDictionary.search("b.."); // return true
Constraints:

1 <= word.length <= 20
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 10,000 calls will be made to addWord and search.
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

class WordDictionary {
public:

    TrieNode* root ;

    WordDictionary() {
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
    
    void addWord(string word) {
        //TC:O(L) and SC:O(L)
        insertUtil( root ,word , 0);
    }

     bool searchUtil(TrieNode* root ,string word , int index){
        // base case 
        if(index == word.length()){
            return root->isTerminal ;
        }  

        // If wildcard , consider this matched and check for all children 
        //basically consider all children are permitted but so check for all children 
        if(word[index]== '.'){
            bool isMatched = false ; 
            for(int i = 0 ; i < 26 ; i++){

                if(root->children[i]!=NULL){
                    if(searchUtil(root->children[i] ,word , index + 1)){
                        isMatched = true ;
                        break;
                    }
                }
            }

            return isMatched ;// if any path returns true 
        }

        int ind = word[index] - 'a' ;
        // check if the child exists , if it does ,make next call or return fase ;

        if( root->children[ind]!=NULL){
            return searchUtil(root->children[ind] ,word , index + 1);
        }else{
            return false ; 
        }
    }
    
    bool search(string word) {
        // TC:O(L) for simple trie 
        // if every letter was '.' then 26 choices for each 
        // SO TC:O(26^L) 
        //SC:O(L)
        return searchUtil(root,word , 0);
    }
};
