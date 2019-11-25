/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (65.96%)
 * Likes:    745
 * Dislikes: 74
 * Total Accepted:    159.1K
 * Total Submissions: 239.6K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */

// @lc code=start
class Solution {
  public:
    string reverseWords(string s) {
        string res;
        if (s.empty()) {
            return res;
        }
        string::iterator start = s.begin();
        for (auto it = s.begin(); it != s.end() + 1; ++it) {
            if (*it == ' ' || *it == '\0') {
                reverse(start, it);
                start = it + 1;
            }
        }
        return s;
    }
};