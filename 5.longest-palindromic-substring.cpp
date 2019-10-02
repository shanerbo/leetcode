/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.97%)
 * Likes:    4390
 * Dislikes: 401
 * Total Accepted:    664.2K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
class Solution {
 public:
  string longestPalindrome(string s) {
    int l = 0, r = 0;
    int maxStart = 0, maxLen = 1;
    for (int p = 0; p < s.length(); p++) {
      auto localMaxlen = 1;
      l = p - 1;
      r = p + 1;
      while (r < s.length() && s[r] == s[p]) {
        localMaxlen++;
        r++;
        /* skip same char abbbbbbbba */
      }
      while (l >= 0 && r < s.length() && s[l] == s[r]) {
        localMaxlen += 2;
        l--;
        r++;
      }
      if (localMaxlen >= maxLen) {
        maxStart = l + 1;
        maxLen = localMaxlen;
      }
    }
    return s.substr(maxStart, maxLen);
  }
};
