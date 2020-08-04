/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.90%)
 * Likes:    1129
 * Dislikes: 51
 * Total Accepted:    257.4K
 * Total Submissions: 585.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<vector<int>> res;

  private:
    void dfs(int target, int position, vector<int> &candidates, vector<int> &path) {
        if (target == 0) {
            res.push_back(path);
        } else {
            for (int i = position; i < candidates.size() && candidates[i] <= target; i++) {
                // need to skip any char is same as previous char
                // if candidates[i] = 1, cadidates = [1,1,1,1,1,1,1,2] need to skip all 1's after candidates[i];
                if (i != position && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                path.push_back(candidates[i]);
                dfs(target - candidates[i], i + 1, candidates, path);
                path.pop_back();
            }
        }
    }

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(target, 0, candidates, path);
        return res;
    }
};
// @lc code=end
