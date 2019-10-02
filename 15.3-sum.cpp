/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.84%)
 * Likes:    4590
 * Dislikes: 531
 * Total Accepted:    656K
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
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());  // sort vector
    set<vector<int>> ret;
    if (nums.size() < 3) {
      return {};
    } else if (*(nums.begin()) > 0) {
      return {};
    } else if (*(nums.end() - 1) < 0) {
      return {};
    }

    for (auto it = nums.begin(); it != nums.end(); ++it) {
      auto l = nums.begin();
      auto r = nums.end() - 1;
      int twoSum = 0 - *it;
      while (l < it && it < r) {
        if (*l + *r > twoSum) {
          r--;
        } else if (*l + *r < twoSum) {
          l++;
        } else if (*l + *r == twoSum) {
          auto tmp = {*l, *it, *r};
          ret.insert(tmp);
          r--;
          l++;
        }
      }
    }
    vector<vector<int>> vector(ret.begin(), ret.end());

    return vector;
  }
};
