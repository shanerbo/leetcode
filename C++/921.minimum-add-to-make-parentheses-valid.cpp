/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 *
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (73.80%)
 * Likes:    827
 * Dislikes: 63
 * Total Accepted:    76.4K
 * Total Submissions: 102.9K
 * Testcase Example:  '"())"'
 *
 * Given a string S of '(' and ')' parentheses, we add the minimum number of
 * parentheses ( '(' or ')', and in any positions ) so that the resulting
 * parentheses string is valid.
 *
 * Formally, a parentheses string is valid if and only if:
 *
 *
 * It is the empty string, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 *
 *
 * Given a parentheses string, return the minimum number of parentheses we must
 * add to make the resulting string valid.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "())"
 * Output: 1
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "((("
 * Output: 3
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "()"
 * Output: 0
 *
 *
 *
 * Example 4:
 *
 *
 * Input: "()))(("
 * Output: 4
 *
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * S.length <= 1000
 * S only consists of '(' and ')' characters.
 *
 *
 *
 *
 *
 *
 *
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
class Solution {
public:
  int minAddToMakeValid(string S) {
    int closeNeed = 0, res = 0;
    for (auto const &c : S) {
      if (c == '(') {
        closeNeed++;
      } else {
        closeNeed--;
        if (closeNeed < 0) {
          res++;
          closeNeed += 1;
        }
      }
    }
    return res + closeNeed;
  }
};
// @lc code=end
