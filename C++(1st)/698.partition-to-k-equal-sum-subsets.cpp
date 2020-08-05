/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (43.90%)
 * Likes:    1118
 * Dislikes: 64
 * Total Accepted:    58.9K
 * Total Submissions: 133.9K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    bool dfs(vector<int> &nums, vector<bool> &visited, int k, int s, int start, int groupSum, int currSum) {
        if (s == k) {
            return true;
        }
        if (currSum == groupSum) {
            return dfs(nums, visited, k, s + 1, 0, groupSum, 0);
        }
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (dfs(nums, visited, k, s, i + 1, groupSum, currSum + nums[i]))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }

  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        if (k == 0 || nums.empty()) {
            return false;
        }
        int sum = 0;
        for (auto const &n : nums) {
            sum += n;
        }
        int groupSum = sum / k;
        if (groupSum * k != sum) {
            return false;
        }
        vector<bool> visited(nums.size(), false);
        int setNumber = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (n > groupSum) {
                return false;
            }
            if (n == groupSum) {
                visited[i] = true;
                setNumber++;
            }
        }
        return dfs(nums, visited, k, setNumber, 0, groupSum, 0);
    }
};
// @lc code=end
