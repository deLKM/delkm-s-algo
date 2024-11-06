/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
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
    bool isSymmetric(TreeNode* root) {
        TreeNode* p = root->left;
        TreeNode* q = root->right;

        return isSameTree(p, q);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if left node and right node are both null, return true
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // if left node and right node are all not null, using recursion to compare the next pair
        else if (p != nullptr && q != nullptr) {
            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left) && p->val == q->val;
        }
        // if left node or right node is not null, return false
        else {
            return false;
        }
    }
};
// @lc code=end

