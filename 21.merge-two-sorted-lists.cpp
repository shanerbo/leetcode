/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.14%)
 * Likes:    2703
 * Dislikes: 395
 * Total Accepted:    699.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* l3tmp = nullptr;
        if (l1->val <= l2->val) {
            l3tmp = l1;
            l1 = l1->next;
        } else {
            l3tmp = l2;
            l2 = l2->next;
        }
        auto* l3 = l3tmp;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                l3tmp->next = l1;
                l1 = l1->next;
            } else {
                l3tmp->next = l2;
                l2 = l2->next;
            }
            l3tmp = l3tmp->next;
        }
        if (l1) {
            l3tmp->next = l1;
        } else if (l2) {
            l3tmp->next = l2;
        }
        return l3;
    }
};
// @lc code=end
