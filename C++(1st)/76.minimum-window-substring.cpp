/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.18%)
 * Likes:    2947
 * Dislikes: 212
 * Total Accepted:    289.6K
 * Total Submissions: 897.1K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> checkList;
        if (t.length() == 0 || t.length() > s.length() || s.length() == 0) {
            return "";
        }
        int count = 0;
        for (auto const &c : t) {
            checkList[c]++;
        }
        int start = 0, end = 0, minStart = 0, len = INT_MAX;
        for (end = 0; end < s.length(); ++end) {
            if (checkList.count(s[end]) > 0) {
                checkList[s[end]]--;
                if (checkList[s[end]] >= 0) {
                    count++;
                }
            }
            while (count == t.length()) {
                minStart = len < end - start + 1 ? minStart : start;
                len = len < end - start + 1 ? len : end - start + 1;
                char currChar = s[start];
                if (checkList.count(currChar) > 0) {
                    checkList[currChar]++;
                    if (checkList[currChar] > 0) {
                        count--;
                    }
                }
                start++;
            }
        }
        if (len == INT_MAX) {
            return "";
        }
        return s.substr(minStart, len);
    }
};
// @lc code=end
