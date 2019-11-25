/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (30.62%)
 * Likes:    1568
 * Dislikes: 84
 * Total Accepted:    146K
 * Total Submissions: 471K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    int m, n;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    struct Trie {
        vector<Trie *> next;
        bool word;
        Trie() : next(26, nullptr), word(false){};
        void insert(string w) {
            auto head = this;
            for (auto const &c : w) {
                if (!head->next[c - 'a']) {
                    head->next[c - 'a'] = new Trie();
                }
                head = head->next[c - 'a'];
            }
            head->word = true;
        }
    };

  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> res;
        Trie *root = new Trie();
        for (auto const &w : words) {
            root->insert(w);
        }
        string path;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                checkWord(board, root, path + board[i][j], res, i, j);
            }
        }
        return res;
    }
    void checkWord(vector<vector<char>> &board, Trie *root, string path, vector<string> &res, int i, int j) {
        char c = board[i][j];
        if (root->next[c - 'a'] == nullptr) {
            return;
        } // no such word;
        root = root->next[c - 'a'];
        if (root->word) {
            res.push_back(path);
            root->word = false;
        }
        board[i][j] = '\0';
        for (int p = 0; p < 4; p++) {
            int x = i + dir[p].first;
            int y = j + dir[p].second;
            if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] != '\0') {
                checkWord(board, root, path + board[x][y], res, x, y);
            }
        }
        board[i][j] = c;
    }
};
// @lc code=end
