/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/

#include <iostream>
#include <queue>
#include <climits>
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
    int maxLevelSum(TreeNode* root) {
        // For only one node
        if(root->left == NULL && root->right==NULL){
            return 1;
        }

        // Do bfs 
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int minLevel=1;
        int level=1;
        int sum=root->val;
        int maxSum=INT_MIN;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){
                if(sum > maxSum){
                    maxSum=sum;
                    minLevel=level;
                }
                sum=0;
                level++;
                if(!q.empty())  q.push(NULL);
               
            }else{

                sum+= node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }

                if(node->right!=NULL){
                    q.push(node->right);
                }
            }

        }

        //TC:O(n)
        //SC:O(n)
        return minLevel;
    }
};