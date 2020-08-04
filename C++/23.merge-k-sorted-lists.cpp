/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.29%)
 * Likes:    2995
 * Dislikes: 198
 * Total Accepted:    461.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l1, ListNode* l2) { return l1->val > l2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto& l : lists) {
            if (!l) continue;
            pq.push(l);
        }
        ListNode* head = new ListNode(0);
        auto* tmp = head;
        while (pq.size() != 0) {
            auto* top = pq.top();
            pq.pop();
            if (top->next) {
                pq.push(top->next);
            }
            tmp->next = top;
            tmp = tmp->next;
        }
        return head->next;
    }
};
// @lc code=end
