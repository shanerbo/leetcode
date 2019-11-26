/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.47%)
 * Likes:    2591
 * Dislikes: 92
 * Total Accepted:    566.1K
 * Total Submissions: 1M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// @lc code=start
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int counter = 0;
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == 0) {
                it = nums.erase(it);
                counter++;
            } else {
                ++it;
            }
        }
        for (int i = 0; i < counter; ++i) {
            nums.push_back(0);
        }
    }
};
// @lc code=end
