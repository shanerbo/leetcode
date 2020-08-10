/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (45.05%)
 * Likes:    2359
 * Dislikes: 247
 * Total Accepted:    461K
 * Total Submissions: 1M
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,4,5,1,2]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
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
  int findMin1(vector<int> &nums) {
    int s = 0, e = nums.size() - 1;
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }

    return helper(nums, s, e);
  }
  int findMin(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        return nums[i + 1];
      }
    }
    return nums[0];
  }

private:
  int helper(vector<int> &nums, int s, int e) {
    if (s == e) {
      return nums[s];
    }
    int m = (e - s) / 2;
    m += s;
    if (nums[m] > nums[e]) {
      return helper(nums, m + 1, e);
    } else {
      return helper(nums, s, m);
    }
  }
};
// @lc code=end
