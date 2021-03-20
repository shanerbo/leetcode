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
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
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
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class Solution {
private:
  vector<vector<int>> direction = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  void helper(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or
        grid[i][j] != '1') {
      return;
    }

    grid[i][j] = '0';
    for (auto const &dir : direction) {
      helper(grid, i + dir[0], j + dir[1]);
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          helper(grid, i, j);
          res++;
        }
      }
    }

    return res;
  }
};
// @lc code=end
