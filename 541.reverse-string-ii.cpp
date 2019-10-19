/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (46.32%)
 * Likes:    287
 * Dislikes: 896
 * Total Accepted:    69.5K
 * Total Submissions: 149.9K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */

// @lc code=start
class Solution {
  public:
    string reverseStr(string s, int k) {
        if (s.length() < 1) {
            return s;
        }
        if (s.length() < k) {
            reverse(s.begin(), s.end());
            return s;
        }
        int combination = s.length() / (2 * k);
        int rest = s.length() - 2 * k * combination;
        auto bit = s.begin(), eit = s.begin(), rit = s.begin() + combination * 2 * k;
        for (int i = 0; i < combination; ++i) {
            bit = s.begin() + 2 * k * i;
            eit = bit + k;
            reverse(bit, eit);
        }
        if (rest < k) {
            reverse(rit, s.end());
        } else if (rest >= k) {
            reverse(rit, rit + k);
        }
        return s;
    }
};