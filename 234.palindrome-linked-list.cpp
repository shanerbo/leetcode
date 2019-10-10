/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.17%)
 * Likes:    1998
 * Dislikes: 287
 * Total Accepted:    306.7K
 * Total Submissions: 824.8K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode *head) {
        // find mid of the linked list using fast-slow pointer fast moves two step, slow moves one step
        auto *fast = head, *slow = head;
        while (fast && fast->next) { // fast->next is valid aka fast->next->null is the last checkpoint
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next; // if the length is odd move forward one step;
        }

        // reverse linked list
        ListNode *prev = nullptr, *curr = slow;
        while (curr) {
            ListNode *next = nullptr;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        while (prev) {
            if (prev->val != head->val) {
                return false;
            } else {
                prev = prev->next;
                head = head->next;
            }
        }
        return true;
    }
};
// @lc code=end
