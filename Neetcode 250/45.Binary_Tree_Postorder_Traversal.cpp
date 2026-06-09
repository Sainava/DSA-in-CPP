/*
You are given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:



Input: root = [1,2,3,4,5,6,7]

Output: [4,5,2,6,7,3,1]
Example 2:



Input: root = [1,2,3,null,4,5,null]

Output: [4,2,5,3,1]
Example 3:

Input: root = []

Output: []
Constraints:

0 <= number of nodes in the tree <= 100
-100 <= Node.val <= 175
Follow up: Recursive solution is trivial, could you do it iteratively?


*/
#include <iostream>
#include <vector>
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

    TreeNode* findPred(TreeNode* curr){
        // Find the righmost node in the left subtree
        TreeNode* pred  = curr->left ; 

        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }

        return pred ; 
    }

    void reversePath(TreeNode* start, TreeNode* end){
        if(start == end) return ;

        // Like reverse a linked list 
        TreeNode* prev = NULL ; 
        TreeNode * curr = start ; 
        TreeNode * nxt = start ;

        while(prev!= end){
            nxt = curr -> right ; 
            curr -> right = prev ; 
            prev = curr ;
            curr = nxt ; 
        }
    }

    void addPath(TreeNode* start, TreeNode* end, vector<int>& ans){
        reversePath(start , end) ; 

        TreeNode* curr = end ; 

        while( true ){
            ans.push_back(curr -> val );

            if( curr == start)
                break ;
            
            curr = curr -> right ;
        }

        reversePath(end ,start) ;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ; 

        TreeNode dummy(0) ; 
        dummy.left = root ; 

        TreeNode* curr = &dummy ; 

        while(curr != NULL){

            if( curr->left == NULL){
                curr = curr -> right ; 
            }
            else {
                // Find predecessor
                TreeNode * pred = findPred(curr);

                if(pred->right == NULL){
                    pred->right = curr ; 
                    curr = curr -> left ; 
                }
                else{
                    addPath(curr->left ,pred , ans);

                    pred->right = NULL ;
                    curr = curr -> right ; 
                }
            }
        }

        // Why it's O(n)

        // Each tree edge is involved in only a constant number of operations:

        // Traversed while finding predecessors.
        // Used once when creating a thread.
        // Used once when removing a thread.
        // Reversed and restored at most once.

        // An edge cannot keep getting reversed repeatedly.

        // Therefore the total work across the entire traversal is proportional to the number of nodes/edges.

        // Total = O(n)

        // SC:O(1)

        return ans ; 

    }
};