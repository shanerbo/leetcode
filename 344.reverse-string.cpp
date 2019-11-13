/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (64.50%)
 * Likes:    927
 * Dislikes: 586
 * Total Accepted:    532.6K
 * Total Submissions: 824.6K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    void reverseString(vector<char> &s) {
        if (s.empty() || s.size() == 1) {
            return;
        }
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] == s[s.size() - 1 - i]) {
                continue;
            }
            swap(s[i], s[s.size() - i - 1]);
        }
        return;
    }
};
// @lc code=end
