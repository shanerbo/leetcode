/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (27.13%)
 * Likes:    1209
 * Dislikes: 71
 * Total Accepted:    77.4K
 * Total Submissions: 284.8K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 * 
 * 
 * Note:
 * 
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    string removeKdigits(string num, int k) {
        string res;
        if (num.empty()) {
            return num;
        }
        for (auto const &n : num) {
            while (k && res.length() && res.back() > n) {
                res.pop_back();
                k--;
            }
            // we need to keep res in ascending order
            if (res.length() || n != '0') // skip leading 0
            {
                res += n;
            }
        }
        // if original num is in ascending order, we need to remove last k char and res is not empty
        while (k-- && !res.empty()) {
            res.pop_back();
        }

        return res.empty() ? "0" : res;
    }
};
// @lc code=end
