/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.96%)
 * Likes:    2603
 * Dislikes: 84
 * Total Accepted:    458.3K
 * Total Submissions: 786.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {

  private:
    bool exist(vector<int> &path, int append) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == append) {
                return true;
            }
        }
        return false;
    }
    void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!exist(path, nums[i])) {
                path.emplace_back(nums[i]);
                dfs(nums, path, res);
                path.pop_back();
            } else {
                continue;
            }
        }
    };

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, path, res);
        return res;
    }
};
// @lc code=end
