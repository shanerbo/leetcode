/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.69%)
 * Likes:    5204
 * Dislikes: 206
 * Total Accepted:    647.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int lastResult = nums[0];
        int sum = lastResult;
        for (int i = 1; i < nums.size(); ++i) {
            lastResult = max(lastResult + nums[i], nums[i]);
            sum = max(sum, lastResult);
        }
        return sum;
    }
};
// @lc code=end
