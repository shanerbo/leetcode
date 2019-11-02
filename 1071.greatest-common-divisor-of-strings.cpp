/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (53.96%)
 * Likes:    189
 * Dislikes: 61
 * Total Accepted:    14K
 * Total Submissions: 26K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T
 * concatenated with itself 1 or more times)
 * 
 * Return the largest string X such that X divides str1 and X divides str2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= str1.length <= 1000
 * 1 <= str2.length <= 1000
 * str1[i] and str2[i] are English uppercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

  public:
    string gcdOfStrings(string str1, string str2) {
        int GCD = gcd(str1.length(), str2.length());
        string gcdString = str1.substr(0, GCD);
        for (int i = 0; i < str1.length(); i += GCD) {
            if (gcdString != str1.substr(i, GCD)) {
                return "";
            }
        }
        for (int i = 0; i < str2.length(); i += GCD) {
            if (gcdString != str2.substr(i, GCD)) {
                return "";
            }
        }
        return gcdString;
    }
};
// @lc code=end
