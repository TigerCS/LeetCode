/*
http://oj.leetcode.com/problems/recover-binary-search-tree/

wo elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure. 
*/

class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        recoverTreeHelper(root, prev, first, second);
        if(first && second)
            swap(first->val, second->val);
    }
     
    void recoverTreeHelper(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second)
    {
        if(!root) return;
        recoverTreeHelper(root->left, prev, first, second);
        if(prev && prev->val > root->val) {
            second = root;
            if(!first)
                first = prev;
        }
        prev = root;
        recoverTreeHelper(root->right, prev, first, second);
    }
};
