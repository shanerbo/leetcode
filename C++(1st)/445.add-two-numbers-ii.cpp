/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.70%)
 * Likes:    948
 * Dislikes: 125
 * Total Accepted:    117.4K
 * Total Submissions: 225.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
static int my_speed_up = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) {
            return nullptr;
        }
        if (!l2) {
            return l1;
        } else if (!l1) {
            return l2;
        }
        ListNode *res = new ListNode(0);
        ListNode *ans = res;
        reverse(l1);
        reverse(l2);
        int carry = 0, sum = 0;
        while (l1 || l2) {
            if (l1 && l2) {
                sum = l1->val + l2->val + carry;
            } else if (!l1) {
                sum = l2->val + carry;
            } else {
                sum = l1->val + carry;
            }
            if (sum / 10 > 0) {
                carry = 1;
            } else {
                carry = 0;
            }
            l1 = l1 && l1->next ? l1->next : nullptr;
            l2 = l2 && l2->next ? l2->next : nullptr;
            res->next = new ListNode(sum % 10);
            res = res->next;
        }
        if (carry == 1) {
            res->next = new ListNode(1);
        }
        reverse(ans->next);
        return ans->next;
    }
    void reverse(ListNode *&a) {
        ListNode **head = &a;
        ListNode **pivot = &(*head)->next;
        while (*pivot) {
            swap(*head, (*pivot)->next);
            swap(*head, *pivot);
        }
    }
};

// @lc code=end
