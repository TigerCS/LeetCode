/*
http://oj.leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root) return res; 
        stack<TreeNode*> nodeStack;
        TreeNode* cur = root;
        while(!nodeStack.empty()||cur) {
            if(cur) {
                nodeStack.push(cur);
                cur=cur->left;
            }
            else
            {
              cur = nodeStack.top(); nodeStack.pop();
              res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
