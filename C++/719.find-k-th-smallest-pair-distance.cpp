/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (31.61%)
 * Likes:    1023
 * Dislikes: 36
 * Total Accepted:    34.8K
 * Total Submissions: 109.6K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B.
 *
 * Example 1:
 *
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 *
 *
 *
 * Note:
 *
 * 2 .
 * 0 .
 * 1 .
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
  int smallestDistancePair(vector<int> &nums, int k) {
    if (nums.empty()) {
      return -1;
    }
    sort(nums.begin(), nums.end());
    int lower = 0;
    int upper = nums[nums.size() - 1] - lower;
    while (lower < upper) {
      int currCnt = 0;

      // see how many pairs that distance smaller than m
      int m = (lower + upper) >> 1;
      for (int i = 0, j = 0; i < nums.size(); ++i) {
        while (j < nums.size() && nums[j] - nums[i] <= m) {
          j++;
        }
        currCnt += j - 1 - i;
      }
      if (currCnt < k) {
        lower = m + 1;
      } else {
        upper = m;
      }
    }
    return lower;
  }
};
// @lc code=end
