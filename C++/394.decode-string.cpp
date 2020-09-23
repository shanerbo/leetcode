/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (46.74%)
 * Likes:    2049
 * Dislikes: 111
 * Total Accepted:    142.2K
 * Total Submissions: 302.5K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
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
  string decodeString(string s) {
    if (s.empty()) {
      return "";
    }
    stack<string> st;
    for (int j = 0; j < s.length(); ++j) {
      char c = s[j];
      if (c == ']') {
        string pattern, res;
        int repeat = 0;
        while (!st.empty()) {
          string letter = st.top();
          st.pop();
          if (letter == "[") {
            repeat = stoi(st.top());
            st.pop();
            break;
          } else {
            pattern = letter + pattern;
          }
        }
        for (int i = 0; i < repeat; ++i) {
          res += pattern;
        }
        st.push(res);
      } else {
        string repeat;
        while (c - '0' >= 0 && c - '0' <= 9) {
          repeat += c;
          c = s[++j];
        }
        if (!repeat.empty()) {
          st.push(repeat);
          j--;
        } else {
          st.push(string(1, c));
        }
      }
    }
    string res;
    while (!st.empty()) {
      res = st.top() + res;
      st.pop();
    }
    return res;
  }
};