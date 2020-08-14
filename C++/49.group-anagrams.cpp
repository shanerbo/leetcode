/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (49.66%)
 * Likes:    2069
 * Dislikes: 132
 * Total Accepted:    407.9K
 * Total Submissions: 820.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
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
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    for (auto const &s : strs) {
      char checkList[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (auto const &c : s) {
        checkList[c - 'a']++;
      }
      string converted;
      for (size_t i = 0; i < 26; i++) {
        if (checkList[i] != 0) {
          for (size_t j = 0; j < checkList[i]; j++) {
            converted += 'a' + i;
          }
        }
      }
      m[converted].push_back(s);
    }
    for (auto const &e : m) {
      res.push_back(e.second);
    }
    return res;
  }
};
// @lc code=end
