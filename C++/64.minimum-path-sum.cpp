/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (49.29%)
 * Likes:    1750
 * Dislikes: 45
 * Total Accepted:    275.5K
 * Total Submissions: 558.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}};
        int res = 0;
        if (grid.empty()) {
            return res;
        }
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                int shortestPath = min(grid[i - 1][j], grid[i][j - 1]);
                grid[i][j] += shortestPath;
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end
