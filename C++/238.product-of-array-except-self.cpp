/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
  /**
   * [2, 3, 4, 5]
   * =>
   * [1, 2*1, 3*2*1, 4*3*2*1]
   * =>
   * [4*3*2*1, 3*2*1*(5), 2*1*(5*4), 1*(5*4*3)](reversed)
   *
   */
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res = {1};
    for (size_t i = 1; i < nums.size(); ++i) {
      res.push_back(res[i - 1] * nums[i - 1]);
    }
    int product = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
      res[i] *= product;
      product *= nums[i];
    }
    return res;
  }
};
// @lc code=end
