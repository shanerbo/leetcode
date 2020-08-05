/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.64%)
 * Likes:    2325
 * Dislikes: 123
 * Total Accepted:    342.7K
 * Total Submissions: 1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */

// @lc code=start
class Solution {
    using Board = vector<vector<char>>;

  private:
    bool wordSearch(Board &board, string word, int i, int j) {
        if (word.length() == 0) {
            return true;
        }
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] != word[0]) {
            return false;
        }
        char tmp = word[0];
        board[i][j] = '#';
        if (wordSearch(board, word.substr(1), i - 1, j) || wordSearch(board, word.substr(1), i + 1, j) || wordSearch(board, word.substr(1), i, j - 1) || wordSearch(board, word.substr(1), i, j + 1)) {
            return true;
        }
        board[i][j] = tmp;
        return false;
    }

  public:
    bool exist(vector<vector<char>> &board, string word) {
        char start = word[0];
        int row, col;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && wordSearch(board, word, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end
//|| wordSearch(board, word.substr(1), i - 1, j - 1) || wordSearch(board, word.substr(1), i + 1, j + 1) || wordSearch(board, word.substr(1), i + 1, j - 1) || wordSearch(board, word.substr(1), i - 1, j + 1)