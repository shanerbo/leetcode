/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (63.40%)
 * Likes:    3117
 * Dislikes: 93
 * Total Accepted:    177.1K
 * Total Submissions: 278.1K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 *
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 *
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
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
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &t) {
    vector<int> waits(t.size(), 0);
    stack<int> stack;
    for (size_t i = 0; i < t.size(); i++) {
      if (!stack.empty()) {
        while (!stack.empty() && t[i] > t[stack.top()]) {
          waits[stack.top()] = i - stack.top();
          stack.pop();
        }
      }
      stack.push(i);
    }
    return waits;
  }
};
// @lc code=end
