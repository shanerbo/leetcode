/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (29.96%)
 * Likes:    2187
 * Dislikes: 656
 * Total Accepted:    251.3K
 * Total Submissions: 838.4K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            /*the key idea is that for any trival list, it must contain 1...k(k=nums.size()) digit. put each number     *into correspoing position.
            */
            while (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < size; i++) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return size + 1;
    }
};
// @lc code=end
