/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (48.96%)
 * Likes:    610
 * Dislikes: 90
 * Total Accepted:    155.1K
 * Total Submissions: 316.1K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        if (n == 0) {
            return ret;
        } else {
            // the order of direction is > v < ^
            // each direction begin with n and -2 each iteration
            int num = 1;
            int end = n * n;
            int x = 0, y = 0;
            while (num <= end) {
                for (; y < n && ret[x][y] == 0; ++y) {
                    ret[x][y] = num++;
                }
                y--;
                x++;
                for (; x < n && ret[x][y] == 0; ++x) {
                    ret[x][y] = num++;
                }
                x--;
                y--;
                for (; y >= 0 && ret[x][y] == 0; --y) {
                    ret[x][y] = num++;
                }
                y++;
                x--;
                for (; x >= 0 && ret[x][y] == 0; --x) {
                    ret[x][y] = num++;
                }
                x++;
                y++;
            }
            return ret;
        }
    }
};
// @lc code=end
