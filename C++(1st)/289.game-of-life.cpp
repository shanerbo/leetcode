/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (48.86%)
 * Likes:    1194
 * Dislikes: 220
 * Total Accepted:    137.8K
 * Total Submissions: 282K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 * 
 * Example:
 * 
 * 
 * Input: 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output: 
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        /*
         * 10 -> 11 live->die
         * 00 -> 01 die->live
         * 00 -> 00 die->die
         * 10 -> 10 live->live
         */
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] <<= 1;
            }
        }
        int width = board[0].size();
        int height = board.size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int sum = 0;
                for (int k = i - 1; k < i + 2; k++) {
                    if (k >= 0 && k < height) {
                        for (int p = j - 1; p < j + 2; p++) {
                            if (p >= 0 && p < width) {
                                if (i == k && j == p) {
                                    continue;
                                }
                                sum = sum + (board[k][p] >> 1);
                            }
                        }
                    }
                }
                if (board[i][j] >> 1 == 1) { // used to be alive
                    if (sum > 3 || sum < 2) {
                        board[i][j] += 1; // 10 -> 11
                    }
                }
                if (board[i][j] >> 1 == 0 && sum == 3) {
                    board[i][j] += 1;
                }
            }
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 3 || board[i][j] == 0) {
                    board[i][j] = 0;
                } else {
                    board[i][j] = 1;
                }
            }
        }
    }
};
// @lc code=end
