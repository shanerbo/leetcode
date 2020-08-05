/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.38%)
 * Likes:    2410
 * Dislikes: 58
 * Total Accepted:    424.4K
 * Total Submissions: 765.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret = {{}}; // empty set is a subset;
    for (auto &num : nums) {
      int subSetSize = ret.size(); // this is very important
      for (int i = 0; i < subSetSize; ++i) {
        auto newSubSet = ret[i];
        newSubSet.push_back(num);
        ret.push_back(newSubSet);
      }
    }
    return ret;
  }
};
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
      return res;
    }
    vector<int> sub = {};
    helper(nums, 0, sub, res);
    return res;
  }

private:
  void helper(vector<int> &nums, int position, vector<int> &sub,
              vector<vector<int>> &res) {
    res.push(sub);
    for (size_t i = position; i < nums.size(); i++) {
      sub.push_back(nums[i]);
      helper(nums, i + 1, sub, res);
      sub.pop_back();
    }
  }
};
// @lc code=end
