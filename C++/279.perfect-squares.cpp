/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (47.21%)
 * Likes:    3079
 * Dislikes: 192
 * Total Accepted:    317.7K
 * Total Submissions: 671.8K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
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
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for (size_t i = 1; i * i <= n; i++) {
      dp[i] = 1;
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      auto max = n - curr;
      for (size_t i = 1; i * i <= max; i++) {
        if (dp[i * i + curr] == INT_MAX || curr == 0) {
          dp[i * i + curr] = dp[curr] + 1;
          if (i * i + curr == n) {
            return dp[n];
          }
          q.push(i * i + curr);
        }
      }
    }
    return dp[n];
  }
};
// @lc code=end
