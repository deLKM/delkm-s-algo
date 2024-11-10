/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> nums;
    void traversal(TreeNode* root) {
        if (root == nullptr) return;

        traversal(root->left);
        nums.push_back(root->val);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        if (nums.size() < 2) return 0;

        int result = INT_MAX;
        for (int i = 0; i < nums.size() - 1; ++i) {
            result = std::min(result, nums[i + 1] - nums[i]);
        }
        return result;
    }
};
// @lc code=end

