/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.93%)
 * Likes:    1314
 * Dislikes: 449
 * Total Accepted:    273.9K
 * Total Submissions: 915.2K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    int prime(int n) {
        if (n % 2 == 0 && n != 2) {
            return -1;
        } else {
            int root = sqrt(n);

            for (int i = 1; i <= root; i++) {
                if (n % i == 0 && i != 1) {
                    return -1;
                }
            }
            return n;
        }
    }

  public:
    int countPrimes(int n) {
        int ret = 1;
        if (n <= 2) {
            return 0;
        }
        for (int i = 3; i < n; i += 2) {
            if (prime(i) != -1) {
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end
