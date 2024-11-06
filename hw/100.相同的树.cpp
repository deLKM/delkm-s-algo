/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if left node and right node are both null, return true
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // if left node and right node are all not null, using recursion to compare the next pair
        else if (p != nullptr && q != nullptr) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
        }
        // if left node or right node is not null, return false
        else {
            return false;
        }
    }
};
// @lc code=end