/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (57.00%)
 * Likes:    2981
 * Dislikes: 258
 * Total Accepted:    330.4K
 * Total Submissions: 577.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Example:
 *
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 *
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
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
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 1);
    vector<int> r_res(nums.size(), 1);
    if (nums.empty()) {
      return res;
    }

    for (int i = 1; i < nums.size(); ++i) {
      res[i] = nums[i - 1] * res[i - 1];
      r_res[nums.size() - i - 1] =
          nums[nums.size() - i] * r_res[nums.size() - i];
    }
    for (int i = 0; i < nums.size(); ++i) {
      res[i] *= r_res[i];
    }
    return res;
  }
};
// @lc code=end
