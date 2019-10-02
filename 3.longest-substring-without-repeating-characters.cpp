/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.88%)
 * Likes:    6437
 * Dislikes: 376
 * Total Accepted:    1.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    std::map<char, int> dict;
    int max = 0;
    int p = 0;
    for (auto i = 0; i < s.length(); i++) {
      auto c = s[i];
      auto it = dict.find(c);
      if (it != dict.end() && it->second >= p) {
        p = it->second + 1;
      } else {
        auto len = i - p + 1;
        max = std::max(len, max);
      }
      dict[c] = i;
    }
    return max;
  }
};
