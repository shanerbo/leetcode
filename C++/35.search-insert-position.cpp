/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.26%)
 * Likes:    1627
 * Dislikes: 207
 * Total Accepted:    479.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
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
  int searchInsert(vector<int> &nums, int target) {
    if (nums.empty()) {
      return 0;
    }
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
      int m = s + (e - s) / 2;
      if (nums[m] == target) {
        return m;
      }

      if (nums[m] < target) {
        s = m + 1;
      } else if (nums[m] > target) {
        e = m - 1;
      } else {
        return m;
      }
    }

    return s;
  }
};
// @lc code=end
