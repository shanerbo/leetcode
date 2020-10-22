/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.19%)
 * Likes:    1636
 * Dislikes: 1483
 * Total Accepted:    552.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
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
  string longestCommonPrefix(vector<string> &strs) {
    string res;
    if (strs.empty()) {
      return res;
    }
    auto prefix = strs[0];
    for (size_t j = 0; j < prefix.size(); j++) {
      for (size_t i = 0; i < strs.size(); i++) {
        if (j >= strs[i].size()) {
          return res;
        }
        if (strs[i][j] != prefix[j]) {
          return res;
        }
      }
      res += prefix[j];
    }

    return res;
  }
};
// @lc code=end
