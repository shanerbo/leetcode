/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (51.51%)
 * Likes:    1107
 * Dislikes: 456
 * Total Accepted:    297.2K
 * Total Submissions: 576.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res(1, -1);
        if (numbers.size() < 1) {
            return res;
        }
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++) {
            int subTarget = target - numbers[i];

            if (map.find(numbers[i]) != map.end()) {
                if (i > map[numbers[i]]) {
                    return {map[numbers[i]] + 1, i + 1};
                } else {
                    return {i + 1, map[numbers[i]] + 1};
                }
            } else {
                map[subTarget] = i;
            }
        }
        return res;
    }
};
// @lc code=end
