/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (46.49%)
 * Likes:    2495
 * Dislikes: 92
 * Total Accepted:    117.1K
 * Total Submissions: 251.5K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array nums which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays.
 *
 * Write an algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [7,2,5,10,8], m = 2
 * Output: 18
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,5], m = 2
 * Output: 9
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,4,4], m = 3
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= m <= min(50, nums.length)
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int l = INT_MIN, r = 0;
    for (auto const &n : nums) {
      r += n;
      l = max(l, n);
    }
    int mid = (l + r) / 2;
    while (l <= r) {
      int local_sum = 0, group_num = 1, local_max = 0;

      for (auto const &n : nums) {
        if (local_sum + n <= mid) {
          local_sum += n;
        } else {
          group_num++;
          local_sum = n;
        }
        local_max = max(local_sum, local_max);
      }
      if (group_num > m) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }

      mid = (l + r) / 2;
    }

    return l;
  }
};
// @lc code=end
