/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;  // {sum, num}
    int res = 0, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int target = sum - k;
      if (map.find(target) != map.end()) {
        res += map[target];
      }
      map[sum]++;
      if (sum == k) {
        res++;
      }
    }
    return res;
  }
};
// @lc code=end
