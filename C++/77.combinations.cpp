/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (54.88%)
 * Likes:    1677
 * Dislikes: 69
 * Total Accepted:    308.2K
 * Total Submissions: 556.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> sets = {{}};
    vector<vector<int>> res;
    for (int j = 1; j <= n; ++j) {
      auto size = sets.size();
      for (int i = 0; i < size; ++i) {
        sets[i].push_back(j);
        if (sets[i].size() == k) {
          res.push_back(sets[i]);
        }
        if (sets[i].size() < k) {
          sets.push_back(sets[i]);
        }
      }
    }
    return res;
  }
  void helper(vector<vector<int>> &res, int n, int k, vector<int> &set,
              int pos) {
    if (set.size() == k) {
      res.push_back(set);
      return;
    }
    for (int i = pos; i <= n; ++i) {
      set.push_back(i);
      helper(res, n, k, set, i + 1);
      set.pop_back();
    }
  }
  vector<vector<int>> combine1(int n, int k) {
    vector<vector<int>> res;
    vector<int> set;
    helper(res, n, k, set, 1);
    return res;
  }
};
// @lc code=end
