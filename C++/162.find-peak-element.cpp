/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    long l = 0, r = nums.size() - 1;
    while (l < r) {
      long mid = (l + r) >> 1;
      long left = 0, right = 0;
      if (mid == 0) {
        left = INT_MIN;
      } else {
        left = nums[mid - 1];
      }
      if (mid + 1 == nums.size()) {
        right = INT_MIN;
      } else {
        right = nums[mid + 1];
      }
      if (left < nums[mid] and nums[mid] > right) {
        return mid;
      }
      if (left > nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
// @lc code=end
