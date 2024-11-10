/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * */

#include <vector>

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
    std::vector<int> nums;

    void traversal(TreeNode* root) {
        if (!root) return;

        traversal(root->left);
        nums.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
    //     if (!root) return true;
    //     bool leftValid = !root->left ? true : (root->left->val < root->val ? true : false);
    //     bool rightValid = !root->right ? true : (root->right->val > root->val ? true : false);
    //     return leftValid && rightValid && isValidBST(root->left) && isValidBST(root->right);
        traversal(root);
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false; 
            }
        }

        return true; 
    }
};
// @lc code=end

