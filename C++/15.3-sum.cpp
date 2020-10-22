/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.85%)
 * Likes:    4602
 * Dislikes: 532
 * Total Accepted:    657.7K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
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
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (size_t i = 0; i < nums.size(); i++) {
      int start = i + 1, end = nums.size() - 1;
      if (nums[i] > 0) {
        return res;
      }
      int target = -nums[i];
      while (start < end) {
        if (nums[start] + nums[end] == target) {
          vector<int> tuple = {nums[i], nums[start], nums[end]};
          res.push_back(tuple);
          while (start < nums.size() - 1 && nums[start] == nums[start + 1]) {
            start++;
          }
          while (end > start + 1 && nums[end] == nums[end - 1]) {
            end--;
          }

          start++;
          end--;
        } else if (nums[start] + nums[end] < target) {
          start++;
        } else {
          end--;
        }
      }

      while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return res;
  }
};
// @lc code=end
