/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.38%)
 * Likes:    1930
 * Dislikes: 139
 * Total Accepted:    337.5K
 * Total Submissions: 683.1K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 */
class Solution {
   public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int total = m + n;
        int bigger = m >= n ? m : n;
        double nominator = 1;
        double denominator = 1;
        for (int i = total; i > bigger; --i) {
            nominator *= i;
        }
        for (int i = total - bigger; i > 0; --i) {
            denominator *= i;
        }
        return nominator / denominator * 1;
    }
};
