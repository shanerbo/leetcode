/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.37%)
 * Likes:    1120
 * Dislikes: 1523
 * Total Accepted:    326.8K
 * Total Submissions: 661.9K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// @lc code=start
// class Solution {
//   public:
//     int missingNumber(vector<int> &nums) {
//         int sum = 0;
//         if (nums.size() < 1)
//             return 0;
//         for (auto &num : nums) {
//             sum += num;
//         }
//         int realSum = (nums.size()) * (nums.size() + 1) / 2;
//         return realSum - sum;
//     }
// };
/*
Method 2
*/
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        nums.push_back(0);
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret += (i - nums[i]);
        }
        return ret;
    }
};
// @lc code=end
