/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.71%)
 * Likes:    3099
 * Dislikes: 577
 * Total Accepted:    344.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
 *
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    int sSize = s.length(), pSize = p.length();
    vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < sSize + 1; i++) {
      for (int j = 1; j < pSize + 1; j++) {
        if (p[j - 1] == '*') {
          auto noRepeated = dp[i][j - 2];
          if (i < 1) {
            dp[i][j] = noRepeated;
            continue;
          }

          auto previousResult = dp[i - 1][j];
          auto sameChar = s[i - 1] == p[j - 1 - 1];
          auto isDot = p[j - 2] == '.';
          auto validPrefix = isDot || sameChar;
          auto validRegex = validPrefix && previousResult;
          dp[i][j] = noRepeated || validRegex;
        } else {
          if (i < 1) {
            dp[i][j] = false;
          } else {
            auto previousResult = dp[i - 1][j - 1];
            auto sameChar = p[j - 1] == s[i - 1];
            auto isDot = p[j - 1] == '.';
            dp[i][j] = previousResult && (sameChar || isDot);
          }
        }
      }
    }
    return dp[sSize][pSize];
  }
};
