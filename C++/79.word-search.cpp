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
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
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
#include <algorithm>
#include <bitset>
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

using namespace std;
// @lc code=start
class Solution {
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() && word.empty()) {
      return true;
    }
    if (board.empty() && !word.empty()) {
      return false;
    }
    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == word[0]) {
          auto temp = board[i][j];
          board[i][j] = '.';
          if (helper(board, word, i, j, 1)) {
            return true;
          }
          board[i][j] = temp;
        }
      }
    }
    return false;
  }
  bool helper(vector<vector<char>> &board, string &word, int i, int j,
              int pos) {
    if (pos >= word.size()) {
      return true;
    }
    char target = word[pos];
    for (auto const &dir : dirs) {
      if (i + dir[0] < board.size() && j + dir[1] < board[0].size() &&
          i + dir[0] >= 0 && j + dir[1] >= 0 &&
          board[i + dir[0]][j + dir[1]] != '.' &&
          board[i + dir[0]][j + dir[1]] == word[pos]) {
        auto temp = board[i + dir[0]][j + dir[1]];
        board[i + dir[0]][j + dir[1]] = '.';
        if (helper(board, word, i + dir[0], j + dir[1], pos + 1)) {
          return true;
        }
        board[i + dir[0]][j + dir[1]] = temp;
      }
    }
    return false;
  }
};
// @lc code=end// @lc code=end
