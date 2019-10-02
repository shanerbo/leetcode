/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::map<int, int> dict;
    std::vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
      dict.insert({target - nums[i], i});
      auto it = dict.find(nums[i]);
      if (it != dict.end() && i != it->second) {
        ret = {it->second, i};
      }
    }
    return ret;
  }
}

;
