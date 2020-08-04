/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (46.42%)
 * Likes:    463
 * Dislikes: 41
 * Total Accepted:    24.4K
 * Total Submissions: 52.5K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 * 
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int res = 0;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (grid.empty()) {
            return res;
        }
        int r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }
        while (q.size() > 0) {
            res++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> loc = q.front();
                q.pop();
                for (int j = 0; j < dir.size(); ++j) {
                    int x = loc.first + dir[j].first;
                    int y = loc.second + dir[j].second;
                    if (x >= 0 && y >= 0 && x < r && y < c && grid[x][y] == 1) {
                        q.push(make_pair(x, y));
                        grid[x][y] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res == 0 ? 0 : res - 1;
    }
};