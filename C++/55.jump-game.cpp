/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (34.59%)
 * Likes:    4467
 * Dislikes: 335
 * Total Accepted:    493.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i][j] <= 10^5
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
  bool canJump(vector<int> &nums) { return helper(nums, 0); }
  bool canJump1(vector<int> &nums) { return helper(nums, 0); }
  bool helper(vector<int> &nums, int pos) {
    int maxStep = nums[pos];

    if (pos + maxStep >= nums.size() - 1 || pos >= nums.size() - 1) {
      return true;
    }
    if (maxStep == 0) {
      return false;
    }

    for (size_t i = maxStep; i > 0; --i) {
      //   cout << pos + i << endl;
      if (helper(nums, pos + i)) {
        return true;
      }
    }
    // cout << "here" << endl;
    return false;
  }
};
// @lc code=end
