/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (46.25%)
 * Likes:    2017
 * Dislikes: 62
 * Total Accepted:    360.2K
 * Total Submissions: 776.2K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
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
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
      return res;
    }
    sort(nums.begin(), nums.end());
    helper(nums, 0, res);
    return res;
  }
  void helper(vector<int> nums, int s, vector<vector<int>> &res) {
    if (s == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (size_t i = s; i < nums.size(); i++) {
      if (nums[s] == nums[i] && s != i) {
        continue;
      }

      swap(nums[i], nums[s]);
      // this is important
      helper(nums, s + 1, res);
      //   swap(nums[i], nums[s]);
    }
  }
};
// @lc code=end
