/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (51.54%)
 * Likes:    2634
 * Dislikes: 81
 * Total Accepted:    419.4K
 * Total Submissions: 811.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    void dfs(vector<int> &candidates, vector<vector<int>> &res, int start, int target, int currSum, vector<int> &path) {
        if (currSum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (currSum + candidates[i] <= target) {
                path.push_back(candidates[i]);
                dfs(candidates, res, i, target, currSum + candidates[i], path);
                path.pop_back();
            }
        }
        return;
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) {
            return res;
        }
        vector<int> path;
        dfs(candidates, res, 0, target, 0, path);
        return res;
    }
};
// @lc code=end
