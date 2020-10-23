/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1362
 * Dislikes: 97
 * Total Accepted:    385.3K
 * Total Submissions: 842.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
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
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int diff = 10001;
    for (size_t i = 0; i < nums.size(); i++) {
      int start = i + 1, end = nums.size() - 1;
      while (start < end) {
        int sum = nums[i] + nums[start] + nums[end];

        if (target == sum) {
          return sum;
        } else if (target > sum) {
          start++;
        } else {
          end--;
        }
        int newDiff = target - sum;
        diff = abs(diff) <= abs(newDiff) ? diff : newDiff;
      }
      while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
        ++i;
      }
    }
    return target - diff;
  }
};
// @lc code=end
