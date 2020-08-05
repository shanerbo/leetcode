/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (39.16%)
 * Likes:    1146
 * Dislikes: 75
 * Total Accepted:    148.9K
 * Total Submissions: 379.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
    using graph = vector<vector<char>>;

  private:
    vector<vector<char>> board;
    bool validRow(int i, int j, char num, graph &board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == num) {
                return false;
            }
        }
        return true;
    }

    bool validCol(int i, int j, char num, graph &board) {
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == num) {
                return false;
            }
        }
        return true;
    }

    bool validSquare(int i, int j, char num, graph &board) {
        int boxRow = i / 3 * 3;
        int boxCol = j / 3 * 3;
        for (int k = boxRow; k < boxRow + 3; k++) {
            for (int p = boxCol; p < boxCol + 3; p++) {
                if (board[k][p] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validEntry(int i, int j, char num, graph &board) {
        if (validRow(i, j, num, board) && validCol(i, j, num, board) && validSquare(i, j, num, board)) {
            return true;
        } else {
            return false;
        }
    };

    bool emptyCell(vector<int> &loc, graph &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    loc[0] = i;
                    loc[1] = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool solve(graph &board) {
        vector<int> loc(2);
        if (!emptyCell(loc, board)) {
            return true;
        }
        int x = loc[0];
        int y = loc[1];
        for (int i = 1; i < 10; i++) {
            if (validEntry(x, y, i + '0', board)) {
                board[loc[0]][loc[1]] = i + '0';
                if (solve(board)) {
                    return true;
                }
                board[loc[0]][loc[1]] = '.'; // if fails set back to .
            }
        }
        return false;
    }

  public:
    void
    solveSudoku(vector<vector<char>> &board) {
        solve(board);
    }
};
// @lc code=end
