/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.28%)
 * Likes:    1524
 * Dislikes: 106
 * Total Accepted:    220.8K
 * Total Submissions: 607.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode *reverseBetween(ListNode *head, int M, int N) {
        ListNode **m = &head;
        for (int i = 1; i < M; i++) {
            m = &(*m)->next;
        }
        ListNode **mn = &(*m)->next;
        for (int i = M; i < N; i++) {
            swap(*m, (*mn)->next);
            swap(*m, *mn);
        }

        return head;
    }
};
// @lc code=end
