/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (45.28%)
 * Likes:    2770
 * Dislikes: 97
 * Total Accepted:    491.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

// @lc code=start
class Solution {
    //   private:
    //     int res = 0;
    //     void dfs(int rest) {
    //         if (rest == 0) {
    //             res++;
    //         }
    //         if (rest < 0) {
    //             return;
    //         }

    //         dfs(rest - 1);
    //         dfs(rest - 2);
    //     }

  public:
    int climbStairs(int n) { // test it you will find this is fibonacci series
        // if (n < 1) {
        //     return res;
        // } else {
        //     dfs(n);
        // }
        // return res;
        int fib1 = 0;
        int fib2 = 1;
        if (n < 1) {
            return fib1;
        } else if (n < 2) {
            return fib2;
        }
        int fib3;
        for (int i = 0; i < n; i++) {
            fib3 = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib3;
        }
        return fib3;
    }
};
// @lc code=end
