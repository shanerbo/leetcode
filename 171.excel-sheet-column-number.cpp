/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (52.59%)
 * Likes:    692
 * Dislikes: 128
 * Total Accepted:    249.5K
 * Total Submissions: 472.8K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 */

// @lc code=start
class Solution {
  public:
    int titleToNumber(string s) {
        int res = 0;
        if (s.length() == 0) {
            return res;
        }
        int sig = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (sig == 0) {
                res += (s[i] - 'A' + 1);
            } else {
                res += (s[i] - 'A' + 1) * pow(26, sig);
            }
            sig++;
        }
        return res;
    }
};
// @lc code=end
