/*
Given a binary tree root, return the level order traversal of it as a nested list, where each sublist contains the values of nodes at a particular level in the tree, from left to right.

Example 1:



Input: root = [1,2,3,4,5,6,7]

Output: [[1],[2,3],[4,5,6,7]]
Example 2:

Input: root = [1]

Output: [[1]]
Example 3:

Input: root = []

Output: []
Constraints:

0 <= The number of nodes in the tree <= 1000.
-1000 <= Node.val <= 1000
*/
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if( root==NULL) return {};
        queue<TreeNode* > q;
        q.push(root);

        vector<vector<int>> ans;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> temp(levelSize);

            for(int i = 0 ; i < levelSize ; i++){
                TreeNode * node = q.front();
                q.pop();

                temp[i]=node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            ans.push_back(temp);

        }

        //TC:O(n) since every node is pushed and popped once 
        //SC:O(n)
        return ans ;
    }
};
