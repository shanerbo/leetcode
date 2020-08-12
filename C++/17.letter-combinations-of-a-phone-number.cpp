/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.18%)
 * Likes:    2623
 * Dislikes: 337
 * Total Accepted:    453.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
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
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) {
      return res;
    }

    vector<string> map = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper(digits, 0, "", map, res);
    return res;
  }
  void helper(string &digits, int pos, string curr, vector<string> &map,
              vector<string> &res) {
    if (curr.size() == digits.size()) {
      res.push_back(curr);
      return;
    }

    for (auto const &c : map[digits[pos] - '0']) {
      cout << c;
      helper(digits, pos + 1, curr + c, map, res);
    }
  }
};
// @lc code=end
