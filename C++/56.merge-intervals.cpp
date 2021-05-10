/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    constexpr size_t START = 0, END = 1;
    if (intervals.empty()) {
      return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(*intervals.begin());
    for (auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
      auto &back = res.back();
      if (back[END] >= (*it)[START]) {
        // [1,3] [2,4]
        back = {back[START], max(back[END], (*it)[END])};
      } else {
        // [1,3] [4, 5]
        res.push_back((*it));
      }
    }
    return res;
  }
};
// @lc code=end
