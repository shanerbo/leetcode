/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (56.38%)
 * Likes:    348
 * Dislikes: 30
 * Total Accepted:    39.8K
 * Total Submissions: 70.3K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string S, return the "reversed" string where all characters that are
 * not a letter stay in the same place, and all letters reverse their
 * positions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "ab-cd"
 * Output: "dc-ba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S doesn't contain \ or "
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    string reverseOnlyLetters(string s) {
        string res;
        if (s.empty()) {
            return res;
        }
        unordered_map<int, char> map;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (!isalpha(c)) {
                map[i] = c;
            } else {
                res += c;
            }
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i <= res.size(); ++i) {
            if (map.find(i) != map.end()) {
                res.insert(i, 1, map[i]);
            }
        }
        return res;
    }
};
// @lc code=end
