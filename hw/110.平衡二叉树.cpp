/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <algorithm>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) { return true; }

        int leftDepth, rightDepth;

        // if (root->left == nullptr) {
        //     leftDepth = 0; 
        // }
        // else {
        //     leftDepth = maxDepth(root->left);
        // }
        // if (root->right == nullptr) { 
        //     rightDepth = 0; 
        // }
        // else {
        //     rightDepth = maxDepth(root->right);
        // }

        leftDepth = (root->left == nullptr) ? 0 : maxDepth(root->left);
        rightDepth = (root->right == nullptr) ? 0 : maxDepth(root->right);
        
        if (leftDepth - rightDepth > 1 || leftDepth - rightDepth < -1) { return false; }
        else { return isBalanced(root->left)&&isBalanced(root->right); }

    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// @lc code=end

