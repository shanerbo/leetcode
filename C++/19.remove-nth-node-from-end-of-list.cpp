/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.61%)
 * Likes:    2181
 * Dislikes: 161
 * Total Accepted:    457.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 *
 * Example:
 *
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 *
 * Note:
 *
 * Given n will always be valid.
 *
 * Follow up:
 *
 * Could you do this in one pass?
 *
 */
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
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
  ListNode *removeNthFromEnd1(ListNode *head, int n) {
    if (!head) {
      return nullptr;
    }
    auto hare = head;
    auto prev = &head;
    for (size_t i = 0; i < n; i++) {
      hare = hare->next;
    }
    while (hare) {
      hare = hare->next;
      prev = &((*prev)->next);
    }
    *prev = (*prev)->next;
    return head;
  }

  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) {
      return nullptr;
    }
    auto hare = head, tortoise = head;
    for (size_t i = 0; i < n; i++) {
      hare = hare->next;
    }
    ListNode *prev = nullptr;
    for (; hare;) {
      prev = tortoise;
      tortoise = tortoise->next;
      hare = hare->next;
    }
    if (!prev) {
      return head->next;
    } else {
      prev->next = tortoise->next;
    }

    return head;
  }
};
// @lc code=end
