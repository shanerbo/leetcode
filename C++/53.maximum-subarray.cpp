/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.69%)
 * Likes:    5204
 * Dislikes: 206
 * Total Accepted:    647.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
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
  int maxSubArray(vector<int> &nums) {
    int res = INT_MIN;
    if (nums.empty()) {
      return res;
    }
    int lastResult = nums[0];
    res = lastResult;
    for (size_t i = 1; i < nums.size(); ++i) {
      auto n = nums[i];
      lastResult = max(n, lastResult + n);
      res = max(res, lastResult);
    }
    return res;
  }
};
// @lc code=end
