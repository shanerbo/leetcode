/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    1850
 * Dislikes: 83
 * Total Accepted:    92.7K
 * Total Submissions: 189.5K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 *
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 *
 * Example 1:
 *
 *
 * Input: S = "aab"
 * Output: "aba"
 *
 *
 * Example 2:
 *
 *
 * Input: S = "aaab"
 * Output: ""
 *
 *
 * Note:
 *
 *
 * S will consist of lowercase letters and have length in range [1, 500].
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
  string reorganizeString(string S) {
    int map[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int charHasMostCount = 0;
    int charLoc;
    for (auto const &c : S) {
      if (charHasMostCount <= ++map[c - 'a']) {
        charHasMostCount = map[c - 'a'];
        charLoc = c - 'a';
      }
    }
    if (charHasMostCount > (S.size() + 1) / 2) {
      return "";
    }
    string res(S.size(), '.');
    int start = 0;

    for (; map[charLoc];) {
      res[start] = charLoc + 'a';
      map[charLoc]--;
      start += 2;
    }
    for (size_t i = 0; i < 26; i++) {
      while (map[i]) {
        if (start >= S.size()) {
          start = 1;
        }
        res[start] = 'a' + i;
        start += 2;
        map[i]--;
      }
    }
    return res;
  }
};
// @lc code=end
