/*
 * @lc app=leetcode id=1 lang=cpp
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

using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    if (nums.empty()) {
      return {};
    }
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      auto n = nums[i];
      int substract = target - n;
      if (map.find(substract) != map.end()) {
        return {i, map[substract]};
      }
      map[n] = i;
    }
    return {};
  }
};
// @lc code=end
