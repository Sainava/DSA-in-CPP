/*
You are given two integer arrays preorder and inorder.

preorder is the preorder traversal of a binary tree
inorder is the inorder traversal of the same tree
Both arrays are of the same size and consist of unique values.
Rebuild the binary tree from the preorder and inorder traversals and return its root.

Example 1:



Input: preorder = [1,2,3,4], inorder = [2,1,3,4]

Output: [1,2,3,null,null,null,4]
Example 2:

Input: preorder = [1], inorder = [1]

Output: [1]
Constraints:

1 <= inorder.length <= 1000.
inorder.length == preorder.length
-1000 <= preorder[i], inorder[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <unordered_map>
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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder ,int inorderStartIndex ,  int inorderEndIndex , int n ,int &preorderIndex , unordered_map<int,int> &mp ){
        if(preorderIndex > n || inorderStartIndex > inorderEndIndex){
            return NULL ;
        }

        TreeNode* node = new TreeNode(preorder[preorderIndex]);

        // Find this index in inorder to separate left and right subtree 
        int position =mp[preorder[preorderIndex]];
        preorderIndex++;

        // Now call for left subtree 
        node->left = solve( preorder,inorder , inorderStartIndex , position - 1 , n , preorderIndex , mp);
        node->right = solve( preorder,inorder , position + 1 , inorderEndIndex , n , preorderIndex , mp );

        return node ; 
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // The first element of preorder is the root 
        // Find that root element in inorder .
        // Then all elements to the left of root in inorder is the left subtree and 
        //all elements to the right of root in inorder is the right subtree 
        //Recursion will solve the remaining cases 

        int inorderStartIndex = 0 ;
        int inorderEndIndex = inorder.size() - 1 ; // To find the size of the tree we need to consider 
        int n = preorder.size() - 1 ;

        int preorderIndex = 0 ; 

        unordered_map<int,int> mp ; 
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i ;
        }

        TreeNode * node = solve(preorder,  inorder ,inorderStartIndex ,inorderEndIndex , n , preorderIndex , mp);

        //TC:O(n) and SC:O(n)
        return node ;

        
    }
};
