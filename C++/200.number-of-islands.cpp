/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.14%)
 * Likes:    3282
 * Dislikes: 117
 * Total Accepted:    442.2K
 * Total Submissions: 1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class Solution {
  private:
    int row, col;
    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row >= this->row || col >= this->col || row < 0 || col < 0 || grid[row][col] != '1') {
            return;
        }
        {
            grid[row][col] = '0';
            dfs(grid, row + 1, col);
            dfs(grid, row - 1, col);
            dfs(grid, row, col + 1);
            dfs(grid, row, col - 1);
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        int ret = 0;
        if (grid.size() < 1) {
            return ret;
        } else {
            this->row = grid.size();
            this->col = grid[0].size();
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == '1') {
                        dfs(grid, i, j);
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
