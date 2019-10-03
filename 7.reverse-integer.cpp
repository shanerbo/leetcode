/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.50%)
 * Likes:    2475
 * Dislikes: 3840
 * Total Accepted:    815K
 * Total Submissions: 3.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */
class Solution {
   public:
    int reverse(int x) {
        if (x > INT_MAX || x < INT_MIN) {
            return 0;
        }
        int ret = 0;
        while (x) {
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && ret % 10 > 7)) {
                return 0;
            }
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && ret % 10 < -8)) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x = x / 10;
        }
        return ret;
    }
};
