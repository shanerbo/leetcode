/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.99%)
 * Likes:    4467
 * Dislikes: 403
 * Total Accepted:    673.5K
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
public:
  string longestPalindrome(string s) {
    if (s.empty()) {
      return s;
    }

    int start = 0, length = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      int currEnd = i + 1, currStart = i - 1;
      int currLength = 1;
      while (currEnd < s.size() && s[i] == s[currEnd]) {
        currLength++;
        currEnd++;
      }
      while (currStart >= 0 && currEnd < s.size() &&
             s[currStart] == s[currEnd]) {
        currLength += 2;
        currStart--;
        currEnd++;
      }
      if (currLength >= length) {
        start = currStart + 1;
        length = currLength;
      }
    }
    return s.substr(start, length);
  }
};
// @lc code=end
