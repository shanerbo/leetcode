/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.90%)
 * Likes:    6098
 * Dislikes: 1589
 * Total Accepted:    1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode(0);
    ListNode *tmp = res;
    int carryOver = 0;
    while (l1 || l2) {
      int sum = 0;
      if (l1 && l2) {
        sum = l1->val + l2->val + carryOver;
        l1 = l1->next;
        l2 = l2->next;
      } else if (l1) {
        sum = l1->val + carryOver;
        l1 = l1->next;
      } else if (l2) {
        sum = l2->val + carryOver;
        l2 = l2->next;
      }
      if (sum > 9) {
        carryOver = 1;
        sum = sum - 10;
      } else {
        carryOver = 0;
      }

      tmp->next = new ListNode(sum);
      tmp = tmp->next;
    }
    if (carryOver != 0) {
      tmp->next = new ListNode(1);
    }

    return res->next;
  }
};
// @lc code=end
