/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (47.14%)
 * Likes:    4126
 * Dislikes: 482
 * Total Accepted:    471.4K
 * Total Submissions: 997.1K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
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
  int maxArea(vector<int> &height) {
    ios_base::sync_with_stdio(false);
    int left = 0, right = height.size() - 1, heightest = INT_MIN;
    int res = 0;
    while (left < right) {
      if (height[left] > height[right]) {
        heightest = height[right];
        res = max((right - left) * heightest, res);
        right--;
      } else {
        heightest = height[left];
        res = max((right - left) * heightest, res);
        left++;
      }
    }

    return res;
  }
}; // @lc code=end
