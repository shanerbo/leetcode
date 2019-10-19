/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (18.14%)
 * Likes:    685
 * Dislikes: 2461
 * Total Accepted:    320.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

// @lc code=start
class Solution {
  public:
    string reverseWords(string s) {
        if (s.length() < 1)
            return "";
        s += ' ';
        stack<string> stack;
        string res;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            } else {
                for (j = i; j < s.length(); j++) {
                    if (s[j] == ' ') {
                        stack.push(s.substr(i, j - i));
                        i = j;
                        break;
                    }
                }
                i = j;
            }
        }

        int stackSize = stack.size();
        if (stackSize == 0) {
            return "";
        }

        for (int i = 0; i < stackSize; ++i) {
            res = res + ' ' + stack.top();
            stack.pop();
        }
        return res.substr(1);
    }
};
// @lc code=end
