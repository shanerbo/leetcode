/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    vector<int> check_list(nums.size(), -1);
    for (auto& n : nums) {
      if (n > 0 and n - 1 < nums.size() and check_list[n - 1] == -1) {
        check_list[n - 1] = 0;
      }
    }
    for (int i = 0; i < check_list.size(); ++i) {
      if (check_list[i] == -1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};
// @lc code=end
