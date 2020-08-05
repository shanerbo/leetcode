/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (32.17%)
 * Likes:    2404
 * Dislikes: 86
 * Total Accepted:    263K
 * Total Submissions: 813.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution {

  public:
    int coinChange(vector<int> &coins, int amount) {
        if (coins.size() == 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }

        int res;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (auto const &coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i] != -1 && dp[i - coin] != -1) {
                    dp[i] = min(1 + dp[i - coin], dp[i]);
                } else if (dp[i] == -1 && dp[i - coin] != -1) {
                    dp[i] = dp[i - coin] + 1;
                } else if (dp[i] == -1 && dp[i - coin] == -1) {
                    continue;
                }
            }
        }
        return dp[amount] == -1 ? -1 : dp[amount];
    }
};
// @lc code=end
