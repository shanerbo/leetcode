/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    if (nums.empty()) {
      return {};
    }
    vector<vector<int>> res;
    // [-2, -2, -2, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1]
    for (int curr = 0; curr < nums.size(); ++curr) {
      int l = curr + 1, r = nums.size() - 1;
      int target = 0 - nums[curr];
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          res.push_back({nums[l], nums[curr], nums[r]});
          while (l + 1 < curr and nums[l] == nums[l + 1]) {
            l++;
          }
          while (r - 1 > curr and nums[r] == nums[r - 1]) {
            r--;
          }
          l++;
          r--;
        } else if (nums[l] + nums[r] > target) {
          r--;
        } else {
          l++;
        }
      }
      // skip duplicated nums
      while (curr + 1 < nums.size() and nums[curr] == nums[curr + 1]) {
        curr++;
      }
    }
    return res;
  }
};

// @lc code=end
