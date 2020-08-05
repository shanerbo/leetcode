/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 *
 * https://leetcode.com/problems/custom-sort-string/description/
 *
 * algorithms
 * Medium (63.66%)
 * Likes:    509
 * Dislikes: 152
 * Total Accepted:    45.9K
 * Total Submissions: 72K
 * Testcase Example:  '"cba"\n"abcd"'
 *
 * S and T are strings composed of lowercase letters. In S, no letter occurs
 * more than once.
 * 
 * S was sorted in some custom order previously. We want to permute the
 * characters of T so that they match the order that S was sorted. More
 * specifically, if x occurs before y in S, then x should occur before y in the
 * returned string.
 * 
 * Return any permutation of T (as a string) that satisfies this property.
 * 
 * 
 * Example :
 * Input: 
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation: 
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b",
 * and "a". 
 * Since "d" does not appear in S, it can be at any position in T. "dcba",
 * "cdba", "cbda" are also valid outputs.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S has length at most 26, and no character is repeated in S.
 * T has length at most 200.
 * S and T consist of lowercase letters only.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    string customSortString(string S, string T) {
        if (T.empty()) {
            return T;
        }
        string res;
        unordered_map<char, int> map;
        for (auto const &c : S) {
            map[c] = 0;
        }
        for (auto const &c : T) {
            if (map.count(c) > 0) {
                map[c]++;
            } else {
                res += c;
            }
        }
        for (auto const &s : S) {
            for (int i = 0; i < map[s]; ++i) {
                res += s;
            }
        }
        return res;
    }
};
// @lc code=end
