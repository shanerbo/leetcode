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
    string res;
    int maxLength = 0;
    for (int i = 0; i < s.size(); ++i) {
      int left = i - 1;
      int right = i + 1;
      char currChar = s[i];
      while (right < s.size() && s[right] == currChar) {
        right++;
      }
      while (left >= 0 && right < s.size()) {
        if (s[left] == s[right]) {
          left--;
          right++;
        } else {
          break;
        }
      }
      left++;
      right--;
      if (right - left + 1 >= maxLength) {
        maxLength = right - left + 1;
        std::cout << left << ' ' << right << std::endl;
        res = s.substr(left, maxLength);
      }
    }
    return res;
  }
};
// @lc code=end
