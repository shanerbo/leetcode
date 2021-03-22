/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.91%)
 * Likes:    2707
 * Dislikes: 212
 * Total Accepted:    433.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return {};
    }
#define START 0
#define END 1
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      auto in = intervals[i];
      int start = in[START], end = in[END];
      bool merged = false;
      for (int j = 0; j < res.size(); ++j) {
        if (res[j][1] >= start) {
          res[j] = {res[j][0], max(end, res[j][1])};
          merged = true;
          break;
        }
      }
      if (!merged) {
        res.push_back(in);
      }
    }
    return res;
  }
};
// @lc code=end
