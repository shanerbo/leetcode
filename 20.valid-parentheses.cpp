/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.32%)
 * Likes:    3407
 * Dislikes: 162
 * Total Accepted:    712K
 * Total Submissions: 1.9M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        vector<char> stack;
        for (auto& c : s) {
            if (map.find(c) != map.end()) {
                stack.push_back(c);
            } else {
                if (stack.size() != 0 && map[stack.back()] == c) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
};
// @lc code=end
