/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <vector>
using namespace std;
constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          res = max(helper(grid, i, j), res);
        }
      }
    }
    return res;
  }
  int helper(vector<vector<int>>& g, int i, int j) {
    int sum = 1;
    g[i][j] = 0;
    for (const auto& dir : dirs) {
      int new_i = i + dir[0], new_j = j + dir[1];
      if (new_i >= 0 and new_i < g.size() and new_j >= 0 and
          new_j < g[0].size() and g[new_i][new_j] == 1) {
        sum += helper(g, i + dir[0], j + dir[1]);
      }
    }
    return sum;
  }
};
// @lc code=end
