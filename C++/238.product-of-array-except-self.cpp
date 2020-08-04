/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (56.90%)
 * Likes:    2939
 * Dislikes: 254
 * Total Accepted:    325.7K
 * Total Submissions: 570.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> res(size, 1);
        for (int i = 1; i < size; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int prevProduct = 1;
        for (int i = size - 1; i >= 0; i--) {
            res[i] *= prevProduct;
            prevProduct *= nums[i];
        }
        return res;
    }
};
// @lc code=end
