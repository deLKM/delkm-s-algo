/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * */
#include <cmath>
#include <utility>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int val1 = (l1 != nullptr) ? l1->val: 0;
            int val2 = (l2 != nullptr) ? l2->val: 0;
            int sum = val1 + val2 + carry;

            if (head == nullptr) {
                head = tail = new ListNode(sum % 10);
            } 
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }

            carry = sum / 10;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
        }

        return head;
    }
};
// @lc code=end

int main() {
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* result = s.addTwoNumbers(l1, l2);
    return 0;
}

