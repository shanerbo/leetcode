/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int last_ascending_idx = -1, last_greater_idx = -1, n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] < nums[i + 1]) {
        last_ascending_idx = i;
      }
    }
    if (last_ascending_idx == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > nums[last_ascending_idx]) {
        last_greater_idx = i;
      }
    }
    swap(nums[last_ascending_idx], nums[last_greater_idx]);
    reverse(nums.begin() + last_ascending_idx + 1, nums.end());
  }
};