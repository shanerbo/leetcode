/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (42.14%)
 * Likes:    1256
 * Dislikes: 58
 * Total Accepted:    166.1K
 * Total Submissions: 393K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 1}};
    bool validate(vector<string> &graph, int r, int c, int n) {
        for (auto const &t : graph) {
            if (t[c] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < 2; i++) {
            int x = r, y = c;
            int x1 = dir[i].first, y1 = dir[i].second;
            while (x >= 0 && y >= 0 && x < n && y < n) {
                if (graph[x][y] == 'Q') {
                    return false;
                }
                x = x + x1;
                y = y + y1;
            }
        }

        return true;
    }
    void backTracking(vector<vector<string>> &res, vector<string> &path, int size, int row) {
        if (row >= size) {
            res.emplace_back(path);
            return;
        }
        for (int j = 0; j < size; j++) {
            if (validate(path, row, j, size)) {
                path[row][j] = 'Q';
                backTracking(res, path, size, row + 1);
                path[row][j] = '.';
            }
        }
        return;
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        backTracking(res, path, n, 0);
        return res;
    }
};
// @lc code=end
