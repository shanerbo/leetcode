/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.96%)
 * Likes:    2603
 * Dislikes: 84
 * Total Accepted:    458.3K
 * Total Submissions: 786.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
      return res;
    }
    vector<int> perm;
    helper(res, 0, nums);
    return res;
  }
  void helper(vector<vector<int>> &res, int pos, vector<int> &nums) {
    if (pos >= nums.size()) {
      res.push_back(nums);
    }
    for (size_t i = pos; i < nums.size(); i++) {
      swap(nums[pos], nums[i]);
      helper(res, pos + 1, nums);
      swap(nums[pos], nums[i]);
    }
  }
};
// @lc code=end
