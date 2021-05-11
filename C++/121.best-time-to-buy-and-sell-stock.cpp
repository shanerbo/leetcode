/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int m = prices[0], res = 0;
        for (const auto &p : prices) {
            if (p < m) {
                m = p;
            }
            res = max(res, p - m);
        }
        return res;
    }
};
// @lc code=end
