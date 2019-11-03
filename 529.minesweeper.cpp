/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (54.83%)
 * Likes:    409
 * Dislikes: 384
 * Total Accepted:    43.2K
 * Total Submissions: 78.3K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool mineDetect(vector<vector<char>> &board, pair<int, int> loc, queue<pair<int, int>> &q) {
        int m = board.size();
        int n = board[0].size();
        int mines = 0;
        vector<pair<int, int>> neighbour;
        for (int i = 0; i < dir.size(); i++) {
            int x = loc.first + dir[i].first;
            int y = loc.second + dir[i].second;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                neighbour.emplace_back(make_pair(x, y));
                if (board[x][y] == 'M') {
                    mines++;
                    continue;
                }
            }
        }
        if (mines == 0) {
            for (auto const p : neighbour) {
                if (board[p.first][p.second] == 'E') {
                    board[p.first][p.second] = 'B';
                    q.push(make_pair(p.first, p.second));
                }
            }
        } else {
            board[loc.first][loc.second] = mines + '0';
        }

        return mines;
    };

  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        if (board.empty()) {
            return board;
        }
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            pair<int, int> loc = q.front();
            q.pop();
            int mineAround = mineDetect(board, loc, q);
        }
        return board;
    }
};
// @lc code=end
