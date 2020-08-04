/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.57%)
 * Likes:    12050
 * Dislikes: 419
 * Total Accepted:    2.2M
 * Total Submissions: 4.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for idx, val := range nums {
		m[target-val] = idx
	}
	for idx, val := range nums {
		if value, ok := m[val]; ok && value != idx {
			return []int{idx, value}
		}

	}
	return []int{}
}

// @lc code=end
