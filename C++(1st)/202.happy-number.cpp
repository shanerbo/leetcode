/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (46.95%)
 * Likes:    1103
 * Dislikes: 285
 * Total Accepted:    281K
 * Total Submissions: 596.8K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */

// @lc code=start
class Solution {
  public:
    bool isHappy(int n) {
        set<int> set;
        if (n < 0) {
            return false;
        }
        while (n > 0) {
            if (n == 1) {
                return true;
            }
            int tmp = n;
            int square = 0;
            while (tmp != 0) {
                int i = tmp % 10;
                tmp /= 10;
                square += i * i;
            }
            n = square;
            if (!set.insert(n).second) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
