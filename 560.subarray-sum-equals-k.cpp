/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (42.97%)
 * Likes:    2644
 * Dislikes: 72
 * Total Accepted:    152.5K
 * Total Submissions: 354.5K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0;
        if (nums.size() == 0) {
            return res;
        }
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        unordered_map<int, int> map = {{0, 1}};
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int target = num - k;
            res += map[target];
            map[num]++;
        }
        return res;
    }
};
// @lc code=end
