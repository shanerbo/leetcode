/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int target = 0;
        unordered_map<int, int> map;
        for (const auto &a : nums1) {
            for (const auto &b : nums2) {
                map[a + b]++;
            }
        }
        int res = 0;
        for (const auto &a : nums3) {
            for (const auto &b : nums4) {
                if (map.find(target - a - b) != map.end()) {
                    res += map[target - a - b];
                }
            }
        }
        return res;
    }
};
// @lc code=end
