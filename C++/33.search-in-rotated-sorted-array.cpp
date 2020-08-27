/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (34.59%)
 * Likes:    5495
 * Dislikes: 475
 * Total Accepted:    769.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Given an integer array nums sorted in ascending order, and an integer
 * target.
 *
 * Suppose that nums is rotated at some pivot unknown to you beforehand (i.e.,
 * [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You should search for target in nums and if you found return its index,
 * otherwise return -1.
 *
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int s = 0, e = nums.size() - 1;
    int m = (e + s) / 2;
    while (s <= e) {

      m = (e + s) / 2;
      if (nums[m] == target) {
        return m;
      }

      if (nums[m] >= nums[e]) {
        if (nums[s] <= target && target < nums[m]) {
          e = m - 1;
        } else {
          s = m + 1;
        }
      } else {
        if (nums[e] >= target && target > nums[m]) {
          s = m + 1;
        } else {
          e = m - 1;
        }
      }
    }
    return -1;
  };
};
// @lc code=end
