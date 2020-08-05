/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.25%)
 * Likes:    2412
 * Dislikes: 798
 * Total Accepted:    293.4K
 * Total Submissions: 934.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        if (nums.empty()) {
            return;
        }
        int firstP = -1;
        int switchP= -1;
        for (int i = nums.size() - 1 - 1; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                firstP = i;
                break;
            }
        }
        if (firstP == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (uint32_t i = nums.size() - 1; i >= 0; --i) {
            if(nums[i] > nums[firstP]){
                switchP = i;
                break;
            }
        }
        swap(nums[switchP], nums[firstP]);
        reverse(nums.begin()+firstP+1, nums.end());
    }
};
// @lc code=end
