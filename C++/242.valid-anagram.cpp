/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.79%)
 * Likes:    900
 * Dislikes: 119
 * Total Accepted:    414.4K
 * Total Submissions: 768.2K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.length() == 0 && t.length() == 0) {
            return true;
        }

        if (s.length() == 0 || t.length() == 0 || t.length() != s.length()) {
            return false;
        }
        vector<int> charCount(26, 0);
        for (auto const c : s) {
            charCount[c - 'a']++;
        }
        for (auto const c : t) {
            charCount[c - 'a']--;
        }
        for (auto const count : charCount) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end
