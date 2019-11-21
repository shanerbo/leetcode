/*
 * @lc app=leetcode id=325 lang=cpp
 */
class Solution {
  public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        int res = 0;
        if (nums.empty()) {
            return res;
        }
        unordered_map<int, int> map;
        map[nums[0]] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0) {
                nums[i] = nums[i] + nums[i - 1];
                if (map.count(nums[i]) == 0) {
                    map[nums[i]] = i;
                }
            }
            int target = nums[i] - k;
            if (nums[i] == k) {
                res = max(res, i + 1);
            }
            if (map.count(target) > 0 && map[target] < i) {
                res = max(res, i - map[target]);
            }
        }
        return res;
    }
};