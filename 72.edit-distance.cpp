/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (39.77%)
 * Likes:    2576
 * Dislikes: 40
 * Total Accepted:    202.7K
 * Total Submissions: 508.6K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int minDistance(string word1, string word2) {
        // this is a tipical DP problem
        // if the Ci == Cj dp[i][j] = dp[i-1][j-1]
        // else Ci != Cj dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1; because we can sert delete replace
        if (word1.length() == word2.length() && word1.length() == 0) {
            return 0;
        }
        int row = word2.length(), col = word1.length();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        for (int i = 0; i < col + 1; i++) {
            dp[0][i] = i;
        }
        for (int i = 0; i < row + 1; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < col + 1; j++) {
                if (word2[i - 1] == word1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[word2.length()][word1.length()];
    }
};
// @lc code=end
