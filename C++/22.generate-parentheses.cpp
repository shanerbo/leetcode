/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.31%)
 * Likes:    3378
 * Dislikes: 200
 * Total Accepted:    400.2K
 * Total Submissions: 698.2K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class Solution {
  void helper(vector<string> &res, string s, int leftNeed, int rightNeed) {
    if (leftNeed == 0 and rightNeed == 0) {
      res.push_back(s);
      return;
    }
    if (leftNeed > 0) {
      helper(res, s + '(', leftNeed - 1, rightNeed + 1);
    }
    if (rightNeed > 0) {
      helper(res, s + ')', leftNeed, rightNeed - 1);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(res, "", n, 0);
    return res;
  }
};
// @lc code=end
