/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.51%)
 * Likes:    2540
 * Dislikes: 3958
 * Total Accepted:    841.3K
 * Total Submissions: 3.3M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
// @lc code=start
class Solution {
public:
  int reverse(int x) {
    int sign = x < 0 ? -1 : 1;
    if (x == INT_MIN) {
      return 0;
    }
    int res = 0;
    x = abs(x);
    while (x) {
      int residual = x % 10;
      if (res > INT_MAX / 10 || INT_MAX - res * 10 < residual) {
        return 0;
      } else {
        res = res * 10 + residual;
        x /= 10;
      }
    }
    if (sign < 0 && res == INT_MAX) {
      return 0;
    }

    return res * sign;
  }
};
// @lc code=end
