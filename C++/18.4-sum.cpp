/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.58%)
 * Likes:    1274
 * Dislikes: 254
 * Total Accepted:    265.5K
 * Total Submissions: 840.7K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
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
// @lc code=start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4) {
      return {};
    }
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++) {
      int target_1 = target - nums[i];
      for (size_t j = i + 1; j < nums.size(); j++) {
        int target_2 = target_1 - nums[j];
        size_t start = j + 1, end = nums.size() - 1;
        while (start < end) {
          if (nums[start] + nums[end] > target_2) {
            end--;
          } else if (nums[start] + nums[end] < target_2) {
            start++;
          } else {
            res.push_back({nums[i], nums[j], nums[start], nums[end]});
            do {
              start++;
            } while (start < end and nums[start] == nums[start - 1]);
            do {
              end--;
            } while (start < end and nums[end] == nums[end + 1]);
          }
        }

        while (j < nums.size() - 1 and nums[j] == nums[j + 1]) {
          ++j;
        }
      }

      while (i < nums.size() - 1 and nums[i] == nums[i + 1]) {
        ++i;
      }
    }
    return res;
  }
};
// @lc code=end
