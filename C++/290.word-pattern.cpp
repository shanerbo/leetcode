/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (37.00%)
 * Likes:    1412
 * Dislikes: 181
 * Total Accepted:    221.3K
 * Total Submissions: 582.8K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 *
 * Example 1:
 *
 *
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 *
 * Example 2:
 *
 *
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 *
 * Example 3:
 *
 *
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 *
 * Example 4:
 *
 *
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
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
  bool wordPattern(string pattern, string str) {
    if (str.empty()) {
      return false;
    }
    if (pattern.empty() && !str.empty()) {
      return false;
    }
    istringstream iss(str);
    string word;
    vector<string> dict;
    while (iss >> word) {
      dict.push_back(word);
    }
    if (dict.size() != pattern.size()) {
      return false;
    }

    unordered_map<char, string> map;
    unordered_map<string, char> map2;
    for (size_t i = 0; i < pattern.size(); ++i) {
      char c = pattern[i];
      if (map.find(c) == map.end()) {
        map[c] = dict[i];
      } else {
        if (map[c] != dict[i]) {
          return false;
        }
      }
      if (map2.find(dict[i]) == map2.end()) {
        map2[dict[i]] = c;
      } else {
        if (map2[dict[i]] != c) {
          return false;
        }
      }
    }

    return true;
  }
};
// @lc code=end
