/*
You are given a root node reference of a BST and a key, delete the node with the given key in the BST, if present. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: There can be multiple results after deleting the node, return any one of them.

Example 1:



Input: root = [5,3,9,1,4], key = 3

Output: [5,4,9,1]
Explanation: Another valid answer is:



Example 2:

Input: root = [5,3,6,null,4,null,10,null,null,7], key = 3

Output: [5,4,6,null,null,null,10,7]
Constraints:

0 <= The number of nodes in the tree <= 10,000.
-100,000 <= key, Node.val <= 100,000
All the values Node.val are unique.
*/
#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* findPred(TreeNode* node){
        // Rightmost node in the left subtree 

        TreeNode* pred = node->left ;

        while( pred -> right != NULL){
            pred = pred-> right ; 
        }

        return pred;
    }

    TreeNode* helper(TreeNode* node ){
        // Remember we need to delete node 
        if( node -> left == NULL ){
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if ( node -> right == NULL){
            TreeNode* temp = node->left;
            delete node;
            return temp; 
        }

        // Both left and right subtree are not null so we need to make new connections 

        // Find the pred of this node 

        TreeNode* pred = findPred(node);

        // pred is the greatest element in the left subtree but smaller then node
        // And node->right is greater than node 
        // So right of pred is now all nodes greater than pred
        pred->right = node-> right ;

        TreeNode * temp = node -> left ; 
        delete node ; 
        return temp; 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root== NULL){
            return NULL;
        }

        TreeNode* dummy = root ; 

        // If roor needs to be deleted 
        if(root-> val == key){
            return helper(root);
        }

        while (root!= NULL){

            if(root -> val > key){
                // Left subtree
                if( root-> left != NULL && root->left->val == key){
                    // Need to delete this val 
                    root->left = helper(root->left);
                    break;
                }
                root = root-> left ; 
            }
            else{
                // Right subtree
                if( root->right != NULL && root->right-> val == key ){
                    root->right = helper(root->right);
                    break;
                }
                root = root->right ; 
            }

        }

        // Return root of the tree ; 
        // TC:O(h) for search 
        // TC:O(h) to find pred 
        // TC:O(h) total so TC:O(logn) for Balanced BST and TC:O(n) for skewed BST
        //SC:O(1)

        return dummy ; 
    }
};