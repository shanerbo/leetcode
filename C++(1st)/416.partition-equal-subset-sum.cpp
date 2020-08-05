/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (41.70%)
 * Likes:    1642
 * Dislikes: 50
 * Total Accepted:    119.1K
 * Total Submissions: 285K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        if (nums.size() == 0) {
            return false;
        }
        for (auto const &n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector<int> visited(nums.size(), 0);
        int target = sum / 2;
        for (auto const &n : nums) {
            if (n == target) {
                return true;
            }
            if (n > target) {
                return false;
            }
        }
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        // dp[0][0] = 1;
        // for (int i = 1; i <= nums.size(); ++i) {
        //     for (int j = 1; j <= target; ++j) {
        //         dp[i][j] = dp[i - 1][j];
        //         if (j >= nums[i - 1]) {
        //             dp[i][j] = dp[i - 1][j - nums[i - 1]] == 0 ? dp[i][j] == 0 ? 0 : 1 : 1;
        //             if (j == target && dp[i][j] == 1) {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return dp[nums.size()][target] == 1;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto const &num : nums) {
            for (int j = target; j > 0; j--) {
                if (j >= num) {
                    dp[j] = dp[j] == 0 ? dp[j - num] == 0 ? 0 : 1 : 1;
                    if (dp[j] == 1 && j == target) {
                        return true;
                    }
                }
            }
        }
        return dp[target];
    }
};
