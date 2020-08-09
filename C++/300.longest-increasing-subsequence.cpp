/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (42.56%)
 * Likes:    4991
 * Dislikes: 111
 * Total Accepted:    395.3K
 * Total Submissions: 927.7K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Example:
 *
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 * Note:
 *
 *
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
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
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, 1);
    if (nums.empty()) {
      return 0;
    }
    int res = 1;
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
      for (int j = 1; j < i; j++) {
        if (nums[i - 1] > nums[j - 1]) {
          dp[i] = max(dp[i], dp[j] + 1);
          res = max(res, dp[i]);
        }
      }
    }
    return res;
  }
};
// @lc code=end
