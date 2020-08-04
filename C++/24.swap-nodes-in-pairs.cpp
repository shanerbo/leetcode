/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.72%)
 * Likes:    1467
 * Dislikes: 133
 * Total Accepted:    368.2K
 * Total Submissions: 786.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode *swapPairs(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode **prev = &head, **pivot = &(*prev)->next;
        while ((*prev) && (*pivot)) {
            swap(*prev, (*pivot)->next);
            swap(*prev, *pivot);
            if (!(*pivot)) {
                break;
            }
            prev = pivot;
            pivot = &(*prev)->next;
        }
        return head;
    }
};
// @lc code=end
