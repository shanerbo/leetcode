/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.10%)
 * Likes:    1796
 * Dislikes: 2033
 * Total Accepted:    307.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
class Solution {

  public:
    int numDecodings(string s) {
        int res = 0;
        if (s.length() < 1) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }

        vector<int> dp(s.length() + 1, 1);
        for (int i = 2; i <= s.length(); i++) {
            if (s[i - 1] == '0') {
                if (i - 2 < 0) {
                    dp[i] = 0;
                } else if (s[i - 2] == '0') {
                    return 0;
                } else if (s[i - 2] - '0' <= 2) {
                    dp[i] = dp[i - 2];
                } else {
                    return 0;
                }
            }

            else if (stoi(s.substr(i - 2, 2)) <= 26 && stoi(s.substr(i - 2, 2)) > 0 && s[i - 2] != '0') {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end
