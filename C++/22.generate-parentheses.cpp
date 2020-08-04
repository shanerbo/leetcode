/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.31%)
 * Likes:    3378
 * Dislikes: 200
 * Total Accepted:    400.2K
 * Total Submissions: 698.2K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */

// @lc code=start
class Solution {
    string seq = "";

   private:
    void dfs(vector<string>& ret, string seq, const int size, int left,
             int right) {
        if (left == 0 && right == 0) {
            ret.push_back(seq);
            return;
        } else {
            if (left > 0) {
                dfs(ret, seq + '(', size, left - 1, right);
            }
            if (left < right) {
                dfs(ret, seq + ')', size, left, right - 1);
            }
        }
    };

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int size = n, left = n, right = n;
        dfs(ret, seq, size, left, right);
        return ret;
    }
};
// @lc code=end
