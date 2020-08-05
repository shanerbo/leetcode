/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.38%)
 * Likes:    2410
 * Dislikes: 58
 * Total Accepted:    424.4K
 * Total Submissions: 765.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

// @lc code=start
class Solution1 {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ret = {{}}; // empty set is a subset;
        for (auto &num : nums) {
            int subSetSize = ret.size();
            for (int i = 0; i < subSetSize; ++i) {
                auto newSubSet = ret[i];
                newSubSet.push_back(num);
                ret.push_back(newSubSet);
            }
        }
        return ret;
    }
};
class Solution {
    void dfs(vector<int> &nums, int position, vector<int> &sub, vector<vector<int>> &subs) {
        subs.push_back(sub);
        for (int i = position; i < nums.size(); i++) {
            /* code */
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> sub;
        vector<vector<int>> subs;
        dfs(nums, 0, sub, subs);
        return subs;
    }
};
// @lc code=end